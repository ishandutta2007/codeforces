#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;
const int P = 998244353;
const int N = 350;
int n, h[N];
ll w[N][N], b[N][N], res;
vector<int> e[N];

void dfs(int u, int p, int r) {
	h[u] = 0;
	w[u][0] = 1;
	b[u][0] = 1;

	for (auto v : e[u]) {
		if (v == p)
			continue;
		dfs(v, u, r);

		ll nw[N]{}, nb[N]{};
		for (int i = 0; i <= h[u]; i++)
			for (int j = 0; j <= h[v]; j++) {
				int mn = min(i, j + 1);
				int mx = max(i, j + 1);

				auto add = [&](ll &a, ll b) {
					a = (a + b) % P;
				};

				add(nb[mn], b[u][i] * b[v][j]);
				add(nw[mx], w[u][i] * w[v][j]);

				if (i + j + 1 <= r) {
					add(nb[i], b[u][i] * w[v][j]);
					add(nb[j + 1], w[u][i] * b[v][j]);
				}

				else {
					add(nw[i], w[u][i] * b[v][j]);
					add(nw[j + 1], b[u][i] * w[v][j]);
				}
			}

		memcpy(w[u], nw, sizeof nw);
		memcpy(b[u], nb, sizeof nb);
		h[u] = max(h[u], h[v] + 1);
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		e[a].push_back(b);
		e[b].push_back(a);
	}

	for (int r = 1; r < n; r++) {
		memset(w, 0, sizeof w);
		memset(b, 0, sizeof b);
		dfs(1, 0, r);
		res = (res + accumulate(w[1], w[1] + n, 0ll)) % P;
	}

	for (int i = 0; i < n; i++)
		res = res * (P + 1) / 2 % P;
	cout << res << endl;
	return 0;
}