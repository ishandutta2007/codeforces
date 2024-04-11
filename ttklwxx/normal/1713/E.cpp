#include<iostream>
#include<cstdio>
#include<cmath>
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
int fa[10005];
int findf(int n)
{
	if(fa[n]==n)return n;
	return fa[n]=findf(fa[n]);
}
int main()
{
	int t,n,x,y;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				a[i][j]=read();
			}
		}
		for(int i=1;i<=2*n;i++)fa[i]=i;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(a[i][j]<a[j][i])
				{
					if(findf(i)!=findf(j+n))
					{
						x=findf(i);
						y=findf(j);
						if(x!=y)fa[x]=y;
						x=findf(i+n);
						y=findf(j+n);
						if(x!=y)fa[x]=y;
					}
				}
				if(a[i][j]>a[j][i])
				{
					if(findf(i)!=findf(j))
					{
						x=findf(i);
						y=findf(j+n);
						if(x!=y)fa[x]=y;
						x=findf(i+n);
						y=findf(j);
						if(x!=y)fa[x]=y;
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(findf(i)!=findf(j))printf("%d ",a[j][i]);
				else printf("%d ",a[i][j]);
			}
			printf("\n");
		}
	}
}