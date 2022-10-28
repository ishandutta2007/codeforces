#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

vector<int> adj[N];
bool good[N];

void dfs(int u) {
	for (auto c : adj[u]) {
		good[u] &= good[c];
		dfs(c);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int root = 0;
	for (int i = 1; i <= n; ++i) {
		int par;
		cin >> par >> good[i];
		if (par != -1) {
			adj[par].push_back(i);
		} else {
			root = i;
		}
	}

	dfs(root);

	bool ok = false;
	for (int i = 1; i <= n; ++i) {
		if (good[i]) {
			ok = true;
			cout << i << " ";
		}
	}
	if (!ok) {
		cout << -1;
	}
	cout << "\n";
}