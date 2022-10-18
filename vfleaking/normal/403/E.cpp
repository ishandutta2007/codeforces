#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <climits>
#include <iterator>
using namespace std;

const int MaxN = 200000;
const int MaxLogN = 18;

template <class T>
inline void tension(T &a, const T &b)
{
	if (b < a)
		a = b;
}

class TreeQuerier
{
private:
	struct halfEdge
	{
		int u;
		halfEdge *next;
	};
	halfEdge adj_pool[(MaxN - 1) * 2], *adj_tail;
	halfEdge *adj[MaxN + 1];

	int n;
	int depth[MaxN + 1];
	int fa[MaxN + 1][MaxLogN + 1];

	halfEdge *oppo(halfEdge *e)
	{
		return adj_pool + ((e - adj_pool) ^ 1);
	}
	void addEdge(int v, int u)
	{
		adj_tail->u = u, adj_tail->next = adj[v], adj[v] = adj_tail++;
	}

	int dfsCnt;
	int dfsSeq[MaxN + 1];
	int posL[MaxN + 1], posR[MaxN + 1];

	void dfs(int v)
	{
		dfsSeq[posL[v] = ++dfsCnt] = v;

		depth[v] = depth[fa[v][0]] + 1;
		for (int j = 0; fa[v][j]; j++)
			fa[v][j + 1] = fa[fa[v][j]][j];

		for (halfEdge *e = adj[v]; e; e = e->next)
			if (e->u != fa[v][0])
				fa[e->u][0] = v, dfs(e->u);

		posR[v] = dfsCnt;
	}

	int getLca(int v, int u)
	{
		if (depth[v] < depth[u])
			swap(v, u);
		for (int k = 0, d = depth[v] - depth[u]; d > 0; k++, d >>= 1)
			if (d & 1)
				v = fa[v][k];

		if (v == u)
			return v;

		int k = 0;
		while (k >= 0)
		{
			if (fa[v][k] == fa[u][k])
				k--;
			else
				v = fa[v][k], u = fa[u][k], k++;
		}
		return fa[v][0];
	}

	struct otherItem
	{
		int id;
		int lcaD;
		int v, u;

		friend inline bool operator<(const otherItem &lhs, const otherItem &rhs)
		{
			return lhs.lcaD < rhs.lcaD;
		}
	};

	bool otherExist[MaxN + 1];
	vector<otherItem> otherLi[MaxN + 1];

	otherItem otherLi_min(int v)
	{
		if (otherLi[v].empty())
		{
			otherItem t;
			t.lcaD = INT_MAX;
			return t;
		}
		return otherLi[v].back();
	}

	static const int MaxTN = 1 << 18;

	int zkw_n;
	otherItem zkw[MaxTN << 1 | 1];

	void zkw_init()
	{
		for (zkw_n = 1; zkw_n - 2 < n; zkw_n <<= 1);

		for (int i = 1; i <= n; i++)
			zkw[zkw_n + i] = otherLi_min(dfsSeq[i]);
		for (int i = zkw_n - 1; i >= 1; i--)
			zkw[i] = min(zkw[i << 1 | 0], zkw[i << 1 | 1]);
	}
	void zkw_update_v(int pos)
	{
		zkw[zkw_n + pos] = otherLi_min(dfsSeq[pos]);
		for (int i = (zkw_n + pos) >> 1; i >= 1; i >>= 1)
			zkw[i] = min(zkw[i << 1 | 0], zkw[i << 1 | 1]);
	}
	otherItem zkw_query(int le, int ri)
	{
		otherItem res;
		res.lcaD = INT_MAX;
		for (le += zkw_n - 1, ri += zkw_n + 1; le ^ ri ^ 1; le >>= 1, ri >>= 1)
		{
			if (~le & 1)
				tension(res, zkw[le ^ 1]);
			if (ri & 1)
				tension(res, zkw[ri ^ 1]);
		}
		return res;
	}

public:
	void init(const int &_n, const int *a, const int *b)
	{
		n = _n;

		adj_tail = adj_pool;
		for (int v = 1; v <= n; v++)
			adj[v] = NULL;
		for (int v = 2; v <= n; v++)
		{
			int u = a[v];
			addEdge(v, u), addEdge(u, v);
		}

		dfsCnt = 0;
		depth[0] = 0;
		fa[1][0] = 0, dfs(1);

		for (int v = 2; v <= n; v++)
		{
			int u = b[v];

			int id = v - 1;

			otherExist[id] = true;

			otherItem t;
			t.id = id;
			t.lcaD = depth[getLca(v, u)];
			t.v = v, t.u = u;
			otherLi[v].push_back(t);

			t.v = u, t.u = v;
			otherLi[u].push_back(t);
		}
		
		for (int v = 1; v <= n; v++)
		{
			sort(otherLi[v].begin(), otherLi[v].end());
			reverse(otherLi[v].begin(), otherLi[v].end());
		}

		zkw_init();
	}

	template <class OIt>
	OIt erase(int eId, OIt out)
	{
		halfEdge *e = adj_pool + ((eId - 1) << 1);
		int v = oppo(e)->u, u = e->u;
		if (depth[v] < depth[u])
			swap(v, u);

		otherItem it;
		while (it = zkw_query(posL[v], posR[v]), it.lcaD < depth[v])
		{
			otherLi[it.v].pop_back(), zkw_update_v(posL[it.v]);
			if (otherExist[it.id])
				otherExist[it.id] = false, *out++ = it.id;
		}

		return out;
	}
};

int main()
{
	int n;
	static int a[MaxN + 1], b[MaxN + 1];
	static TreeQuerier qA, qB;

	cin >> n;
	for (int v = 2; v <= n; v++)
		scanf("%d", &a[v]);
	for (int v = 2; v <= n; v++)
		scanf("%d", &b[v]);

	qA.init(n, a, b);
	qB.init(n, b, a);

	int col = 0;
	vector<int> eIdLiA, eIdLiB;

	int stIdx;
	scanf("%d", &stIdx);
	eIdLiA.push_back(stIdx);

	while (!eIdLiA.empty())
	{
		if (col == 0)
			printf("Blue\n");
		else
			printf("Red\n");
		for (vector<int>::iterator it = eIdLiA.begin(); it != eIdLiA.end(); it++)
			printf("%d ", *it);
		printf("\n");
		for (vector<int>::iterator it = eIdLiA.begin(); it != eIdLiA.end(); it++)
		{
			if (col == 0)
				qA.erase(*it, back_inserter(eIdLiB));
			else
				qB.erase(*it, back_inserter(eIdLiB));
		}

		sort(eIdLiB.begin(), eIdLiB.end());
		if (col == 1)
			eIdLiB.erase(remove(eIdLiB.begin(), eIdLiB.end(), stIdx), eIdLiB.end());

		col = !col;
		eIdLiA.clear();
		eIdLiA.swap(eIdLiB);
	}

	return 0;
}