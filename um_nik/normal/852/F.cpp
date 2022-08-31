#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

ll MOD;
ll mult(ll x, ll y) {
	return (x * y) % MOD;
}
ll bin_pow(ll x, ll p) {
	if (p == 0) return 1;
	if (p & 1) return mult(x, bin_pow(x, p - 1));
	return bin_pow(mult(x, x), p / 2);
}
ll rev(ll x) {
	return bin_pow(x, MOD - 2);
}

const int N = (int)1e6 + 200;
ll f[N], rf[N], p[N];
ll ans[N];
ll b[N];

ll getC(int n, int k) {
	if (k < 0 || k > n) return 0;
	return mult(f[n], mult(rf[k], rf[n - k]));
}

bool check(int n, int m, ll a, ll Q) {
	for (int i = 0; i < n; i++)
		b[i] = a % Q;
	while(m--) {
		for (int i = 0; i < n - 1; i++)
			b[i] = (b[i] * b[i + 1]) % Q;
	}
	for (int i = 0; i < n; i++)
		if (ans[i] != b[i])
			return false;
	return true;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int n, m;
	ll a, Q;
	scanf("%d%d%lld%lld", &n, &m, &a, &Q);
	m++;
	MOD = 0;
	ll X = 1;
	do {
		p[MOD] = X;
		X = (X * a) % Q;
		MOD++;
	} while(X != 1);
	p[MOD] = 1;

	f[0] = 1;
	for (int i = 1; i < MOD; i++)
		f[i] = mult(f[i - 1], i);
	rf[MOD - 1] = rev(f[MOD - 1]);
	for (int i = MOD - 1; i > 0; i--)
		rf[i - 1] = mult(rf[i], i);
	f[MOD] = 0;

	ans[0] = a;
	ans[1] = p[m];
	for (int i = 2; i < n; i++) {
		ans[i] = (ans[i - 2] * p[getC(m, i)]) % Q;
	}
	reverse(ans, ans + n);
/*
	if (!check(n, m - 1, a, Q)) {
		printf("BAD\n");
		for (int i = 0; i < n; i++)
			printf("%lld ", ans[i]);
		printf("\n");
		for (int i = 0; i < n; i++)
			printf("%lld ", b[i]);
		printf("\n");
		return 0;
	}
*/
	for (int i = 0; i < n; i++)
		printf("%lld ", ans[i]);
	printf("\n");

	return 0;
}