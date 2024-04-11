#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MaxN = 100000;

struct halfEdge
{
	int u;
	halfEdge *next;
};

int n;
int numVA[MaxN + 1], numVB[MaxN + 1];
vector<int> flag[MaxN + 1];
halfEdge pool[(MaxN - 1) * 2];
halfEdge *tail = pool;
halfEdge *adj[MaxN + 1];

inline void addEdge(const int &v, const int &u)
{
	tail->u = u, tail->next = adj[v], adj[v] = tail++;
}

int seqLen = 0;
int inPos[MaxN + 1], outPos[MaxN + 1];
void dfs(const int &v, const int &father)
{
	inPos[v] = ++seqLen;
	for (halfEdge *i = adj[v]; i; i = i->next)
		if (i->u != father)
			dfs(i->u, v);
	outPos[v] = seqLen;
}

struct node
{
	int d, l;
};
node tree[MaxN * 4];

inline void seg_add(
		const int &p, const int &pL, const int &pR,
		const int &qL, const int &qR, const int &val)
{
	if (qL <= pL && pR <= qR)
		tree[p].d += val;
	else
	{
		int pMid = pL + pR >> 1;
		if (qL <= pMid)
			seg_add(p << 1, pL, pMid, qL, qR, val);
		if (pMid < qR)
			seg_add(p << 1 | 1, pMid + 1, pR, qL, qR, val);
	}
	tree[p].l = 0;
	if (pL != pR)
		tree[p].l = tree[p << 1].l + tree[p << 1 | 1].l;
	if (tree[p].d > 0)
		tree[p].l = pR - pL + 1;
}

int outcome[MaxN + 1];
void calcOutcome(const int &v, const int &father)
{
	for (vector<int>::iterator i = flag[v].begin(); i != flag[v].end(); i++)
	{
		seg_add(1, 1, seqLen, inPos[numVA[*i]], outPos[numVA[*i]], 1);
		seg_add(1, 1, seqLen, inPos[numVB[*i]], outPos[numVB[*i]], 1);
	}
	outcome[v] = max(tree[1].l - 1, 0);
	
	for (halfEdge *i = adj[v]; i; i = i->next)
		if (i->u != father)
			calcOutcome(i->u, v);
	
	for (vector<int>::iterator i = flag[v].begin(); i != flag[v].end(); i++)
	{
		seg_add(1, 1, seqLen, inPos[numVA[*i]], outPos[numVA[*i]], -1);
		seg_add(1, 1, seqLen, inPos[numVB[*i]], outPos[numVB[*i]], -1);
	}
}

int main()
{
	int m;
	
	cin >> n >> m;
	for (int i = 1; i < n; i++)
	{
		int v, u;
		scanf("%d %d", &v, &u);
		
		addEdge(v, u);
		addEdge(u, v);
	}
	
	dfs(1, 0);
	
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		flag[a].push_back(i);
		flag[b].push_back(i);
		numVA[i] = a, numVB[i] = b;
	}
	
	calcOutcome(1, 0);
	
	for (int i = 1; i <= n; i++)
		printf("%d ", outcome[i]);
	cout << endl;
	
	return 0;
}