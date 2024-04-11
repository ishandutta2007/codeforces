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

struct Line {
	ll k, b;

	Line() : k(), b() {}
	Line(ll _k, ll _b) : k(_k), b(_b) {}

	ll getVal(ll x) {
		return k * x + b;
	}
};

const ll C = (ll)1e9 + 3;

struct Hull {
	vector<Line> lines;
	vector<ll> bnd;

	Hull() : lines(), bnd() {}

	void addLine(Line L) {
		while(!lines.empty()) {
			if (L.getVal(bnd.back()) >= lines.back().getVal(bnd.back())) {
				lines.pop_back();
				bnd.pop_back();
			} else break;
		}
		if (lines.empty()) {
			bnd.push_back(-C);
			lines.push_back(L);
		} else {
			ll l = bnd.back(), r = C + 1;
			while(r - l > 1) {
				ll x = l + (r - l) / 2;
				if (L.getVal(x) >= lines.back().getVal(x))
					r = x;
				else
					l = x;
			}
			if (l < C) {
				bnd.push_back(r);
				lines.push_back(L);
			}
		}
	}

	ll getVal(ll x) {
		int p = upper_bound(bnd.begin(), bnd.end(), x) - bnd.begin() - 1;
		return lines[p].getVal(x);
	}
};

struct Item {
	ll x, y, val;

	Item() : x(), y(), val() {}

	void scan() {
		scanf("%lld%lld%lld", &x, &y, &val);
		val = x * y - val;
	}

	bool operator < (const Item &I) const {
		return x < I.x;
	}
};

const int N = (int)1e6 + 7;
int n;
Item a[N];
ll ANS = 0;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		a[i].scan();
	sort(a, a + n);
	Hull hull = Hull();
	hull.addLine(Line(0, 0));
	for (int i = 0; i < n; i++) {
		ll w = a[i].val + hull.getVal(-a[i].y);
//		eprintf("%lld\n", w);
		ANS = max(ANS, w);
		hull.addLine(Line(a[i].x, w));
	}
	printf("%lld\n", ANS);

	return 0;
}