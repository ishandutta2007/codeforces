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

const int N = (int)2e5 + 10;
int n;
ll p[N], t[N];

void read()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld", &p[i]);
	for (int i = 0; i < n; i++)
		scanf("%lld", &t[i]);
}

bool cmp(int a, int b)
{
	if (p[a] * t[b] != p[b] * t[a])
		return p[a] * t[b] > p[b] * t[a];
	return p[a] < p[b];
}

ll timeStart[N];
int order[N];
ll allP[N];
int cntP = 0;

const double INF = 1e100;
double kP[N][2];

void solve()
{
	for (int i = 0; i < n; i++)
		allP[i] = p[i];
	sort(allP, allP + n);
	cntP = unique(allP, allP + n) - allP;

	for (int i = 0; i < n; i++)
		order[i] = i;
	sort(order, order + n, cmp);
	for (int i = 0; i < n; i++)
		timeStart[i] = (i == 0 ? 0 : timeStart[i - 1]) + t[order[i]];

	for (int i = 0; i < cntP; i++)
	{
		kP[i][0] = INF;
		kP[i][1] = -INF;
	}
	int startBlock = 0;
	double T = timeStart[n - 1];
	double c = 1;

	for (int i = 1; i <= n; i++)
	{
		if (i == n || p[order[i]] * t[order[startBlock]] != p[order[startBlock]] * t[order[i]])
		{
			ll minT = (startBlock == 0 ? 0 : timeStart[startBlock - 1]);
			ll maxT = timeStart[i - 1];

			for (int s = startBlock; s < i; s++)
			{
				ll curMinT = minT + t[order[s]];
				ll curMaxT = maxT;

				int pId = lower_bound(allP, allP + cntP, p[order[s]]) - allP;
				kP[pId][0] = min(kP[pId][0], -curMaxT * 1. * p[order[s]] / T);
				kP[pId][1] = max(kP[pId][1], -curMinT * 1. * p[order[s]] / T);
			}
			startBlock = i;
		}
	}

	for (int i = 0; i < cntP - 1; i++)
	{
		double k1 = kP[i][1];
		double b1 = allP[i];

		double k2 = kP[i + 1][0];
		double b2 = allP[i + 1];
		if (k1 <= k2)
			continue;

		double curC = (b2 - b1) / (k1 - k2);

		c = min(c, curC);
	}
	printf("%.15lf\n", c);
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