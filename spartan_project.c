#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define SIZE 100

//declare eight functions
void welcome(); // to display the welcome screen
void login();// to display the login screen
void add_books(void);
void search_books(void);
void view_book_records(void);
void view_all_books(void);
void menu(void);

void main() // declare main function
{
	welcome(); // call welcome screen
	login();// call login screen
}

//to show as a front page

void headMessage()
{
    printf("\n");
    printf("\t\t\t############################################################################");
    printf("\n\t\t\t############################################################################");
    printf("\n\t\t\t############                                                   #############");
    printf("\n\t\t\t############         Library management System                 #############");
    printf("\n\t\t\t############                                                   #############");
    printf("\n\t\t\t############################################################################");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    printf("\n\t\t\t----------------------------------------------------------------------------");
}
void welcome()
{
    headMessage(); //calling another function in welcome function
    printf("\n\n\n\n");
    printf("\t\t***     *     ***  **********    ***         ****        ***        ***     ***   **********\n");
    printf("\t\t ***   ***   ***   ***           ***       **    *     *** ***      ** ** ** **   ***\n");
    printf("\t\t  ***  **** ***    *******       ***      **          **     **     **  ***  **   ******\n");
    printf("\t\t   ***********     *******       ***      **         **      **     **   *   **   ******\n");
    printf("\t\t    ***   ***      ***           *******   **    *    ***  ***      **       **   ***\n");
    printf("\t\t     *     *       **********    *******     ****       ****        **       **   *********\n");
    printf("\n\n\n\t\t\t Enter any key to continue.....");
    getch();
}
void login()
{
	system("cls");//calling system class
	int L=0; //catching true or false for check
	char a[30], b[30]; //arrays for user and pass
	system("cls");



	printf("------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t\tLogin Screen");
	printf("\n------------------------------------------------------------------------------------------------");
	do
	{
		printf("\n\t\t\t\tEnter Username and Password");

		printf("\n\t\t\t\tUsername:");
		scanf("%s" ,a);

		printf("\n\t\t\t\tPassword:");
		scanf("%s" ,b);
		if((strcmp(a,"project115")==0)&& (strcmp(b,"project115")==0))
		{
			printf("\n\t\t\t\tLogged Into System.");
			printf("\n\t\t\t\tPress any key to go next.....");
			printf("\n------------------------------------------------------------------------------------------------");
			getch();
			menu();
		}
		else
		{

			printf("\t\t\t\tLogin Failed Enter Again Username & Password Again\n\n");
			L++; //to ask again input the user and pass
		}
	}
    while(L<=3); //we can try only less than 3 times
	if(L>3)
    {
		system("cls");
		printf("Sorry,Unknown User.");
		getch();
		system("cls");
	}

}

struct books//structure to call in program
{
	int books_id; // declare the integer data type
	char b_name[SIZE];// declare the character data type = books 1st name
	char a_name[SIZE];// declare the character data type = books last name
	char s_name[SIZE];// declare the character data type = student name
	char author[SIZE];// declare the character data type = author name
    char book_name[SIZE]; //for view_all_books option
	char edition[SIZE];  //for view_all_books option

	//to store book issue date
	int days;// declare the integer data type d-name
	int yr; // declare the integer data type

}m;

struct books X[100];   //another variable of books datatype

void menu()
	{
		int choice;
         //choice view with options , work as menu
		system("cls");
		printf("\n\t------------------------------------------------------------------------------------------------\n");
		printf("\t\t\t\tMAIN MENU");
		printf("\n\t------------------------------------------------------------------------------------------------\n");
		printf("\t1. Add Book Records\n");
		printf("\t2. Search Books\n");
		printf("\t3. View Books Record\n");
		printf("\t4. view All Books of each Department\n");
		printf("\t5. Exit\n\n\n\n");
		printf("\t\tPlease Enter a choice[1-5]:");

		scanf("\t%i",&choice);
		//call any options
		switch(choice)
			{
				case 1:
				add_books();//if we press 1 button it will add books function
				break;
				case 2:
			    search_books();
				break;
				case 3:
				view_book_records();
				break;
				case 4:
                view_all_books();
                break;
                case 5:
				exit(0);
				break;

				default:
					printf("Wrong Entry!!"); //for pressing more than 6 value
					exit(0);


			}
}

