#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
#define int ll

void add(int &a, int b, int mod) {
	a += b;
	if (a >= mod) {
		a -= mod;
	}
}

int mult(int a, int b, int mod) {
	return (a * 1ll * b) % mod;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, mod;
	cin >> n >> mod;
	vector<int> f(n + 1);
	f[0] = 1;
	for (int i = 1; i <= n; i++) {
		f[i] = mult(f[i - 1], i % mod, mod);
	}
	int ans = 0;
	for (int len = 1; len <= n; len++) {
		int cur = mult((n - len + 1) % mod, (n - len + 1) % mod, mod);
		cur = mult(cur, f[len], mod);
		cur = mult(cur, f[n - len], mod);
		add(ans, cur, mod);
	}
	cout << ans << '\n';
}