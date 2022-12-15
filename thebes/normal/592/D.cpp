#include <bits/stdc++.h>
using namespace std;

const int MN = 15e4+5;
int d[MN], c[MN], t[MN], N, M, i, u[MN];
pair<int,int> a[MN], b[MN], sol(-1,0);
vector<int> adj[MN]; queue<int> q;

int dfs1(int n, int p){
	for(auto v : adj[n]){
		if(!t[v] || v == p) continue;
		pair<int,int> tmp={dfs1(v,n)+1,v};
		if(tmp.first>a[n].first){b[n]=a[n];a[n]=tmp;}
		else if(tmp.first>b[n].first) b[n]=tmp;
	}
	return a[n].first;
}

void dfs2(int n, int p){
	if(p) u[n]=max(u[p],(n==a[p].second)?b[p].first:a[p].first)+1;
	if(max(u[n],a[n].first)==sol.first) sol.second=min(sol.second,n);
	else if(max(u[n],a[n].first)>sol.first) sol={max(u[n],a[n].first),n};
	for(auto v : adj[n])
		if(v != p && t[v]) dfs2(v,n);
}

int main(){
	for(scanf("%d%d",&N,&M),i=0;i<N-1;i++){
		int x, y; scanf("%d%d",&x,&y);
		adj[x].push_back(y);
		adj[y].push_back(x);
		d[x]++; d[y]++;
	}
	for(i=0;i<M;i++){
		int x; scanf("%d",&x);
		c[x] = 1;
	}
	for(i=1;i<=N;i++){
		if(d[i]==1&&!c[i]) q.push(i);
		t[i] = 1;
	}
	int cnt = N;
	while(!q.empty()){
		int x = q.front(); q.pop();
		t[x] = 0; cnt--;
		for(auto v : adj[x]){
			if((--d[v])==1&&!c[v]) q.push(v);
		}
	}
	for(i=1;!t[i];i++){}
	dfs1(i,0); dfs2(i,0);
	printf("%d\n%d\n",sol.second,2*(cnt-1)-sol.first);
	return 0;
}