void add_books()
{
    system("cls");
	int days;
	FILE *sfile;//calling file to store books
	int valid ;
	int i;
	char answer;
	sfile = fopen("BookRecord.txt","a");
	printf("\n\t\t****************************************************");
	printf("\n\t\t***************ADD NEW BOOK RECORDS******************");
	printf("\n\t\t******************************************************");
	printf("\n\n\t\t  ENTER DETAILS BELOW:");
	printf("\n\t\t------------------------------");
	printf("\n\t\tBook ID NO.\t\t:");
	fflush(stdin);
	scanf("%d",&m.books_id);
	printf("\n\tNO SPACE ALLOWED FROM HERE\n");
	do
	{
       //adding info to an empty file
		printf("\n\t\tBook First Name\t\t:");
		fflush(stdin);
		gets(m.b_name);
		m.b_name[0]=toupper(m.b_name[0]);
		//calling a loop to check input is valid or name
		for (i=0;i<strlen(m.b_name); ++i)
		{
			if(isalpha(m.b_name[i]))//check if its have all alphabate no special char
			{
				valid = 1;//true
			}
			else
			{
				valid = 0;//ask for input again
				break;
			}
		}
		if (!valid)
		{
			printf("\nName contain invalid character. Please enter again.");
		}
	}
	while(! valid);
	//if we get true value of valid we will go for second input
	do
	{
		printf("\n\t\tBook Last Name\t\t:");
		fflush(stdin);
		gets(m.a_name);
		m.a_name[0]=toupper(m.a_name[0]);
		for (i=0;i<strlen(m.a_name); ++i)
		{
			if(isalpha(m.a_name[i]) || ispunct(m.a_name[i]))   //checking for alphabets and underscore
				valid = 1;
			else
			{
				valid = 0;
				break;
			}
		}
		if (!valid)
		{
			printf("\nName contain invalid character. Please enter again.");
		}
	}while(!valid);
	do
	{
		printf("\n\t\tStudent Name\t\t:");
		fflush(stdin);
		gets(m.s_name);
		m.s_name[0]=toupper(m.s_name[0]);
		for (i=0;i<strlen(m.s_name); ++i)
		{
			if(isalpha(m.s_name[i]) )
				valid = 1;
			else
			{
				valid = 0;
				break;
			}
		}
		if (!valid)
		{
			printf("\nName contain invalid character. Please enter again.");
		}
	}while(!valid);
		do
			{
				printf("\n\t\tAuthor First Name\t:");
				fflush(stdin);
				gets(m.author);
				m.author[0]=toupper(m.author[0]);
				for (i=0;i<strlen(m.author); ++i)
				{
					if(isalpha(m.author[i]))
					valid = 1;
					else
					{
						valid = 0;
						break;
					}
				}
				if (!valid)
				{
					printf("\nAuthor First Name contain invalid character. Please enter again.");
				}
			}while(!valid);

			printf("\n\t\tEnter Duration To Take Book");

			do
			{
				printf("\n\t\tMaximum [1-15] Days\t:");
				scanf("%i",&m.days);
				if(m.days<1 || m.days>15)
				{
					printf("\n\tYou Cannot take more than 15x Days.Re-Enter.");
				}
			}
			while(m.days<1 || m.days>15);

	fprintf(sfile,"%d %s %s %s %s %d\n\n",m.books_id, m.b_name, m.a_name, m.s_name,m.author,m.days);
	fclose(sfile);
	printf("\n\t SUCCESFULLY RECORDED.\n");
	getch(); //go for next page
	printf("\n\t\t Do you want to add another book?[Y/N]:");
	scanf("%s",&answer);
	while(toupper(answer)!='Y'&& toupper(answer)!='N')
	{
		printf("Invalid!\n\tDo you want to add book?[Y/N]:");
		scanf("%s",&answer);
	}
	if(toupper(answer)=='Y')
	{
		add_books();//send to add books function
	}
	else
	{
		printf("\n\t\tPress any key to go to mainmenu.....");
		menu(); //send to menu function
	}

}

