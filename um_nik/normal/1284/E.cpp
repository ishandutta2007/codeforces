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

ll getC(int n, int k) {
	if (k < 0 || k > n) return 0;
	ll res = 1;
	for (int i = 0; i < k; i++) {
		res *= n - i;
		res /= i + 1;
	}
	return res;
}

struct Point {
	ll x, y;

	Point() : x(), y() {}
	Point(ll _x, ll _y) : x(_x), y(_y) {}

	Point operator + (const Point &a) const {
		return Point(x + a.x, y + a.y);
	}
	Point operator - (const Point &a) const {
		return Point(x - a.x, y - a.y);
	}
	ll operator * (const Point &a) const {
		return x * a.y - y * a.x;
	}
};

int getQ(const Point &a) {
	if (a.y != 0) return (a.y > 0 ? 0 : 1);
	return (a.x >= 0 ? 0 : 1);
}
bool cmp(const Point &v, const Point &u) {
	int q1 = getQ(v), q2 = getQ(u);
	if (q1 != q2) return q1 < q2;
	return v * u > 0;
}

const int N = 5505;
Point a[N];
Point b[N];
int n;
ll ans;

void solve() {
	sort(a, a + n, cmp);
	for (int i = 0; i <= n; i++)
		a[n + i] = a[i];
	int p = 0;
	for (int i = 0; i < n; i++) {
		while(p < i + n && a[i] * a[p] >= 0) p++;
		ans -= getC(p - i - 1, 3);
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	ans = n * getC(n - 1, 4);
	for (int i = 0; i < n; i++)
		scanf("%lld%lld", &b[i].x, &b[i].y);
	n--;
	for (int i = 0; i <= n; i++) {
		int m = 0;
		for (int j = 0; j <= n; j++) {
			if (i == j) continue;
			a[m++] = b[j] - b[i];
		}
		solve();
	}
	printf("%lld\n", ans);
	return 0;
}