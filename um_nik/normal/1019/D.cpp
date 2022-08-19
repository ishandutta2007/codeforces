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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int N = 2020;
const int M = N * N / 2;

struct Point {
	ll x, y;
	
	Point() : x(), y() {}
	Point(ll _x, ll _y) : x(_x), y(_y) {}

	void scan() {
		scanf("%lld%lld", &x, &y);
	}
	void print() {
		printf("%lld %lld\n", x, y);
	}

	Point operator + (const Point &a) const {
		return Point(x + a.x, y + a.y);
	}
	Point operator - (const Point &a) const {
		return Point(x - a.x, y - a.y);
	}
	ll operator % (const Point &a) const {
		return x * a.x + y * a.y;
	}
	ll operator * (const Point &a) const {
		return x * a.y - y * a.x;
	}
	ll sqrLen() const {
		return *this % *this;
	}
};

Point a[N];
int p[N];
int rp[N];
pii b[M];
int n;
ll S;

bool cmp1(const int &id1, const int &id2) {
	Point v = a[id1], u = a[id2];
	if (v.y != u.y) return v.y < u.y;
	return v.x < u.x;
}
bool cmp2(const pii &p1, const pii &p2) {
	Point v = a[p1.second] - a[p1.first], u = a[p2.second] - a[p2.first];
	return v * u > 0;
}

void solve(int v, int u) {
	Point w = a[u] - a[v];
	int l = 0, r = n;
	while(r - l > 1) {
		int m = (l + r) / 2;
		if (w * (a[p[m]] - a[v]) <= -S)
			l = m;
		else
			r = m;
	}
	if (w * (a[p[l]] - a[v]) == -S) {
		printf("Yes\n");
		a[v].print();
		a[u].print();
		a[p[l]].print();
		exit(0);
	}

	l = 0; r = n;
	while(r - l > 1) {
		int m = (l + r) / 2;
		if (w * (a[p[m]] - a[v]) <= S)
			l = m;
		else
			r = m;
	}
	if (w * (a[p[l]] - a[v]) == S) {
		printf("Yes\n");
		a[v].print();
		a[u].print();
		a[p[l]].print();
		exit(0);
	}

}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%lld", &n, &S);
	S *= 2;

	for (int i = 0; i < n; i++)
		a[i].scan();
	for (int i = 0; i < n; i++)
		p[i] = i;
	sort(p, p + n, cmp1);
	for (int i = 0; i < n; i++)
		rp[p[i]] = i;
	int m = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < i; j++) {
			Point d = a[j] - a[i];
			if (d.y < 0 || (d.y == 0 && d.x < 0)) {
				b[m++] = mp(j, i);
			} else {
				b[m++] = mp(i, j);
			}
		}
	sort(b, b + m, cmp2);
	for (int i = 0; i < m; i++) {
		int v = b[i].first, u = b[i].second;
		solve(v, u);
		int pv = rp[v], pu = rp[u];
		swap(p[pv], p[pu]);
		swap(rp[v], rp[u]);
	}
	printf("No\n");

	return 0;
}