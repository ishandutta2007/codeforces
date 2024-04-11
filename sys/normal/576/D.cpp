#include <bits/stdc++.h>
using namespace std;

const int Maxn = 155;
int n, m;
struct Matrix
{
	bitset <Maxn> val[Maxn];
	void init(void)
	{
		for (int i = 0; i < Maxn; i++)
			val[i].reset();
	}
	Matrix operator * (const Matrix &A) const
	{
		Matrix ans;
		for (int j = 1; j <= n; j++)
			for (int i = 1; i <= n; i++)
				if (val[i][j]) ans.val[i] |= A.val[j];
		return ans;
	}
}G, resG, tmp;
struct edg
{
	int x, y, d;
	bool operator < (const edg &tmp) const
	{
		return d < tmp.d;
	}
}edge[Maxn];
Matrix fast_pow(Matrix x, int y)
{
	Matrix ans = x, now = x;
	y--;
	while (y)
	{
		if (y & 1) ans = ans * now;
		now = now * now;
		y >>= 1;
	}
	return ans;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
		scanf("%d%d%d", &edge[i].x, &edge[i].y, &edge[i].d);
	sort(edge + 1, edge + 1 + m);
	if (edge[1].d)
	{
		printf("Impossible");
		return 0;
	}
	for (int i = 1; i <= n; i++)
		resG.val[i].set(i);
	for (int i = 1; i <= m; i++)
	{
		G.init();
		for (int j = 1; j <= i; j++)
			G.val[edge[j].x].set(edge[j].y);
		tmp = resG;
		for (int j = 1; j <= n; j++)
		{
			tmp = tmp * G;
			if (tmp.val[1].test(n))
			{
				printf("%d", edge[i].d + j);
				return 0;
			}
		}
		if (i != m && edge[i + 1].d != edge[i].d)
			resG = resG * fast_pow(G, edge[i + 1].d - edge[i].d);
	}
	printf("Impossible");
	return 0;
}