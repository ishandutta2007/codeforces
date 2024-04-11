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

const ll MOD = (ll)998244353;
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

const int LOG = 12;
const int N = 1 << LOG;
const int NN = N + 5;
ll w[NN];
int binRev[NN];

void initFFT() {
	ll W = 2;
	while(true) {
		ll x = W;
		for (int i = 1; i < LOG; i++)
			x = mult(x, x);
		if (x == MOD - 1) break;
		W++;
	}
	w[0] = 1;
	for (int i = 1; i < N; i++)
		w[i] = mult(w[i - 1], W);
	for (int mask = 1; mask < N; mask++)
		binRev[mask] = (binRev[mask >> 1] >> 1) | ((mask & 1) << (LOG - 1));
}
void FFT(ll* A) {
	for (int i = 0; i < N; i++)
		if (binRev[i] > i)
			swap(A[i], A[binRev[i]]);
	for (int lvl = 0; lvl < LOG; lvl++) {
		int len = 1 << lvl;
		for (int st = 0; st < N; st += len * 2)
			for (int i = 0; i < len; i++) {
				ll x = A[st + i], y = mult(w[i << (LOG - 1 - lvl)], A[st + len + i]);
				A[st + i] = add(x, y);
				A[st + len + i] = sub(x, y);
			}
	}
}

const int M = 2002;
ll C[M][M];
ll f[M], rf[M];
ll prec[M][M];
ll pw[M];
int fenv[3][M];
int n;
int a[M], b[M];
int used[M];
bool used2[M];

void clearFenv() {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < M; j++)
			fenv[i][j] = 0;
}

void addFenv(int k, int r, int dx) {
	for (; r < n; r |= r + 1)
		fenv[k][r] += dx;
}
int getFenv(int k, int r) {
	r--;
	int res = 0;
	for (; r >= 0; r = (r & (r + 1)) - 1)
		res += fenv[k][r];
	return res;
}
int getSum(int k, int l, int r) {
	return getFenv(k, r - 1) - getFenv(k, l - 1);
}

void init() {
	initFFT();
	for (int i = 0; i < M; i++)
		C[i][0] = C[i][i] = 1;
	for (int i = 0; i < M; i++)
		for (int j = 1; j < i; j++)
			C[i][j] = add(C[i - 1][j - 1], C[i - 1][j]);
	f[0] = 1;
	for (int i = 1; i < M; i++)
		f[i] = mult(f[i - 1], i);
	rf[M - 1] = rev(f[M - 1]);
	for (int i = M - 1; i > 0; i--)
		rf[i - 1] = mult(rf[i], i);
	ll aa[NN], bb[NN];
	for (int i = 0; i < N; i++)
		bb[i] = 0;
	for (int i = 0; i < M; i++)
		bb[i] = f[i];
	FFT(bb);
	for (int k = 0; k < M; k++) {
		for (int i = 0; i < N; i++)
			aa[i] = 0;
		for (int i = 0; i <= k; i++) {
			aa[i] = C[k][i];
			if (i & 1)
				aa[i] = sub(0, aa[i]);
		}
		FFT(aa);
		for (int i = 0; i < N; i++)
			aa[i] = mult(aa[i], bb[i]);
		FFT(aa);
		reverse(aa + 1, aa + N);
		ll rn = rev(N);
		for (int i = k; i < M; i++)
			prec[i][k] = mult(rn, aa[i]);
	}
}

ll solve() {
//	cerr << "solve" << endl;
	ll ans = 0;	
	clearFenv();
	for (int i = 0; i < n; i++)
		b[i] = a[i];
	for (int i = 0; i < n; i++) {
		used[i] = 0;
		used2[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		addFenv(0, i, 1);
		addFenv(2, i, 1);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]); a[i]--;
		if (used[b[i]] == 0)
			addFenv(2, b[i], -1);
		used[b[i]]++;
		int all = getFenv(0, a[i]);
		int k = getFenv(2, n);
		int bad = getFenv(2, a[i]);
		if (b[i] < a[i] && !used2[b[i]]) {
			all--;
		}
		//cerr << all << " " << bad << endl;
		ans = add(ans, mult(all - bad, prec[n - i - 1][k]));
		if (bad > 0)
			ans = add(ans, mult(bad, prec[n - i - 1][k - 1]));
		addFenv(0, a[i], -1);
		if (used[a[i]] == 0)
			addFenv(2, a[i], -1);
		used[a[i]]++;
		used2[a[i]] = 1;
	}
	return ans;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	init();
/*
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j <= i; j++)
			eprintf("%lld ", prec[i][j]);
		eprintf("\n");
	}
*/
	ll ans = 0;
	scanf("%d", &n);

	pw[0] = 1;
	for (int i = 1; i <= n; i++)
		pw[i] = mult(pw[i - 1], prec[n][n]);

	clearFenv();
	for (int i = 0; i < n; i++)
		addFenv(0, i, 1);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		a[i]--;
		int s = getFenv(0, a[i]);
		ans = add(ans, mult(s, f[n - i - 1]));
		addFenv(0, a[i], -1);
	}
	ans = mult(ans, pw[n - 1]);
//	cerr << ans << endl;
	for (int it = 1; it < n; it++) {
		ans = add(ans, mult(pw[n - it - 1], solve()));
//		cerr << ans << endl;
	}
	printf("%lld\n", ans);

	return 0;
}