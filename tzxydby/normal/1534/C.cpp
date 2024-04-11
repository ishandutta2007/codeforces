#include<bits/stdc++.h>
using namespace std;
const int N=400005,mod=1e9+7;
int n,vis[N],s,a[N],b[N];
vector<int>e[N];
void dfs(int u)
{
	vis[u]=1;
	for(auto v:e[u])
		if(!vis[v])
			dfs(v);
}
void sol()
{
	scanf("%d",&n);
	s=1;
	for(int i=1;i<=n;i++)
	{
		vis[i]=0;
		e[i].clear();
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)
		e[a[i]].push_back(b[i]),e[b[i]].push_back(a[i]);
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			dfs(i);
			s=s*2%mod;
		}
	}
	printf("%d\n",s);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();	
	return 0;
}