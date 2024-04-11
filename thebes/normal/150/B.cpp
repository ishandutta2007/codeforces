#include <bits/stdc++.h>
using namespace std;

const int MN = 2e3+3, mod = 1e9+7;
int vis[MN], n, m, k, i, j, cnt, ans=1;
vector<int> adj[MN];

void dfs(int n){
	vis[n] = 1;
	for(auto v : adj[n])
		if(!vis[v]) dfs(v);
}

int main(){
	for(scanf("%d%d%d",&n,&m,&k),i=1;i<=n;i++){
		if(i+k-1 > n) break;
		for(j=0;j<ceil(k/2.0);j++){
			adj[i+j].push_back(i+k-1-j);
			adj[i+k-1-j].push_back(i+j);
		}
	}
	for(i=1;i<=n;i++)
		if(!vis[i]){dfs(i); cnt++;}
	for(i=0;i<cnt;i++)
		ans = (1LL*m*ans)%mod;
	printf("%d\n",ans);
	return 0;
}