#include <stdio.h>
int max(int a, int b)
{
	if(a>b) return a;
	else return b;
}
int main()
{
	int n,i,tmp,sol=0;
	tmp=0;
	scanf("%i",&n);
	char c;
	//printf("%i %i\n",'A','Z');
	//for(i='A';i<='Z';i++) printf("%c",i);
	for(i=0;i<=n;i++)
	{
		scanf("%c",&c);
		if(c>='A' && c<='Z') tmp++;//,printf("%c\n",c);
		else if(c==' ') tmp=0;
		sol=max(sol,tmp);
	}
	/*if(c>='A' && c<='Z') tmp++,printf("%c\n",c);
	else if(c==' ') tmp=0;
	sol=max(sol,tmp);*/
	printf("%i\n",sol);
	return 0;
}