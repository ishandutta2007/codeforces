#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2005;
int ans = 0, a[N], lev[N];
vector <int> adj[N];
bool ck[N];

void dfs(int u){
	ans = max(ans, lev[u]);
	ck[u] = true;
	for (int i = 0; i < adj[u].size(); i++){
		if (!ck[adj[u][i]]){
			lev[adj[u][i]] = lev[u] + 1;
			dfs(adj[u][i]);
		}
	}
	return;
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	memset(ck, 0, sizeof(ck));
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		if (a[i] != -1){
			a[i]--;
			adj[a[i]].push_back(i);
			adj[i].push_back(a[i]);
		}
	}
	for (int i = 0; i < n; i++){
		if (a[i] == -1){
			lev[i] = 1;
			dfs(i);
		}
	}
	cout << ans;
}