void search_books()
{
	system("cls");

	printf("\n\t\t******************************************************");
	printf("\n\t\t***************** SEARCH BOOKS LIST ******************");
	printf("\n\t\t******************************************************\n\n");


	 printf("\n");

     int s;

        printf("Option 1. CSE dept\n");
        printf("Option 2. BBA dept\n");
        printf("Option 3. CIVIL dept\n");
        printf("Option 4. EEE dept\n");
        printf("Option 5. ARCHITECTURE dept\n");
        printf("Option 6. PHARMACY dept\n");
        printf("Option 7. BIOCHEMISTRY dept\n\n");

        printf("Which departments' book you want to search?");
        printf("\n\t ENTER ANY KEY (1 to 7)\n");

     scanf("%d",&s);

     int n1,n2,n3,n4,n5,n6,n7,index;
     char target[50];

        switch (s)
        {
        case 1:
            {
                FILE *fps1;

                fps1= fopen("cse.txt","r");

                if(fps1==NULL)
                {
                    printf("\n..ERROR..\n..CAN'T OPEN FILE..\n\n");

                }
                else{


                  fscanf(fps1, "%d", &n1);

                 for(int i=0; i<n1; i++)
                {
                    fscanf(fps1, "%d", &X[i].books_id);
                    fscanf(fps1, "%s", X[i].book_name);
                    fscanf(fps1, "%s", X[i].author);
                    fscanf(fps1, "%s", X[i].edition);

                }


                fclose(fps1);

                //write book's name u want to search
                printf("Write the book name u want to search\n<warning: replace spaces with underscore>\n");
                scanf("%s", target);


                     for(int i=0; i<n1; i++)
                   {
                        if(strcmp(X[i].book_name, target)==0)
                         {
                             index=i;
                              printf("Available\n");
                              printf("\n\tBook name: %s\nAuthor's name: %s\nEdition: %s\nBook id: %d",X[index].book_name,X[index].author,X[index].edition,X[index].books_id);
                              break;
                         }
                         else
                         {
                             printf("\nNo Such Records");
                             break;
                         }
                    }




                  }
                 break;
                }
        case 2:
            {
                FILE *fps2;

                fps2= fopen("bba-file.txt","r");

                if(fps2==NULL)
                {
                    printf("\n..ERROR..\n..CAN'T OPEN FILE..\n\n");
                }
                else{


                  fscanf(fps2, "%d", &n1);

                 for(int i=0; i<n2; i++)
                {
                    fscanf(fps2, "%d", &X[i].books_id);
                    fscanf(fps2, "%s", X[i].book_name);
                    fscanf(fps2, "%s", X[i].author);
                    fscanf(fps2, "%s", X[i].edition);

                }


                fclose(fps2);

                //write book's name u want to search
                printf("\tWrite the book name u want to search\n<warning: replace spaces with underscore>\n");
                scanf("%s", target);


                     for(int i=0; i<n2; i++)
                   {
                        if(strcmp(X[i].book_name, target)==0)
                         {
                             index=i;
                              printf("Available\n");
                              printf("\n\tBook name: %s\nAuthor's name: %s\nEdition: %s\nBook id: %d",X[index].book_name,X[index].author,X[index].edition,X[index].books_id);
                              break;
                         }
                         else
                         {
                             printf("\nNo Such Records");
                             break;
                         }
                    }


                  }
                 break;
                }

        case 3:
            {
                FILE *fps3;

                fps3= fopen("civil-file.txt","r");

                if(fps3==NULL)
                {
                    printf("\n..ERROR..\n..CAN'T OPEN FILE..\n\n");
                }
                else{


                  fscanf(fps3, "%d", &n1);

                 for(int i=0; i<n1; i++)
                {
                    fscanf(fps3, "%d", &X[i].books_id);
                    fscanf(fps3, "%s", X[i].book_name);
                    fscanf(fps3, "%s", X[i].author);
                    fscanf(fps3, "%s", X[i].edition);

                }


                fclose(fps3);

                //write book's name u want to search
                printf("Write the book name u want to search\n<warning: replace spaces with underscore>\n");
                scanf("%s", target);


                     for(int i=0; i<n3; i++)
                   {
                        if(strcmp(X[i].book_name, target)==0)
                         {
                             index=i;
                              printf("Available\n");
                               printf("\n\tBook name: %s\nAuthor's name: %s\nEdition: %s\nBook id: %d",X[index].book_name,X[index].author,X[index].edition,X[index].books_id);
                              break;
                         }
                         else
                         {
                             printf("\nNo Such Records");
                             break;
                         }
                    }




                  }
                 break;
                }
        case 4:
            {
                FILE *fps4;

                fps4= fopen("eee-file.txt","r");

                if(fps4==NULL)
                {
                    printf("\n..ERROR..\n..CAN'T OPEN FILE..\n\n");
                }
                else{


                  fscanf(fps4, "%d", &n1);

                 for(int i=0; i<n1; i++)
                {
                    fscanf(fps4, "%d", &X[i].books_id);
                    fscanf(fps4, "%s", X[i].book_name);
                    fscanf(fps4, "%s", X[i].author);
                    fscanf(fps4, "%s", X[i].edition);

                }


                fclose(fps4);

                //write book's name u want to search
                printf("Write the book name u want to search\n<warning: replace spaces with underscore>\n");
                scanf("%s", target);


                     for(int i=0; i<n4; i++)
                   {
                        if(strcmp(X[i].book_name, target)==0)
                         {
                             index=i;
                              printf("Available\n");
                               printf("\n\tBook name: %s\nAuthor's name: %s\nEdition: %s\nBook id: %d",X[index].book_name,X[index].author,X[index].edition,X[index].books_id);
                              break;
                         }
                         else
                         {
                             printf("\nNo Such Records");
                             break;
                         }
                    }




                  }
                 break;
                }
        case 5:
            {
                FILE *fps5;

                fps5= fopen("architecture-file.txt","r");

                if(fps5==NULL)
                {
                    printf("\n..ERROR..\n..CAN'T OPEN FILE..\n\n");
                }
                else{


                  fscanf(fps5, "%d", &n1);

                 for(int i=0; i<n1; i++)
                {
                    fscanf(fps5, "%d", &X[i].books_id);
                    fscanf(fps5, "%s", X[i].book_name);
                    fscanf(fps5, "%s", X[i].author);
                    fscanf(fps5, "%s", X[i].edition);

                }


                fclose(fps5);

                //write book's name u want to search
                printf("Write the book name u want to search\n<warning: replace spaces with underscore>\n");
                scanf("%s", target);


                     for(int i=0; i<n5; i++)
                   {
                        if(strcmp(X[i].book_name, target)==0)
                         {
                             index=i;
                              printf("Available\n");
                              printf("\n\tBook name: %s\nAuthor's name: %s\nEdition: %s\nBook id: %d",X[index].book_name,X[index].author,X[index].edition,X[index].books_id);
                              break;
                         }
                         else
                         {
                             printf("\nNo Such Records");
                             break;
                         }
                    }




                  }
                 break;
            }
        case 6:
            {
                FILE *fps6;

                fps6= fopen("pharmacy-file.txt","r");

                if(fps6==NULL)
                {
                    printf("\n..ERROR..\n..CAN'T OPEN FILE..\n\n");
                }
                else{


                  fscanf(fps6, "%d", &n1);

                 for(int i=0; i<n6; i++)
                {
                    fscanf(fps6, "%d", &X[i].books_id);
                    fscanf(fps6, "%s", X[i].book_name);
                    fscanf(fps6, "%s", X[i].author);
                    fscanf(fps6, "%s", X[i].edition);

                }


                fclose(fps6);

                //write book's name u want to search
                printf("Write the book name u want to search\n<warning: replace spaces with underscore>\n");
                scanf("%s", target);


                     for(int i=0; i<n6; i++)
                   {
                        if(strcmp(X[i].book_name, target)==0)
                         {
                             index=i;
                              printf("Available\n");
                              printf("\n\tBook name: %s\nAuthor's name: %s\nEdition: %s\nBook id: %d",X[index].book_name,X[index].author,X[index].edition,X[index].books_id);
                              break;
                         }
                         else
                         {
                             printf("\nNo Such Records");
                             break;
                         }
                    }

                  }
                 break;

            }

        case 7:
            {
                FILE *fps7;

                fps7= fopen("biochemistry-file.txt","r");

                if(fps7==NULL)
                {
                    printf("\n..ERROR..\n..CAN'T OPEN FILE..\n\n");
                }
                else{


                  fscanf(fps7, "%d", &n1);

                 for(int i=0; i<n1; i++)
                {
                    fscanf(fps7, "%d", &X[i].books_id);
                    fscanf(fps7, "%s", X[i].book_name);
                    fscanf(fps7, "%s", X[i].author);
                    fscanf(fps7, "%s", X[i].edition);

                }


                fclose(fps7);

                //write book's name u want to search
                printf("Write the book name u want to search\n<warning: replace spaces with underscore>\n");
                scanf("%s", target);


                     for(int i=0; i<n7; i++)
                   {
                        if(strcmp(X[i].book_name, target)==0)
                         {
                             index=i;
                              printf("Available\n");
                              printf("\n\tBook name: %s\nAuthor's name: %s\nEdition: %s\nBook id: %d",X[index].book_name,X[index].author,X[index].edition,X[index].books_id);
                              break;
                         }
                         else
                         {
                             printf("\nNo Such Records");
                             break;
                         }
                    }




                  }
                 break;
            }
        default :
            printf("\n\tYou didn't choose any dept yet\n");

         }

        printf("\t\t\n\n\nPress any key to go to mainmenu.....");
		getch();
		menu();
}

