#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,l[N],r[N],ans;
long long a[N];
vector<int>e[N];
void dfs(int u)
{
	int z=1;
	long long s=0;
	for(auto v:e[u])
	{
		dfs(v);
		s+=a[v];
		z=0;
	}
	if(z)
	{
		ans++;
		a[u]=r[u];
	}
	else
	{
		if(s<l[u])
		{
			ans++;
			a[u]=r[u];
		}
		else
			a[u]=min(s,1ll*r[u]);
	}
}
void sol()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		e[i].clear();
		a[i]=0;
	}
	ans=0;
	for(int i=2;i<=n;i++)
	{
		int p;
		scanf("%d",&p);
		e[p].push_back(i);
	}
	for(int i=1;i<=n;i++)
		scanf("%d%d",&l[i],&r[i]);
	dfs(1);
	printf("%d\n",ans);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}