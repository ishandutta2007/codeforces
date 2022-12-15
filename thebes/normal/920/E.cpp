#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#include <bits/stdc++.h>
using namespace std;

const int MN = 2e5+5;
int N, M, i, x, y, cnt;
set<int> adj[MN], to;
vector<int> sz;

void dfs(int n){
	vector<int> nxt; cnt++;
	for(auto it=to.begin();it!=to.end();){
		if(adj[n].count(*it)){it++; continue;}
		nxt.push_back(*it); 
		auto tmp = it; it++;
		to.erase(tmp);
	}
	for(auto v : nxt)
		dfs(v);
}

int main(){
	for(scanf("%d%d",&N,&M),i=1;i<=M;i++){
		scanf("%d%d",&x,&y);
		adj[x].insert(y);
		adj[y].insert(x);
	}
	for(i=1;i<=N;i++)
		to.insert(i);
	while(to.size()){
		auto it=to.begin(); cnt=0;
		int tmp = *it; to.erase(it);
		dfs(tmp);
		sz.push_back(cnt);
	}
	sort(sz.begin(),sz.end());
	printf("%d\n",sz.size());
	for(auto v : sz) printf("%d ",v);
	getchar(); getchar();
	return 0;
}