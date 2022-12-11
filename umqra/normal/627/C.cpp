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

const int N = (int)3e5 + 100;
const int LOG = 20;
const int INF = (int)1e9;
pii p[N];
int sparse[LOG][N];
int h[N];
int d, n, m;

int getMin(int l, int r)
{
	int k = h[r - l + 1];
	int a = sparse[k][l];
	int b = sparse[k][r - (1 << k) + 1];
	if (p[a].Y < p[b].Y)
		return a;
	return b;
}

pair<ll, ll> solve(int l, int r)
{
	if (r - l <= n)
		return mp(0, n - (r - l));

	int lId = upper_bound(p, p + m, mp(l, INF)) - p;
	int rId = lower_bound(p, p + m, mp(r, -1)) - p - 1;
	int mid = getMin(lId, rId);
	pair<ll, ll> lPart = solve(l, p[mid].X);
	int rem = r - p[mid].X;
	int need = min(rem, n);
	if (rem <= n)
		return mp(lPart.X + max(0LL, (need - lPart.Y) * 1LL * p[mid].Y), max(0LL, lPart.Y - need));
	ll added = max(0LL, (need - lPart.Y) * 1LL * p[mid].Y);
	pair<ll, ll> rPart = solve(p[mid].X, r);
	return mp(lPart.X + added + rPart.X, rPart.Y);
}

int main()
{
	scanf("%d%d%d", &d, &n, &m);
	for (int i = 0; i < m; i++)
		scanf("%d%d", &p[i].X, &p[i].Y);
	sort(p, p + m);
	for (int i = 0; i < LOG; i++)
	{
		for (int s = 0; s <= m - (1 << i); s++)
		{
			if (i == 0)
				sparse[i][s] = s;
			else
			{
				int a = sparse[i - 1][s];
				int b = sparse[i - 1][s + (1 << (i - 1))];
				if (p[a].Y < p[b].Y)
					sparse[i][s] = a;
				else
					sparse[i][s] = b;
			}
		}
	}

	h[1] = 0;
	for (int i = 2; i < N; i++)
		h[i] = h[i / 2] + 1;
	ll P = 0;
	for (int i = 0; i < m; i++)
	{
		if (p[i].X - P > n)
		{
			puts("-1");
			return 0;
		}
		P = p[i].X;
	}
	if (d - P > n)
	{
		puts("-1");
		return 0;
	}

	pair<ll, ll> res = solve(0, d);
	cout << res.X << endl;
	return 0;
}