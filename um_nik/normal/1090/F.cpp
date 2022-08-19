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

ll query(int x, int y, int z) {
	printf("? %d %d %d\n", x + 1, y + 1, z + 1);
	fflush(stdout);
	ll a;
	scanf("%lld", &a);
	return a;
}

const int N = 1020;
int n;
ll t[6][6][6];
ll ans[N];
pli a[6];

ll mget(int x, int y, int z) {
	if (x > y) swap(x, y);
	if (y > z) swap(y, z);
	if (x > y) swap(x, y);
	return t[x][y][z];
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);

	for (int i = 0; i < 5; i++)
		for (int j = i + 1; j < 5; j++)
			for (int k = j + 1; k < 5; k++) {
				t[i][j][k] = query(i, j, k);
				a[i].first += t[i][j][k];
				a[j].first += t[i][j][k];
				a[k].first += t[i][j][k];
			}
	for (int i = 0; i < 5; i++)
		a[i].second = i;
	sort(a, a + 5);
	int p1 = a[0].second, p2 = a[1].second, p3 = a[2].second, p4 = a[3].second, p5 = a[4].second;
	ll w13 = mget(p1, p2, p3);
	ll w14 = mget(p1, p2, p4);
	ll w15 = mget(p1, p2, p5);
	ll w25 = mget(p2, p3, p5);
	ll w35 = mget(p3, p4, p5);

	ll s = w13 + w15 + w35;
	if (s & 1) throw;
	s /= 2;

	a[0].first = s - w35;
	a[2].first = s - w15;
	a[4].first = s - w13;
	a[1].first = w25 - a[4].first;
	a[3].first = w14 - a[0].first;

	for (int i = 0; i < 5; i++)
		ans[a[i].second] = a[i].first;

	for (int i = 5; i < n; i++) {
		ll x = query(a[0].second, a[1].second, i);
		ll y = query(a[3].second, a[4].second, i);
		if (x < a[0].first + a[1].first) {
			ans[i] = x - a[1].first;
		} else if (x > a[0].first + a[1].first) {
			ans[i] = x - a[0].first;
		} else if (y < a[3].first + a[4].first) {
			ans[i] = y - a[4].first;
		} else if (y > a[3].first + a[4].first) {
			ans[i] = y - a[3].first;
		} else if (a[1].first == a[3].first) {
			ans[i] = a[1].first;
		} else throw;
	}

	printf("!");
	for (int i = 0; i < n; i++)
		printf(" %lld", ans[i]);
	printf("\n");
	fflush(stdout);

	return 0;
}