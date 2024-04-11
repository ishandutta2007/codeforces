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
	int t,n,m,l,h,sth;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		m=read();
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
		{
			a[i][j]=read();
			if(a[i][j]==1)h=j;
		}
		for(int j=1;j<=m;j++)for(int i=1;i<=n;i++)
		{
			b[j][i]=read();
			if(b[j][i]==1)l=j;
		}
		for(int i=1;i<=n;i++)
		{
			sth=0;
			for(int j=1;j<=n;j++)
			{
				if(a[j][h]==b[l][i])
				{
					sth=j;
					break;
				}
			}
			for(int j=1;j<=m;j++)printf("%d ",a[sth][j]);
			printf("\n");
		}
	} 
	return 0;
}