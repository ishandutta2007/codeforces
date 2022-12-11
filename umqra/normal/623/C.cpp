/*
	Team: Dandelion
	Room: 258
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <sstream>
#include <fstream>
#include <functional>
#include <cassert>
#include <complex>
#include <valarray>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

const int N = (int)1e5 + 10;
const ll INF = (ll)1e9;

struct Point
{
	ll x, y;
	Point () : x(), y() {}
	void scan()
	{
		scanf("%lld%lld", &x, &y);
	}
	bool operator < (const Point &a) const
	{
		return y < a.y || (y == a.y && x < a.x);
	}
};

ll sqr(ll a)
{
	return a * a;
}

Point p[N];
ll prefMinX[N], prefMaxX[N];
ll suffMinX[N], suffMaxX[N];
int n;

void precalc()
{
	for (int i = 0; i < n; i++)
	{
		prefMinX[i] = (i == 0 ? p[i].x : min(prefMinX[i - 1], p[i].x));
		prefMaxX[i] = (i == 0 ? p[i].x : max(prefMaxX[i - 1], p[i].x));
	}

	for (int i = n - 1; i >= 0; i--)
	{
		suffMinX[i] = (i == n - 1 ? p[i].x : min(suffMinX[i + 1], p[i].x));
		suffMaxX[i] = (i == n - 1 ? p[i].x : max(suffMaxX[i + 1], p[i].x));
	}
}

ll getMaxD(ll y1, ll y2, ll x1, ll x2)
{
	ll d = max(sqr(y1 - y2), sqr(x1 - x2));
	d = max(d, max(sqr(y1), sqr(y2)) + max(sqr(x1), sqr(x2)));
	return d;
}

bool check(ll d)
{
	ll xD = sqr(prefMinX[n - 1] - prefMaxX[n - 1]);
	if (xD <= d)
		return true;
	int it = 0;
	int kek = n;
	eprintf("D: %lld\n", d);
	for (int i = 0; i < n; i++)
		eprintf("%lld ", p[i].y);
	eprintf("\n");
	for (int i = 0; i < n; i++)
	{
		if (i != 0 && p[i].y == p[i - 1].y)
			continue;

		while (it < n && (it <= i || (sqr(p[it].y - p[i].y) <= d)))
			it++;
		while (kek > 0 && llabs(p[kek - 1].y) > llabs(p[i].y))
			kek--;
		int cur = min(kek, it);
		eprintf("%d: %d %d\n", i, it, kek);
		if (cur < i)
			break;
		ll y1 = p[i].y;
		ll y2 = p[cur - 1].y;

		if (i == 0 && cur == n)
			return true;
		ll x1, x2;
		if (i == 0)
		{
			x1 = suffMinX[cur];
			x2 = suffMaxX[cur];
		}
		else if (cur == n)
		{
			x1 = prefMinX[i - 1];
			x2 = prefMaxX[i - 1];
		}
		else
		{
			x1 = min(suffMinX[cur], prefMinX[i - 1]);
			x2 = max(suffMaxX[cur], prefMaxX[i - 1]);
		}
		ll curD = getMaxD(y1, y2, x1, x2);
		if (curD <= d)
			return true;
	}
	it = n - 1;
	kek = -1;
	eprintf("None!\n");
	for (int i = n - 1; i >= 0; i--)
	{
		if (i != n - 1 && p[i].y == p[i + 1].y)
			continue;

		while (it >= 0 && (it >= i || (sqr(p[it].y - p[i].y) <= d)))
			it--;
		while (kek < n - 1 & llabs(p[kek + 1].y) > llabs(p[i].y))
			kek++;
		int cur = max(kek, it);
		eprintf("%d: %d %d\n", i, it, kek);
		if (cur > i)
			break;
		ll y1 = p[i].y;
		ll y2 = p[cur + 1].y;
		if (i == n - 1 && cur == -1)
			return true;
		ll x1, x2;
		if (i == n - 1)
		{
			x1 = prefMinX[cur];
			x2 = prefMaxX[cur];
		}
		else if (cur == -1)
		{
			x1 = suffMinX[i + 1];
			x2 = suffMaxX[i + 1];
		}
		else
		{
			x1 = min(prefMinX[cur], suffMinX[i + 1]);
			x2 = max(prefMaxX[cur], suffMaxX[i + 1]);
		}
		ll curD = getMaxD(y1, y2, x1, x2);
		if (curD <= d)
			return true;
	}
	return false;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		p[i].scan();
	}
	sort(p, p + n);
	precalc();
	ll l = -1, r = (ll)1e18;
	while (r - l > 1)
	{
		ll mid = (l + r) / 2;
		if (check(mid))
			r = mid;
		else
			l = mid;
	}
	printf("%lld\n", r);
	return 0;
}