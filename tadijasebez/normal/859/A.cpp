#include <stdio.h>
int a[100];
int sol=25;
int max(int a, int b){ return a>b?a:b;}
int main()
{
	int i,n;
	scanf("%i",&n);
	for(i=0;i<n;i++) scanf("%i",&a[i]),sol=max(sol,a[i]);
	printf("%i\n",sol-25);
	return 0;
}