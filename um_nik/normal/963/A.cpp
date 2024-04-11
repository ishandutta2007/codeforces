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

const ll MOD = (ll)1e9 + 9;
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

const int N = 100100;
char s[N];
ll A, B;
ll ans;
int n, k;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%lld%lld%d", &n, &A, &B, &k);
	scanf("%s", s);
	ll cur = bin_pow(A, n);
	ll C = mult(B, rev(A));
	for (int i = 0; i < k; i++) {
		if (s[i] == '+')
			ans = add(ans, cur);
		else
			ans = sub(ans, cur);
		cur = mult(cur, C);
	}
	C = bin_pow(C, k);
	n++;
	n /= k;

	if (C == 1) {
		ans = mult(ans, n);
	} else {
		ans = mult(ans, sub(bin_pow(C, n), 1));
		ans = mult(ans, rev(sub(C, 1)));
	}
	printf("%lld\n", ans);

	return 0;
}