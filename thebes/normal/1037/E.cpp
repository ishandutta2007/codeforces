#include <bits/stdc++.h>
using namespace std;

const int MN = 2e5+5;
vector<int> adj[MN];
int n, m, k, use[MN], deg[MN], i, x, y, ans[MN], tot;
pair<int,int> e[MN];
queue<int> q;

int main(){
	for(scanf("%d%d%d",&n,&m,&k),i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		e[i] = {x, y};
		adj[x].push_back(y);
		adj[y].push_back(x);
		deg[x]++, deg[y]++;
	}
	for(i=1;i<=n;i++) use[i]=1;
	for(i=1;i<=n;i++){
		if(deg[i]<k){
			use[i] = 0;
			q.push(i);
		}
	}
	tot = n;
	while(q.size()){
		int c = q.front(); q.pop(); tot--;
		use[c] = 0;
		for(auto v : adj[c]){
			if((--deg[v])<k&&use[v]){
				use[v] = 0;
				q.push(v);
			}
		}
	}
	ans[m] = tot;
	for(i=m;i>=1;i--){
		tie(x, y) = e[i];
		adj[x].erase(adj[x].end()-1);
		adj[y].erase(adj[y].end()-1);
		if((!use[x])||(!use[y])){
            ans[i-1]=tot;
            continue;
		}
		deg[x]--, deg[y]--;
		if(deg[x]<k&&use[x]) q.push(x), use[x]=0;
		if(deg[y]<k&&use[y]) q.push(y), use[y]=0;
		while(q.size()){
			int c = q.front(); q.pop(); tot--;
			for(auto v : adj[c]){
				if((--deg[v])<k&&use[v]){
					use[v] = 0;
					q.push(v);
				}
			}
		}
		ans[i-1]=tot;
	}
	for(i=1;i<=m;i++)
		printf("%d\n",ans[i]);
	return 0;
}