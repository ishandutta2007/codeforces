#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
const int mod = 998244353;

int t, n, A[N], fac[N], inv[N], pr[N], cnt, phi[N], num[N];

namespace {
	int add(int x) {return (x >= mod) ? x - mod : x;}
	int sub(int x) {return (x < 0) ? x + mod : x;}
	void Add(int &x, int y) {x = add(x + y);}
	void Sub(int &x, int y) {x = sub(x - y);}
	int Pow(int x, int y = mod - 2) {
		int res = 1;
		for(; y; y >>= 1, x = 1LL * x * x % mod)
		if(y & 1)
		res = 1LL * res * x % mod;
		return res;
	}
}

bool isp[N];

void pre(int n) {
	fac[0] = 1;
	for(int i = 1; i <= n; ++ i) fac[i] = 1LL * fac[i - 1] * i % mod;
	inv[n] = Pow(fac[n]);
	for(int i = n - 1; i >= 0; -- i) inv[i] = 1LL * inv[i + 1] * (i + 1) % mod;
	memset(isp, 1, sizeof(isp));
	isp[1] = 0; phi[1] = 1;
 	for(int i = 1; i <= n; ++ i) {
		if(isp[i]) {
			pr[++ cnt] = i; phi[i] = i - 1;
		}
		for(int j = 1; j <= cnt && pr[j] * i <= n; ++ j) {
			isp[i * pr[j]] = 0; 
			if(i % pr[j] == 0) {
				phi[i * pr[j]] = phi[i] * pr[j]; break;
			} else phi[i * pr[j]] = phi[i] * phi[pr[j]];
		}
	}
}

int gcd(int x, int y) {
	return (!y) ? x : gcd(y, x % y);
}

void rmain() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++ i) A[i] = 0;
	for(int i = 1, x; i <= n; ++ i) scanf("%d", &x), ++ A[x]; A[n + 1] = 0;
	//A[1] = n / 2, A[2] = n / 2;
	int g = n;
	for(int i = 1; i <= n; ++ i) g = gcd(g, A[i]);
	sort(A + 1, A + n + 1);
	reverse(A + 1, A + n + 1);
	int tot = 0;
	while(A[tot + 1] != 0) ++ tot; // vector 
	if(g == n) {
		puts("1");
		return;
	}
	int sum = 0, cnt = 0;
	for(int i = 1; i <= g; ++ i) {
		if(g % i == 0) {
			int c = fac[n / i], s = 0;
			for(int j = 1; j <= tot; ++ j) num[j] = A[j] / i, c = 1LL * c * inv[num[j]] % mod, 
			Add(s, 1LL * num[j] * (num[j] - 1) % mod);
			Add(cnt, 1LL * c * phi[i] % mod);
			s = 1LL * s * c % mod * inv[n / i] % mod * fac[n / i - 2] % mod;
			Add(sum, 1LL * n * s % mod * phi[i] % mod);
		}
	}
	printf("%d\n", sub(n - 1LL * sum * Pow(cnt) % mod));
}

int main() {
	pre(1000000);
	int t;
	for(cin >> t; t --;) {
		rmain();
	}
}