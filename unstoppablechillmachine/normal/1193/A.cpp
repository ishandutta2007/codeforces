#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
//#define int ll

const int MOD = 998244353;

void add(int &a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

int mult(int a, int b) {
	return (a * 1ll * b) % MOD;
}

int b_pow(int a, int b) {
	if (!b) {
		return 1;
	}
	if (b & 1) {
		return mult(a, b_pow(a, b - 1));
	}
	return b_pow(mult(a, a), b >> 1);
}

const int N = 18;
int edge[N], f[N];
map<int, int> dp[1 << N];

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		edge[u] |= 1 << v;
		edge[v] |= 1 << u;
	}
	f[n - 1] = 0;
	for (int i = n - 2; i >= 0; i--) {
		f[i] = f[i + 1] | (1 << (i + 1));
	}
	int all = (1 << n) - 1;	
	dp[0][all] = 1;
	for (int mask = 0; mask < all; mask++) {
		for (auto it : dp[mask]) {
			int B = it.F;
			for (int i = 0; i < n; i++) {
				if ((B >> i) & 1) {
					add(dp[mask | (1 << i)][(B & f[i]) | (edge[i] & (mask ^ all))], it.S);
				}
			}
		}
	}
	cout << mult(mult(dp[all][0], m), b_pow(2, MOD - 2)) << '\n';
}