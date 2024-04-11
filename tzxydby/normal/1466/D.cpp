#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100005;
int n,sum,a[N];
vector<int>e[N],x;
void dfs(int u,int f)
{
	for(auto v:e[u])
	{
		if(v==f)
			continue;
		dfs(v,u);
	}
	for(int i=0;i<e[u].size()-1;i++)
		x.push_back(a[u]);
}
void sol()
{
	cin>>n;
	sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		e[i].clear();
		sum+=a[i];
	}
	x.clear();
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0);
	sort(x.begin(),x.end());
	reverse(x.begin(),x.end());
	cout<<sum<<' ';
	for(int i=0;i<n-2;i++)
	{
		sum+=x[i];
		cout<<sum<<' ';
	}
	cout<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--)
		sol();
	return 0;
}