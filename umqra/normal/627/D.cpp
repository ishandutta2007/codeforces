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

const int M = (int)1e8;
char buf[M];
int mpos = 0;

inline void * operator new (size_t sz)
{
	mpos += sz;
	return buf + mpos - sz;
}

inline void operator delete(void*){}


const int N = (int)2e5 + 10;
const int LOG = 20;

int vTime[N];
vector <int> g[N];
int sz[N], h[N];
int weight[N];
int valueEnd[N], valueCont[N];
int deg[N];
int block[N];

int center[LOG][N];

int sumValue[N], dp[N];
pii edges[N];
int n, k;

void read()
{
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &vTime[i]);
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;
		edges[i] = mp(a, b);
		deg[a]++;
		deg[b]++;
	}
	for (int i = 0; i < n; i++)
		g[i].resize(deg[i]);
	for (int i = 0; i < n - 1; i++)
	{
		int a = edges[i].X;
		int b = edges[i].Y;
		g[a][--deg[a]] = b;
		g[b][--deg[b]] = a;
	}
}

void calcInfo(int v, int p)
{
	sz[v] = 1;
	for (int to : g[v])
	{
		if (to == p || block[to])
			continue;
		h[to] = h[v] + 1;
		calcInfo(to, v);
		sz[v] += sz[to];
	}
}

int getCenter(int v)
{
	int total = sz[v];
	int p = -1;
	while (1)
	{
		bool changed = false;
		for (int to : g[v])
		{
			if (to == p || block[to])
				continue;
			if (2 * sz[to] >= total)
			{
				p = v;
				v = to;
				changed = true;
				break;
			}
		}
		if (!changed)
			break;
	}
	return v;
}

void calcDp(int v, int p)
{
//	eprintf("Vertex: %d, valueEnd: %d, valueCont: %d\n", v + 1, valueEnd[v], valueCont[v]);
	dp[v] = 0;
	sumValue[v] = weight[v];
	int sumFull = 0;
	int maxNotFull = 0;
	for (int to : g[v])
	{
		if (to == p || block[to])
			continue;
		calcDp(to, v);
		sumValue[v] += sumValue[to];
		if (sumValue[to] == dp[to])
			sumFull += sumValue[to];
		else
			maxNotFull = max(maxNotFull, dp[to]);
	}
	if (valueEnd[v] > 0)
		dp[v] = max(valueEnd[v] + sumFull, valueCont[v] + maxNotFull + sumFull);
	else
		dp[v] = 0;
}

int solve(int v, int deep = 0)
{
//	eprintf("Solve: %d\n", v);
	if (center[deep][v] == -1)
	{
		calcInfo(v, -1);
		center[deep][v] = getCenter(v);
	}
	v = center[deep][v];

//	eprintf("Center: %d\n", v + 1);
	calcDp(v, -1);
	if (sumValue[v] < k)
		return k - 1;
	
	int ans = dp[v];
//	eprintf("v: %d, ans: %d\n", v, dp[v]);
	int max1 = 0, max2 = 0;
	int sumFull = 0;
	int cntNonFull = 0;
	for (int to : g[v])
	{
		if (block[to])
			continue;
		if (dp[to] == sumValue[to])
		{
			sumFull += sumValue[to];
			continue;
		}
		cntNonFull++;
		if (max1 < dp[to])
		{
			max2 = max1;
			max1 = dp[to];
		}
		else if (max2 < dp[to])
			max2 = dp[to];
	}
//	eprintf("full: %d, max: %d/%d, all: %d\n", sumFull, max1, max2, all);
//	eprintf("maxs: %d %d\n", max1, max2);

	block[v] = 1;
	for (int i = 0; i < (int)g[v].size(); i++)
	{
		int to = g[v][i];
		if (block[to])
			continue;
		if (valueEnd[to] > 0 && valueCont[v] > 0)
		{
			int endWithoutYou = sumFull + max1 + valueCont[v];
			if (sumValue[to] == dp[to])
				endWithoutYou -= dp[to];
			else
				endWithoutYou -= (max1 == dp[to] ? max1 - max2 : 0);
			endWithoutYou = max(endWithoutYou, sumFull - (sumValue[to] == dp[to] ? sumValue[to] : 0) + valueEnd[v]);

			int added = 0;
			if (cntNonFull == 0)
				added = valueCont[v] + sumFull - sumValue[to];
			else if (cntNonFull == 1 && sumValue[to] > dp[to])
				added = valueCont[v] + sumFull;
			valueEnd[to] = max(valueEnd[to] + added, valueCont[to] + endWithoutYou);
		}

		if (valueCont[to] > 0 && valueCont[v] > 0 && (cntNonFull == 0 || (cntNonFull == 1 && sumValue[to] > dp[to])))
		{
			int withoutYou = sumFull + valueCont[v];
			if (sumValue[to] == dp[to])
				withoutYou -= sumValue[to];

			valueCont[to] += withoutYou;
		}

		weight[to] += sumValue[v] - sumValue[to];	
		ans = max(ans, solve(to, deep + 1));
	}
	return ans;
}

bool check(int x)
{
	for (int i = 0; i < n; i++)
	{
		if (vTime[i] < x)
			valueEnd[i] = valueCont[i] = 0;
		else
			valueEnd[i] = valueCont[i] = 1;
//		eprintf("%d ", valueCont[i]);
		weight[i] = 1;
		block[i] = 0;
	}
//	eprintf("\n");
	return solve(0) >= k;
}

void solve()
{
	memset(center, -1, sizeof(center));
	int l = 0, r = (int)1e6 + 10;
	while (r - l > 1)
	{
		int mid = (l + r) / 2;
		if (check(mid))
			l = mid;
		else
			r = mid;
	}
	printf("%d\n", l);
}

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
#endif
	read();
	solve();
	return 0;
}