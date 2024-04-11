#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5+5;
int N, M, D, i, x, y, ans, fl[MN];
vector<int> adj[MN];
pair<int,int> a[MN], b[MN];

int dfs1(int n, int p){
	for(auto v : adj[n]){
		if(v == p) continue;
		pair<int,int> tmp={dfs1(v,n)+1,v};
		if(tmp.first == 0) continue;
		if(tmp.first>a[n].first) b[n]=a[n],a[n]=tmp;
		else if(tmp.first>b[n].first) b[n]=tmp;
	}
	return(fl[n])?max(a[n].first,0):a[n].first;
}

void dfs2(int n, int p, int s){
	if(max(s,a[n].first)<=D) ans++;
	if(s==0) s = -1;
	if(fl[n]) s=max(s,0);
	for(auto v : adj[n]){
		if(v == p) continue;
		if(v == a[n].second)
			dfs2(v,n,max(s,b[n].first)+1);
		else dfs2(v,n,max(s,a[n].first)+1);
	}
}

int main(){
	for(scanf("%d%d%d",&N,&M,&D);i<M;i++){
		scanf("%d",&x);
		fl[x] = 1;
	}
	memset(a, -1, sizeof(a));
	memset(b, -1, sizeof(b));
	for(i=0;i<N-1;i++){
		scanf("%d%d",&x,&y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs1(1,0); dfs2(1,0,-1);
	printf("%d\n",ans);
	return 0;
}