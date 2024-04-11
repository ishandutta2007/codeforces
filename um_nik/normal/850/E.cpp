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

const int M = 20;
const int N = (1 << M) + 7;
char s[N];
int n;
ll a[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	scanf("%s", s);
	for (int i = 0; i < (1 << n); i++)
		a[i] = (int)(s[i] - '0');
	for (int len = 1; len < (1 << n); len <<= 1) {
		for (int st = 0; st < (1 << n); st += (len << 1))
			for (int i = 0; i < len; i++) {
				ll x = a[st + i], y = a[st + len + i];
				a[st + i] = add(x, y);
				a[st + len + i] = sub(x, y);
			}
	}
	for (int mask = 0; mask < (1 << n); mask++)
		a[mask] = mult(a[mask], a[mask]);
	for (int len = 1; len < (1 << n); len <<= 1) {
		for (int st = 0; st < (1 << n); st += (len << 1))
			for (int i = 0; i < len; i++) {
				ll x = a[st + i], y = a[st + len + i];
				a[st + i] = add(x, y);
				a[st + len + i] = sub(x, y);
			}
	}
	ll q = 1;
	for (int i = 0; i < n; i++) {
		if (q & 1) q += MOD;
		q /= 2;
	}
	ll ans = 0;
	for (int mask = 0; mask < (1 << n); mask++) {
		ll x = 1 << n;
		for (int k = 0; k < n; k++)
			if ((mask >> k) & 1)
				x >>= 1;
		ans = add(ans, mult(x, mult(q, a[mask])));
	}
	printf("%lld\n", mult(3, ans));

	return 0;
}