#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=1000050;
vector<int> E[N];
int k,n,sol;
int DFS(int u, int p, int d)
{
	vector<int> dep;
	for(int v:E[u]) if(v!=p) dep.pb(DFS(v,u,d+1));
	if(dep.empty()) return d;
	sort(dep.begin(),dep.end());
	int ans=0;
	for(int i=0;i+1<dep.size();i++)
	{
		if(dep[i]+dep[i+1]-2*d<=k) ans++;
	}
	sol+=dep.size()-ans-1;
	return dep[ans];
}
int main()
{
	scanf("%i %i",&n,&k);
	int u,v;
	for(int i=1;i<n;i++) scanf("%i %i",&u,&v),E[u].pb(v),E[v].pb(u);
	int root=0;
	for(int i=1;i<=n;i++) if(E[i].size()>1) root=i;
	DFS(root,0,1);
	printf("%i\n",sol+1);
	return 0;
}