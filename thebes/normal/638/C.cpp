#include <bits/stdc++.h>
using namespace std;

const int MN = 2e5+5;
vector<int> adj[MN], tmp[MN];
map<pair<int,int>,int> id;
int N, i, x, y, ans, idx;

void solve(int n, int p, int t){
	int temp = 1;
	for(auto v : adj[n]){
		if(temp == t) temp++;
		if(v == p) continue;
		tmp[temp].push_back(id[{min(n,v),max(n,v)}]);
		solve(v, n, temp); temp++;
	}
}

int main(){
	for(scanf("%d",&N),i=1;i<N;i++){
		scanf("%d%d",&x,&y);
		id[{min(x,y),max(x,y)}]=i;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for(i=1;i<=N;i++){
		if(adj[i].size()>ans)
			ans = adj[i].size(), idx = i;
	}
	solve(idx, 0, 0);
	printf("%d\n",adj[idx].size());
	for(i=1;i<=adj[idx].size();i++){
		printf("%d ",tmp[i].size());
		for(auto v : tmp[i]) printf("%d ",v);
		printf("\n");
	}
	return 0;
}