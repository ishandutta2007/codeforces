#include<bits/stdc++.h>
using namespace std;
const int N=100005;
vector<pair<int,int>>e[N];
int sz[N],cen[N],n,t,w;
long long ans;
namespace bit
{
	int b[N];
	void init()
	{
		for(int i=1;i<=n+1;i++)
			b[i]=0;
	}
	void add(int x,int v)
	{
		if(x<0)
			return;
		x++;
		for(int i=x;i<=n+1;i+=i&(-i))
			b[i]+=v;
	}
	int query(int x)
	{
		if(x<0)
			return 0;
		x++;
		int s=0;
		for(int i=x;i;i-=i&(-i))
			s+=b[i];
		return s;
	}
}
void dfs(int u,int f)
{
	sz[u]=1;
	for(auto i:e[u])
	{
		int v=i.first;
		if(v!=f&&!cen[v])
		{
			dfs(v,u);
			sz[u]+=sz[v];
		}
	}
}
pair<int,int> centroid(int u,int f,int t)
{
	pair<int,int> ans=make_pair(1e9,-1);
	int s=1,m=0;
	for(auto i:e[u])
	{
		int v=i.first;
		if(v==f||cen[v])
			continue;
		ans=min(ans,centroid(v,u,t));
		m=max(m,sz[v]);
		s+=sz[v];
	}
	m=max(m,t-s);
	ans=min(ans,make_pair(m,u));
	return ans;
}
void path(int u,int f,pair<int,int> d,vector<pair<int,int>> &x)
{
	x.push_back(d);
	for(auto i:e[u])
	{
		int v=i.first,w=i.second;
		if(v==f||cen[v])
			continue;
		path(v,u,make_pair(d.first+w,d.second+1),x);
	}
}
long long count(vector<pair<int,int>> &x)
{
	sort(x.begin(),x.end());
	int j=x.size()-1;
	long long ans=0;
	for(int i=0;i<x.size();i++)
		bit::add(x[i].second,1);
	int l=0,r=x.size()-1;
	if(x.size())
	while(l<r)
	{
		if(x[l].first+x[r].first<=w)
		{
			bit::add(x[l].second,-1);
			ans+=bit::query(t-x[l].second);
			l++;
		}
		else
		{
			bit::add(x[r].second,-1);
			r--;
		}
	}
	bit::add(x[l].second,-1);
	return ans;
}
void solve(int u)
{
	dfs(u,0);
	int s=centroid(u,0,sz[u]).second;
	cen[s]=1;
	for(auto i:e[s])
	{
		int v=i.first;
		if(cen[v])
			continue;
		solve(v);
	}
	vector<pair<int,int>> y;
	y.push_back(make_pair(0,0));
	for(auto i:e[s])
	{
		int v=i.first,w=i.second;
		if(cen[v])
			continue;
		vector<pair<int,int>> x;
		path(v,s,make_pair(w,1),x);
		ans-=count(x);
		y.insert(y.end(),x.begin(),x.end());
	}
	ans+=count(y);
	cen[s]=0;
}
int main()
{
	scanf("%d%d%d",&n,&t,&w);
	for(int i=2;i<=n;i++)
	{
		int u=i,v,w;
		scanf("%d%d",&v,&w);
		e[u].emplace_back(v,w);
		e[v].emplace_back(u,w);
	}
	solve(1);
	printf("%I64d\n",ans);
	return 0;
}