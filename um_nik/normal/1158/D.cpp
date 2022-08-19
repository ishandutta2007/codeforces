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

struct Point {
	ll x, y;

	Point() : x(), y() {}
	Point(ll _x, ll _y) : x(_x), y(_y) {}

	Point operator - (const Point &a) const {
		return Point(x - a.x, y - a.y);
	}
	ll operator * (const Point &a) const {
		return x * a.y - y * a.x;
	}

	bool operator < (const Point &a) const {
		if (x != a.x) return x < a.x;
		return y < a.y;
	}

	void scan() {
		scanf("%lld%lld", &x, &y);
	}
};

Point P;
bool cmp(const Point &v, const Point &u) {
	return (v - P) * (u - P) > 0;
}

const int N = 2010;
int n;
int ans[N];
int ansSz;
Point a[N];
bool used[N];
Point b[N];
char s[N];
map<Point, int> mapchik;

char sgn(ll x) {
	if (x > 0)
		return 'L';
	else
		return 'R';
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		a[i].scan();
		mapchik[a[i]] = i;
	}
	scanf("%s", s);
	P = mapchik.begin()->first;
	ans[ansSz++] = mapchik[P];
	used[ans[ansSz - 1]] = 1;
	while(ansSz < n - 1) {
		int m = 0;
		for (int i = 0; i < n; i++)
			if (!used[i])
				b[m++] = a[i];
		sort(b, b + m, cmp);
		if (sgn((b[0] - P) * (b[m - 1] - b[0])) == s[ansSz - 1])
			P = b[0];
		else
			P = b[m - 1];
		ans[ansSz++] = mapchik[P];
		used[ans[ansSz - 1]] = 1;
	}
	for (int i = 0; i < n; i++)
		if (!used[i])
			ans[ansSz++] = i;
	for (int i = 0; i < n; i++)
		printf("%d ", ans[i] + 1);
	printf("\n");

	return 0;
}