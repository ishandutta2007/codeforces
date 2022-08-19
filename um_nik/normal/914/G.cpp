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

const int MOD = (int)1e9 + 7;
int add(int x, int y) {
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}
int sub(int x, int y) {
	x -= y;
	if (x < 0) return x + MOD;
	return x;
}
int mult(int x, int y) {
	return ((ll)x * y) % MOD;
}
int bin_pow(int x, int p) {
	if (p == 0) return 1;
	if (p & 1) return mult(x, bin_pow(x, p - 1));
	return bin_pow(mult(x, x), p / 2);
}
int rev(int x) {
	return bin_pow(x, MOD - 2);
}

const int K = 17;
const int N = (1 << K);
const int NN = N + 7;
int a[NN];
int b[NN];
int c[NN];
int f[NN];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	f[0] = 0;
	f[1] = 1;
	for (int i = 2; i < N; i++)
		f[i] = add(f[i - 1], f[i - 2]);

	int n;
	scanf("%d", &n);
	while(n--) {
		int x;
		scanf("%d", &x);
		a[x]++;
	}
	for (int mask = 0; mask < N; mask++) {
		b[mask] = mult(a[mask], a[0]);
		for (int nmask = mask; nmask > 0; nmask = (nmask - 1) & mask)
			b[mask] = add(b[mask], mult(a[nmask], a[mask ^ nmask]));
	}
	for (int mask = 0; mask < N; mask++)
		c[mask] = a[mask];
	for (int k = 0; k < K; k++) {
		for (int mask = 0; mask < N; mask++) {
			if ((mask >> k) & 1) continue;
			int nmask = mask ^ (1 << k);
			int x = add(c[mask], c[nmask]);
			int y = sub(c[mask], c[nmask]);
			c[mask] = x;
			c[nmask] = y;
		}
	}
	for (int mask = 0; mask < N; mask++)
		c[mask] = mult(c[mask], c[mask]);
	for (int k = 0; k < K; k++) {
		for (int mask = 0; mask < N; mask++) {
			if ((mask >> k) & 1) continue;
			int nmask = mask ^ (1 << k);
			int x = add(c[mask], c[nmask]);
			int y = sub(c[mask], c[nmask]);
			c[mask] = x;
			c[nmask] = y;
		}
	}
	int rN = rev(N);
	for (int mask = 0; mask < N; mask++)
		c[mask] = mult(c[mask], rN);
/*
	for (int mask = 0; mask < 8; mask++) {
		printf("%d : %d %d %d\n", mask, a[mask], b[mask], c[mask]);
	}
*/
	for (int mask = 0; mask < N; mask++) {
		a[mask] = mult(a[mask], f[mask]);
		b[mask] = mult(b[mask], f[mask]);
		c[mask] = mult(c[mask], f[mask]);
	}

	for (int k = 0; k < K; k++) {
		for (int mask = 0; mask < N; mask++) {
			if ((mask >> k) & 1) continue;
			a[mask] = add(a[mask], a[mask ^ (1 << k)]);
			b[mask] = add(b[mask], b[mask ^ (1 << k)]);
			c[mask] = add(c[mask], c[mask ^ (1 << k)]);
		}
	}
	for (int mask = 0; mask < N; mask++)
		a[mask] = mult(a[mask], mult(b[mask], c[mask]));
	for (int k = 0; k < K; k++) {
		for (int mask = 0; mask < N; mask++) {
			if ((mask >> k) & 1) continue;
			a[mask] = sub(a[mask], a[mask ^ (1 << k)]);
		}
	}
	int ans = 0;
	for (int mask = 1; mask < N; mask <<= 1)
		ans = add(ans, a[mask]);
	printf("%d\n", ans);

	return 0;
}