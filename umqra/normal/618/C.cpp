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

struct Point
{
	int x, y;
	int id;
	Point () : x(), y() {}
	Point (int _x, int _y) : x(_x), y(_y) {}
	Point operator + (const Point &a) const
	{
		return Point(x + a.x, y + a.y);
	}
	Point operator - (const Point &a) const
	{
		return Point(x - a.x, y - a.y);
	}
	ll operator % (const Point &a) const
	{
		return 1LL * x * a.x + 1LL * y * a.y;
	}
	ll operator * (const Point &a) const
	{
		return 1LL * x * a.y - 1LL * y * a.x;
	}
	bool operator < (const Point &a) const
	{
		return x < a.x || (x == a.x && y < a.y);
	}
	void scan()
	{
		scanf("%d%d", &x, &y);
	}
};

Point minP;

bool cmp(const Point &a, const Point &b)
{
	Point v = a - minP;
	Point u = b - minP;
	if (v * u != 0)
		return v * u > 0;
	return (v % v) < (u % u);
}

const int N = (int)1e5 + 10;
Point p[N];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		p[i].scan();
		p[i].id = i;
	}
	minP = *min_element(p, p + n);
	sort(p, p + n, cmp);
	int it = 1;
	while ((p[1] - p[0]) * (p[it] - p[0]) == 0)
		it++;
	vector <int> ans = {p[0].id, p[1].id, p[it].id};
	sort(ans.begin(), ans.end());
	for (int x : ans)
		printf("%d ", x + 1);
	return 0;
}