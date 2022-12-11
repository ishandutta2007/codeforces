#include<bits/stdc++.h>
#define ll long long
#define maxn 200005
using namespace std;
int n,k;
vector<int> g[maxn];
int sz[maxn],d[maxn];
struct Node
{
	int d,sz,id;
}a[maxn];
bool operator < (Node A,Node B)
{
	return A.d-A.sz>B.d-B.sz;
}
void dfs(int u,int f)
{
	d[u]=d[f]+1;
	sz[u]=1;
	for(int v:g[u])if(v!=f)
	{
		dfs(v,u);
		sz[u]+=sz[v];
	}
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	for(int i=1;i<=n;++i)a[i].d=d[i],a[i].sz=sz[i],a[i].id=i;
	sort(a+1,a+n+1);
	ll ans=0;
	for(int i=1;i<=k;++i)
	{
		int u=a[i].id;
		ans+=d[u]-sz[u]; 
	}
	cout<<ans<<endl;
}