#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MaxN = 100000;

// adjust
template <class T>
inline bool relax(T &a, const T &b)
{
	if (b > a)
	{
		a = b;
		return true;
	}
	return false;
}
template <class T>
inline bool tension(T &a, const T &b)
{
	if (b < a)
	{
		a = b;
		return true;
	}
	return false;
}

// adj tab
const int MaxNVer = MaxN;
const int MaxNEdge = MaxN * 2;

struct halfEdge
{
    int u;
    halfEdge *next;
};
halfEdge adj_pool[MaxNEdge], *adj_tail = adj_pool;

int n;
halfEdge *adj[MaxNVer + 1];

inline void addEdge(const int &v, const int &u)
{
    adj_tail->u = u;
    adj_tail->next = adj[v], adj[v] = adj_tail++;
}

int main()
{
	int n, cK, cP;
	cin >> n >> cK >> cP;

	for (int i = 0; i < n - 1; i++)
	{
		int v, u;
		scanf("%d %d", &v, &u);
		addEdge(v, u), addEdge(u, v);
	}

	int q_n = 0;
	static int q[MaxN];
	static int dep[MaxN + 1];
	dep[1] = 1, q[q_n++] = 1;
	for (int i = 0; i < q_n; i++)
	{
		int v = q[i];
		for (halfEdge *e = adj[v]; e; e = e->next)
			if (!dep[e->u])
				dep[e->u] = dep[v] + 1, q[q_n++] = e->u;
	}

	int res = 0;

	sort(dep + 1, dep + n + 1);
	int p = 2;
	int sum = 0;
	for (int i = 2; i <= n; i++)
	{
		sum += (i - p) * (dep[i] - dep[i - 1]);
		while (sum > cP)
			sum -= dep[i] - dep[p], p++;
		relax(res, min(i - p + 1, cK));
	}

	cout << res << endl;

	return 0;
}