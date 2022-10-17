#include<stdio.h>
int a,b,c,d,n,z;
int main()
{
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&n);
	for(int i=1;i<=n;i++)
		if(i%a&&i%b&&i%c&&i%d)
			z++;
	printf("%d\n",n-z);
}