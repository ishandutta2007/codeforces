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

int gcd(int x, int y) {
	return y == 0 ? x : gcd(y, x % y);
}

const int N = 100100;
ll c[(1 << 9) + 5];
ll e[(1 << 6) + 5];
int d[N];
bool g[3][3];
ll a[8];
int b[3];

bool isGoodMask(int mask) {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			g[i][j] = (mask & 1);
			mask >>= 1;
		}
	int p[3];
	for (int i = 0; i < 3; i++)
		p[i] = i;
	do {
		bool ok = true;
		for (int i = 0; i < 3; i++)
			ok &= g[i][p[i]];
		if (ok) return true;
	} while(next_permutation(p, p + 3));
	return false;
}
bool isGoodMask2(int mask) {
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++) {
			g[i][j] = (mask & 1);
			mask >>= 1;
		}
	int p[3];
	for (int i = 0; i < 3; i++)
		p[i] = i;
	do {
		if (g[0][p[0]] && g[0][p[1]] && g[1][p[2]]) return true;
	} while(next_permutation(p, p + 3));
	return false;
}

void precalc() {
	for (int i = 1; i < N; i++)
		for (int j = i; j < N; j += i)
			d[j]++;
	for (int mask = 0; mask < (1 << 9); mask++)
		c[mask] = (ll)isGoodMask(mask);
	for (int mask = 1; mask < (1 << 9); mask++)
		for (int smask = (mask - 1) & mask; smask > 0; smask = (smask - 1) & mask) {
			c[mask] -= c[smask];
		}
	for (int mask = 0; mask < (1 << 6); mask++)
		e[mask] = (ll)isGoodMask2(mask);
	for (int mask = 1; mask < (1 << 6); mask++)
		for (int smask = (mask - 1) & mask; smask > 0; smask = (smask - 1) & mask) {
			e[mask] -= e[smask];
		}
}

ll solve2(int x, int y) {
	return (ll)d[x] * d[y];
}

ll solve3() {
	ll ans = 0;
	for (int mask = 1; mask < (1 << 9); mask++) {
		if (c[mask] == 0) continue;
		ll w = c[mask];
		int nm = mask;
		for (int i = 0; i < 3; i++) {
			w *= a[nm & 7];
			nm >>= 3;
		}
		ans += w;
	}
	return ans;
}

ll solve2() {
	ll ans = 0;
	for (int mask = 1; mask < (1 << 6); mask++) {
		if (e[mask] == 0) continue;
		ll w = e[mask];
		int nm = mask;
		for (int i = 0; i < 2; i++) {
			w *= a[nm & 7];
			nm >>= 3;
		}
		ans += w;
	}
	return ans;
}

ll solve() {
	for (int i = 0; i < 3; i++)
		scanf("%d", &b[i]);
	for (int mask = 1; mask < 8; mask++) {
		int x = 0;
		for (int i = 0; i < 3; i++)
			if ((mask >> i) & 1)
				x = gcd(x, b[i]);
		a[mask] = d[x];
	}
	ll ans = solve3();
	ans += 3 * solve2(); //solve2(gcd(b[0], b[1]), b[2]) + solve2(gcd(b[0], b[2]), b[1]) + solve2(gcd(b[1], b[2]), b[0]));
	ans += 2 * a[7];
	return ans / 6;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	precalc();
	int t;
	scanf("%d", &t);
	while(t--) printf("%lld\n", solve());

	return 0;
}