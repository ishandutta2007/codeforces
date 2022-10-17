#include<stdio.h>
#include<iostream>
using namespace std;
int n,a[4020];
int f[4020][4020];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	int z=1;
	for(int i=1;i<=n;i++)
	{
		int p=0;
		for(int j=1;j<i;j++)
		{
			f[i][j]=2;
			if(p)
				f[i][j]=max(f[i][j],f[j][p]+1);
			z=max(z,f[i][j]);
			if(a[j]==a[i])
				p=j;
		}
	}
	printf("%d",z);
	return 0;
}