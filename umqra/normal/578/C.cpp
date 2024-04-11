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

const double eps = 1e-9;
const double INF = 1e18;
const int N = (int)2e5 + 10;

bool Eq(double a, double b)
{
	return fabs(a - b) < eps;
}

bool Ls(double a, double b)
{
	return a < b && !Eq(a, b);
}

bool LsEq(double a, double b)
{
	return a < b || Eq(a, b);
}

struct Line
{
	double k, b;
	Line () : k(), b() {}
	Line (double _k, double _b) : k(_k), b(_b) {}
	double xInter(Line &t)
	{
		return (b - t.b) / (t.k - k);
	}
	double value(double x)
	{
		return k * x + b;
	}
	bool operator < (const Line &a) const
	{
		return k < a.k;
	}
	void print()
	{
		printf("%lf*x + %lf\n", k, b);
	}
};

Line stUp[N], stDown[N];
Line lines[N];
int a[N], sum[N];

bool canThrowUp(Line &x, Line &b, Line &n)
{
	return (LsEq(x.xInter(n), x.xInter(b)));
}

bool canThrowDown(Line &x, Line &b, Line &n)
{
	return (LsEq(x.xInter(n), x.xInter(b)));
}

double ans = 1e18;

void relaxAnswer(double x, Line &t, Line &b)
{
	ans = min(ans, fabs(t.value(x) - b.value(x)));
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + a[i];

	lines[0] = Line(0, 0);
	n++;
	for (int i = 1; i < n; i++)
		lines[i] = Line(i, sum[i]);
	sort(lines, lines + n);
	int upCnt = 0, downCnt = 0;
	for (int i = 0; i < n; i++)
	{
		while (upCnt > 1 && canThrowUp(stUp[upCnt - 2], stUp[upCnt - 1], lines[i]))
			upCnt--;
		stUp[upCnt++] = lines[i];
	}

	reverse(lines, lines + n);
	for (int i = 0; i < n; i++)
	{
		while (downCnt > 1 && canThrowDown(stDown[downCnt - 2], stDown[downCnt - 1], lines[i]))
			downCnt--;
		stDown[downCnt++] = lines[i];
	}

	int itUp = 0, itDown = 0;
	while (itUp < upCnt - 1 || itDown < downCnt - 1)
	{
		double x1 = (itUp < upCnt - 1 ? stUp[itUp].xInter(stUp[itUp + 1]) : INF);
		double x2 = (itDown < downCnt - 1 ? stDown[itDown].xInter(stDown[itDown + 1]) : INF);
		if (x1 < x2)
		{
			relaxAnswer(x1, stUp[itUp], stDown[itDown]);
			itUp++;
		}
		else
		{
			relaxAnswer(x2, stUp[itUp], stDown[itDown]);
			itDown++;
		}
	}
	printf("%.10lf\n", ans);
	return 0;
}