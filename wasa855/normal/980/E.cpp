#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	char ch=getchar();
	while(!isdigit(ch))
	{
		ch=getchar();
	}
	int ans=0;
	while(isdigit(ch))
	{
		ans=ans*10+ch-48;
		ch=getchar();
	}
	return ans;
}
int lowbit(int x)
{
	return x&(-x);
}
struct Edge
{
	int to;
	int nxt;
};
Edge edge[2000005];
int ss;
int fir[1000005];
int dep[1000005];
int siz[1000005];
int f[1000005];
int dfn[1000005];
int n,k,now;
int cnt;
bool ok[1000005];
struct Bitree
{
	int a[1000005];
	void add(int u,int dat)
	{
		while(u<=n)
		{
			a[u]+=dat;
			u+=lowbit(u);
		}
	}
	int query(int u)
	{
		int ans=0;
		while(u)
		{
			ans+=a[u];
			u-=lowbit(u);
		}
		return ans;
	}
};
Bitree b;
void add(int u,int v)
{
	ss++;
	edge[ss].to=v;
	edge[ss].nxt=fir[u];
	fir[u]=ss;
	ss++;
	edge[ss].to=u;
	edge[ss].nxt=fir[v];
	fir[v]=ss;
}
void dfs(int u,int fa)
{
	f[u]=fa;
	dfn[u]=++cnt;
	dep[u]=dep[fa]+1;
	siz[u]=1;
	for(int i=fir[u];i!=0;i=edge[i].nxt)
	{
		int to=edge[i].to;
		if(to!=fa)
		{
			dfs(to,u);
			siz[u]+=siz[to];
		}
	}
}
void work(int u)
{
	if(dep[u]-b.query(dfn[u])+now>k)
	{
		return ;
	}
	while(u!=n)
	{
		if(ok[u])
		{
			break;
		}
		ok[u]=true;
		b.add(dfn[u],1);
		b.add(dfn[u]+siz[u],-1);
		u=f[u];
		now++;
	}
}
int main()
{
	cin>>n>>k;
	k=n-k;
	int u,v;
	for(int i=1;i<n;i++)
	{
		u=read();
		v=read();
		add(u,v);
	}
	ok[n]=true;
	dfs(n,0);
//	cout<<"ZHI\n";
	for(int i=n-1;i>=1;i--)
	{
//		cout<<i<<endl;
		if(ok[i]==false)
		{
			work(i);
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(ok[i]==false)
		{
			printf("%d ",i);
		}
	}
	cout<<"\n";
	return 0;
}