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
ll a[N];
int n, m;
ll ans[N][3];
int ansSz;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int v, u;
		ll w;
		scanf("%d%d%lld", &v, &u, &w);
		v--;u--;
		a[v] -= w;
		a[u] += w;
	}
	int p1 = 0, p2 = 0;
	while(true) {
		while(p1 < n && a[p1] <= 0) p1++;
		while(p2 < n && a[p2] >= 0) p2++;
		if (p1 >= n) {
			if (p2 < n) throw;
			break;
		}
		ll x = min(a[p1], -a[p2]);
		ans[ansSz][0] = p2 + 1;
		ans[ansSz][1] = p1 + 1;
		ans[ansSz][2] = x;
		ansSz++;
		a[p1] -= x;
		a[p2] += x;
	}
	printf("%d\n", ansSz);
	for (int i = 0; i < ansSz; i++)
		printf("%lld %lld %lld\n", ans[i][0], ans[i][1], ans[i][2]);

	return 0;
}