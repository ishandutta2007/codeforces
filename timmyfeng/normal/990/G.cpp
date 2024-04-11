#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
const int MX = 2e5 + 1;

bool sieve[MX], in_graph[MX], vstd[MX];
vector<int> pos[MX], adj[MX];
int mu[MX];
ll res[MX];

void init() {
	vector<int> primes;
	mu[1] = 1;
	for (int i = 2; i < MX; ++i) {
		if (!sieve[i]) {
			mu[i] = -1;
			primes.push_back(i);
		}
		for (auto j : primes) {
			if (i * j >= MX)
				break;
			sieve[i * j] = true;
			if (i % j == 0) {
				mu[i * j] = 0;
				break;
			}
			mu[i * j] = -mu[i];
		}
	}
}

int dfs(int u, int p) {
	int res = 1;
	vstd[u] = true;
	for (auto c : adj[u]) {
		if (c == p || !in_graph[c])
			continue;
		res += dfs(c, u);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	init();

	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int a;
		cin >> a;
		pos[a].push_back(i);
	}
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i < MX; ++i) {
		for (int j = i; j < MX; j += i) {
			for (auto k : pos[j]) {
				in_graph[k] = true;
			}
		}

		for (int j = i; j < MX; j += i) {
			for (auto k : pos[j]) {
				if (!vstd[k]) {
					ll cnt = dfs(k, 0);
					res[i] += cnt * (cnt + 1) / 2;
				}
			}
		}

		for (int j = i; j < MX; j += i) {
			for (auto k : pos[j]) {
				in_graph[k] = false;
				vstd[k] = false;
			}
		}
	}

	for (int i = 1; i < MX; ++i) {
		ll ans = 0;
		for (int j = 1; j * i < MX; ++j) {
			ans += mu[j] * res[j * i];
		}
		if (ans) {
			cout << i << ' ' << ans << '\n';
		}
	}
}