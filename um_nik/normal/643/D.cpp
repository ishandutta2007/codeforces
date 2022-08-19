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

const ll INF = (ll)1e18;
const int N = (int)1e5 + 10;
const int BLOCK = 250;

struct Query
{
	int type;
	int a, b;
	Query () : type(), a(), b() {}
	void scan()
	{
		scanf("%d", &type);
		if (type == 1)
		{
			scanf("%d%d", &a, &b);
			a--, b--;
		}
		else if (type == 2)
		{
			scanf("%d", &a);
			a--;
		}
	}
};

Query q[N];
ll people[N];
ll fromChild[N];

int to[N];
int degIn[N];
int n, cntQ;

void read()
{
	scanf("%d%d", &n, &cntQ);
	for (int i = 0; i < n; i++)
		scanf("%lld", &people[i]);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &to[i]);
		to[i]--;
	}
	for (int i = 0; i < cntQ; i++)
		q[i].scan();
}

void init()
{
	for (int i = 0; i < n; i++)
		degIn[to[i]]++;
}

int saveTo[N];
int saveDegIn[N];

void save()
{
	for (int i = 0; i < n; i++)
	{
		saveTo[i] = to[i];
		saveDegIn[i] = degIn[i];
	}
}

void applySave()
{
	for (int i = 0; i < n; i++)
	{
		to[i] = saveTo[i];
		degIn[i] = saveDegIn[i];
		fromChild[i] = 0;
	}

	for (int i = 0; i < n; i++)
	{
		int p = to[i];
		fromChild[p] += people[i] / (degIn[i] + 2);
	}
}

inline ll getMe(int v)
{
	return people[v] - (degIn[v] + 1) * (people[v] / (degIn[v] + 2));
}

inline ll getParent(int v)
{
	int p = to[v];
	return people[p] / (degIn[p] + 2);
}

inline ll getValue(int v)
{
	ll me = getMe(v);
	ll parent = getParent(v);
	return me + parent + fromChild[v];
}

ll saveMin[N], saveMax[N];
ll saveGet[N];

int inter[N];
int marked[N];
int cntI = 0;

int minChild[N], maxChild[N];

void initStuff()
{
	cntI = 0;
	for (int i = 0; i < n; i++)
	{
		minChild[i] = maxChild[i] = -1;
		marked[i] = 0;
		saveMin[i] = INF;
		saveMax[i] = -INF;
	}
}

void getInter(int l, int r)
{
	initStuff();
	save();
	for (int i = l; i <= r; i++)
	{
		if (q[i].type == 1)
		{
			int a = q[i].a;
			int b = q[i].b;
			degIn[to[a]]--;
			degIn[b]++;

			inter[cntI++] = a;
			inter[cntI++] = to[a];
			inter[cntI++] = to[to[a]];

			to[a] = b;
			inter[cntI++] = to[a];
			inter[cntI++] = to[to[a]];
		}
	}
	applySave();
	for (int i = 0; i < n; i++)
		saveGet[i] = getValue(i);

	for (int i = 0; i < cntI; i++)
		marked[inter[i]] = 1;

	int globMin = -1, globMax = -1;
	for (int i = 0; i < n; i++)
	{
		if (marked[i])
			continue;

		int t = to[i];
		ll curVal = saveGet[i];

		if (minChild[t] == -1 || saveMin[t] > curVal)
		{
			minChild[t] = i;
			saveMin[t] = curVal;
		}

		if (maxChild[t] == -1 || saveMax[t] < curVal)
		{
			maxChild[t] = i;
			saveMax[t] = curVal;
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (marked[i])
		{
			if (maxChild[i] != -1)
			{
				inter[cntI++] = maxChild[i];
				marked[maxChild[i]] = 1;
			}
			if (minChild[i] != -1)
			{
				inter[cntI++] = minChild[i];
				marked[minChild[i]] = 1;
			}
		}
	}

	ll globMaxValue = -INF, globMinValue = INF;
	for (int i = 0; i < n; i++)
	{
		if (marked[i])
			continue;
		ll curVal = saveGet[i];
		if (globMin == -1 || globMinValue > curVal)
		{
			globMin = i;
			globMinValue = curVal;
		}
		if (globMax == -1 || globMaxValue < curVal)
		{
			globMax = i;
			globMaxValue = curVal;
		}
	}
	if (globMin != -1)
		inter[cntI++] = globMin;
	if (globMax != -1)
		inter[cntI++] = globMax;

	sort(inter, inter + cntI);
	cntI = unique(inter, inter + cntI) - inter;
}

void reconnect(int v, int newTo)
{
	int p = to[v];
	int pp = to[to[v]];

	fromChild[p] -= people[v] / (degIn[v] + 2);
	fromChild[pp] -= people[p] / (degIn[p] + 2);
	fromChild[pp] += people[p] / (degIn[p] + 1);

	degIn[p]--;
	degIn[newTo]++;

	to[v] = newTo;

	p = to[v];
	pp = to[to[v]];
	fromChild[p] += people[v] / (degIn[v] + 2);
	fromChild[pp] -= people[p] / (degIn[p] + 1);
	fromChild[pp] += people[p] / (degIn[p] + 2);
}

void solve()
{
	init();
	for (int i = 0; i < cntQ; i += BLOCK)
	{
		getInter(i, min(cntQ, i + BLOCK) - 1);
		for (int s = i; s < min(i + BLOCK, cntQ); s++)
		{
			if (q[s].type == 1)
				reconnect(q[s].a, q[s].b);
			else if (q[s].type == 2)
				printf("%lld\n", getValue(q[s].a));
			else
			{
				ll minValue = INF, maxValue = -INF;
				for (int a = 0; a < cntI; a++)
				{
					ll value = getValue(inter[a]);
					minValue = min(minValue, value);
					maxValue = max(maxValue, value);
				}
				printf("%lld %lld\n", minValue, maxValue);
			}
		}
	}
}

int main()
{
	read();
	solve();
	return 0;
}