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
int a[1001][1001],b[1001][1001];
int main()
{
	int n,m;
	n=read();
	m=read();
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)a[i][j]=read();
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)b[i][j]=read();
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
	{
		if(i!=1)
		{
			if(min(a[i][j],b[i][j])<=min(a[i-1][j],b[i-1][j])||max(a[i][j],b[i][j])<=max(a[i-1][j],b[i-1][j]))
			{
				printf("Impossible\n");
				return 0;
			}
		}
		if(j!=1)
		{
			if(min(a[i][j],b[i][j])<=min(a[i][j-1],b[i][j-1])||max(a[i][j],b[i][j])<=max(a[i][j-1],b[i][j-1]))
			{
				printf("Impossible\n");
				return 0;
			}
		}
	}
	printf("Possible\n");
	return 0;
}