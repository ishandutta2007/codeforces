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

const ll MOD = (ll)1e9 + 7;
ll add(ll x, ll y) {
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}
ll sub(ll x, ll y) {
	x -= y;
	if (x < 0) return x + MOD;
	return x;
}
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

const int N = 200200;
ll f[N], rf[N];

ll getC(int n, int k) {
	if (k < 0 || k > n) return 0;
	return mult(f[n], mult(rf[k], rf[n - k]));
}

ll A = 0, B = 0;

ll getS(int n, int k) {
	if (k > n) return 0;
	ll res = 0;
	for (int x = k; x > 0; x--) {
		ll val = mult(getC(k, x), bin_pow(x, n));
		if ((k - x) & 1)
			res = sub(res, val);
		else
			res = add(res, val);
	}
	return mult(rf[k], res);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	f[0] = 1;
	for (int i = 1; i < N; i++)
		f[i] = mult(f[i - 1], i);
	rf[N - 1] = rev(f[N - 1]);
	for (int i = N - 1; i > 0; i--)
		rf[i - 1] = mult(rf[i], i);

	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		ll x;
		scanf("%lld", &x);
		A = add(A, x);
	}

	B = add(getS(n, k), mult(n - 1, getS(n - 1, k)));
	printf("%lld\n", mult(A, B));

	return 0;
}