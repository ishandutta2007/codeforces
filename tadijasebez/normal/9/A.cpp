#include <stdio.h>
int main()
{
int a,b;
scanf("%i%i",&a,&b);
if(a<b) a=b;
b=7-a;
if(b==1) printf("1/6");
if(b==2) printf("1/3");
if(b==3) printf("1/2");
if(b==4) printf("2/3");
if(b==5) printf("5/6");
if(b==6) printf("1/1");
return 0;
}