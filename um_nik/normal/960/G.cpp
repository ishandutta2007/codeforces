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
ll Rev(ll x) {
	return bin_pow(x, MOD - 2);
}

const int LOG = 18;
const int N = 1 << LOG;
const int NN = N + 5;
ll W;
ll w[NN];
int rev[NN];
ll f[NN], rf[NN];

void initFFT() {
	W = 2;
	while(true) {
		ll x = W;
		for (int i = 1; i < LOG; i++)
			x = mult(x, x);
		if (x == MOD - 1)
			break;
		W++;
	}
	w[0] = 1;
	for (int i = 1; i < N; i++)
		w[i] = mult(w[i - 1], W);
	for (int mask = 1; mask < N; mask++) {
		int k = 0;
		while(((mask >> k) & 1) == 0) k++;
		rev[mask] = rev[mask ^ (1 << k)] ^ (1 << (LOG - 1 - k));
	}
}

ll F[2][NN];
void FFT(ll* A, int k) {
	int L = 1 << k;
	for (int i = 0; i < L; i++)
		F[0][rev[i] >> (LOG - k)] = A[i];
	int t = 0, nt = 1;
	for (int lvl = 0; lvl < k; lvl++) {
		int len = 1 << lvl;
		for (int st = 0; st < L; st += (len << 1))
			for (int i = 0; i < len; i++) {
				ll ad = mult(F[t][st + len + i], w[i << (LOG - 1 - lvl)]);
				F[nt][st + i] = add(F[t][st + i], ad);
				F[nt][st + len + i] = sub(F[t][st + i], ad);
			}
		swap(t, nt);
	}
	for (int i = 0; i < L; i++)
		A[i] = F[t][i];
}

ll a[NN];
ll b[NN];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int n, A, B;
	scanf("%d%d%d", &n, &A, &B);
	if (A == 0 || B == 0) {
		printf("0\n");
		return 0;
	}
	n--;
	A--;
	B--;
	if (n < A + B) {
		printf("0\n");
		return 0;
	}

	initFFT();
/*
	a[0] = a[1] = a[2] = 1;
	FFT(a, 4);
	for (int i = 0; i < 16; i++)
		a[i] = mult(a[i], a[i]);
	FFT(a, 4);
	reverse(a + 1, a + 16);
	for (int i = 0; i < 16; i++)
		printf("%lld ", a[i]);
	return 0;
*/
	f[0] = 1;
	for (int i = 1; i < N; i++)
		f[i] = mult(f[i - 1], i);
	rf[N - 1] = Rev(f[N - 1]);
	for (int i = N - 1; i > 0; i--)
		rf[i - 1] = mult(rf[i], i);

	for (int i = 0; i < n; i++) {
		a[2 * i] = i;
		a[2 * i + 1] = 1;
	}
	while(n == 0 || (n & (n - 1))) {
		a[2 * n] = 1;
		a[2 * n + 1] = 0;
		n++;
	}
	n *= 2;

	for (int k = 1; (1 << k) < n; k++) {
		ll rn = 1;
		for (int i = 0; i < k + 1; i++) {
			if (rn & 1) rn += MOD;
			rn /= 2;
		}
		int L = 1 << k;
		for (int st = 0; st < n; st += (L << 1)) {
			for (int i = 0; i < L; i++)
				b[i] = a[st + L + i];
			for (int i = L; i < 2 * L; i++)
				a[st + i] = b[i] = 0;
			FFT(a + st, k + 1);
			FFT(b, k + 1);
			for (int i = 0; i < 2 * L; i++)
				a[st + i] = mult(a[st + i], b[i]);
			FFT(a + st, k + 1);
			for (int i = 0; i < 2 * L; i++)
				a[st + i] = mult(a[st + i], rn);
			reverse(a + st + 1, a + st + 2 * L);
		}
	}

	ll ans = a[A + B];
//	printf("%lld\n", ans);
	ans = mult(ans, f[A + B]);
	ans = mult(ans, mult(rf[A], rf[B]));
	printf("%lld\n", ans);

	return 0;
}