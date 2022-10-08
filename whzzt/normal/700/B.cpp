#include<bits/stdc++.h>
using namespace std;
const int N=200005;
vector<int>e[N];
int n,k,sz[N];
long long ans;
void dfs(int x,int fa){for(int v:e[x])if(v!=fa)dfs(v,x),sz[x]+=sz[v],ans+=min(sz[v],2*k-sz[v]);}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1,x;i<=2*k;i++)scanf("%d",&x),sz[x]=1;
	for(int i=1,u,v;i<n;i++)scanf("%d%d",&u,&v),e[u].push_back(v),e[v].push_back(u);
	dfs(1,0),printf("%lld\n",ans);
	return 0;
}