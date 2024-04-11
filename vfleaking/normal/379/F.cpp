#include <iostream>
#include <cstdio>
using namespace std;

const int MaxNQ = 500000;
const int MaxN = 4 + MaxNQ * 2;
const int MaxLogN = 20;

int n;
int fa[MaxN + 1][MaxLogN + 1];
int depth[MaxN + 1];

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

inline int getLca(int v, int u)
{
	if (depth[v] < depth[u])
		swap(v, u);
	for (int j = 0, t = depth[v] - depth[u]; t > 0; t >>= 1, j++)
		if (t & 1)
			v = fa[v][j];
	if (v == u)
		return v;

	int k = 0;
	while (k >= 0)
	{
		if (fa[v][k] == fa[u][k])
			k--;
		else
		{
			v = fa[v][k], u = fa[u][k];
			k++;
		}
	}
	return fa[v][0];
}
inline int getDist(int v, int u)
{
	int lca = getLca(v, u);
	return depth[v] + depth[u] - 2 * depth[lca];
}

int main()
{
	n = 4;
	fa[1][0] = 0, depth[1] = 0;
	fa[2][0] = 1, depth[2] = 1;
	fa[3][0] = 1, depth[3] = 1;
	fa[4][0] = 1, depth[4] = 1;

	int nQ;
	cin >> nQ;

	int d = 2, dA = 2, dB = 4;

	while (nQ--)
	{
		int v;
		scanf("%d", &v);

		n++;
		fa[n][0] = v;
		for (int j = 0; fa[n][j]; j++)
			fa[n][j + 1] = fa[fa[n][j]][j];
		depth[n] = depth[v] + 1;

		n++;
		fa[n][0] = v;
		for (int j = 0; fa[n][j]; j++)
			fa[n][j + 1] = fa[fa[n][j]][j];
		depth[n] = depth[v] + 1;

		int d1 = getDist(n, dA);
		int d2 = getDist(n, dB);
		if (d1 > d2 && relax(d, d1))
			dB = n;
		else if (d2 >= d1 && relax(d, d2))
			dA = n;

		printf("%d\n", d);
	}

	return 0;
}