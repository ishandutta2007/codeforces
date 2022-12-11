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

const double INF = 1e100;
const int N = (int)2e5 + 100;
const int K = 60;

int t[N];
ll sumT[N];
double sumRevT[N];
int n, k;

void read()
{
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &t[i]);
}

void precalc()
{
	sumT[0] = t[0];
	for (int i = 1; i < n; i++)
		sumT[i] = sumT[i - 1] + t[i];

	sumRevT[0] = 1. / t[0];
	for (int i = 1; i < n; i++)
		sumRevT[i] = sumRevT[i - 1] + (1. / t[i]);
}

double calcValue(int save, int pos)
{
	if (save == -1)
		return 0;
	return (sumRevT[pos] - sumRevT[save]) * sumT[save];
}

double dp[K][N];

struct Function
{
	double initValue;
	int savePoint;
	int domPoint;
	Function () : initValue(), savePoint(), domPoint() {}
	Function (double _v, int _s, int _d) : initValue(_v), savePoint(_s), domPoint(_d) {}
	double getValue(int pos)
	{
		return initValue + calcValue(savePoint, pos);
	}
};

vector <Function> f[K];

double getDpValue(int level, int pos)
{
	if (f[level].size() == 0)
		return -INF;
	int l = -1, r = (int)f[level].size();
	while (r - l > 1)
	{
		int mid = (l + r) / 2;
		if (f[level][mid].domPoint <= pos)
			l = mid;
		else
			r = mid;
	}
	if (l == -1)
		return -INF;

	return f[level][l].getValue(pos);
}

void addFunction(int level, Function cur)
{
//	eprintf("Adding on level: %d, start value: %lf, save: %d\n", level, cur.initValue, cur.savePoint);
//	eprintf("%lf\n", cur.getValue(n - 1));
	while (f[level].size() > 0)
	{
		int point = f[level].back().domPoint;
		if (f[level].back().getValue(point) <= cur.getValue(point))
			f[level].pop_back();
		else
			break;
	}
	if (f[level].size() == 0)
	{
		f[level].push_back(cur);
		return;
	}
	int l = max(f[level].back().domPoint, cur.domPoint - 1);
	int r = n;
	while (r - l > 1)
	{
		int mid = (l + r) / 2;
		if (f[level].back().getValue(mid) > cur.getValue(mid))
			l = mid;
		else
			r = mid;
	}
//	eprintf("Dominated %d\n", r);
	if (r < n)
	{
		cur.domPoint = r;
		f[level].push_back(cur);
	}
}

void solve()
{
	precalc();
	for (int i = 0; i <= k; i++)
		for (int s = 0; s <= n; s++)
			dp[i][s] = -INF;

	double ans = 0;
	for (int i = 0; i < n; i++)
		ans += sumT[i] * 1. / t[i];

//	eprintf("Ans: %lf\n", ans);
	f[1].push_back(Function(0, -1, 0));
	for (int i = 0; i < n - 1; i++)
	{
		for (int s = k - 1; s >= 1; s--)
		{
			double value = getDpValue(s, i);
			if (value < -INF / 2)
				continue;
//			eprintf("%d %d - %lf\n", i, s, value);
			addFunction(s + 1, Function(value, i, i + 1));
		}
	}
	printf("%.10lf\n", ans - f[k].back().getValue(n - 1));
}

int main()
{
	read();
	solve();
	return 0;
}