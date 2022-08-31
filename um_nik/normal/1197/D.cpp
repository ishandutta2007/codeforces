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

const ll INF = (ll)1e18;
const int N = 300300;
const int M = 10;
ll ans = 0;
int n, m;
ll k;
ll b[M];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d%lld", &n, &m, &k);
	for (int i = 0; i < m; i++)
		b[i] = INF;
	b[0] = 0;
	ll bal = 0;
	for (int i = 1; i <= n; i++) {
		ll x;
		scanf("%lld", &x);
		bal += x;
		b[i % m] = min(b[i % m], bal - (i / m) * k);
		for (int r = 0; r < m; r++) {
			ll z = bal - (i / m) * k;
			if (i % m > r) z -= k;
			ans = max(ans, z - b[r]);
		}
	}
	printf("%lld\n", ans);

	return 0;
}