#include <stdio.h>

int min(int a, int b){ return a>b?b:a;}
int max(int a, int b){ return a>b?a:b;}

int main()
{
	int n,d;
	scanf("%i",&n);
	d=n%10;
	if(d<=5) printf("%i\n",(n/10)*10);
	else printf("%i\n",(n/10+1)*10);
	return 0;
}