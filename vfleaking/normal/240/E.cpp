#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int MaxN = 100000;
const int MaxM = 100000;

struct edge
{
	int v, u, w;
	int id;

	static inline bool lessw(const edge &lhs, const edge &rhs)
	{
		return lhs.w < rhs.w;
	}
};

struct le_node
{
	edge e;
	int delta;
	int dep;
	le_node *lc, *rc;

	inline void add_delta(int d)
	{
		delta += d;
		e.w += d;
	}
	inline void tag_down()
	{
		if (lc)
			lc->add_delta(delta);
		if (rc)
			rc->add_delta(delta);
		delta = 0;
	}

	static le_node pool[], *tail;

	static le_node *atom(edge e)
	{
		le_node *p = tail++;
		p->e = e;
		p->delta = 0;
		p->dep = 0;
		p->lc = p->rc = NULL;
		return p;
	}

	static le_node *merge(le_node *lhs, le_node *rhs)
	{
		if (!lhs)
			return rhs;
		if (!rhs)
			return lhs;
		if (!edge::lessw(lhs->e, rhs->e))
			swap(lhs, rhs);

		lhs->tag_down();

		lhs->rc = merge(lhs->rc, rhs);

		if (!lhs->lc || lhs->lc->dep < lhs->rc->dep)
			swap(lhs->lc, lhs->rc);
		lhs->dep = lhs->lc->dep + 1;
		return lhs;
	}
};
le_node le_node::pool[MaxM], *le_node::tail = le_node::pool;

int ufs_find(int *ufs, int v)
{
	return v == ufs[v] ? v : ufs[v] = ufs_find(ufs, ufs[v]);
}

bool solveMDST(int n, le_node **inE, int r)
{
	static bool book[MaxN + 1];

	int sta_n;
	static int sta[MaxN];
	static bool insta[MaxN + MaxN + 1];

	static int outer[MaxN + MaxN + 1];
	static int ufs[MaxN + MaxN + 1];
	static int next[MaxN + MaxN + 1];
	for (int v = 1; v <= n; v++)
	{
		book[v] = false;
		outer[v] = ufs[v] = v;
		next[v] = 0;
	}
	for (int v = 1; v <= n + n; v++)
		insta[v] = false;

	inE[r] = NULL;
	book[r] = true;

	for (int sv = 1; sv <= n; sv++)
		if (!book[sv])
		{
			int m = 0;
			
			sta_n = 0;
			sta[sta_n++] = sv, insta[sv] = true;

			while (true)
			{
				int v = sta[sta_n - 1];
				if (v <= n && book[v])
				{
					insta[v] = false, sta_n--;
					break;
				}

				while (inE[v] && ufs_find(ufs, inE[v]->e.v) == ufs_find(ufs, inE[v]->e.u))
					inE[v]->tag_down(), inE[v] = le_node::merge(inE[v]->lc, inE[v]->rc);

				if (!inE[v])
					return false;

				int u = ufs_find(ufs, inE[v]->e.v);
				if (insta[u])
				{
					m++;
					outer[n + m] = ufs[n + m] = n + m;
					next[n + m] = 0;
					inE[n + m] = NULL;

					int pos_u = sta_n;
					while (sta[--pos_u] != u);

					for (int k = pos_u; k < sta_n; k++)
					{
						int vm = sta[k];
						next[vm] = ufs_find(ufs, inE[vm]->e.v);

						inE[vm]->tag_down();

						le_node *rest = le_node::merge(inE[vm]->lc, inE[vm]->rc);
						if (rest)
							rest->add_delta(-inE[vm]->e.w), inE[n + m] = le_node::merge(inE[n + m], rest);

						inE[vm]->lc = inE[vm]->rc = NULL;
					}
					for (int k = pos_u; k < sta_n; k++)
					{
						int vm = sta[k];
						outer[vm] = ufs[vm] = n + m;
						insta[vm] = false;
					}
					sta_n = pos_u;

					u = n + m;
				}

				insta[u] = true, sta[sta_n++] = u;
			}

			while (sta_n > 0)
			{
				int v = sta[--sta_n];
				insta[v] = false;
				if (v > n)
				{
					int vs = inE[v]->e.u;
					int vm = vs;
					int dw = 0;
					do
					{
						for (int u = next[vm]; u != vm; u = next[u])
							sta[sta_n++] = u, insta[u] = true;
						dw += inE[vm]->e.w;
						vm = outer[vm];
					}
					while (vm != v);

					inE[vs] = inE[v], inE[vs]->e.w += dw;
					inE[vs]->lc = inE[vs]->rc = NULL, book[vs] = true;
					ufs[vs] = vs;
				}
				else
				{
					inE[v]->lc = inE[v]->rc = NULL, book[v] = true;
					ufs[v] = v;
				}
			}
		}
	return true;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m;
	cin >> n >> m;
	
	static le_node *inE[MaxN + MaxN + 1];
	for (int i = 1; i <= m; i++)
	{
		int v, u, c;
		scanf("%d %d %d", &v, &u, &c);

		inE[u] = le_node::merge(inE[u], le_node::atom((edge){.v = v, .u = u, .w = c, .id = i}));
	}

	if (!solveMDST(n, inE, 1))
		printf("-1\n");
	else
	{
		vector<int> res;
		for (int v = 2; v <= n; v++)
			if (inE[v]->e.w == 1)
				res.push_back(inE[v]->e.id);
		sort(res.begin(), res.end());
		printf("%d\n", (int)res.size());
		for (int i = 0; i < (int)res.size(); i++)
			printf("%d ", res[i]);
		printf("\n");
	}
	
	return 0;
}