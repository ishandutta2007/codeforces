#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define gao(x) cerr << #x << " " << x << "\n"
#define pb push_back
#define sz(x) (int)x.size()
#define fi first
#define se second
#define ll long long
 
using namespace std;

const int M = 1e6 + 50;
const int MOD = 1e9 + 7;

ll bin_pow(ll a, ll b) {
	ll c = 1;
	while(b) {
		if(b & 1) c = c * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return c;
}

ll fac[M], rev[M];

ll C(int n, int k) {
	return fac[n] * rev[n - k] % MOD * rev[k] % MOD;
}

void factorials() {
	fac[0] = 1;
	for (int i = 1; i < M; ++i)
		fac[i] = fac[i - 1] * i % MOD;
	rev[M - 1] = bin_pow(fac[M - 1], MOD - 2);
	for (int i = M - 1; 0 < i; --i)
		rev[i - 1] = rev[i] * i % MOD;
}

void solve() {
	int n, k;
	cin >> n >> k;
	ll ans = 1;
	ll suf = 1;
	rep(i, 1, n) {
		ll rem = n - (i + 1ll * (i - 1) * (k - 1));
		if (rem < 0) continue;
		suf = suf * bin_pow(n - i + 1, MOD - 2) % MOD;
		ans = (ans + C(rem + i, i) * fac[i] % MOD * suf % MOD) % MOD;
	}
	cout << ans << "\n";
}

int main() {
	factorials();
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int T;
	cin >> T;
	while (T--)
		solve();
	return 0;
}