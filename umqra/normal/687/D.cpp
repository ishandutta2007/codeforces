#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <ctime>
#include <cmath>
#include <algorithm>

#include <valarray>
#include <complex>
#include <functional>
#include <cassert>

using namespace std;
typedef long long ll;

const int N = 1010;
const int E = (int)1e6 + 10;

struct Edge
{
	int id, a, b, cost;
	Edge () : id(), a(), b(), cost() {}
	Edge (int _id, int _a, int _b, int _c) : id(_id), a(_a), b(_b), cost(_c) {}
};

Edge listE[E];
int qL[N], qR[N];

struct DSU
{
	int par[N];
	int sz[N];
	int parity[N];
	
	DSU()
	{
		clear();
	}
	
	void clear()
	{
		for (int i = 0; i < N; i++)
		{
			par[i] = i;
			parity[i] = 0;
			sz[i] = 0;
		}
	}
	pair<int, int> get(int v)
	{
		int p = 0;
		int root = v;
		while (par[root] != root)
		{
			p ^= parity[root];
			root = par[root];
		}
		int z = p;
		while (par[v] != v)
		{
			int opar = par[v], oparity = parity[v];
			par[v] = root;
			parity[v] = p;
			p ^= oparity;
			v = opar;
		}
		return make_pair(root, z);
	}
	bool join(int a, int b)
	{
		pair<int, int> infoA = get(a);
		pair<int, int> infoB = get(b);
		if (infoA.first == infoB.first)
			return infoA.second != infoB.second;
		if (sz[infoA.first] == sz[infoB.first])
			sz[infoA.first]++;
		if (sz[infoA.first] > sz[infoB.first])
		{
			par[infoB.first] = infoA.first;
			parity[infoB.first] = 1 ^ infoA.second ^ infoB.second;
		}
		else
		{
			par[infoA.first] = infoB.first;
			parity[infoA.first] = 1 ^ infoA.second ^ infoB.second;
		}
		return true;
	}
};

DSU Dsu;
int n, m, q;

void read()
{
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < m; i++)
	{
		int a, b, cost;
		scanf("%d%d%d", &a, &b, &cost);
		a--, b--;
		listE[i] = Edge(i, a, b, cost);
	}
	for (int i = 0; i < q; i++)
	{
		scanf("%d%d", &qL[i], &qR[i]);
		qL[i]--;
		qR[i]--;
	}
}

bool cmp(const Edge &a, const Edge &b)
{
	return a.cost > b.cost;
}

void solve()
{
	sort(listE, listE + m, cmp);
	for (int i = 0; i < q; i++)
	{
		int l = qL[i], r = qR[i];
		Dsu.clear();
		int ans = -1;
		for (int s = 0; s < m; s++)
		{
			if (listE[s].id >= l && listE[s].id <= r)
			{
				if (!Dsu.join(listE[s].a, listE[s].b))
				{
					ans = listE[s].cost;
					break;
				}
			}
		}
		printf("%d\n", ans);
	}
}

int main()
{
//#ifdef LOCAL
//	freopen ("input.txt", "r", stdin);
//#endif
	read();
	solve();
    return 0;
}