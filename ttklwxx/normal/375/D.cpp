#include<iostream>
#include<cstdio>
#include<vector>
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
vector<int>v[200005];
int qk[200005],qans[200005];
int c[200005];
int sl[200005],sum[200005];
int siz[200005],son[200005];
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
void dfs1(int x,int f)
{
	siz[x]=1;
	int maxn=-1;
	for(int i=head[x];i;i=a[i].nex)
	{
		if(a[i].v==f)continue;
		dfs1(a[i].v,x);
		siz[x]+=siz[a[i].v];
		if(siz[a[i].v]>maxn)
		{
			maxn=siz[a[i].v];
			son[x]=a[i].v;
		}
	}
}
void add(int x,int f)
{
	sl[c[x]]++;
	sum[sl[c[x]]]++;
	for(int i=head[x];i;i=a[i].nex)
	{
		if(a[i].v==f)continue;
		add(a[i].v,x);
	}
}
void del(int x,int f)
{
	sum[sl[c[x]]]--;
	sl[c[x]]--;
	for(int i=head[x];i;i=a[i].nex)
	{
		if(a[i].v==f)continue;
		del(a[i].v,x);
	}
}
void dsu(int x,int f)
{
	for(int i=head[x];i;i=a[i].nex)
	{
		if(a[i].v==son[x]||a[i].v==f)continue;
		dsu(a[i].v,x);
		del(a[i].v,x);
	}
	if(son[x]!=0)dsu(son[x],x);
	sl[c[x]]++;
	sum[sl[c[x]]]++;
	for(int i=head[x];i;i=a[i].nex)
	{
		if(a[i].v==son[x]||a[i].v==f)continue;
		add(a[i].v,x);
	}
	for(int i=0;i<v[x].size();i++)
	{
		qans[v[x][i]]=sum[qk[v[x][i]]];
	}
}
int main()
{
	int n,m,x,y;
	n=read();
	m=read();
	for(int i=1;i<=n;i++)c[i]=read();
	for(int i=1;i<=n-1;i++)
	{
		x=read();
		y=read();
		addb(x,y);
		addb(y,x);
	}
	for(int i=1;i<=m;i++)
	{
		x=read();
		y=read();
		qk[i]=y;
		v[x].push_back(i);
	}
	dfs1(1,0);
	dsu(1,0);
	for(int i=1;i<=m;i++)printf("%d\n",qans[i]);
	return 0;
}