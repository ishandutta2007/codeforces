#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

vector<int> adj[N];
long long ans;
int p[N];
int s[N];
int a[N];

void dfs(int u) {
	if (s[u] == -1) {
		s[u] = adj[u].empty() ? s[p[u]] : 1e9;
		for (auto c : adj[u]) {
			s[u] = min(s[u], s[c]);
		}
	}
	a[u] = s[u] - s[p[u]];	
	if (a[u] < 0) {
		cout << -1 << "\n";
		exit(0);
	}
	ans += a[u];
	for (auto c : adj[u]) {
		dfs(c);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 2; i <= n; ++i) {
		cin >> p[i];
		adj[p[i]].push_back(i);
	}
	for (int i = 1; i <= n; ++i) {
		cin >> s[i];
	}

	dfs(1);

	cout << ans << "\n";
}