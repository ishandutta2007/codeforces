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
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll INF = (ll)4e18 + 44;
const int N = (int)1e7 + 7;
ull b[N];
ll a[N];
int n;

void read() {
	scanf("%d", &n);
	ll l, r;
	ull x, y, z;
	scanf("%lld%lld%llu%llu%llu", &l, &r, &x, &y, &z);
	scanf("%llu%llu", &b[0], &b[1]);
	for (int i = 2; i < n; i++) {
		b[i] = 0;
		b[i] += b[i - 2] * x;
		b[i] += b[i - 1] * y;
		b[i] += z;
		b[i] &= ((ull)1 << 32) - 1;
	}
	for (int i = 0; i < n; i++)
		a[i] = l + (b[i] % (r - l + 1));
}

void solve() {
	read();
/*
	for (int i = 0; i < n; i++)
		eprintf("%lld ", a[i]);
	eprintf("\n");
*/
	ll ans = INF;
	ll m = INF;
	for (int i = 0; i < n; i++) {
		if (m < a[i]) ans = min(ans, m * a[i]);
		if (a[i] < m) m = a[i];
	}
	reverse(a, a + n);
	for (int i = 0; i < n; i++)
		a[i] *= -1;
	m = INF;
	for (int i = 0; i < n; i++) {
		if (m < a[i]) ans = min(ans, m * a[i]);
		if (a[i] < m) m = a[i];
	}
	if (ans == INF)
		printf("IMPOSSIBLE\n");
	else
		printf("%lld\n", ans);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--) solve();

	return 0;
}