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

const int MOD = 998244353;
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
int bin_pow(int x, ll p) {
	if (p == 0) return 1;
	if (p & 1) return mult(x, bin_pow(x, p - 1));
	return bin_pow(mult(x, x), p / 2);
}
int rev(int x) {
	return bin_pow(x, MOD - 2);
}

const int N = (int)2e6 + 7;
int f[N], rf[N];

int getC(int n, int k) {
	if (k < 0 || k > n) return 0;
	return mult(f[n], mult(rf[k], rf[n - k]));
}

int solve(int n, int m) {
	int ans = mult(sub(bin_pow(3, m), 3), bin_pow(3, (ll)n * (n - m)));
	ans = add(ans, mult(3, bin_pow(sub(bin_pow(3, n - m), 1), n)));
	return ans;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	f[0] = 1;
	for (int i = 1; i < N; i++)
		f[i] = mult(f[i - 1], i);
	rf[N - 1] = rev(f[N - 1]);
	for (int i = N - 1; i > 0; i--)
		rf[i - 1] = mult(rf[i], i);

	int n;
	scanf("%d", &n);

	int ans = 0;
	for (int m = 1; m <= n; m++) {
		ans = add(ans, mult(mult(getC(n, m), bin_pow(3, m)), bin_pow(sub(bin_pow(3, n), 3), n - m)));
	}

	for (int m = 1; m <= n; m++) {
		if (m & 1)
			ans = add(ans, mult(getC(n, m), solve(n, m)));
		else
			ans = sub(ans, mult(getC(n, m), solve(n, m)));
	}

	printf("%d\n", ans);

	return 0;
}