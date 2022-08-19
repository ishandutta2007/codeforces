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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 300300;

struct Item {
	ll x, y;
	int id;

	Item() : x(), y(), id() {}

	void scan(int _id) {
		id = _id;
		scanf("%lld%lld", &x, &y);
	}

	bool operator < (const Item &I) const {
		return y - x < I.y - I.x;
	}
};

int n, m;
ll ans[N];
Item a[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		a[i].scan(i);
	while(m--) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		ll s = min(a[v].x + a[u].y, a[v].y + a[u].x);
		ans[v] -= s;
		ans[u] -= s;
	}
	sort(a, a + n);
	ll sumX = 0, sumY = 0;
	for (int i = 0; i < n; i++)
		sumX += a[i].x;
	for (int i = 0; i < n; i++) {
		sumX -= a[i].x;
		ans[a[i].id] += sumX + sumY + a[i].x * i + a[i].y * (n - 1 - i);
		sumY += a[i].y;
	}
	for (int i = 0; i < n; i++)
		printf("%lld ", ans[i]);
	printf("\n");

	return 0;
}