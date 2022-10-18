#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;

const int MaxN = 100000;

template <class T>
inline void relax(T &a, const T &b)
{
	if (b > a)
		a = b;
}

inline int getint()
{
	char c;
	while (c = getchar(), ('0' > c || c > '9') && c != '-');

	if (c != '-')
	{
		int res = c - '0';
		while (c = getchar(), '0' <= c && c <= '9')
			res = res * 10 + c - '0';
		return res;
	}
	else
	{
		int res = 0;
		while (c = getchar(), '0' <= c && c <= '9')
			res = res * 10 + c - '0';
		return -res;
	}
}

struct halfEdge
{
	int u, w;
	halfEdge *next;
};
halfEdge adj_pool[(MaxN - 1) * 2], *adj_tail = adj_pool;

int n;
halfEdge *faE[MaxN + 1];
bool isSpec[MaxN + 1];
int up[MaxN + 1];
int down[MaxN + 1];
halfEdge *downE1[MaxN + 1], *downE2[MaxN + 1], *downE3[MaxN + 1];
halfEdge *adj[MaxN + 1];

int outcome[MaxN + 1];

inline void addEdge(const int &v, const int &u, const int &w)
{
	adj_tail->u = u, adj_tail->w = w;
	adj_tail->next = adj[v], adj[v] = adj_tail++;
}

inline halfEdge *opposite(const halfEdge *e)
{
	if (!e)
		return NULL;
	return adj_pool + ((e - adj_pool) ^ 1);
}

inline int getDownEVal(const halfEdge *e)
{
	if (!e)
		return INT_MIN;
	if (down[e->u] == INT_MIN)
		return INT_MIN;
	return e->w + down[e->u];
}
inline int getUpEVal(const halfEdge *e)
{
	if (!e)
		return INT_MIN;
	if (up[e->u] == INT_MIN)
		return INT_MIN;
	return e->w + up[e->u];
}
inline halfEdge *getFirstMaxEWhenUp(const halfEdge *e)
{
	if (!e)
		return NULL;
	if (!downE1[e->u])
		return NULL;
	if (downE1[e->u] != opposite(e))
		return downE1[e->u];
	else if (downE2[e->u])
		return downE2[e->u];
	else
		return NULL;
}
inline halfEdge *getSecondMaxEWhenUp(const halfEdge *e)
{
	if (!e)
		return NULL;
	if (!downE1[e->u] || !downE2[e->u])
		return NULL;
	if (downE1[e->u] != opposite(e) && downE2[e->u] != opposite(e))
		return downE2[e->u];
	else
		return downE3[e->u];
}

inline void calc()
{
	static int q[MaxN];
	int top, bot;

	top = bot = 0;
	faE[1] = NULL, q[bot++] = 1;
	while (top != bot)
	{
		int v = q[top++];
		for (halfEdge *e = adj[v]; e; e = e->next)
			if (e != faE[v])
				faE[e->u] = opposite(e), q[bot++] = e->u;
	}

	for (int i = n - 1; i >= 0; i--)
	{
		int v = q[i];
		for (halfEdge *e = adj[v]; e; e = e->next)
			if (e != faE[v])
			{
				if (getDownEVal(e) > getDownEVal(downE1[v]))
					downE3[v] = downE2[v], downE2[v] = downE1[v], downE1[v] = e;
				else if (getDownEVal(e) > getDownEVal(downE2[v]))
					downE3[v] = downE2[v], downE2[v] = e;
				else if (getDownEVal(e) > getDownEVal(downE3[v]))
					downE3[v] = e;
			}
		down[v] = getDownEVal(downE1[v]);
		if (isSpec[v])
			relax(down[v], 0);
	}

	up[1] = INT_MIN;
	for (int i = 1; i < n; i++)
	{
		int v = q[i];
		up[v] = getUpEVal(opposite(faE[faE[v]->u]));

		halfEdge *maxE = getFirstMaxEWhenUp(faE[v]);
		if (maxE)
			relax(up[v], getDownEVal(maxE));
		if (isSpec[faE[v]->u])
			relax(up[v], 0);
	}

	static int cntGoUp[MaxN + 1];
	static int cntGoDown[MaxN + 1];

	for (int v = 1; v <= n; v++)
		if (isSpec[v])
		{
			int upWay = faE[v] ? faE[v]->w + up[v] : INT_MIN;
			int downWay = down[v];
			if (upWay == downWay)
				continue;
			if (upWay > downWay)
				outcome[v]++, cntGoUp[v]++;
			else
				cntGoDown[v]++;
		}
	for (int i = n - 1; i >= 0; i--)
	{
		int v = q[i];
		int cur = cntGoUp[v];
		if (cur == 0)
			continue;

		outcome[faE[v]->u] += cur;
		if (isSpec[v] && up[v] == 0)
			continue;
		
		int upWay = getUpEVal(opposite(faE[faE[v]->u]));
		halfEdge *firstMaxE = getFirstMaxEWhenUp(faE[v]);
		halfEdge *secondMaxE = getSecondMaxEWhenUp(faE[v]);
		int downWay = getDownEVal(firstMaxE);
		if (upWay == downWay)
			continue;
		if (upWay > downWay)
			cntGoUp[faE[v]->u] += cur;
		else if (getDownEVal(firstMaxE) > getDownEVal(secondMaxE))
			cntGoDown[firstMaxE->u] += cur;
	}
	for (int i = 0; i < n; i++)
	{
		int v = q[i];
		int cur = cntGoDown[v];
		if (cur == 0)
			continue;

		outcome[v] += cur;
		if (isSpec[v] && down[v] == 0)
			continue;
		if (!downE1[v])
			continue;
		if (downE2[v] && getDownEVal(downE1[v]) == getDownEVal(downE2[v]))
			continue;
		cntGoDown[downE1[v]->u] += cur;
	}
}

int main()
{
	int m;

	cin >> n >> m;
	for (int i = 0; i < m; i++)
		isSpec[getint()] = true;
	for (int i = 0; i < n - 1; i++)
	{
		int v = getint(), u = getint(), w = getint();
		addEdge(v, u, w), addEdge(u, v, w);
	}

	calc();

	int res = 0, nRes = 0;
	for (int v = 1; v <= n; v++)
		if (!isSpec[v])
		{
			if (outcome[v] > res)
				res = outcome[v], nRes = 1;
			else if (outcome[v] == res)
				nRes++;
		}
	cout << res << " " << nRes << endl;

	return 0;
}