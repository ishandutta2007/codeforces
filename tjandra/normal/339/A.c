#include<stdio.h>
int main()
{
	unsigned sa=0,du=0,ti=0,plus=0;
	char c;
	while((c=getchar())>0){if(c=='1')sa++;if(c=='2')du++;if(c=='3')ti++;}
	while(sa--)
	{
		plus?putchar('+'):(plus=1);
		putchar('1');
	}
	while(du--)
	{
		plus?putchar('+'):(plus=1);
		putchar('2');
	}
	while(ti--)
	{
		plus?putchar('+'):(plus=1);
		putchar('3');
	}
	putchar('\n');
	return 0;
}