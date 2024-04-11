#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;
int n, m, q, ct, val[Maxn][Maxn], R[Maxn][Maxn], D[Maxn][Maxn];
short maxi[Maxn][Maxn][10][10];
int get_maxi(int lt1, int lt2, int rt1, int rt2)
{
	int Range1 = log2(lt2 - lt1 + 1), Range2 = log2(rt2 - rt1 + 1);
	return max(max(maxi[lt1][rt1][Range1][Range2], maxi[lt2 - (1 << Range1) + 1][rt1][Range1][Range2]), 
	max(maxi[lt1][rt2 - (1 << Range2) + 1][Range1][Range2], maxi[lt2 - (1 << Range1) + 1][rt2 - (1 << Range2) + 1][Range1][Range2]));
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &val[i][j]);
	for (int i = 1; i <= n; i++)
		for (int j = m; j >= 1; j--)
			if (val[i][j]) R[i][j] = R[i][j + 1] + 1;
			else R[i][j] = 0;
	for (int j = 1; j <= m; j++)
		for (int i = n; i >= 1; i--)
			if (val[i][j]) D[i][j] = D[i + 1][j] + 1;
			else D[i][j] = 0;
	for (int i = n; i >= 1; i--)
		for (int j = m; j >= 1; j--)
			maxi[i][j][0][0] = min(maxi[i + 1][j + 1][0][0] + 1, min(R[i][j], D[i][j]));
	for (int Range1 = 0; (1 << Range1) <= n; Range1++)
		for (int Range2 = 0; (1 << Range2) <= m; Range2++)
		{
			if (!Range1 && !Range2) continue;
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= m; j++)
					if (Range2)
						maxi[i][j][Range1][Range2] = max(maxi[i][j][Range1][Range2 - 1], maxi[i][min(m, j + (1 << (Range2 - 1)))][Range1][Range2 - 1]);
					else maxi[i][j][Range1][Range2] = max(maxi[i][j][Range1 - 1][Range2], maxi[min(n, i + (1 << (Range1 - 1)))][j][Range1 - 1][Range2]);
		}
	scanf("%d", &q);
	int lastans = 0;
	while (q--)
	{
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		if (a > c) swap(a, c);
		if (b > d) swap(b, d);
		int l = 0, r = min(d - b, c - a) + 1;
		while (l + 1 <= r)
		{
			int mid = (l + r + 1) >> 1;
			if (get_maxi(a, c - mid + 1, b, d - mid + 1) >= mid) l = mid;
			else r = mid - 1;
		}
		printf("%d\n", lastans = l);
	}
	return 0;
}