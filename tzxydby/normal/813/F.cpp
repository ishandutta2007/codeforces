#include<bits/stdc++.h>
using namespace std;
const int N=2000005;
int n,m,x[N],y[N],a[N],ok=1,p[N],q[N],f[N],sz[N],t;
vector<int>e[N],g[N];
map<pair<int,int>,int>mp;
void update(int k,int l,int r,int a,int b,int v)
{
	if(l==a&&r==b)
	{
		e[k].emplace_back(v);
		return;
	}
	int mid=l+r>>1;
	if(b<=mid) update(k<<1,l,mid,a,b,v);
	else if(a>mid) update(k<<1|1,mid+1,r,a,b,v);
	else update(k<<1,l,mid,a,mid,v),update(k<<1|1,mid+1,r,mid+1,b,v);
}
int fa(int u){return u==f[u]?u:fa(f[u]);}
void merge(int u,int v)
{
	t++;
	p[t]=u,q[t]=v;
	g[u].push_back(v);
	sz[u]+=sz[v];
	f[v]=u;
}
void rev(int u)
{
	a[u]^=1;
	for(auto v:g[u])
		rev(v);
}
void undo(int d)
{
	while(t!=d)
	{
		int u=p[t],v=q[t];
		g[u].pop_back();
		sz[u]-=sz[v];
		f[v]=v;
		t--;
	}
}
void dfs(int k,int l,int r)
{
	int d=t,dk=ok;
	if(ok)
	{
		for(auto i:e[k])
		{
			int u=x[i],v=y[i];
			int fu=fa(u),fv=fa(v);
			if(fu==fv)
			{
				if(a[u]==a[v])
					ok=0;
			}
			else
			{
				if(sz[fu]<sz[fv])
				{
					swap(u,v);
					swap(fu,fv);
				}
				if(a[u]==a[v])
					rev(fv);
				merge(fu,fv);
			}
		}
	}
	if(l==r)
	{
		puts(ok?"YES":"NO");
		undo(d);
		ok=dk;
		return;
	}
	int mid=l+r>>1;
	dfs(k<<1,l,mid);
	dfs(k<<1|1,mid+1,r);
	undo(d);
	ok=dk;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		if(mp.find(make_pair(x[i],y[i]))==mp.end()||mp[make_pair(x[i],y[i])]==0)
			mp[make_pair(x[i],y[i])]=i;
		else
		{
			update(1,1,m,mp[make_pair(x[i],y[i])],i-1,i);
			mp[make_pair(x[i],y[i])]=0;
		}
	}
	for(auto i:mp)
		if(i.second)
			update(1,1,m,i.second,m,i.second);
	for(int i=1;i<=n;i++)
		f[i]=i;
	dfs(1,1,m);
	return 0;
}