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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
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
int n, k;
pll a[N];
ll c[N];
bool used[N];
ll l[N], r[N];
ll ANS;

void precalc() {
	k--;
	for (int ll = 1; ll <= n; ll++) {
		c[ll] = add(c[ll - 1], (ll - 1) / k);
	}
}

ll solve(int v) {
	used[v] = 1;
	ll L = 0, R = 0;
	if (v > 0 && used[v - 1])
		L = v - l[v - 1];
	if (v + 1 < n && used[v + 1])
		R = r[v + 1] - v;
	r[v - L] = v + R;
	l[v + R] = v - L;
	return sub(c[L + R + 1], add(c[L], c[R]));
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &k);
	precalc();
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i].first);
		a[i].second = i;
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++)
		ANS = add(ANS, mult(a[i].first, solve(a[i].second)));
	printf("%lld\n", ANS);

	return 0;
}