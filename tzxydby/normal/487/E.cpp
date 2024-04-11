#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m,q,w[N],dfn[N],low[N],st[N],tp,k,cnt,fa[N],dep[N],son[N],sz[N],top[N],ar[N],tr[N<<2];
vector<int>g[N],e[N];
multiset<int>s[N];
void tarjan(int u)
{
	dfn[u]=low[u]=++cnt;
	st[++tp]=u;
	for(auto v:g[u])
	{
		if(!dfn[v])
		{
			tarjan(v);
			low[u]=min(low[u],low[v]);
			if(low[v]==dfn[u])
			{
				k++;
				for(int x=0;x!=v;tp--)
				{
					x=st[tp];
					e[k].push_back(x);
					e[x].push_back(k);
				}
				e[k].push_back(u);
				e[u].push_back(k);
			}
		}
		else
			low[u]=min(low[u],dfn[v]);
	}
}
void dfs(int u,int f)
{
	fa[u]=f,dep[u]=dep[f]+1,sz[u]=1;
	for(auto v:e[u])
	{
		if(v==f)
			continue;
		dfs(v,u);
		sz[u]+=sz[v];
		if(sz[son[u]]<sz[v])
			son[u]=v;
	}
}
void dfs2(int u,int f,int tp)
{
	dfn[u]=++cnt,top[u]=tp,ar[cnt]=u;
	if(son[u])
		dfs2(son[u],u,tp);
	for(auto v:e[u])
	{
		if(v==f||v==son[u])
			continue;
		dfs2(v,u,v);
	}
}
void build(int k,int l,int r)
{
	if(l==r)
	{
		tr[k]=w[ar[l]];
		return;
	}
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	tr[k]=min(tr[k<<1],tr[k<<1|1]);
}
void upd(int k,int l,int r,int x,int v)
{
	if(l==r)
	{
		tr[k]=v;
		return;
	}
	int mid=l+r>>1;
	if(x<=mid) upd(k<<1,l,mid,x,v);
	else upd(k<<1|1,mid+1,r,x,v);
	tr[k]=min(tr[k<<1],tr[k<<1|1]);
}
int query(int k,int l,int r,int a,int b)
{
	if(l==a&&r==b)
		return tr[k];
	int mid=l+r>>1;
	if(b<=mid) return query(k<<1,l,mid,a,b);
	else if(a>mid) return query(k<<1|1,mid+1,r,a,b);
	else return min(query(k<<1,l,mid,a,mid),query(k<<1|1,mid+1,r,mid+1,b));
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
		cin>>w[i];
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	k=n;
	tarjan(1);
	dfs(1,0);
	cnt=0;
	dfs2(1,0,1);
	for(int i=1;i<=n;i++)
		if(fa[i])
			s[fa[i]].insert(w[i]);
	for(int i=n+1;i<=k;i++)
		w[i]=*s[i].begin();
	build(1,1,k);
	while(q--)
	{
		char op;
		int x,y;
		cin>>op>>x>>y;
		if(op=='C')
		{
			upd(1,1,k,dfn[x],y);
			if(fa[x])
			{
				int u=fa[x];
				s[u].erase(s[u].lower_bound(w[x]));
				s[u].insert(y);
				w[u]=*s[u].begin();
				upd(1,1,k,dfn[u],w[u]);
			}
			w[x]=y;
		}
		else
		{
			int ans=1e9;
			while(top[x]!=top[y])
			{
				if(dep[top[x]]<dep[top[y]])
					swap(x,y);
				ans=min(ans,query(1,1,k,dfn[top[x]],dfn[x]));
				x=fa[top[x]];
			}
			if(dfn[x]>dfn[y])
				swap(x,y);
			ans=min(ans,query(1,1,k,dfn[x],dfn[y]));
			if(x>n)
				ans=min(ans,w[fa[x]]);
			printf("%d\n",ans);
		}
	}
	return 0;
}