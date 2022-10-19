#include<iostream>
#include<cstdio>
#include<cstring>
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
int fa[400005];
int findf(int n)
{
	if(fa[n]==n)return n;
	return fa[n]=findf(fa[n]);
}
struct bbian
{
	int u,v,w,nex;
}a[800004];
int head[200005],tmp;
int yh[200005],jo[400005];
bool vis[400005];
void addb(int x,int y,int z)
{
	a[++tmp].u=x;
	a[tmp].v=y;
	a[tmp].w=z;
	a[tmp].nex=head[x];
	head[x]=tmp;
}
void dfs(int x,int f)
{
	for(int i=head[x];i;i=a[i].nex)
	{
		if(a[i].v==f)continue;
		if(a[i].w!=-1)
		{
			yh[a[i].v]=(yh[x]^a[i].w);
		}
		else
		{
			if(jo[a[i].v]==jo[x])yh[a[i].v]=yh[x];
			else yh[a[i].v]=(yh[x]^1);
		}
		dfs(a[i].v,x);
	}
}
int tu[200005],tv[200005];
int main()
{
	int t,n,m,x,y,v,tx,ty;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		m=read();
		for(int i=1;i<=2*n;i++)fa[i]=i,vis[i]=false;
		for(int i=1;i<=n;i++)head[i]=0,jo[i]=0;
		tmp=0;
		flag=true;
		for(int i=1;i<=n-1;i++)
		{
			x=read();
			y=read();
			v=read();
			tu[i]=x;
			tv[i]=y;
			addb(x,y,v);
			addb(y,x,v);
			if(v==-1)continue;
			if(__builtin_popcount(v)%2==0)
			{
				tx=findf(x);
				ty=findf(y);
				if(tx!=ty)fa[tx]=ty;
				tx=findf(x+n);
				ty=findf(y+n);
				if(tx!=ty)fa[tx]=ty;
			}
			else
			{
				tx=findf(x);
				ty=findf(y+n);
				if(tx!=ty)fa[tx]=ty;
				tx=findf(x+n);
				ty=findf(y);
				if(tx!=ty)fa[tx]=ty;
			}
		}
		for(int i=1;i<=m;i++)
		{
			x=read();
			y=read();
			v=read();
			if(v==0)
			{
				tx=findf(x);
				ty=findf(y);
				if(tx!=ty)fa[tx]=ty;
				tx=findf(x+n);
				ty=findf(y+n);
				if(tx!=ty)fa[tx]=ty;
			}
			else
			{
				tx=findf(x);
				ty=findf(y+n);
				if(tx!=ty)fa[tx]=ty;
				tx=findf(x+n);
				ty=findf(y);
				if(tx!=ty)fa[tx]=ty;
			}
		}
		for(int i=1;i<=n;i++)
		{
			tx=findf(i);
			ty=findf(i+n);
			if(tx==ty)
			{
				flag=false;
				break;
			}
			if(vis[ty])
			{
				jo[i]=1;
			}
			else
			{
				jo[i]=0;
				vis[tx]=true;
			}
			//printf("%d\n",jo[i]);
		}
		if(flag==false)
		{
			printf("NO\n");
			continue;
		}
		dfs(1,0);
		printf("YES\n");
		for(int i=1;i<=n-1;i++)
		{
			printf("%d %d %d\n",tu[i],tv[i],yh[tu[i]]^yh[tv[i]]);
		}
	}
	return 0;
}