#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;
const int MAXN = 200050;

int n, nxt, an[MAXN], ae[MAXN];
vector<pi> gph[MAXN];

void dfs(int x, int pa, int dep){
	for(auto &e : gph[x]){
		int y = e.first;
		if(y == pa) continue;
		ae[e.second] = ++nxt;
		an[y] = n + nxt;
		if(dep % 2 == 1){
			swap(ae[e.second], an[y]);
		}
		dfs(y, x, dep + 1);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int tc; cin >> tc;
	while(tc--){
		cin >> n; n = (1 << n);
		for(int i = 1; i <= n; i++) gph[i].clear();
		for(int i = 0; i < n - 1; i++){
			int u, v; cin >> u >> v;
			gph[u].push_back({v, i});
			gph[v].push_back({u, i});
		}
		nxt = 0; an[1] = n;
		dfs(1, 1, 1);
		cout << 1 << "\n";
		for(int i = 1; i <= n; i++) cout << an[i] << " "; cout << "\n";
		for(int i = 0; i < n - 1; i++) cout << ae[i] << " "; cout << "\n";
	}
}