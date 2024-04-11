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

const int MAG = 100;
const int LOG = 15;
//const int LOG = 5;
const int N = 1 << LOG;
const int NN = N + 5;
ll a[NN], aa[NN];
ll F[NN], G[NN];
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
		binRev[mask] = (binRev[mask >> 1] >> 1) ^ ((mask & 1) << (LOG - 1));
}

void FFT(ll* A, int k) {
	int L = 1 << k;
	for (int i = 0; i < L; i++) {
		int x = binRev[i] >> (LOG - k);
		if (i < x) swap(A[i], A[x]);
	}
	for (int lvl = 0; lvl < k; lvl++) {
		int len = 1 << lvl;
		for (int st = 0; st < L; st += (len << 1))
			for (int i = 0; i < len; i++) {
				ll x = A[st + i], y = mult(A[st + len + i], w[i << (LOG - 1 - lvl)]);
				A[st + i] = add(x, y);
				A[st + len + i] = sub(x, y);
			}
	}
}

vector<ll> multPoly(vector<ll> A, vector<ll> B) {
	int sz = (int)A.size() + (int)B.size() - 1;
	int k = 0;
	while((1 << k) < sz) k++;
	sz = 1 << k;
	for (int i = 0; i < sz; i++)
		F[i] = G[i] = 0;
	for (int i = 0; i < (int)A.size(); i++)
		F[i] = A[i];
	for (int i = 0; i < (int)B.size(); i++)
		G[i] = B[i];
	FFT(F, k);
	FFT(G, k);
	for (int i = 0; i < sz; i++)
		F[i] = mult(F[i], G[i]);
	FFT(F, k);
	reverse(F + 1, F + sz);
	ll rn = rev(sz);
	for (int i = 0; i < sz; i++)
		F[i] = mult(F[i], rn);
	A.resize(sz);
	for (int i = 0; i < sz; i++)
		A[i] = F[i];
	while(!A.empty() && A.back() == 0) A.pop_back();
	return A;
}

vector<ll> solve(vector<ll> b) {
	int sz = (int)b.size();
//	eprintf("solve %d\n", sz);
	if (sz < MAG) {
		vector<ll> c;
		c.resize(sz + 1);
		for (int i = 0; i <= sz; i++)
			c[i] = 0;
		c[0] = 1;
		for (int i = 0; i < sz; i++) {
			ll x = b[i];
			for (int j = i; j >= 0; j--)
				c[j + 1] = (c[j + 1] * x + c[j]) % MOD;
			c[0] = (c[0] * x) % MOD;
		}
		return c;
	}
	vector<ll> b1, b2;
	for (int i = 0; i < sz; i++) {
		if (i & 1)
			b1.push_back(b[i]);
		else
			b2.push_back(b[i]);
	}
	return multPoly(solve(b1), solve(b2));
}

void solve(int n, int k) {
	for (int i = 0; i < n; i++)
		a[i] = aa[i];
	int t;
	ll q;
	scanf("%d%lld", &t, &q);
	if (t == 1) {
		int p;
		ll d;
		scanf("%d%lld", &p, &d);
		p--;
		a[p] = d;
	} else {
		int l, r;
		ll d;
		scanf("%d%d%lld", &l, &r, &d);
		l--;
		for (int i = l; i < r; i++)
			a[i] += d;
	}
	for (int i = 0; i < n; i++) {
		a[i] = (q - a[i]) % MOD;
		if (a[i] < 0) a[i] += MOD;
	}
	vector<ll> z;
	z.resize(n);
	for (int i = 0; i < n; i++)
		z[i] = a[i];
	z = solve(z);
	printf("%lld\n", z[n - k]);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	initFFT();
/*
	for (int i = 0; i < 4; i++)
		b[i] = 1;
	FFT(b, 4);
	for (int i = 0; i < 16; i++)
		b[i] = mult(b[i], b[i]);
	FFT(b, 4);
	reverse(b + 1, b + 16);
	for (int i = 0; i < 16; i++)
		eprintf("%lld ", b[i]);
	return 0;
*/
	int n, k, q;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%lld", &aa[i]);
	scanf("%d", &q);
	while(q--) solve(n, k);

	return 0;
}