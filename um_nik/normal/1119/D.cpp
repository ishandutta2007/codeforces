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

const int N = 200200;
int n, q;
int m;
pli ev[N];
ll a[N];
ll ans[N];
ll res1, res2;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	sort(a, a + n);
	for (int i = 0; i < n - 1; i++)
		ev[m++] = mp(a[i + 1] - a[i], -1);
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		ll l, r;
		scanf("%lld%lld", &l, &r);
		r = r - l + 1;
		ev[m++] = mp(r, i);
	}
	res1 = n, res2 = 0;
	sort(ev, ev + m);
	for (int i = 0; i < m; i++) {
		if (ev[i].second == -1) {
			res1--;
			res2 += ev[i].first;
		} else {
			ans[ev[i].second] = res1 * ev[i].first + res2;
		}
	}
	for (int i = 0; i < q; i++)
		printf("%lld ", ans[i]);
	printf("\n");
	return 0;
}