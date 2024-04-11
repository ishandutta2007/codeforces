#include <bits/stdc++.h>
 
#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())
 
using namespace std;
 
inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int N = 202'202;
vector<int> g[N];

void solve() {
	int n = nxt();
	vector<int> a(n);
	generate(all(a), nxt);
	for (int i = 1; i < n; ++i) {
		int x = nxt(), y = nxt();
		--x; --y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	vector<int> ans(n);
	function<void(int, int)> dfs1 = [&](int u, int p) {
		for (int v : g[u]) {
			if (v == p) continue;
			ans[v] = __gcd(ans[u], a[v]);
			dfs1(v, u);
		}
	};
	dfs1(0, 0);

	vector<int> divs;
	for (int i = 1; i <= a[0]; ++i) {
		if (a[0] % i == 0) {
			divs.push_back(i);
		}
	}
	int m = divs.size();
	vector<int> cnt(m);
	function<void(int, int, int)> dfs2 = [&](int u, int p, int d) {
		for (int i = 0; i < m; ++i) {
			if (a[u] % divs[i] == 0) {
				cnt[i] += 1;
			}
			if (cnt[i] >= d) {
				ans[u] = max(ans[u], divs[i]);
			}
		}
		for (int v : g[u]) {
			if (v == p) continue;
			dfs2(v, u, d + 1);
		}
		for (int i = 0; i < m; ++i) {
			if (a[u] % divs[i] == 0) {
				cnt[i] -= 1;
			}
		}
	};
	dfs2(0, 0, 0);
	for (int i = 0; i < n; ++i) {
		cout << ans[i] << " ";
	}
	cout << "\n";
}

int main() {
	int t = 1;
	while (t--) {
		solve();
	}

	return 0;
}