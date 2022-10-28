#include <bits/stdc++.h> 
using namespace std;

const int MX = 1e5 + 1;

int cur, nxt[MX], pre[MX], vertex[MX][3];
set<int> triangle[MX];
vector<int> ans;

void dfs() {
	int u = ans[cur++];

	vector<int> rem, stay;
	for (auto i : vertex[u]) {
		triangle[i].erase(u);
		if (triangle[i].empty()) {
			rem.push_back(i);
		} else {
			stay.push_back(i);
			if (triangle[i].size() == 1u) {
				ans.push_back(*triangle[i].begin());
			}
		}
	}

	if (stay.empty()) {
		for (int i = 0; i < 3; ++i) {
			nxt[rem[i]] = rem[(i + 1) % 3];
			pre[rem[i]] = rem[(i - 1 + 3) % 3];
		}
	} else {
		dfs();
		if (nxt[stay[0]] == stay[1]) {
			swap(stay[0], stay[1]);
		}
		pre[stay[0]] = rem[0];
		nxt[rem[0]] = stay[0];
		nxt[stay[1]] = rem[0];
		pre[rem[0]] = stay[1];
	}
}

void solve() {
	int n;
	cin >> n;

	fill(triangle + 1, triangle + n, set<int>());
	for (int i = 1; i <= n - 2; ++i ){
		for (int j = 0; j < 3; ++j ){
			cin >> vertex[i][j];
			triangle[vertex[i][j]].insert(i);
		}
	}

	ans.clear();
	for (int i = 1; i <= n; ++i) {
		if (triangle[i].size() == 1u) {
			ans.push_back(*triangle[i].begin());
		}
	}

	cur = 0;
	dfs();

	int v = 1;
	do {
		cout << v << ' ';
		v = nxt[v];
	} while (v != 1);
	cout << '\n';

	ans.erase(ans.end() - 2, ans.end());
	for (auto i : ans) {
		cout << i << ' ' ;
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}