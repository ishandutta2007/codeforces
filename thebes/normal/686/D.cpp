#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#include <bits/stdc++.h>
using namespace std;

const int MN = 3e5+5;
int sz[MN], N, Q, i, x, p[MN], cent[MN];
vector<int> adj[MN];
void solve(int n){
	sz[n] = 1;
	for(auto v : adj[n]){
		solve(v);
		sz[n] += sz[v];
	}
	int mx=0, idx=0;
	for(auto v : adj[n]){
		if(sz[v] > mx) 
			mx=sz[v], idx = v;
	}
	if(mx<=sz[n]/2) cent[n] = n;
	else{
		cent[n] = cent[idx];
		while(sz[n]-sz[cent[n]]>sz[n]/2) cent[n]=p[cent[n]];
	}
}
int main(){
	for(scanf("%d%d",&N,&Q),i=2;i<=N;i++){
		scanf("%d",&x);p[i]=x;
		adj[x].push_back(i);
	}
	solve(1);
	while(Q--){
		scanf("%d",&x);
		printf("%d\n",cent[x]);
	}
	return 0;
}