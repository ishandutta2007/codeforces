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
set<int> a[N];
int n, m;
pii b[N];
pii c[N];

void solve(int S, int L, int k) {
	int x = -1;
	while(k > 0) {
		auto itL = a[L].upper_bound(x);
		if (itL == a[L].end()) throw;
		int y = *itL;
		auto itS = a[S].upper_bound(x);
		while(itS != a[S].end() && *itS < y) {
			itS++;
		}
		if (itS == a[S].end() || *itS > y) {
			k--;
			printf("%d %d %d\n", L + 1, S + 1, y);
			a[S].insert(y);
			a[L].erase(y);
			x = y;
		} else
			x = y;
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	m = 0;
	for (int i = 0; i < n; i++) {
		int k;
		scanf("%d", &k);
		b[i] = mp(k, i);
		m += k;
		while(k--) {
			int x;
			scanf("%d", &x);
			a[i].insert(x);
		}
	}
	sort(b, b + n);
	reverse(b, b + n);
	for (int i = 0; i < n; i++) {
		int z = m / n;
		if (i < m % n) z++;
		c[i] = mp(b[i].first - z, b[i].second);
	}
	sort(c, c + n);
	int res = 0;
	for (int i = 0; i < n; i++)
		if (c[i].first > 0) res += c[i].first;
	printf("%d\n", res);
	int L = 0, R = n - 1;
	while(L < R) {
		while(L < R && c[L].first == 0) L++;
		while(L < R && c[R].first == 0) R--;
		if (L >= R) break;
		int z = min(-c[L].first, c[R].first);
		c[L].first += z;
		c[R].first -= z;
		solve(c[L].second, c[R].second, z);
	}

	return 0;
}