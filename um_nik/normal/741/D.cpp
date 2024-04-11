#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

const int MM = (int)4e7;
char buf[MM];
int mpos = 0;
inline void* operator new(size_t n)
{
	mpos += n;
	if (mpos >= MM) throw;
	return buf + mpos - n;
}
inline void operator delete(void*){}

typedef pair<int, int> pii;
#define mp make_pair

const int N = 500500;
const int K = 22;
const int M = (1 << K) + 7;
int a[N];
int d[N];
int par[N];
int ans[N];
int id[N];
pii val[N];
int nxt[N];
int fst[N], lst[N];
vector<int> g[N];
int curId[M];
int curD[M];
int n;
int maxSon[N];
int sz[N];

void read()
{
	scanf("%d", &n);
	d[0] = 0;
	a[0] = 0;
	for (int v = 1; v < n; v++)
	{
		int u;
		char c;
		scanf("%d %c ", &u, &c);
		u--;
		a[v] = a[u] ^ (1 << (int)(c - 'a'));
		par[v] = u;
		d[v] = d[u] + 1;
		val[v] = mp(a[v], d[v]);
		nxt[v] = -1;
		g[u].push_back(v);
	}
	val[0] = mp(a[0], d[0]);
	nxt[0] = -1;
	return;
}

void dfs(int v)
{
	if (maxSon[v] == -1)
	{
		ans[v] = 0;
		fst[v] = lst[v] = v;
		id[v] = v;
		curId[a[v]] = v;
		curD[a[v]] = d[v];
		return;
	}
	for (int u : g[v])
		if (u != maxSon[v])
			dfs(u);
	dfs(maxSon[v]);
	id[v] = id[maxSon[v]];
	for (int u : g[v])
	{
		if (u == maxSon[v]) continue;
		for (int it = fst[id[u]]; it != -1; it = nxt[it])
		{
			pii t = val[it];
			int x = t.first;
			if (curId[x] == id[v])
				ans[v] = max(ans[v], curD[x] + t.second - 2 * d[v]);
			for (int i = 0; i < K; i++)
			{
				int y = x ^ (1 << i);
				if (curId[y] == id[v])
					ans[v] = max(ans[v], curD[y] + t.second - 2 * d[v]);
			}
		}
		for (int it = fst[id[u]]; it != -1; it = nxt[it])
		{
			pii t = val[it];
			int x = t.first;
			if (curId[x] != id[v])
				curD[x] = -1;
			curId[x] = id[v];
			curD[x] = max(curD[x], t.second);
		}
		nxt[lst[id[v]]] = fst[id[u]];
		lst[id[v]] = lst[id[u]];
	}
	int x = a[v];
	if (curId[x] == id[v])
		ans[v] = max(ans[v], curD[x] - d[v]);
	for (int i = 0; i < K; i++)
	{
		int y = x ^ (1 << i);
		if (curId[y] == id[v])
			ans[v] = max(ans[v], curD[y] - d[v]);
	}
	if (curId[x] != id[v])
		curD[x] = -1;
	curId[x] = id[v];
	curD[x] = max(curD[x], d[v]);
	nxt[lst[id[v]]] = v;
	lst[id[v]] = v;
	return;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	read();
	for (int i = 0; i < n; i++)
	{
		sz[i] = 1;
		maxSon[i] = -1;
		ans[i] = 0;
	}
	for (int v = n - 1; v > 0; v--)
	{
		sz[par[v]] += sz[v];
		if (maxSon[par[v]] == -1 || sz[v] > sz[maxSon[par[v]]])
			maxSon[par[v]] = v;
	}
	dfs(0);
	for (int v = n - 1; v > 0; v--)
		ans[par[v]] = max(ans[par[v]], ans[v]);
	for (int i = 0; i < n; i++)
		printf("%d ", ans[i]);
	printf("\n");

	return 0;
}