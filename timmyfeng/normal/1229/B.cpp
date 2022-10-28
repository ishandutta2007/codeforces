#include <bits/stdc++.h> 
using namespace std;

using ll = long long;

const int LOG_N = 18;
const int MX = 1e5 + 1;
const int M = 1e9 + 7;

vector<int> adj[MX];
int par[LOG_N][MX];
ll x[LOG_N][MX];
int dep[MX];

int add(int a, int b) {
	a += b;
	if (a >= M) {
		a -= M;
	}
	return a;
}

int mul(ll a, ll b) {
	return 1LL * a * b % M;
}

ll gcd(ll a, ll b) {
	if (!b) {
		return a;
	}
	return gcd(b, a % b);
}

void dfs(int u, int p) {
	for (auto c : adj[u]) {
		if (c != p) {
			dep[c] = dep[u] + 1;
			par[0][c] = u;
			dfs(c, u);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> x[0][i];
	}

	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(1, 0);
	dep[0] = -1;

	int log_n;
	for (log_n = 1; (1 << log_n) < 2 * n; ++log_n) {
		for (int i = 1; i <= n; ++i) {
			par[log_n][i] = par[log_n - 1][par[log_n - 1][i]];
			x[log_n][i] = gcd(x[log_n - 1][par[log_n - 1][i]], x[log_n - 1][i]);
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		int cur = i;
		for (int i = log_n - 1; i >= 0; --i) {
			if (!x[i][cur]) {
				cur = par[i][cur];
			}
		}
		ll val = x[0][cur];
		
		while (cur) {
			int pre = cur;
			for (int i = log_n - 1; i >= 0; --i) {
				if (x[i][cur] % val == 0) {
					cur = par[i][cur];
				}
			}
			ans = add(ans, mul(dep[pre] - dep[cur], val));
			val = gcd(x[0][cur], val);
		}
	}
	cout << ans << "\n";
}