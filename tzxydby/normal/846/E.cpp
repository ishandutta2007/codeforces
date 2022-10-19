#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100005;
int n,b[N],a[N],f[N],k[N];
vector<int>e[N];
__int128 s[N];
void dfs(int u)
{
	s[u]=b[u]-a[u];
	for(auto v:e[u])
	{
		dfs(v);
		if(s[v]<0)
			s[u]+=k[v]*s[v];
		else
			s[u]+=s[v];
	}
	if(s[u]<-1e22)
		s[u]=-1e22;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>b[i];
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=2;i<=n;i++)
	{
		cin>>f[i]>>k[i];
		e[f[i]].push_back(i);
	}
	dfs(1);
	if(s[1]>=0)
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}