#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m,s[N],t[N],cnt,tr[N<<5],sz[N<<5],rt[N]={1},lc[N<<5],rc[N<<5],w=1,ans[N],tag[N<<5];
vector<int>e[N],q[N];
void dfs1(int u,int f)
{
	s[u]=++cnt;
	for(int i=0;i<e[u].size();i++)
		if(e[u][i]!=f)
			dfs1(e[u][i],u);
	t[u]=cnt;
}
void pushdown(int k)
{
	if(tr[k]==sz[k])
	{
		if(tr[lc[k]]!=sz[lc[k]])
		{
			w++;
			tr[w]=sz[lc[k]],sz[w]=sz[lc[k]],lc[w]=lc[lc[k]],rc[w]=rc[lc[k]];
			lc[k]=w;
		}
		if(tr[rc[k]]!=sz[rc[k]])
		{
			w++;
			tr[w]=sz[rc[k]],sz[w]=sz[rc[k]],lc[w]=lc[rc[k]],rc[w]=rc[rc[k]];
			rc[k]=w;
		}
	}
}
void build(int k,int l,int r)
{
	sz[k]=r-l+1;
	if(l==r)
		return;
	int mid=l+r>>1;
	lc[k]=++w,rc[k]=++w;
	build(lc[k],l,mid);
	build(rc[k],mid+1,r);
}
int update(int k,int l,int r,int a,int b)
{
	int nk=++w;
	tr[nk]=tr[k],sz[nk]=sz[k],lc[nk]=lc[k],rc[nk]=rc[k];
	if(l==a&&r==b)
	{
		tr[nk]=sz[nk];
		return nk;
	}
	pushdown(nk);
	int mid=l+r>>1;
	if(b<=mid) lc[nk]=update(lc[nk],l,mid,a,b);
	else if(a>mid) rc[nk]=update(rc[nk],mid+1,r,a,b);
	else lc[nk]=update(lc[nk],l,mid,a,mid),rc[nk]=update(rc[nk],mid+1,r,mid+1,b);
	tr[nk]=tr[lc[nk]]+tr[rc[nk]];
	return nk;
}
void dfs2(int u,int f)
{
	rt[u]=rt[f];
	for(int i=0;i<q[u].size();i++)
	{
		int v=q[u][i];
		rt[u]=update(rt[u],1,n,s[v],t[v]);
	}
	if(q[u].size())
		rt[u]=update(rt[u],1,n,s[u],t[u]);
	ans[u]=tr[rt[u]]-1;
	int las=w;
	for(int i=0;i<e[u].size();i++)
	{
		int v=e[u][i];
		if(v==f)
			continue;
		dfs2(v,u);
	}
	w=las;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		q[u].push_back(v);
		q[v].push_back(u);
	}
	dfs1(1,0);
	build(1,1,n);
	dfs2(1,0);
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]==-1?0:ans[i]);
	return 0;
}