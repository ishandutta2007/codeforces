#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 1e5 + 7;
vector <int> g[MAX_N];
int cnt[MAX_N];

void dfs(int v) {
	cnt[v] = 0;
	if (g[v].empty()) cnt[v] = 1;
	for (int u : g[v]) {
		dfs(u);
		cnt[v] += cnt[u];
	}
}

int main() {
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	if (n == 1) {
		cout << "1" << endl;
		return 0;
	}
	for (int i = 2; i <= n; i++) {
		int p;
		cin >> p;
		g[p].push_back(i);
	}
	dfs(1);
	sort(cnt + 1, cnt + n + 1);
	for (int i = 1; i <= n; i++) cout << cnt[i] << ' ';
	cout << endl;
	return 0;
}