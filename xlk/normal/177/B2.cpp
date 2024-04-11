#include<stdio.h>
int n,z;
int main()
{
	scanf("%d",&n);
	z=n;
	for(int i=2;i*i<=n;i++)
		while(n%i==0)
			n/=i,z+=n;
	z+=n>1;
	printf("%d\n",z);
	return 0;
}