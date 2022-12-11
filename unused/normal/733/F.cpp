#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;

struct edge
{
	int s, e, v, w, idx;
	bool operator<(const edge &r) const
	{
		return v < r.v;
	}
};

edge dat[200005];
bool treed[200005];
int parent[200005];

int getparent(int t)
{
	return t == parent[t] ? t : parent[t] = getparent(parent[t]);
}

bool merge(int a, int b)
{
	int pa = getparent(a);
	int pb = getparent(b);

	if (pa == pb) return false;

	parent[pa] = pb;
	return true;
}

struct hld {
	static const int MAXLN = 19;
	static const int MAXN = 1 << (MAXLN - 1);
	vector<int> tree[MAXN];
	int subsize[MAXN], depth[MAXN], pa[MAXLN][MAXN];

	int chead[MAXN], cidx[MAXN];
	int lchain;
	int flatpos[MAXN + 1], fptr;

	pair<int, int> maxtree[MAXN * 2 + 1];

	void dfs(int u, int par) {
		pa[0][u] = par;
		subsize[u] = 1;
		for (int v : tree[u]) {
			if (v == pa[0][u]) continue;
			depth[v] = depth[u] + 1;
			dfs(v, u);
			subsize[u] += subsize[v];
		}
	}

	void init(int size)
	{
		lchain = fptr = 0;
		dfs(0, -1);
		memset(chead, -1, sizeof(chead));

		for (int i = 1; i < MAXLN; i++) {
			for (int j = 0; j < size; j++) {
				if (pa[i - 1][j] != -1) {
					pa[i][j] = pa[i - 1][pa[i - 1][j]];
				}
			}
		}
	}

	void decompose(int u) {
		if (chead[lchain] == -1) chead[lchain] = u;
		cidx[u] = lchain;
		flatpos[u] = ++fptr;

		int maxchd = -1;
		for (int v : tree[u]) {
			if (v == pa[0][u]) continue;
			if (maxchd == -1 || subsize[maxchd] < subsize[v]) maxchd = v;
		}
		if (maxchd != -1) decompose(maxchd);

		for (int v : tree[u]) {
			if (v == pa[0][u] || v == maxchd) continue;
			++lchain; decompose(v);
		}
	}

	int lca(int u, int v) {
		if (depth[u] < depth[v]) swap(u, v);

		int logu;
		for (logu = 1; 1 << logu <= depth[u]; logu++);
		logu--;

		int diff = depth[u] - depth[v];
		for (int i = logu; i >= 0; --i) {
			if ((diff >> i) & 1) u = pa[i][u];
		}
		if (u == v) return u;

		for (int i = logu; i >= 0; --i) {
			if (pa[i][u] != pa[i][v]) {
				u = pa[i][u];
				v = pa[i][v];
			}
		}
		return pa[0][u];
	}

	void update(int node, pair<int, int> val)
	{
		int pos = flatpos[node] + MAXN;
		maxtree[pos] = val;
		while (pos >>= 1)
		{
			maxtree[pos] = max(maxtree[pos << 1], maxtree[pos << 1 | 1]);
		}
	}

	// TODO: implement query functions
	inline pair<int, int> query(int s, int e) {
		pair<int, int> ret; s += MAXN; e += MAXN;
		while (s <= e)
		{
			if (s & 1) ret = max(ret, maxtree[s++]);
			if (!(e & 1)) ret = max(ret, maxtree[e--]);
			s >>= 1; e >>= 1;
		}
		return ret;
	}

	pair<int, int> subquery(int u, int v) {
		int uchain, vchain = cidx[v];
		pair<int, int> ret;
		for (;;) {
			uchain = cidx[u];
			if (uchain == vchain) {
				ret = max(ret, query(flatpos[v], flatpos[u]));
				break;
			}

			ret = max(ret, query(flatpos[chead[uchain]], flatpos[u]));
			u = pa[0][chead[uchain]];
		}
		return ret;
	}

	inline pair<int, int> hldquery(int u, int v) {
		int p = lca(u, v);
		pair<int, int> old = query(flatpos[p], flatpos[p]);
		update(p, { -1, -1 });
		pair<int, int> ret = max(subquery(u, p), subquery(v, p));
		update(p, old);
		return ret;
	}
};

hld hl;

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		parent[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		scanf("%d", &dat[i].v);
	}

	for (int i = 0; i < m; i++)
	{
		scanf("%d", &dat[i].w);
	}

	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &dat[i].s, &dat[i].e);
		dat[i].s--; dat[i].e--;
		dat[i].idx = i + 1;
	}

	sort(dat, dat + m);

	long long initans = 0;

	for (int i = 0; i < m; i++)
	{
		if (treed[i] = merge(dat[i].s, dat[i].e))
		{
			hl.tree[dat[i].s].push_back(dat[i].e);
			hl.tree[dat[i].e].push_back(dat[i].s);
			initans += dat[i].v;
		}
	}

	int S;
	scanf("%d", &S);
	for (int i = 0; i < m; i++) dat[i].w = S / dat[i].w;

	hl.init(n);
	hl.decompose(0);
	int maxw = -1;

	for (int i = 0; i < m; i++)
	{
		if (treed[i])
		{
			if (hl.pa[0][dat[i].s] == dat[i].e)
			{
				hl.update(dat[i].s, { dat[i].v, i });
			}
			else
			{
				hl.update(dat[i].e, { dat[i].v, i });
			}

			if (maxw == -1 || dat[maxw].w < dat[i].w) maxw = i;
		}
	}

	long long ans = initans - dat[maxw].w;
	int addedge = -1; int removed = -1; int dis = maxw;

	for (int i = 0; i < m; i++)
	{
		if (treed[i]) continue;

		auto q = hl.hldquery(dat[i].s, dat[i].e);

		if (ans > initans - q.first + dat[i].v - dat[i].w)
		{
			ans = initans - q.first + dat[i].v - dat[i].w;
			addedge = i;
			removed = q.second;
			dis = addedge;
		}
	}

	printf("%lld\n", ans);
	for (int i = 0; i < m; i++)
	{
		if (treed[i] && i == removed) continue;
		if (!treed[i] && i != addedge) continue;

		printf("%d %d\n", dat[i].idx, i == dis ? (dat[i].v - dat[i].w) : (dat[i].v));
	}
}