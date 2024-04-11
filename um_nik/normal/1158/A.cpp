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

const int N = 100100;
int n, m;
ll a[N], b[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	for (int i = 0; i < m; i++)
		scanf("%lld", &b[i]);
	sort(a, a + n);
	sort(b, b + m);
	if (b[0] < a[n - 1]) {
		printf("-1\n");
		return 0;
	}
	ll ans = 0;
	for (int i = 0; i < n; i++)
		ans += a[i];
	ans *= m;
	if (a[n - 1] == b[0]) {
		for (int i = 0; i < m; i++)
			ans += b[i] - a[n - 1];
	} else {
		for (int i = 0; i < m; i++)
			ans += b[i] - a[n - 1];
		ans += a[n - 1] - a[n - 2];
	}
	printf("%lld\n", ans);

	return 0;
}