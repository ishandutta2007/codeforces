#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500005;
struct qu
{
	int l,r,k;
	qu(){}
	qu(int _l,int _r,int _k):l(_l),r(_r),k(_k){}
};
vector<pair<int,int>>e[N];
vector<qu>a[N];
int ans[N],n,q,tr[N<<2],tag[N<<2],ar[N],ed[N];
void pushdown(int k)
{
	tr[k<<1]+=tag[k];
	tag[k<<1]+=tag[k];
	tr[k<<1|1]+=tag[k];
	tag[k<<1|1]+=tag[k];
	tag[k]=0;
}
void build(int k,int l,int r)
{
	if(l==r)
	{
		tr[k]=ar[l];
		return;
	}
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	tr[k]=min(tr[k<<1],tr[k<<1|1]);
}
void update(int k,int l,int r,int a,int b,int v)
{
	if(l==a&&r==b)
	{
		tr[k]+=v;
		tag[k]+=v;
		return;
	}
	pushdown(k);
	int mid=l+r>>1;
	if(b<=mid) update(k<<1,l,mid,a,b,v);
	else if(a>mid) update(k<<1|1,mid+1,r,a,b,v);
	else update(k<<1,l,mid,a,mid,v),update(k<<1|1,mid+1,r,mid+1,b,v);
	tr[k]=min(tr[k<<1],tr[k<<1|1]);
}
int query(int k,int l,int r,int a,int b)
{
	if(l==a&&r==b)
		return tr[k];
	pushdown(k);
	int mid=l+r>>1;
	if(b<=mid) return query(k<<1,l,mid,a,b);
	else if(a>mid) return query(k<<1|1,mid+1,r,a,b);
	else return min(query(k<<1,l,mid,a,mid),query(k<<1|1,mid+1,r,mid+1,b));
}
void calc(int u,int d)
{
	for(int i=0;i<e[u].size();i++)
	{
		int v=e[u][i].first,w=e[u][i].second;
		calc(v,d+w);
		if(i==e[u].size()-1)
			ed[u]=ed[v];
	}
	if(!e[u].size())
		ar[u]=d,ed[u]=u;
}
void dfs(int u)
{
	for(auto i:a[u])
		ans[i.k]=query(1,1,n,i.l,i.r);
	for(auto i:e[u])
	{
		int v=i.first,w=i.second;
		update(1,1,n,1,n,w);
		update(1,1,n,v,ed[v],-w-w);
		dfs(v);
		update(1,1,n,1,n,-w);
		update(1,1,n,v,ed[v],+w+w);
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>q;
	for(int i=2;i<=n;i++)
	{
		int x,w;
		cin>>x>>w;
		e[x].emplace_back(i,w);
	}
	for(int i=1;i<=q;i++)
	{
		int u,l,r;
		cin>>u>>l>>r;
		a[u].emplace_back(qu(l,r,i));
	}
	for(int i=1;i<=n;i++)
		ar[i]=1e18;
	calc(1,0);
	build(1,1,n);
	dfs(1);
	for(int i=1;i<=q;i++)
		cout<<ans[i]<<endl;
	return 0;
}