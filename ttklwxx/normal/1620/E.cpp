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
int las[2000005];
int dy[2000005],cd;
int fa[2000005],cnt,dx[2000005];
int findf(int n)
{
	if(fa[n]==n)return n;
	return fa[n]=findf(fa[n]);
}
int main()
{
	int q,op,x,y;
	q=read();
	for(int i=1;i<=q;i++)
	{
		op=read();
		if(op==1)
		{
			x=read();
			if(las[x]==0)
			{
				++cd;
				dy[cd]=++cnt;
				las[x]=cnt;
				fa[cnt]=cnt;
				dx[cnt]=x;
			}
			else
			{
				++cd;
				dy[cd]=las[x];
			}
		}
		else
		{
			x=read();
			y=read();
			if(las[x]==0)continue;
			if(x==y)continue;
			if(las[y]==0)
			{
				++cnt;
				fa[cnt]=cnt;
				dx[cnt]=y;
				las[y]=cnt;
			}
			fa[las[x]]=las[y];
			las[x]=0;
		}
	}
	for(int i=1;i<=cd;i++)
	{
		printf("%d ",dx[findf(dy[i])]);
	}
	return 0;
}