#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MaxN = 100000;
const int MaxM = 100000;
const int MaxNM = 100000;

// adj tab
const int MaxNVer = MaxM + MaxNM;
const int MaxNEdge = MaxNM * 2;

struct halfEdge
{
    int u;
    halfEdge *next;
};
halfEdge adj_pool[MaxNEdge], *adj_tail = adj_pool;

halfEdge *adj[MaxNVer + 1];

inline void addEdge(const int &v, const int &u)
{
    adj_tail->u = u;
    adj_tail->next = adj[v], adj[v] = adj_tail++;
}

template <class T>
struct CompareInArray
{
	const T *a;
	CompareInArray(const int *_a) : a(_a){}

	inline bool operator()(const int &lhs, const int &rhs)
	{
		return a[lhs] < a[rhs];
	}
};

int main()
{
	int n, m;
	static int mat_pool[MaxNM + MaxN];
	static int *mat[MaxN + 1];

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		mat[i] = mat_pool + (m + 1) * (i - 1);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &mat[i][j]);

	int nVer = m;
	for (int i = 1; i <= n; i++)
	{
		int len = 0;
		static int seq[MaxM];

		for (int j = 1; j <= m; j++)
			if (mat[i][j] != -1)
				seq[len++] = j;
		sort(seq, seq + len, CompareInArray<int>(mat[i]));

		for (int ii = 0, jj = 0; ii < len; ii = jj)
		{
			while (jj < len && mat[i][seq[ii]] == mat[i][seq[jj]])
				jj++;
			if (ii != 0)
				for (int k = ii; k < jj; k++)
					addEdge(nVer, seq[k]);
			if (jj != len)
			{
				nVer++;
				for (int k = ii; k < jj; k++)
					addEdge(seq[k], nVer);
			}
		}
	}

	static int q[MaxNVer];
	int top, bottom;
	static int degree[MaxNVer + 1];

	for (int v = 1; v <= nVer; v++)
		for (halfEdge *i = adj[v]; i; i = i->next)
			degree[i->u]++;

	top = bottom = 0;
	for (int v = 1; v <= nVer; v++)
		if (degree[v] == 0)
			q[bottom++] = v;

	while (top != bottom)
	{
		int v = q[top++];
		for (halfEdge *i = adj[v]; i; i = i->next)
			if (--degree[i->u] == 0)
				q[bottom++] = i->u;
	}

	if (bottom != nVer)
		cout << "-1" << endl;
	else
	{
		for (int i = 0; i < bottom; i++)
			if (q[i] <= m)
				printf("%d ", q[i]);
		cout << endl;
	}

	return 0;
}