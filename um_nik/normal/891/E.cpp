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

const ll MOD = (ll)1e9 + 7;
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

const int N = 5050;
ll a[N];
ll dp[N];
int n;
ll ans[N];
ll k;


int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%lld", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);

	ll mulk = 1;
	for (int i = 0; i < n; i++) {
		mulk = mult(mulk, k - i);
		if (mulk == 0) break;
		ans[n - 1 - i] = mult(mulk, bin_pow(n, k - i - 1));
		if (i % 2 == 1) ans[n - 1 - i] = sub(0, ans[n - 1 - i]);
	}

	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j > 0; j--)
			dp[j] = add(dp[j], mult(dp[j - 1], a[i]));
	}

	ll ANS = 0;
	for (int i = 0; i < n; i++)
		ANS = add(ANS, mult(dp[i], ans[i]));
	ANS = mult(ANS, bin_pow(rev(n), k));
	printf("%lld\n", ANS);

	return 0;
}