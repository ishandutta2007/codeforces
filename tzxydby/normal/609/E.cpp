#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int f[N];
long long sum,ans[N];
pair<int,pair<int,int>>e[N];
set<int>s[N];
int find(int u)
{
	return f[u]=f[u]==u?u:find(f[u]); 
}
void solve(int u,int v,int w)
{
	u=find(u);
	v=find(v);
	f[v]=u;
	if(s[u].size()<s[v].size())
		swap(s[u],s[v]);
	while(s[v].size())
	{
		if(s[u].find(*s[v].begin())!=s[u].end())
			ans[*s[v].begin()]-=w;
		else 
			s[u].insert(*s[v].begin());
		s[v].erase(s[v].begin());
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	int n,m,i,u,v,w;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		s[u].insert(i);
		s[v].insert(i);
		e[i]=make_pair(w,make_pair(u,v));
		ans[i]=w;
	}
	for(int i=1;i<=n;i++) 
		f[i]=i;
	sort(e+1,e+m+1);
	for(int i=1;i<=m;i++)
	{
		u=e[i].second.first,v=e[i].second.second,w=e[i].first;
		if(find(u)==find(v)) 
			continue;
		solve(u,v,w);
		sum+=w;
	}
	for(int i=1;i<=m;i++) 
		cout<<ans[i]+sum<<endl;
	return 0;
}