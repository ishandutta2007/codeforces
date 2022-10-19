#include<iostream>
#include<cstdio>
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
int qa[200005],qb[200005];
int vis[200005];
struct bbian
{
	int u,v,nex;
}a[800004];
int head[200005],tmp;
void addb(int x,int y)
{
	a[++tmp].u=x;
	a[tmp].v=y;
	a[tmp].nex=head[x];
	head[x]=tmp;
}
int c[10];
bool dfs(int x,int k)
{
	vis[x]=k;
	c[k]+=qb[x]-qa[x];
	bool flag=true;
	for(int i=head[x];i;i=a[i].nex)
	{
		if(vis[a[i].v]==vis[x])flag=false;
		if(!vis[a[i].v]&&!dfs(a[i].v,3-k))flag=false;
	}
	return flag;
}
signed main()
{
	int t,n,m,x,y;
	bool flag,tflag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		m=read();
		for(int i=1;i<=n;i++)
		{
			vis[i]=0;
			head[i]=0;
		}
		tmp=0;
		for(int i=1;i<=n;i++)qa[i]=read(); 
		for(int i=1;i<=n;i++)qb[i]=read();
		for(int i=1;i<=m;i++)
		{
			x=read();
			y=read();
			addb(x,y);
			addb(y,x);
		}
		tflag=false;
		for(int i=1;i<=n;i++)
		{
			if(!vis[i])
			{
				c[1]=c[2]=0;
				flag=dfs(i,1);
				if((flag)&&(c[1]!=c[2]))
				{
					tflag=true;
					break; 
				} 
				if((flag==false)&&((c[1]+c[2])%2!=0))
				{
					tflag=true;
					break;
				}
			}
		}
		if(tflag==true)printf("NO\n");
		else printf("YES\n");
	}
}