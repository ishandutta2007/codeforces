#include <bits/stdc++.h> 
using namespace std;

const int MX = 2e5 + 1;

set<int> pos[MX];
int x[MX];
int y[MX];
int w[MX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> w[i];
	}

	for (int i = 1; i <= m; ++i) {
		cin >> x[i] >> y[i];
		pos[x[i]].insert(i);
		pos[y[i]].insert(i);
	}

	queue<int> que;
	for (int i = 1; i <= n; ++i) {
		if (int(pos[i].size()) <= w[i]) {
			que.push(i);
		}
	}

	vector<int> ans;
	while (!que.empty()) {
		int u = que.front();
		que.pop();
		for (auto i : pos[u]) {
			int oth = x[i] == u ? y[i] : x[i];
			pos[oth].erase(i);
			if (int(pos[oth].size()) == w[oth]) {
				que.push(oth);
			}
			ans.push_back(i);
		}
		pos[u].clear();
	}

	if (int(ans.size()) == m) {
		cout << "ALIVE\n";
		reverse(ans.begin(), ans.end());
		for (auto& i : ans) {
			cout << i << " ";
		}
		cout << "\n";
	} else {
		cout << "DEAD\n";
	}
}