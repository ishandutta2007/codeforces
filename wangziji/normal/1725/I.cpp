#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10, mod = 998244353;
int n, fa[N], sz[N];
int main() {
// 	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	iota(fa + 1, fa + n + 1, 1);
	fill(sz + 1, sz + n + 1, 1);
	int ans = 1;
	function<int(int)> find = [&] (int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);};
	for(int i = 1; i < n; i ++) {
		int u, v;
		cin >> u >> v;
		int x = find(u), y = find(v);
		ans = 1ll * ans * sz[x] % mod * sz[y] % mod;
		// ans = 1ll * ans * sz[x] % mod * sz[y] % mod;
		ans = 1ll * ans * (2 * i - 1) % mod * sz[x] % mod * sz[y] % mod;
		fa[x] = y, sz[y] += sz[x];
	}
	cout << ans << '\n';
	return 0;
}