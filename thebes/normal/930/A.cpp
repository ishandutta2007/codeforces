#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5+5;
int N, i, x, y, ans;
vector<int> adj[MN];
bitset<MN> dep;

void dfs(int n, int d){
	dep[d].flip(); 
	for(auto v : adj[n])
		dfs(v, d+1);
}

int main(){
	for(scanf("%d",&N),i=2;i<=N;i++){
		scanf("%d",&x);
		adj[x].push_back(i);
	}
	dfs(1,0);
	for(i=0;i<=N;i++)
		ans += dep[i];
	printf("%d\n",ans);
	return 0;
}