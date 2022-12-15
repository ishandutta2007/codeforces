#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5+5;
int d[MN], i, t[MN], N, M, x, y, ans;
vector<int> adj[MN];
queue<int> q, p;

int main(){
	for(scanf("%d%d",&N,&M),i=0;i<N;i++)
		scanf("%d",&t[i]);
	for(i=0;i<M;i++){
		scanf("%d%d",&x,&y);
		adj[y].push_back(x);
		d[x]++;
	}
	for(i=0;i<N;i++){
		if(d[i]==0){
			if(t[i]==1)q.push(i);
			else p.push(i);
		}
	}
	while(!q.empty()||!p.empty()){
		while(!p.empty()){
			x = p.front(); p.pop();
			for(auto v : adj[x]){
				if((--d[v])==0){
					if(t[v]==1) q.push(v);
					else p.push(v);
				}
			}
		}
		if(q.empty()&&p.empty()) break;
		while(!q.empty()){
			x = q.front(); q.pop();
			for(auto v : adj[x]){
				if((--d[v])==0){
					if(t[v]==1) q.push(v);
					else p.push(v);
				}
			}
		}
		ans++;
	}
	printf("%d\n",ans);
	return 0;
}