// view books function
void view_book_records()
{
	int i,count=0;;
	FILE*sfile;
	system("cls");
	sfile=fopen("BookRecord.txt","r");
	printf("\n\t\t\t*********************************************************");
	printf("\n\t\t\t**************** VIEW ALL BOOK RECORDS *****************");
	printf("\n\t\t\t*********************************************************");
	if(sfile==NULL) //if no books recorded yet
	{
		printf("\n\n\t\t RECORD EMPTY");
		getch();//terminate the page
	}
	else
	{

		printf("\n\ta. Book Id NO.\n");     //the format how will it show the data

		printf("\n\tb. Book First Name\n");

        printf("\n\tc. Book Last Name\n");

		printf("\n\td. Students Name\n");

		printf("\n\te. Authors Name\n");

		printf("\n\tf. Due Days\n\n");

		for(i=0;i<95;i++)     //this loop is for printing underline
		{
			printf("-");
		}

		while(fscanf(sfile,"%d %s %s %s %s %d",&m.books_id,m.b_name,m.a_name,m.s_name,m.author,&m.days)!=EOF)
		{

			printf("\n\ta. %d",m.books_id);
            printf("\n\tb. %s",m.b_name);
            printf("\n\tc. %s",m.a_name);
			printf("\n\td. %s",m.s_name);
			printf("\n\te. %s",m.author);
			printf("\n\tf. %d\n\n",m.days);
			count++;

		}
		printf("\nThere are %d books recorded here\n",count);
		printf("\n\n\n\n");
		for(i=0;i<95;i++)       //this loop is for printing underline
		printf("-");
	}
	printf("\n\n\t Press any key for menu........");
	fclose(sfile);
	getch();
	menu();


}


 void view_all_books()
 {
     system("cls");
     printf("\n");

     int s;
     printf("\n\t\t\t*********************************************************");
	 printf("\n\t\t\t****************    VIEW ALL BOOKS      *****************");
	 printf("\n\t\t\t*********************************************************\n\n");

        printf("1. CSE dept\n");
        printf("2. BBA dept\n");
        printf("3. CIVIL dept\n");
        printf("4. EEE dept\n");
        printf("5. ARCHITECTURE dept\n");
        printf("6. PHARMACY dept\n");
        printf("7. BIOCHEMISTRY dept\n\n");

        printf("\n\t ENTER ANY KEY (1 to 7)\n");

     scanf("%d",&s);

     int n1,n2,n3,n4,n5,n6,n7;

        switch (s)
        {
        case 1:
            {FILE *fp1;

                fp1= fopen("bba-file.txt","r");   //need to check

                if(fp1==NULL)
                {
                    printf("\n..ERROR..\n..CAN'T OPEN FILE..\n\n");
                }
                else{

                  fscanf(fp1, "%d", &n1);

                 for(int i=0; i<n1; i++)
                {
                    fscanf(fp1, "%d", &X[i].books_id);
                    fscanf(fp1, "%s", X[i].book_name);
                    fscanf(fp1, "%s", X[i].author);
                    fscanf(fp1, "%s", X[i].edition);

                }


                fclose(fp1);

                    printf("\n\n\tno of books %d\n", n1);
                  for(int i=0; i<n1; i++)
                    {
                        printf("\n\n\tbooks_id no = %d\n", X[i].books_id);
                        printf("\tBOOK name = %s\n", X[i].book_name);
                        printf("\tAUTHOR's name = %s\n", X[i].author);
                        printf("\tEDITION = %s\n\n", X[i].edition );

                    }
                 }
                 break;
        }

        case 2:
                {
                FILE *fp2;

                fp2= fopen("bba-file.txt","r");

                if(fp2==NULL)
                {
                    printf("\n..ERROR..\n..CAN'T OPEN FILE..\n\n");
                }
                else{

                  fscanf(fp2, "%d", &n2);

                 for(int i=0; i<n2; i++)
                {
                    fscanf(fp2, "%d", &X[i].books_id);
                    fscanf(fp2, "%s", X[i].book_name);
                    fscanf(fp2, "%s", X[i].author);
                    fscanf(fp2, "%s", X[i].edition);

                }


                fclose(fp2);

                    printf("\n\n\tno of books %d\n", n2);
                  for(int i=0; i<n2; i++)
                    {
                        printf("\n\n\tbooks_id no = %d\n", X[i].books_id);
                        printf("\tBOOK name = %s\n", X[i].book_name);
                        printf("\tAUTHOR's name = %s\n", X[i].author);
                        printf("\tEDITION = %s\n\n", X[i].edition );

                    }
                 }
                 break;
        }

        case 3:
           {

            FILE *fp3;

                fp3= fopen("civil-file.txt","r");

                if(fp3==NULL)
                {
                    printf("\n..ERROR..\n..CAN'T OPEN FILE..\n\n");
                }
                else{

                  fscanf(fp3, "%d", &n3);

                 for(int i=0; i<n3; i++)
                {
                    fscanf(fp3, "%d", &X[i].books_id);
                    fscanf(fp3, "%s", X[i].book_name);
                    fscanf(fp3, "%s", X[i].author);
                    fscanf(fp3, "%s", X[i].edition);

                }


                fclose(fp3);

                    printf("\n\n\tno of books %d\n", n3);
                    printf("\n\t\tCIVIL DEPARTMENT BOOKS\n");
                  for(int i=0; i<n3; i++)
                    {
                        printf("\n\n\tbooks_id no = %d\n", X[i].books_id);
                        printf("\tBOOK name = %s\n", X[i].book_name);
                        printf("\tAUTHOR's name = %s\n", X[i].author);
                        printf("\tEDITION = %s\n\n", X[i].edition );

                    }
                 }
                 break;
        }
        case 4:
              {

            FILE *fp4;

                fp4= fopen("eee-file.txt","r");

                if(fp4==NULL)
                {
                    printf("\n..ERROR..\n..CAN'T OPEN FILE..\n\n");
                }
                else{

                  fscanf(fp4, "%d", &n4);

                 for(int i=0; i<n4; i++)
                {
                    fscanf(fp4, "%d", &X[i].books_id);
                    fscanf(fp4, "%s", X[i].book_name);
                    fscanf(fp4, "%s", X[i].author);
                    fscanf(fp4, "%s", X[i].edition);

                }


                fclose(fp4);

                    printf("\n\n\tno of books %d\n", n4);
                    printf("\n\t\tEEE DEPARTMENT BOOKS\n");
                  for(int i=0; i<n4; i++)
                    {
                        printf("\n\n\tbooks_id no = %d\n", X[i].books_id);
                        printf("\tBOOK name = %s\n", X[i].book_name);
                        printf("\tAUTHOR's name = %s\n", X[i].author);
                        printf("\tEDITION = %s\n\n", X[i].edition );

                    }
                 }
                 break;
        }
        case 5:
             {

            FILE *fp5;

                fp5= fopen("architecture-file.txt","r");

                if(fp5==NULL)
                {
                    printf("\n..ERROR..\n..CAN'T OPEN FILE..\n\n");
                }
                else{

                  fscanf(fp5, "%d", &n5);

                 for(int i=0; i<n5; i++)
                {
                    fscanf(fp5, "%d", &X[i].books_id);
                    fscanf(fp5, "%s", X[i].book_name);
                    fscanf(fp5, "%s", X[i].author);
                    fscanf(fp5, "%s", X[i].edition);

                }


                fclose(fp5);

                    printf("\n\n\tno of books %d\n", n5);
                    printf("\n\t\tARCHITECTURE DEPARTMENT BOOKS\n");
                  for(int i=0; i<n5; i++)
                    {
                        printf("\n\n\tbooks_id no = %d\n", X[i].books_id);
                        printf("\tBOOK name = %s\n", X[i].book_name);
                        printf("\tAUTHOR's name = %s\n", X[i].author);
                        printf("\tEDITION = %s\n\n", X[i].edition );

                    }
                 }
                 break;
        }
        case 6:
             {

            FILE *fp6;

                fp6= fopen("pharmacy-file.txt","r");

                if(fp6==NULL)
                {
                    printf("\n..ERROR..\n..CAN'T OPEN FILE..\n\n");
                }
                else{

                  fscanf(fp6, "%d", &n6);

                 for(int i=0; i<n6; i++)
                {
                    fscanf(fp6, "%d", &X[i].books_id);
                    fscanf(fp6, "%s", X[i].book_name);
                    fscanf(fp6, "%s", X[i].author);
                    fscanf(fp6, "%s", X[i].edition);

                }


                fclose(fp6);

                    printf("\n\n\tno of books %d\n", n6);
                    printf("\n\t\tPHARMACY DEPARTMENT BOOKS\n");
                  for(int i=0; i<n6; i++)
                    {
                        printf("\n\n\tbooks_id no = %d\n", X[i].books_id);
                        printf("\tBOOK name = %s\n", X[i].book_name);
                        printf("\tAUTHOR's name = %s\n", X[i].author);
                        printf("\tEDITION = %s\n\n", X[i].edition );

                    }
                 }
                 break;
        }
        case 7:
            {
                 FILE *fp7;

                fp7= fopen("biochemistry-file.txt","r");

                if(fp7==NULL)
                {
                    printf("\n..ERROR..\n..CAN'T OPEN FILE..\n\n");
                }
                else{

                  fscanf(fp7, "%d", &n7);

                 for(int i=0; i<n7; i++)
                {
                    fscanf(fp7, "%d", &X[i].books_id);
                    fscanf(fp7, "%s", X[i].book_name);
                    fscanf(fp7, "%s", X[i].author);
                    fscanf(fp7, "%s", X[i].edition);

                }


                fclose(fp7);

                    printf("\n\n\tno of books %d\n", n7);
                    printf("\n\t\tBIOCHEMISTRY DEPARTMENT BOOKS\n");
                  for(int i=0; i<n7; i++)
                    {
                        printf("\n\n\tbooks_id no = %d\n", X[i].books_id);
                        printf("\tBOOK name = %s\n", X[i].book_name);
                        printf("\tAUTHOR's name = %s\n", X[i].author);
                        printf("\tEDITION = %s\n\n", X[i].edition );

                    }
                 }
                 break;
            }

                default :
                    {
                        printf(" No Department Chosen Yet");
                    }
    }
     printf("\n\tEnter any key to go main menu: ");
    getch();
	menu();


 }
// end of program
