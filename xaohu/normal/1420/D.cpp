#include <bits/stdc++.h>

using ll = long long;
using namespace std;

const int N = 3e5 + 5;
const int MOD = 998244353;

ll bin_pow(ll a, ll b) {
	if (b == 0) return 1;
	if (b % 2) return a * bin_pow(a, b - 1) % MOD;
	return bin_pow(a * a % MOD, b / 2);
}

int n, k, l, r;
ll fac[N], rev[N];

ll C(int n, int k) {
	if (n < k) return 0;
	return fac[n] * rev[n - k] % MOD * rev[k] % MOD;
}

map <int, int> add, del;

int main() {
	fac[0] = rev[0] = 1;
	for (int i = 1; i < N; ++i) {
		fac[i] = fac[i - 1] * i % MOD;
		rev[i] = bin_pow(fac[i], MOD - 2);
	}
	scanf ("%d%d", &n, &k);
	vector <int> p;
	while (n--) {
		scanf ("%d%d", &l, &r);
		add[l]++;
		del[r + 1]++;
		p.push_back(l);
		p.push_back(r + 1);
	}
	sort(p.begin(), p.end());
	p.erase(unique(p.begin(), p.end()), p.end());
	ll ans = 0;
	int sum = 0;
	for (auto x : p) {
		sum -= del[x];
		for (int i = 1; i <= add[x]; ++i) {
			ans += C(sum, k - 1);
			ans %= MOD;
			sum++;
		}
	}
	printf ("%lld\n", ans);
}