//Submitting someone else's code so that Lockout bot knows I tested this contest

#include <bits/stdc++.h>

using namespace std;

const int N = 5e5+1;
int n,m;
vector<int> adj[N];
bool vis[N];
vector<int> all[N];
int dep[N];
int par[N];
int pairs = 0;
bool outputted = 0;

void dfs(int u){
	if(outputted)return;
	vis[u] = 1;
	pairs -= all[dep[u]].size()/2;
	all[dep[u]].push_back(u);
	pairs += all[dep[u]].size()/2;
	if(dep[u] >= (n+1)/2){
		outputted = 1;
		cout << "PATH" << "\n";
		int cur = u;
		cout << dep[u] << "\n";
		while(cur != 0){
			cout << cur << " ";
			cur = par[cur];
		}
		cout << "\n";
	}
	for(int v:adj[u]){
		if(vis[v])continue;
		par[v] = u;
		dep[v] = dep[u]+1;
		dfs(v);
	}
}


void solve(){
	cin >> n >> m;
	outputted = 0;
	for(int i = 1;i <= n;i++){
	    adj[i].clear();
	    all[i].clear();
	    vis[i] = 0;
	}
	pairs = 0;
	for(int i = 1;i <= m;i++){
		int a,b;cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dep[1] = 1;
	dfs(1);
	if(outputted)return;
	cout << "PAIRING" << "\n";
	cout << pairs << "\n";
	for(int i = 1;i < (n+1)/2;i++){
		for(int j = 0;j+1 < all[i].size();j+=2){
			cout << all[i][j] << " " << all[i][j+1] << "\n";
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;cin >> t;
	while(t--){
	    solve();
	}
	return 0;
}