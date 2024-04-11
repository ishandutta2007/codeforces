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
int fa[400005],siz1[400005],siz2[400005];
bool vis[400005];
int findf(int n)
{
	if(fa[n]==n)return n;
	return fa[n]=findf(fa[n]);
}
char str[105];
int main()
{
	int t,n,m,x,y,tx,ty,ans=0;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		m=read();
		for(int i=1;i<=n;i++)
		{
			vis[i]=false;
			fa[i]=i;
			siz1[i]=1;
			siz2[i]=0;
		}
		for(int i=n+1;i<=2*n;i++)
		{
			vis[i]=false;
			fa[i]=i;
			siz1[i]=0;
			siz2[i]=1;
		}
		for(int i=1;i<=m;i++)
		{
			x=read();
			y=read();
			scanf("%s",str+1);
			if(str[1]=='i')
			{
				tx=findf(x);
				ty=findf(y+n);
				if(tx!=ty)
				{
					fa[tx]=ty;
					siz1[ty]+=siz1[tx];
					siz2[ty]+=siz2[tx];
					siz1[tx]=siz2[tx]=0;
				}
				tx=findf(x+n);
				ty=findf(y);
				if(tx!=ty)
				{
					fa[tx]=ty;
					siz1[ty]+=siz1[tx];
					siz2[ty]+=siz2[tx];
					siz1[tx]=siz2[tx]=0;
				}
			}
			else
			{
				tx=findf(x);
				ty=findf(y);
				if(tx!=ty)
				{
					fa[tx]=ty;
					siz1[ty]+=siz1[tx];
					siz2[ty]+=siz2[tx];
					siz1[tx]=siz2[tx]=0;
				}
				tx=findf(x+n);
				ty=findf(y+n);
				if(tx!=ty)
				{
					fa[tx]=ty;
					siz1[ty]+=siz1[tx];
					siz2[ty]+=siz2[tx];
					siz1[tx]=siz2[tx]=0;
				}
			}
		}
		flag=false;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			tx=findf(i);
			ty=findf(i+n);
			if(tx==ty)
			{
				flag=true;
				break;
			}
			if(vis[tx]==true||vis[ty]==true)continue;
			vis[tx]=vis[ty]=true;
			ans+=max(siz1[tx],siz2[tx]);
		}
		if(flag==false)printf("%d\n",ans);
		else printf("-1\n");
	}
	return 0;
}