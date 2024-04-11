#include<bits/stdc++.h>
using namespace std;

const int maxn=200007;

int n,m;
int ans[maxn];
vector<int> e[maxn];
int vis[maxn];

bool dfs(int u){
	vis[u]=-1;
	bool fg=false;
	for (int i=0;i<e[u].size();++i){
		int t=e[u][i];
		if (vis[t]==-1){
			fg=true;
			return fg;
		}
		if (vis[t]==1) continue;
		fg|=dfs(t);
	}
	vis[u]=1;
	return fg;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for (int i=1;i<=m;++i){
		int u,v;
		cin>>u>>v;
		if (u<v){
			ans[i]=1;
		}
		else{
			ans[i]=2;
		}
		e[u].push_back(v);
	}
	for (int i=1;i<=n;++i){
		if (dfs(i)){
			cout<<2<<endl;
			for (int j=1;j<=m;++j){
				cout<<ans[j]<<endl;
			}
			return 0;
		}
	}
	cout<<1<<endl;
	for (int i=1;i<=m;++i){
		cout<<1<<endl;
	}
}