#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int n;
char a[10];

int main()
{int i,j;
 
 scanf("%d",&n);
 scanf("%s",a+1);
 if(n==24)
 {	if(a[1]=='2')
 	{	if(a[2]>='4')
 			a[2]='3';
 	}
 	else if(a[1]>'2')
 		a[1]='0';
 }
 else
 {	if(a[1]=='0')
 	{	if(a[2]=='0')
	 		a[2]='1';
	}
	else if(a[1]=='1')
	{	if(a[2]>'2')
			a[2]='2';
	}
	else if(a[1]>'1')
	{	if(a[2]=='0')
			a[1]='1';
		else
			a[1]='0';
	}
 }
 if(a[4]>'5') a[4]='5';
 for(i=1;i<=5;i++)
 	printf("%c",a[i]);
 printf("\n");
 return 0;
}