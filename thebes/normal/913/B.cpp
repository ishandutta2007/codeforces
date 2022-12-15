#include <bits/stdc++.h>
using namespace std;

const int MN = 1e3+3;
vector<int> adj[MN];
int n, i, x;

int check(int n){
	int cnt = 0, r = 1;
	for(auto v : adj[n]){
		if(adj[v].empty()) cnt++;
		else r=min(r,check(v));
	}
	return(r&&cnt>=3);
}

int main(){
	for(scanf("%d",&n),i=2;i<=n;i++){
		scanf("%d",&x);
		adj[x].push_back(i);
	}
	printf("%s\n",(check(1))?"Yes":"No");
	return 0;
}