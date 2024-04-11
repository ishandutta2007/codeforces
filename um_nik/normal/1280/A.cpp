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

const ll MOD = (ll)1e9 + 7;
ll add(ll x, ll y) {
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}
ll mult(ll x, ll y) {
	return (x * y) % MOD;
}

const int N = (int)1e6 + 7;
int a[N];
char s[N];
int n, m;
ll len;

void solve() {
	scanf("%d %s", &m, s);
	n = strlen(s);
	for (int i = 0; i < n; i++)
		a[i] = (int)(s[i] - '0');
	len = n;
	ll z = 0;
	for (int i = 0; i < m; i++) {
		z = a[i] - 1;
		len += z * (len - 1 - i);
		if (n < m) {
			int per = n - i - 1;
			while(n < m && n < len) {
				a[n] = a[n - per];
				n++;
			}
		}
		len %= MOD;
		if (len < 0) len += MOD;
		//eprintf("%lld\n", len);
	}
	printf("%lld\n", len);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--) solve();

	return 0;
}