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
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__);fflush(stderr);
#else
	#define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

double startTime;
double getCurrentTime() {
	return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}


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

int popcount(ll x) {
	return __builtin_popcountll(x);
}

const int N = 55;
const int M = (1 << 15) + 3;
ll b[N];
ll ans[N];
int id[N];
ll c[N];
ll pwAll = 1;
ll A[N][M], B[N][M], C[N][M];

int main()
{
	startTime = (double)clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
		b[i] = -1;
	while(n--) {
		ll x;
		scanf("%lld", &x);
		for (int i = 0; i < m; i++) {
			if (((x >> i) & 1) == 0) continue;
			if (b[i] == -1) {
				b[i] = x;
				break;
			} else {
				x ^= b[i];
			}
		}
		if (x == 0) pwAll = add(pwAll, pwAll);
	}
	n = 0;
	for (int i = 0; i < m; i++) {
		if (b[i] != -1) {
			id[i] = n++;
		}
	}
	for (int i = 0; i < m; i++) {
		if (b[i] == -1) {
			id[i] = n++;
		}
	}
	n = 0;
	for (int i = 0; i < m; i++) {
		if (b[i] != -1) {
			c[n] = 0;
			for (int j = 0; j < m; j++)
				if ((b[i] >> j) & 1)
					c[n] |= 1LL << id[j];
			n++;
		}
	}
	for (int i = n - 1; i >= 0; i--)
		for (int j = i - 1; j >= 0; j--) {
			if ((c[j] >> i) & 1)
				c[j] ^= c[i];
		}

//	for (int i = 0; i < n; i++)
//		printf("%lld\n", c[i]);

	if (n <= 20) {
		for (int mask = 0; mask < (1 << n); mask++) {
			ll x = 0;
			for (int i = 0; i < n; i++)
				if ((mask >> i) & 1)
					x ^= c[i];
			ans[popcount(x)]++;
		}
	} else {
		int n1 = n / 2;
		for (int mask = 0; mask < (1 << n1); mask++) {
			ll x = 0;
			for (int i = 0; i < n1; i++)
				if ((mask >> i) & 1)
					x ^= c[i];
			int z = popcount(mask);
			x >>= n;
			A[z][x] = add(A[z][x], 1);
		}
		for (int mask = 0; mask < (1 << (n - n1)); mask++) {
			ll x = 0;
			for (int i = 0; i < n - n1; i++)
				if ((mask >> i) & 1)
					x ^= c[i + n1];
			int z = popcount(mask);
			x >>= n;
			B[z][x] = add(B[z][x], 1);
		}
		int w = m - n;
		/*
		for (int z = 0; z <= n; z++) {
			for (int mask = 0; mask < (1 << w); mask++)
				printf("A[%d][%d] = %lld\nB[%d][%d] = %lld\n", z, mask, A[z][mask], z, mask, B[z][mask]);
		}
		*/
		for (int z = 0; z <= n - n1; z++) {
			for (int k = 0; k < w; k++) {
				for (int mask = 0; mask < (1 << w); mask++) {
					if ((mask >> k) & 1) continue;
					ll x = A[z][mask], y = A[z][mask ^ (1 << k)];
					A[z][mask] = add(x, y);
					A[z][mask ^ (1 << k)] = sub(x, y);
					x = B[z][mask]; y = B[z][mask ^ (1 << k)];
					B[z][mask] = add(x, y);
					B[z][mask ^ (1 << k)] = sub(x, y);
				}
			}
		}
		for (int z = 0; z <= n; z++)
			for (int p = 0; p <= z; p++)
				for (int mask = 0; mask < (1 << w); mask++)
					C[z][mask] = add(C[z][mask], mult(A[p][mask], B[z - p][mask]));
		ll rr = rev(1 << w);
		for (int z = 0; z <= n; z++) {
			for (int k = 0; k < w; k++) {
				for (int mask = 0; mask < (1 << w); mask++) {
					if ((mask >> k) & 1) continue;
					ll x = C[z][mask], y = C[z][mask ^ (1 << k)];
					C[z][mask] = add(x, y);
					C[z][mask ^ (1 << k)] = sub(x, y);
				}
			}
			//for (int mask = 0; mask < (1 << w); mask++)
			//	printf("C[%d][%d] = %lld\n", z, mask, C[z][mask]);
			for (int mask = 0; mask < (1 << w); mask++) {
				ll r = mult(C[z][mask], rr);
				int q = z + popcount(mask);
				ans[q] = add(ans[q], r);
			}
		}
	}

	for (int i = 0; i <= m; i++) {
		ans[i] %= MOD;
		printf("%lld ", mult(ans[i], pwAll));
	}
	printf("\n");

	return 0;
}