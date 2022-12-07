#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; a <= i; i--)
#define ll long long
#define fi first
#define se second
using namespace std;

const int N = 5050;
const int P = 998244353;

int n, k, sz[N];
ll dp[N][N], ndp[N];
vector<int> e[N];

void dfs(int v, int p) {
	sz[v] = 1;
	dp[v][0] = 1;
	for (auto u : e[v]) {
		if (u == p) continue;
		dfs(u, v);
		memset(ndp, 0, sizeof ndp);
		rep(a, 0, sz[v])
			rep(b, 0, sz[u]) {
				if (a + b + 1 <= k) {
					int c = max(a, b + 1);
					ndp[c] = (ndp[c] + dp[v][a] * dp[u][b]) % P;
				}
				if (b <= k)
					ndp[a] = (ndp[a] + dp[v][a] * dp[u][b]) % P;
			}
		memcpy(dp[v], ndp, sizeof ndp);
		sz[v] += sz[u];
	}
}
 
int main() {
	cin >> n >> k;
	rep(i, 1, n - 1) {
		int a, b;
		cin >> a >> b;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	dfs(1, 0);
	cout << accumulate(dp[1], dp[1] + k + 1, 0ll) % P << endl;
	return 0;
}