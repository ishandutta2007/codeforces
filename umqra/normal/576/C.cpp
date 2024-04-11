#include <iostream>
#include <cassert>
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

const int N = (int)1e6 + 10;
const int BLOCK = 1e3;
struct Point
{
	int id;
	int x, y;
	Point () : id(), x(), y() {}
	Point (int _id, int _x, int _y) : id(_id), x(_x), y(_y)  {}
	bool operator < (const Point &a) const
	{
		return y < a.y;
	}
	void scan(int _i)
	{
		id = _i;
		scanf("%d%d", &x, &y);
	}
};

Point p[N];
vector <Point> block[N];
Point ans[N];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		p[i].scan(i);
	sort(p, p + n);
	for (int i = 0; i < n; i++)
		block[p[i].x / BLOCK].push_back(p[i]);

	int cnt = 0;
	int prevType = 1;
	for (int i = 0; i < N; i++)
	{
		if (prevType == 0)
			reverse(block[i].begin(), block[i].end());
		int maxX = 0, minX = 1e9;
		for (auto x : block[i])
		{
			maxX = max(maxX, x.x);
			minX = min(minX, x.x);
			ans[cnt++] = x;
		}
		if (block[i].size() > 0)
			prevType = 1 - prevType;
	}

	ll len = 0;
	for (int i = 0; i < cnt - 1; i++)
		len += abs(ans[i].x - ans[i + 1].x) + abs(ans[i].y - ans[i + 1].y);
	assert(len <= (ll)25e8);
	for (int i = 0; i < cnt; i++)
		printf("%d ", ans[i].id + 1);

	return 0;
}