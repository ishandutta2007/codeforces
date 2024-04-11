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
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__);fflush(stderr);
#else
	#define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

const int N = 100100;
map<int, set<pii>> mapchik;
pii a[N];
pii b[N];
int ans[N];
int n, m;

void addAns(int x, int y, int d) {
//	eprintf("addAns %d %d %d\n", x, y, d);
	int w = x - y;
	while(!mapchik[w].empty()) {
		auto it = mapchik[w].begin();
		int xx = it->first;
		if (xx >= x + d) return;
		int id = it->second;
		mapchik[w].erase(it);
		if (xx < x) continue;
		ans[id] = 0;
	}
//	eprintf("end addAns\n");
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		a[i] = mp(x, y);
		b[i] = mp(y, x);
	}
	sort(a, a + n);
	sort(b, b + n);
	for (int i = 0; i < m; i++) {
		ans[i] = 1;
		int x, y;
		scanf("%d%d", &x, &y);
		mapchik[x - y].insert(mp(x, i));
	}
	int x = 0, y = 0;
	int p = 0, q = 0;
	while(p < n && q < n) {
//		eprintf("stay in (%d %d), p = %d, q = %d\n", x, y, p, q);
		int dp = a[p].first - x, dq = b[q].first - y;
		if (dp < dq || (dp == dq && a[p].second < y)) {
			if (dp > 0) {
				addAns(x, y, dp);
				x += dp;
				y += dp;
			}
			if (a[p].second < y) {
				addAns(a[p].first, a[p].second, 1);
				if (a[p].first == x) x++;
			}
			p++;
		} else {
			if (dq > 0) {
				addAns(x, y, dq);
				x += dq;
				y += dq;
			}
			if (b[q].second < x) {
				addAns(b[q].second, b[q].first, 1);
				if (b[q].first == y) y++;
			}
			q++;
		}
	}
	while(p < n) {
		int dp = a[p].first - x;
		if (dp > 0) {
			addAns(x, y, dp);
			x += dp;
			y += dp;
		}
		if (a[p].second < y) {
			addAns(a[p].first, a[p].second, 1);
			if (a[p].first == x) x++;
		}
		p++;
	}
	while(q < n) {
		int dq = b[q].first - y;
		if (dq > 0) {
			addAns(x, y, dq);
			x += dq;
			y += dq;
		}
		if (b[q].second < x) {
			addAns(b[q].second, b[q].first, 1);
			if (b[q].first == y) y++;
		}
		q++;
	}
	addAns(x, y, (int)1e9);

	for (int i = 0; i < m; i++) {
		if (ans[i])
			printf("WIN\n");
		else
			printf("LOSE\n");
	}

	return 0;
}