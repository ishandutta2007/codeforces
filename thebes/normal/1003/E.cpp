#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#include <bits/stdc++.h>
using namespace std;

const int MN = 4e5+5;
int N, d, k, dist[MN], vis[MN], i, nxt;
vector<int> adj[MN];
void solve(int n){
	if(vis[n]) return;
	vis[n] = 1;
	for(auto v : adj[n])
		solve(v);
	int sz = k-adj[n].size();
	while(sz&&nxt<=N&&dist[n]){
		adj[n].push_back(nxt);
		adj[nxt].push_back(n);
		dist[nxt]=dist[n]-1;
		solve(nxt++); sz--;
	}
}
void go(int n,int p){
	for(auto v : adj[n]){
		if(v == p) continue;
		printf("%d %d\n",n,v);
		go(v, n);
	}
}

int main(){
	scanf("%d%d%d",&N,&d,&k);
	for(i=1;i<=d;i++){
		adj[i].push_back(i+1);
		adj[i+1].push_back(i);
	}
	if(k==1&&N>2){
		printf("NO\n");
		return 0;
	}
	for(i=1;i<=d+1;i++)
		dist[i]=min(i-1,d+1-i);
	nxt = d+2;
	solve(1);
	if(nxt==N+1){
		printf("YES\n");
		go(1, 0);
	}
	else printf("NO\n");
	getchar(); getchar();
}