#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MaxN = 100000;
const int MaxM = 100000;
const int MaxLogN = 17;

int n;
int depth[MaxN + 1];
int root;
int father[MaxN + 1][MaxLogN + 1];
vector<int> child[MaxN + 1];

struct node
{
	int sum;
	node *left, *right;
};
node pool[MaxN * 2 + (2 * MaxM) * (MaxLogN + 1)];
node *tail = pool;

inline node *newNode()
{
	if (tail - pool > sizeof(pool) / sizeof(node))
		exit(0);
	return tail++;
}

inline node *seg_init(const int &pL, const int &pR)
{
	node *res = newNode();

	if (pL == pR)
	{
		res->left = res->right = NULL;
		res->sum = 0;
	}
	else
	{
		int pMid = pL + pR >> 1;
		res->left = seg_init(pL, pMid);
		res->right = seg_init(pMid + 1, pR);
		res->sum = res->left->sum + res->right->sum;
	}
	return res;
}
inline node *seg_add(
		const node *p,
		const int &pL, const int &pR,
		const int &pos, const int &delta)
{
	node *res = newNode();
	*res = *p;
	if (pL == pR)
	{
		res->sum += delta;
		return res;
	}

	int pMid = pL + pR >> 1;
	if (pos <= pMid)
		res->left = seg_add(p->left, pL, pMid, pos, delta);
	else
		res->right = seg_add(p->right, pMid + 1, pR, pos, delta);
	res->sum = res->left->sum + res->right->sum;
	return res;
}
inline int seg_query(
		const node *p,
		const int &pL, const int &pR,
		const int &qL, const int &qR)
{
	if (qL <= pL && pR <= qR)
		return p->sum;

	int pMid = pL + pR >> 1;

	int res = 0;
	if (qL <= pMid)
		res += seg_query(p->left, pL, pMid, qL, qR);
	if (pMid < qR)
		res += seg_query(p->right, pMid + 1, pR, qL, qR);
	return res;
}

int seqLen = 0;
int occur1[MaxN + 1], occur2[MaxN + 1];
void dfs(const int &cur)
{
	seqLen++;
	occur1[cur] = seqLen;
	for (vector<int>::iterator i = child[cur].begin();
		 i != child[cur].end();
		 i++)
	{
		depth[*i] = depth[cur] + 1;
		for (int j = 0, k = father[*i][0]; k != 0; k = father[k][j], j++)
			father[*i][j] = k;

		dfs(*i);
	}

	seqLen++;
	occur2[cur] = seqLen;
}

node *timeAxis[MaxM + 1];
int attacked[MaxM + 1];

inline int getLCA(int v, int u)
{
	if (depth[v] < depth[u])
		swap(v, u);

	int deltaDepth = depth[v] - depth[u];
	for (int i = 0; i < MaxLogN; i++)
		if (deltaDepth & 1 << i)
			v = father[v][i];

	if (v == u)
		return v;

	int step = 0;
	while (step >= 0)
	{
		if (father[v][step] != father[u][step])
		{
			v = father[v][step];
			u = father[u][step];
			step++;
		}
		else
			step--;
	}
	return father[v][0];
}

inline int queryTree(const int &timeS, const int &timeE,
					 const int &v, const int &u, const int &lca)
{
	int l1, r1, l2, r2;
	l1 = l2 = occur1[lca] + 1;
	r1 = occur1[v];
	r2 = occur1[u];

	int res = depth[v] + depth[u] - depth[lca] * 2 + 1;

	if (l1 <= r1)
		res -=   seg_query(timeAxis[timeE], 1, seqLen, l1, r1)
			   - seg_query(timeAxis[timeS], 1, seqLen, l1, r1);
	if (l2 <= r2)
		res -=   seg_query(timeAxis[timeE], 1, seqLen, l2, r2)
			   - seg_query(timeAxis[timeS], 1, seqLen, l2, r2);
	res -= timeS < attacked[lca] && attacked[lca] <= timeE ? 1 : 0;
	return res;
}

inline int findKth(const int &timeS, const int &timeE,
				   const int &v, const int &k)
{
	int cur = v;
	int step = 0;

	while (step >= 0)
	{
		int t = father[cur][step];
		if (queryTree(timeS, timeE, v, t, t) < k)
		{
			cur = t;
			step++;
		}
		else
			step--;
	}
	return queryTree(timeS, timeE, v, cur, cur) < k ? father[cur][0] : cur;
}

inline void handleAttack(const int &year, const int &v)
{
	timeAxis[year] = seg_add(timeAxis[year - 1],
							 1, seqLen,
							 occur1[v], 1);
	timeAxis[year] = seg_add(timeAxis[year],
							 1, seqLen,
							 occur2[v], -1);
	attacked[v] = year;
}
inline int handleKing(const int &year,
					  const int &v, const int &u,
					  const int &k, const int &y)
{
	timeAxis[year] = timeAxis[year - 1];

	int lca = getLCA(v, u);
	int cntAll = queryTree(y, year, v, u, lca);
	int cntLeft = queryTree(y, year, v, lca, lca);

	int num = k;
	if (y >= attacked[v] || attacked[v] > year)
		num++;
	if (y >= attacked[u] || attacked[u] > year)
		cntAll--;

	if (num > cntAll)
		return -1;
	else if (num <= cntLeft)
		return findKth(y, year, v, num);
	else
		return findKth(y, year, father[u][0], cntAll - num + 1);
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &father[i][0]);
		child[father[i][0]].push_back(i);

		if (father[i][0] == 0)
			root = i;
	}

	depth[1] = 0;
	dfs(root);
	timeAxis[0] = seg_init(1, n * 2);

	int m;
	cin >> m;
	for (int year = 1; year <= m; year++)
	{
		int type;
		int c, a, b, k, y;
		scanf("%d", &type);

		switch (type)
		{
			case 1:
				scanf("%d", &c);
				handleAttack(year, c);
				break;
			case 2:
				scanf("%d %d %d %d", &a, &b, &k, &y);
				printf("%d\n", handleKing(year, a, b, k, y));
				break;
		}
	}

	return 0;
}