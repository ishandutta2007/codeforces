#include <bits/stdc++.h>
using namespace std;

const int M = (119 << 23) + 1;
const int MX = 2e5 + 1;

vector<int> adj[MX];

int add(int a, int b) {
	return (a += b) < M ? a : a - M;
}

int sub(int a, int b) {
	return (a -= b) < 0 ? a + M : a;
}

int mul(int a, int b) {
	return 1LL * a * b % M;
}

struct combination {
	vector<int> fact;
	vector<int> fact_inv;

	combination(int n) : fact(n + 1), fact_inv(n + 1) {
		fact_inv[1] = 1;
		for (int i = 2; i <= n; ++i) {
			fact_inv[i] = M - mul(M / i, fact_inv[M % i]);
		}

		fact[0] = 1;
		fact_inv[0] = 1;
		for (int i = 1; i <= n; ++i) {
			fact[i] = mul(fact[i - 1], i);
			fact_inv[i] = mul(fact_inv[i - 1], fact_inv[i]);
		}
	}
} C(2e5);

int dfs(int u, int p) {
	int res = 1;
	for (auto c : adj[u]) {
		if (c != p) {
			res = mul(res, dfs(c, u));
		}
	}
	return mul(res, C.fact[adj[u].size()]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	cout << mul(n, dfs(1, 0)) << "\n";
}