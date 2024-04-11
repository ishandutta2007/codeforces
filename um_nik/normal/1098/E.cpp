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

int gcd(int x, int y) {
	return y == 0 ? x : gcd(y, x % y);
}

const int N = 100010;
const int M = 50004;
const int LOG = 16;
int sparse[LOG][M];
ll a[N];
ll pref[N];
ll prefSum[N];
int n;

ll solveTriang(ll A, ll B, ll C) {
//	eprintf("%lld %lld %lld\n", A, B, C);
	if (C < 0) return 0;
	if (A > B) swap(A, B);
	ll p = C / B;
	ll k = B / A;
	ll d = (C - p * B) / A;
	return solveTriang(B - k * A, A, C - A * (k * p + d + 1)) + (p + 1) * (d + 1) + k * p * (p + 1) / 2;
}

ll solve2(ll A, ll CA, ll B, ll CB, ll C) {
	if (C >= A * CA + B * CB) return CA * CB;
	if (C < 0) return 0;
//	C++;
	return solveTriang(A, B, C) - solveTriang(A, B, C - A * CA) - solveTriang(A, B, C - B * CB) + solveTriang(A, B, C - A * CA - B * CB);
}

ll solve(ll B) {
	ll ans = 0;
	for (int i = 1; i < n; i++)
		if (a[i] > 0) {
			ll L = min(a[i], B / i);
			ans += L * (a[i] + 1) - L * (L + 1) / 2;
		}
	int r = 1;
	for (int l = 1; l < n; l++) {
		if (a[l] == 0) continue;
		if (r > l)
			ans += a[l] * (pref[r - 1] - pref[l]);
		while(r < n && prefSum[r] - prefSum[l] <= B) {
			if (r > l && a[r] > 0)
				ans += solve2(l, a[l], r, a[r], B - (prefSum[r - 1] - prefSum[l]) - l - r);
			r++;
		}
		if (r == n) continue;
		ans += solve2(l, a[l], r, a[r], B - (prefSum[r - 1] - prefSum[l]) - l - r);
	}
	return ans;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &sparse[0][i]);
	for (int k = 0; k < LOG - 1; k++)
		for (int i = 0; i < n; i++)
			sparse[k + 1][i] = gcd(sparse[k][i], (i + (1 << k) < n ? sparse[k][i + (1 << k)] : 0));
	for (int l = 0; l < n; l++) {
		int cur = 0;
		int r = l;
		while(r < n) {
			cur = gcd(cur, sparse[0][r]);
			int rr = r;
			for (int k = LOG - 1; rr < n && k >= 0; k--) {
				int x = sparse[k][rr];
				if (x % cur == 0) {
					rr += (1 << k);
				}
			}
			rr = min(n, rr);
			a[cur] += rr - r;
			r = rr;
		}
	}
/*
	for (int i = 1; i <= 20; i++)
		eprintf("%lld ", a[i]);
	eprintf("\n");
*/
	ll m = (ll)n * (n + 1) / 2;
	m = m * (m + 1) / 2;
	m = (m + 1) / 2;
//	eprintf("m = %lld\n", m);
	n = N;
	for (int i = 1; i < n; i++) {
		pref[i] = pref[i - 1] + a[i];
		prefSum[i] = prefSum[i - 1] + a[i] * i;
	}
	ll l = -1, r = prefSum[n - 1];
	while(r - l > 1) {
		ll x = (l + r) / 2;
		if (solve(x) >= m)
			r = x;
		else
			l = x;
	}
	printf("%lld\n", r);

	return 0;
}