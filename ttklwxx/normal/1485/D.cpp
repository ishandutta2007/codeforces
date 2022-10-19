#include<iostream>
#include<cstdio>
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
int a[501][501];
int main()
{
	int n,m;
	n=read();
	m=read();
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)a[i][j]=read();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if((i+j)%2==0)printf("%d ",720720);
			else printf("%d ",720720+a[i][j]*a[i][j]*a[i][j]*a[i][j]);
		}
		printf("\n");
	}
	return 0;
}