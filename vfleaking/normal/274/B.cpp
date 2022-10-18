#include <iostream>
#include <cstdio>
using namespace std;

// type
typedef long long s64;

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
const int MaxNEdge = MaxN - 1;

struct halfEdge
{
    int u;
    halfEdge *next;
};
halfEdge adj_pool[MaxNEdge * 2], *adj_tail = adj_pool;

int n;
halfEdge *adj[MaxNVer + 1];
int val[MaxN + 1];

inline void addEdge(const int &v, const int &u)
{
    adj_tail->u = u;
    adj_tail->next = adj[v], adj[v] = adj_tail++;
}

pair<s64, s64> dfs(const int &v, const int &father)
{
	pair<s64, s64> res(0ll, 0ll);
	for (halfEdge *i = adj[v]; i; i = i->next)
		if (i->u != father)
		{
			pair<s64, s64> ret = dfs(i->u, v);
			relax(res.first, ret.first);
			relax(res.second, ret.second);
		}
	s64 t = val[v] + res.first - res.second;
	if (t < 0)
		res.first += -t;
	else
		res.second += t;
	return res;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int v, u;
		scanf("%d %d", &v, &u);

		addEdge(v, u);
		addEdge(u, v);
	}
	for (int i = 1; i <= n; i++)
		scanf("%d", &val[i]);

	pair<s64, s64> res = dfs(1, 0);
	cout << res.first + res.second << endl;

	return 0;
}