#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)

typedef long long ll;
using namespace std;

const int MOD = 998244353;
const int N = 2e5 + 99;

int pt(int a, int b) {
	int c = 1;
	while (b) {
		if (b & 1) c = 1LL * c * a % MOD;
		a = 1LL * a * a % MOD;
		b /= 2;
	}
	return c;
}

int n, m, d[N], pr[N], s;
int fac[N], rev[N];

int C(int n, int k) {
	return 1LL * fac[n] * rev[n - k] % MOD * rev[k] % MOD;
}

int solve(int x, int y, int sum, int a) {
	int z = min(a - 1, x);
	if (x < 0 || y < 0) return 0;
	//cout << x << " " << y << " " << sum << " " << a << endl;
	return (fac[x + y + 1] - 1LL * (z + 1) * fac[x] % MOD * fac[y] % MOD * C(n, y) % MOD + MOD) % MOD * rev[x + y + 1] % MOD * sum % MOD;
} 
	

int main() {
	FOR(i, N) {
		if (!i) fac[i] = rev[i] = 1;
		else {
			fac[i] = 1LL * fac[i - 1] * i % MOD;
			rev[i] = pt(fac[i], MOD - 2);
		}
	}
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> n >> m;
	FOR(i, n) cin >> d[i], s = (s + d[i]) % MOD;
	sort(d, d + n);
	FOR(i, n) pr[i] = ((!i ? 0 : pr[i - 1]) + d[i]) % MOD;
	while (m--) {
		int A, B;
		cin >> A >> B;
		int pos = upper_bound(d, d + n, B - 1) - d;
		int cnt = n - pos;
		int a = !pos ? 0 : pr[pos - 1];
		int b = (pr[n - 1] - a + MOD) % MOD;
		cout << (solve(cnt, n - cnt - 1, a, A) + solve(cnt - 1, n - cnt, b, A)) % MOD << endl;
	}
		
		
	return 0;
}