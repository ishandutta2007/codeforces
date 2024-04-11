#include<iostream>
#include<cstdio>
#include<cstring>
#define int long long
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
int a[1005][1005];
int c[1005][1005];
signed main()
{
	int t,n,ans=0;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)a[i][j]=read();
		}
		for(int i=1;i<=n;i++)c[1][i]=0;
		for(int i=2;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				c[i][j]=1^c[i-1][j+1]^c[i-1][j-1]^c[i-2][j];
				//printf("%d",c[i][j]);
			}
			//printf("\n");
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(c[i-1][j]^c[i+1][j]^c[i][j-1]^c[i][j+1]!=1)
				{
					printf("no\n");
					return -1;
				}
			}
		}
		ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)if(c[i][j]==1)ans^=a[i][j];
		}
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)c[i][j]=0;
		printf("%d\n",ans);
	}
	return 0;
}