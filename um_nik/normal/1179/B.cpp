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

const int N = (int)1e6 + 5;
pii a[N];
pii b[N];
int sz;
int n, m;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int x = 0; x < n; x++)
		for (int y = 0; y < m; y++)
			a[sz++] = mp(x + y, x);
	sort(a, a + sz);
	for (int i = 0; i < sz; i++) {
		int x = a[i].second;
		int y = a[i].first - x;
		a[i] = mp(x, y);
	}
	int l = 0, r = sz - 1;
	sz = 0;
	while(l <= r) {
		b[sz++] = a[l++];
		if (l <= r) b[sz++] = a[r--];
	}
	/*
	set<pii> setik;
	for (int i = 1; i < sz; i++) {
		int x = b[i].first - b[i - 1].first, y = b[i].second - b[i - 1].second;
		setik.insert(mp(x, y));
	}
	if ((int)setik.size() != sz - 1) throw;
	*/
	for (int i = 0; i < sz; i++)
		printf("%d %d\n", b[i].first + 1, b[i].second + 1);
	return 0;
}