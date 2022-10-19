#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> g;
vector<int> d;
int n;


int dfs(int v, int p = -1, int cur_d = 0) {
	int a = cur_d, b = cur_d;
	for(int u: g[v]) {
		if(u == p) continue;
		int s_d = dfs(u, v, cur_d + 1);
		if(s_d > a) {
			b = a;
			a = s_d;
		} else if(s_d > b) {
			b = s_d;
		}
	}
	
	int i = min(a, b) - 1;
	if(i >= 0) {
		d[i] = max(d[i], a + b - 2 * cur_d + 1);
	}
	return a;
}


void solve() {
	cin >> n;
	g.assign(n, {});
	d.assign(n, 0);
	
	for(int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	int m_ans = dfs(0);
	for(int i = n - 2; i >= 0; i--) d[i] = max(d[i], d[i + 1]);
	
	int ans = 0;
	for(int k = 1; k <= n; k++) {
		while(ans < m_ans && d[ans] / 2 + k > ans) ans++;
		cout << ans << ' ';
	} 
	cout << '\n';
}


int main() {
	int T;
	cin >> T;
	while(T--) {
		solve();
	}
}