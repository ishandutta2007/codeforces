#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;

const int N = 1 << 20;
int n, a[N], b[N], vis[N];
vector<pair<int, int>> e[N];
vector<int> euler;

void dfs(int u, int prv) {
	while (e[u].size()) {
		auto [v, i] = e[u].back();
		e[u].pop_back();
		if (vis[i / 2]) {
			continue;
		}
		vis[i / 2] = 1;
		dfs(v, i);
	}
	if (prv != -1)
		euler.push_back(prv);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i];
	for (int k = 20; k >= 0; k--) {

		for (int i = 0; i < N; i++) {
			vis[i] = 0;
			e[i].clear();
		}

		int s = (1 << k) - 1;
		for (int i = 0; i < n; i++) {
			int x = (a[i] & s);
			int y = (b[i] & s);
			e[x].emplace_back(y, 2 * i);
			e[y].emplace_back(x, 2 * i + 1);
		}

		int odd = 0;
		for (int i = 0; i < s; i++)
			if (int(e[i].size()) % 2 == 1)
				odd++;

		if (odd)
			continue;

		euler.clear();
		dfs((a[0] & s), -1);

		if (euler.size() < n)
			continue;

		cout << k << endl;
		for (auto x : euler)
			cout << (x ^ 1) + 1 << " " << x + 1 << " ";
		cout << endl;
		return 0;
	}

	return 0;
}