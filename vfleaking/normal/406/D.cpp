#include <iostream>
#include <cstdio>
using namespace std;

typedef long long s64;

const int MaxN = 100000;
const int MaxLogN = 17;

struct point
{
	s64 x, y;
};
inline s64 cross(const point &a, const point &o, const point &b)
{
	return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

int main()
{
	int n;
	static point po[MaxN + 1];

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> po[i].x >> po[i].y;
	
	static int fa[MaxN + 1][MaxLogN + 1];
	static int depth[MaxN + 1];

	int sta_n = 0;
	static int sta[MaxN];

	depth[n] = 0;
	sta[sta_n++] = n;
	for (int i = n - 1; i >= 1; i--)
	{
		while (sta_n >= 2 && cross(po[sta[sta_n - 1]], po[i], po[sta[sta_n - 2]]) > 0)
			sta_n--;
		fa[i][0] = sta[sta_n - 1], depth[i] = depth[fa[i][0]] + 1;
		for (int j = 0; fa[i][j]; j++)
			fa[i][j + 1] = fa[fa[i][j]][j];
		sta[sta_n++] = i;
	}

	int nQ;
	cin >> nQ;
	while (nQ--)
	{
		int v, u;
		scanf("%d %d", &v, &u);

		if (depth[v] < depth[u])
			swap(v, u);
		for (int k = 0, delta = depth[v] - depth[u]; delta > 0; k++, delta >>= 1)
			if (delta & 1)
				v = fa[v][k];
		if (v == u)
			printf("%d ", v);
		else
		{
			int k = 0;
			while (k >= 0)
			{
				if (fa[v][k] == fa[u][k])
					k--;
				else
					v = fa[v][k], u = fa[u][k], k++;
			}
			printf("%d ", fa[v][0]);
		}
	}

	printf("\n");

	return 0;
}