#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1007;
vector <int> g[MAX_N], us, him;
bool marked_us[MAX_N], marked_him[MAX_N];
int parent[MAX_N];

void dfs_2(int v, int prev, int c) {
	parent[v] = c;
	for (int u : g[v]) {
		if (u != prev) {
			if (marked_us[u]) exit(-1);
			dfs_2(u, v, c);
		}
	}
}

void dfs_1(int v, int prev = -1) {
	for (int u : g[v]) {
		if (u == prev) continue;
		if (marked_us[u]) {
			dfs_1(u, v);
		} else {
			dfs_2(u, v, v);
		}
	}
}

int main() {
	ios_base :: sync_with_stdio(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, k1, k2, v, u;
		cin >> n;
		us.clear();
		him.clear();
		for (int i = 1; i <= n; i++) {
			g[i].clear();
			marked_us[i] = 0;
			marked_him[i] = 0;
			parent[i] = -1;
		}
		for (int i = 1; i < n; i++) {
			cin >> v >> u;
			g[v].push_back(u);
			g[u].push_back(v);
		}
		cin >> k1;
		for (int i = 0; i < k1; i++) {
			cin >> v;
			marked_us[v] = 1;
			us.push_back(v);
		}
		cin >> k2;
		for (int i = 0; i < k2; i++) {
			cin >> v;
			marked_him[v] = 1;
			him.push_back(v);
		}
		cout << "B " << him.front() << endl;
		cin >> v;
		if (marked_us[v]) {
			cout << "C " << v << endl;
			continue;
		} else {
			dfs_1(us.front());
			cout << "A " << parent[v] << endl;
			int mem = parent[v];
			cin >> v;
			if (marked_him[v]) cout << "C " << mem << endl;
			else cout << "C -1" << endl;
		}
	}
	return 0;
}