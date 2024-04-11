#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=200005,M=5000005,inf=210000;
struct seg
{
	int k,b;
	seg(){}
	seg(int _k,int _b):k(_k),b(_b){}
	int val(int x)
	{
		x-=100001;
		return k*x+b;
	}
}tr[M];
int n,c,a[N],b[N],rt[M],lc[M],rc[M],dp[N];
vector<seg>p[N];
vector<int>e[N];
void update(int &k,int l,int r,seg v)
{
	if(!k)
	{
		k=++c;
		tr[k]=v;
		return;
	}
	int mid=l+r>>1,f1=tr[k].val(l)>v.val(l),f2=tr[k].val(mid)>v.val(mid);
	if(f2)
		swap(tr[k],v);
	if(l==r)
		return;
	if(f1!=f2) update(lc[k],l,mid,v);
	else update(rc[k],mid+1,r,v);
}
int query(int k,int l,int r,int x)
{
	if(!k) return 1e18;
	if(l==r)
		return tr[k].val(x);
	int mid=l+r>>1;
	if(x<=mid) return min(tr[k].val(x),query(lc[k],l,mid,x));
	else return min(tr[k].val(x),query(rc[k],mid+1,r,x));
}
void merge(int u,int v)
{
	if(p[u].size()<p[v].size())
	{
		p[u].swap(p[v]);
		swap(rt[u],rt[v]);
	}
	for(auto i:p[v])
		update(rt[u],1,inf,i),p[u].push_back(i);
}
void dfs(int u,int f)
{
	if(f&&e[u].size()==1)
	{
		update(rt[u],1,inf,seg(b[u],dp[u]));
		p[u].push_back(seg(b[u],dp[u]));
		return;
	}
	for(auto v:e[u])
	{
		if(v==f)
			continue;
		dfs(v,u);
		merge(u,v);
	}
	dp[u]=query(rt[u],1,inf,a[u]+100001);
	update(rt[u],1,inf,seg(b[u],dp[u]));
	p[u].push_back(seg(b[u],dp[u]));
}
signed main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)
		cout<<dp[i]<<' ';
	return 0;
}