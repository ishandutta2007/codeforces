#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,m,a[N],b[N],vis[N],c,pl,pr,pm1,pm2,z,v[N];
long long ans;
vector<int>e[N],p;
void dfs(int u)
{
	vis[u]=1;
	c++;
	for(auto v:e[u])
		if(!vis[v])
			dfs(v);
}
void sol()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		e[i].clear();
		vis[i]=0;
	}
	p.clear();
	ans=0;
	m=n;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)
		e[a[i]].push_back(b[i]),e[b[i]].push_back(a[i]);
	for(int i=1;i<=n;i++)
	{
		if(vis[i])
			continue;
		c=0;
		dfs(i);
		p.push_back(c);
		if(c&1)
			m--;
	}
	for(int i=1;i<=m/2;i++)
		ans+=n*2-4*i+2;
	printf("%lld\n",ans);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}