#include <bits/stdc++.h> 
using namespace std;

const int MX = 80;

array<int, 2> best[MX][MX][5];
int w[MX][MX], ans, n, k;
bool used[MX], ok;
vector<int> stk;

int get_best(int u, int v) {
	int i = 0;
	while (i < n - 1 && used[best[u][v][i][1]]) {
		++i;
	}
	ok &= (i < n - 1);
	return best[u][v][i][0];
}

void dfs(int u, int i) {
	stk.push_back(u);
	bool pre = used[u];
	used[u] = true;

	if (i == k - 2) {
		int sum = 0;
		stk.push_back(0);
		ok = true;
		for (int i = 0; i < k / 2; ++i) {
			sum += get_best(stk[i], stk[i + 1]);
		}
		stk.pop_back();
		if (ok) {
			ans = min(ans, sum);
		}
	} else {
		for (int v = 0; v < n; ++v) {
			dfs(v, i + 2);
		}
	}

	stk.pop_back();
	used[u] = pre;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> w[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			vector<array<int, 2>> all;
			for (int l = 1; l < n; ++l) {
				all.push_back({w[i][l] + w[l][j], l});
			}
			sort(all.begin(), all.end());
			copy(all.begin(), all.begin() + k / 2, best[i][j]);
		}
	}

	ans = 2e9;
	dfs(0, 0);
	cout << ans << '\n';
}