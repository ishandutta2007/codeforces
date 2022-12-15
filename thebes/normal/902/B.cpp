#include <bits/stdc++.h>
using namespace std;

const int MN = 10004;
int N, c[MN], ans, i, x;
vector<int> adj[MN];

void solve(int n, int p){
	if(c[n] != p) ans++;
	for(auto v : adj[n])
		solve(v, c[n]);
}

int main(){
	for(scanf("%d",&N),i=2;i<=N;i++){
		scanf("%d",&x);
		adj[x].push_back(i);
	}
	for(i=1;i<=N;i++)
		scanf("%d",&c[i]);
	solve(1, -1);
	printf("%d\n",ans);
	return 0;
}