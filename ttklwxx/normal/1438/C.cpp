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
int a[1001][1001];
signed main()
{
	int t,n,m;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		m=read();
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)a[i][j]=read();
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
		{
			if((i+j)%2==0)
			{
				if(a[i][j]%2==1)a[i][j]++;
			}
			else
			{
				if(a[i][j]%2==0)a[i][j]++;
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)printf("%d ",a[i][j]);
			printf("\n");
		}
	} 
	return 0;
}