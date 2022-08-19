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
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
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

const int N = 152;
const int M = 2520;
ll dp[2][M][M];
int n;
int T;
int L;
int a[N];
int m;

ll f[M], rf[M];

/*

ll calcVal(int p, ll s) {
	assert(s != 0);
	assert(s != 1);
	ll rs = rev(s);
	ll ss = rev(sub(1, s));
	ll res = 0;
	ll pw = bin_pow(s, p);
	for (int k = 0; k <= p; k++) {
		pw = mult(pw, ss);
		ll cur = mult(rf[k], rf[p - k]);
		res = add(res, mult(cur, pw));
		pw = mult(pw, rs);
	}
	return mult(res, mult(f[p], f[p]));
}
*/

ll calcVal(int p, ll s) {
	assert(s != 0);
	assert(s != 1);
	ll ss = mult(s, rev(sub(1, s)));
	ll res = 0;
	ll pw = rev(sub(1, s));
	for (int k = 0; k <= p; k++) {
		//pw = mult(pw, ss);
		ll cur = mult(rf[k], rf[p - k]);
		res = add(res, mult(cur, pw));
		pw = mult(pw, ss);
	}
	return mult(res, mult(f[p], f[p]));
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	f[0] = 1;
	for (int i = 1; i < M; i++)
		f[i] = mult(f[i - 1], i);
	rf[M - 1] = rev(f[M - 1]);
	for (int i = M - 1; i > 0; i--)
		rf[i - 1] = mult(rf[i], i);

	scanf("%d%d", &n, &T);
	bool sm = true;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		sm &= a[i] <= T;
		L += a[i];
	}
	eprintf("L = %d\n", L);
	if (sm) {
		printf("0\n");
		return 0;
	}
	m = (L + T - 1) / T + 3;
	dp[0][0][0] = 1;
	for (int it = 0; it < n; it++) {
		for (int i = 0; i < m; i++)
			for (int j = 0; j <= n; j++)
				dp[1][i][j] = 0;
		for (int k = 0; k * T < a[it]; k++) {
			ll Q = mult(a[it] - k * T, rev(L));
			if (k == 0) {
				for (int i = 0; i < m; i++)
					for (int j = 0; j <= n; j++)
						dp[1][i][j] = add(dp[1][i][j], dp[0][i][j]);
			} else {
				ll A = bin_pow(Q, k - 1);
				ll B = mult(A, rf[k - 1]);
				A = mult(A, mult(Q, rf[k]));
				if (k & 1) {
					A = sub(0, A);
					B = sub(0, B);
				}
				for (int i = 0; i + k < m; i++)
					for (int j = 0; j <= n; j++) {
						dp[1][i + k][j] = add(dp[1][i + k][j], mult(dp[0][i][j], A));
						dp[1][i + k][j + 1] = add(dp[1][i + k][j + 1], mult(dp[0][i][j], B));
					}
			}
		}
		for (int i = 0; i < m; i++)
			for (int j = 0; j <= n; j++)
				dp[0][i][j] = dp[1][i][j];
	}

	ll ans = 0;
	for (int k = 1; k < m; k++) {
		for (int i = 0; i <= n; i++) {
			ll w = dp[0][k][i];
			if (w == 0) continue;
			assert(i <= k);
			int p = k - i;
			ll s = mult(L - k * T, rev(L));
			ll ww = calcVal(p, s);
			//eprintf("%d %d -- %lld %lld\n", k, i, w, ww);
			ans = add(ans, mult(w, ww));
		}
	}
	printf("%lld\n", sub(0, ans));

	return 0;
}