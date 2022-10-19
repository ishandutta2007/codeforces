#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

namespace {
	int add(int x) {return (x >= mod) ? x - mod : x;}
	void Add(int &x, int y) {x = add(x + y);}
	int sub(int x) {return (x < 0) ? x + mod : x;}
	void Sub(int &x, int y) {x = sub(x - y);}
	int Pow(int x, int y = mod - 2) {
		int res = 1;
		for(; y; y >>= 1, x = 1LL * x * x % mod) {
			if(y & 1)  {
				res = 1LL * res * x % mod;
			}
		}
		return res;
	}
}

const int N = 1e6 + 5;

int n, ans, dp[N], fac[N], inv[N];

int C(int x, int y) {
	return 1LL * fac[x] * inv[y] % mod * inv[x - y] % mod;
}

int main() {
	cin >> n;
	fac[0] = 1;
	for(int i = 1; i <= n; ++ i) fac[i] = 1LL * i * fac[i - 1] % mod, inv[i] = Pow(fac[i]);
	ans = fac[n];
	for(int i = 1; i <= n; ++ i) {
		Add(ans, 1LL * (fac[n - i] - 1) * C(n, i) % mod * fac[i] % mod);
	}
	//Sub(ans, n + 1);
	cout << ans << endl;
}