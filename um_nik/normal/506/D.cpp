#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
#define mp make_pair

const int N = (int)1e5 + 5;
const int M = 300;
vector<pii> col[N];
vector<int> big;
vector<int> par[N], sz[N];
map<int, int> reName[N];
map<pii, int> small;

int n, m;

int a[2 * N];
int s;

void readEdge()
{
	int v, u;
	int c;
	scanf("%d%d%d", &v, &u, &c);
	col[c].push_back(mp(v, u));
	return;
}

void read()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
		readEdge();
	return;
}

void incSmall(int v, int u)
{
	pii tmp = mp(v, u);
	if (small.count(tmp) == 0)
		small[tmp] = 1;
	else
		small[tmp]++;
	return;
}

int getPar(int c, int v)
{
	return (par[c][v] == -1 ? v : par[c][v] = getPar(c, par[c][v]));
}

void unite(int c, int v, int u)
{
	v = getPar(c, v);
	u = getPar(c, u);
	if (v == u) return;
	if (sz[c][v] < sz[c][u]) swap(v, u);
	sz[c][v] += sz[c][u];
	par[c][u] = v;
	return;
}

void solveColor(int c)
{
	if ((int)col[c].size() == 0) return;
	int esz = (int)col[c].size();
	s = 0;
	for (int i = 0; i < esz; i++)
	{
		a[s++] = col[c][i].first;
		a[s++] = col[c][i].second;
	}
	sort(a, a + s);
	s = unique(a, a + s) - a;
//	for (int i = 0; i < s; i++)
//		printf("%d ", a[i]);
//	printf("\n");
	for (int i = 0; i < s; i++)
		reName[c][a[i]] = i;
	par[c].resize(s);
	sz[c].resize(s);
	for (int i = 0; i < s; i++)
	{
		par[c][i] = -1;
		sz[c][i] = 1;
	}
	for (int i = 0; i < esz; i++)
		unite(c, reName[c][col[c][i].first], reName[c][col[c][i].second]);
	if (s > M)
		big.push_back(c);
	else
	{
		for (int i = 0; i < s; i++)
			for (int j = i + 1; j < s; j++)
				if (getPar(c, i) == getPar(c, j))
					incSmall(a[i], a[j]);
	}
	return;
}

void solve()
{
	for (int i = 1; i <= m; i++)
		solveColor(i);
	return;
}

void query()
{
	int v, u;
	scanf("%d%d", &v, &u);
	if (v > u) swap(v, u);
	int ans = small[mp(v, u)];
	for (int i = 0; i < (int)big.size(); i++)
	{
		int c = big[i];
		if (reName[c].count(v) == 0 || reName[c].count(u) == 0) continue;
		ans += (int)(getPar(c, reName[c][v]) == getPar(c, reName[c][u]));
	}
	printf("%d\n", ans);
	return;
}

int main()
{
	read();
	solve();
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; i++)
		query();

	return 0;
}