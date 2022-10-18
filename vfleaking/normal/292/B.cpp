#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MaxN = 100000;
const int MaxM = 100000;

// adj tab
const int MaxNVer = MaxN;
const int MaxNEdge = MaxM * 2;

struct halfEdge
{
    int u;
    halfEdge *next;
};
halfEdge adj_pool[MaxNEdge], *adj_tail = adj_pool;

int n, m;
halfEdge *adj[MaxNVer + 1];

inline void addEdge(const int &v, const int &u)
{
    adj_tail->u = u;
    adj_tail->next = adj[v], adj[v] = adj_tail++;
}

int main()
{
	cin >> n >> m;

	static int deg[MaxN + 1];
	for (int i = 1; i <= m; i++)
	{
		int v, u;
		scanf("%d %d", &v, &u);

		addEdge(v, u);
		addEdge(u, v);

		deg[v]++, deg[u]++;
	}

	bool isBus = count(deg + 1, deg + n + 1, 1) == 2 && count(deg + 1, deg + n + 1, 2) == n - 2;
	bool isRing = count(deg + 1, deg + n + 1, 2) == n;
	if (isRing)
	{
		static int q[MaxN];
		static bool book[MaxN + 1];
		int top = 0, bot = 0;

		book[1] = true, q[bot++] = 1;
		while (top != bot)
		{
			int v = q[top++];
			for (halfEdge *i = adj[v]; i; i = i->next)
				if (!book[i->u])
					book[i->u] = true, q[bot++] = i->u;
		}

		isRing = bot == n;
	}

	bool isStar = count(deg + 1, deg + n + 1, n - 1) == 1 && count(deg + 1, deg + n + 1, 1) == n - 1;

	if (isBus)
		cout << "bus topology" << endl;
	else if (isRing)
		cout << "ring topology" << endl;
	else if (isStar)
		cout << "star topology" << endl;
	else
		cout << "unknown topology" << endl;

	return 0;
}