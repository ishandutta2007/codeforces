#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;
const int MAXP = 1700;
const int N = (int)1e5 + 10;
const double INF = 1e19;
const double eps = 1e-7;
ll dp[N];
ll a[N], b[N];

bool Eq(double a, double b)
{
	return fabs(a - b) < eps;
}

bool Ls(double a, double b)
{
	return a < b && !Eq(a, b);
}

bool Gr(double a, double b)
{
	return a > b && !Eq(a, b);	
}

struct line
{
	ll b, k;
	line () {}
	line (ll b, ll k) : b(b), k(k) {}
} Stack[2 * N];
int rSt = 0;

double getXIntersect(line a, line b)
{
	return (double)(a.b - b.b) / (double)(b.k - a.k);
}

bool badTriple(line a, line b, line c)
{
	return Gr(getXIntersect(a, b), getXIntersect(a, c));
}

double getLeftBord(int ind)
{
	if (ind == 0)
		return -INF;
	return getXIntersect(Stack[ind - 1], Stack[ind]);
}

double getRightBord(int ind)
{
	if (ind + 1 == rSt)
		return INF;
	return getXIntersect(Stack[ind], Stack[ind + 1]);
}

int findNeededNum(ll x)
{
	int l = -1, r = rSt;
	while (r - l > 1)
	{
		int m = (l + r) / 2;
		double lB = getLeftBord(m);
		double rB = getRightBord(m);
		if (Gr((double)x, rB))
			l = m;
		else if (Ls((double)x, lB))
			r = m;
		else
			return m;
	}
	throw;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%I64d", &a[i]);
	for (int i = 0; i < n; i++)
		scanf("%I64d", &b[i]);                                   

	dp[0] = 0;          	
	Stack[rSt++] = line(0, b[0]);
	for (int i = 1; i < n; i++)
	{
		int indStack = findNeededNum(a[i]);
		dp[i] = Stack[indStack].b + Stack[indStack].k * a[i];
		line cur = line(dp[i], b[i]);
		while (rSt > 1 && badTriple(Stack[rSt - 2], Stack[rSt - 1], cur))
			rSt--;
		Stack[rSt++] = cur;
	}

	printf("%I64d", dp[n - 1]);

	return 0;
}