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

const int N = (int)1e6 + 7;
ll f[N], rf[N];
ll pw1[N], pw2[N];
int n, m;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	rf[0] = rf[1] = 1;
	for (ll x = 2; x < N; x++)
		rf[x] = sub(0, mult(MOD / x, rf[MOD % x]));
	for (int i = 2; i < N; i++)
		rf[i] = mult(rf[i - 1], rf[i]);
	f[0] = 1;
	for (int i = 1; i < N; i++)
		f[i] = mult(f[i - 1], i);

	scanf("%d%d", &n, &m);

	pw1[0] = pw2[0] = 1;
	for (int i = 1; i < N; i++) {
		pw1[i] = mult(pw1[i - 1], n);
		pw2[i] = mult(pw2[i - 1], m);
	}

	ll ans = 0;
	for (int k = 1; k < n - 1 && k <= m; k++) {
		ll cur = k + 1;
		cur = mult(cur, pw1[n - k - 2]);
		cur = mult(cur, f[n - 2]);
		cur = mult(cur, rf[n - k - 1]);
		cur = mult(cur, f[m - 1]);
		cur = mult(cur, rf[k - 1]);
		cur = mult(cur, rf[m - k]);
		cur = mult(cur, pw2[n - 1 - k]);
		ans = add(ans, cur);
	}
	if (n - 1 <= m) {
		ll cur = f[n - 2];
		cur = mult(cur, f[m - 1]);
		cur = mult(cur, rf[n - 2]);
		cur = mult(cur, rf[m - n + 1]);
		ans = add(ans, cur);
	}
	printf("%lld\n", ans);

	return 0;
}