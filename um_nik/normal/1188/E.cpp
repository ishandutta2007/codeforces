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
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll MOD = 998244353;
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

const int N = (int)2e6 + 3;
int k;
ll f[N], rf[N];

ll getC(int n, int m) {
	if (m < 0 || m > n) return 0;
	return mult(f[n], mult(rf[m], rf[n - m]));
}

int a[N], b[N];

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

	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		int x;
		scanf("%d", &x);
		a[x]++;
	}
	int m = k;
	ll ans = 1;
	int sum = 0;
	for (int i = 0;; i++) {
		m -= a[i];
		sum += a[i] + b[i];
		b[i + k] += a[i] + b[i];
		if (sum > i + 1) break;
		if (m == 0) break;
		int S = i + 1 - sum;
		ans = add(ans, sub(getC(S + k - 1, S), getC(S - m + k - 1, S - m)));
	}
	printf("%lld\n", ans);

	return 0;
}