#include<bits/stdc++.h>
using namespace std;
const int N=300005;
int n,m,x,vis[N];
long long a[N],s;
vector<pair<int,int>>e[N];
vector<int>l,r;
void dfs(int u)
{
	vis[u]=1;
	for(auto i:e[u])
	{
		int v=i.first,d=i.second;
		if(vis[v])
			continue;
		dfs(v);
		if(a[u]+a[v]-x>=0)
		{
			a[u]=a[u]+a[v]-x;
			l.push_back(d);
		}
		else
			r.push_back(d);
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>m>>x;
	for(int i=1;i<=n;i++)
		cin>>a[i],s+=a[i];
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		e[u].emplace_back(v,i);
		e[v].emplace_back(u,i);
	}
	if(1ll*x*(n-1)>s)
	{
		cout<<"NO\n";
		return 0;
	}
	dfs(1);
	if(l.size()+r.size()!=n-1)
	{
		cout<<"NO\n";
		return 0;
	}
	cout<<"YES\n";
	for(auto i=0;i<l.size();i++)
		cout<<l[i]<<"\n";
	for(int i=(int)r.size()-1;i>=0;i--)
		cout<<r[i]<<"\n";
	return 0;
}