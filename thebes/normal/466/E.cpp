#include <bits/stdc++.h>
using namespace std;

const int MN=1e5+5,LG=20;
int n, m, i, x, y, w, sp[MN][LG], anc[MN][LG], dep[MN], ok[MN];
vector<pair<int,int>> p, q, adj[MN];

void dfs(int n,int p,int d){
	dep[n]=d; anc[n][0]=p;
	for(auto v : adj[n]){
		dfs(v.first,n,d+1);
		sp[v.first][0]=v.second;
	}
}

int qu(int x,int y){
	int ret = 0;
	for(int i=LG-1;i>=0;i--){
		if((1<<i)<=dep[x]-dep[y]){
			ret=max(ret,sp[x][i]);
			x=anc[x][i];
		}
	}
	return(x==y)?ret:-1;
}

int main(){
	for(scanf("%d%d",&n,&m),i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		if(x==2) p.push_back({y,i});
		else if(x==1){
			scanf("%d",&w); ok[y]=1;
			adj[w].push_back({y,i});
		}
		else{
			scanf("%d",&w);
			q.push_back({y,w});
		}
	}
	for(i=1;i<=n;i++){
		if(!ok[i]) dfs(i,-1,1);
	}
	for(int j=1;j<LG;j++){
		for(i=1;i<=n;i++){
			if(anc[i][j-1]==-1) continue;
			anc[i][j]=anc[anc[i][j-1]][j-1];
			sp[i][j]=max(sp[i][j-1],sp[anc[i][j-1]][j-1]);
		}
	}
	for(auto v : q){
		int idx = v.second-1;
		int res=qu(p[idx].first,v.first);
		if(res!=-1&&res<=p[idx].second) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}