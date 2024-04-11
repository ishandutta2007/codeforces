#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,m,x[N],y[N],z[N],dis[N],r1,r2;
vector<pair<int,int>>e[N];
void dfs(int u,int f)
{
	dis[u]=dis[f]+1;
	for(auto i:e[u])
	{
		int v=i.first;
		if(v==f)
			continue;
		dfs(v,u);
	}
}
struct graph
{
	int r,c,a[N],b[N],d[N],s[N],t[N],tr[N<<2][2],tag[N<<2];
	void dfs(int u,int f,int x)
	{
		d[u]=d[f]+1,s[u]=++c,a[s[u]]=x,b[s[u]]=d[u]-1;
		for(auto i:e[u])
		{
			int v=i.first,w=i.second;
			if(v==f)
				continue;
			dfs(v,u,x^w);
		}
		t[u]=c;
	}
	void pushup(int k)
	{
		tr[k][0]=max(tr[k<<1][0],tr[k<<1|1][0]);
		tr[k][1]=max(tr[k<<1][1],tr[k<<1|1][1]);
	}
	void pushdown(int k)
	{
		if(tag[k])
		{
			swap(tr[k<<1][0],tr[k<<1][1]);
			tag[k<<1]^=1;
			swap(tr[k<<1|1][0],tr[k<<1|1][1]);
			tag[k<<1|1]^=1;
			tag[k]=0;
		}
	}
	void build(int k,int l,int r)
	{
		if(l==r)
		{
			tr[k][a[l]]=b[l];
			return;
		}
		int mid=l+r>>1;
		build(k<<1,l,mid);
		build(k<<1|1,mid+1,r);
		pushup(k);
	}
	void update(int k,int l,int r,int a,int b)
	{
		if(l==a&&r==b)
		{
			swap(tr[k][0],tr[k][1]);
			tag[k]^=1;
			return;
		}
		pushdown(k);
		int mid=l+r>>1;
		if(b<=mid) update(k<<1,l,mid,a,b);
		else if(a>mid) update(k<<1|1,mid+1,r,a,b);
		else update(k<<1,l,mid,a,mid),update(k<<1|1,mid+1,r,mid+1,b);
		pushup(k);
	}
	void init()
	{
		dfs(r,0,0);
		build(1,1,n);
	}
	int rev(int k)
	{
		int u=x[k],v=y[k];
		if(d[u]<d[v])
			swap(u,v);
		update(1,1,n,s[u],t[u]);
		return tr[1][0];
	}
}g1,g2;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d%d",&x[i],&y[i],&z[i]);
		e[x[i]].emplace_back(y[i],z[i]);
		e[y[i]].emplace_back(x[i],z[i]);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)
		if(dis[i]>dis[r1])
			r1=i;
	dfs(r1,0);
	for(int i=1;i<=n;i++)
		if(dis[i]>dis[r2])
			r2=i;
	g1.r=r1,g2.r=r2;
	g1.init(),g2.init();
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int k;
		scanf("%d",&k);
		int ans=max(g1.rev(k),g2.rev(k));
		printf("%d\n",ans);
	}
	return 0;
}