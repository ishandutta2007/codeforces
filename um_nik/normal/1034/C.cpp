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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll gcd(ll x, ll y) {
	return y == 0 ? x : gcd(y, x % y);
}

const ll MOD = (ll)1e9 + 7;
ll add(ll x, ll y) {
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}

const int N = (int)1e6 + 7;
int n;
ll a[N];
int b[N];
int c[N];
int p[N];
ll dp[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);


	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	for (int i = 1; i < n; i++) {
		scanf("%d", &p[i]);
		p[i]--;
	}
	for (int i = n - 1; i > 0; i--)
		a[p[i]] += a[i];
	for (int i = 0; i < n; i++) {
	//	printf("%lld ", a[i]);
		//if (a[0] % a[i] != 0) continue;
		ll z = a[0] / gcd(a[0], a[i]);
		if (z <= n)
			b[z]++;
	}
//	printf("\n");
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j += i)
			c[j] += b[i];
	ll ans = 0;
	dp[1] = 1;
	for (int i = 1; i <= n; i++) {
		if (c[i] != i) continue;
		ans = add(ans, dp[i]);
		for (int j = 2 * i; j <= n; j += i)
			dp[j] = add(dp[j], dp[i]);
	}
	printf("%lld\n", ans);

	return 0;
}