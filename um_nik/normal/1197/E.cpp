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

const int MOD = (int)1e9 + 7;
int add(int x, int y) {
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}

pii merge(pii x, pii y) {
	pii res = min(x, y);
	res.second = 0;
	if (res.first == x.first) res.second = add(res.second, x.second);
	if (res.first == y.first) res.second = add(res.second, y.second);
	return res;
}

const int N = 400400;
int n;
pii dp[N];
int a[N][2];

struct Event {
	int t, x, id;

	Event() : t(), x(), id() {}
	Event(int _t, int _x, int _id) : t(_t), x(_x), id(_id) {}

	bool operator < (const Event &e) const {
		if (x != e.x) return x > e.x;
		return t < e.t;
	}
};
Event ev[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a[i][1], &a[i][0]);
		ev[2 * i] = Event(0, a[i][0], i);
		ev[2 * i + 1] = Event(1, a[i][1], i);
	}
	sort(ev, ev + 2 * n);
	for (int i = 0; i < n; i++)
		dp[i] = mp(MOD, 0);
	pii cur = mp(MOD, 0);
	for (int i = 0; i < 2 * n; i++) {
		if (ev[i].t == 0) {
			cur = merge(cur, dp[ev[i].id]);
		} else {
			if (cur.first == MOD) {
				dp[ev[i].id] = mp(a[ev[i].id][0], 1);
			} else {
				pii w = cur;
				w.first -= a[ev[i].id][1] - a[ev[i].id][0];
				dp[ev[i].id] = w;
			}
		}
	}
	cur = mp(MOD, 0);
	for (int i = 0; i < n; i++)
		cur = merge(cur, dp[i]);
	printf("%d\n", cur.second);

	return 0;
}