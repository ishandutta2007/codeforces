#include <bits/stdc++.h>
using namespace std;

const int Maxn = 500005;
int T, n, a[Maxn], mini[Maxn][20], maxi[Maxn][20];
int get_mini(int lt, int rt)
{
	int Range = log2(rt - lt + 1);
	return a[mini[lt][Range]] < a[mini[rt - (1 << Range) + 1][Range]] ? mini[lt][Range] : mini[rt - (1 << Range) + 1][Range];
}
int get_maxi(int lt, int rt)
{
	int Range = log2(rt - lt + 1);
	return a[maxi[lt][Range]] > a[maxi[rt - (1 << Range) + 1][Range]] ? maxi[lt][Range] : maxi[rt - (1 << Range) + 1][Range];
}
int work(int lt, int rt)
{
	if (lt >= rt) return 0;
	int pos1 = get_mini(lt, rt), pos2 = get_maxi(lt, rt);
	if (pos1 > pos2) swap(pos1, pos2);
	return work(lt, pos1) + 1 + work(pos2, rt);
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]), mini[i][0] = maxi[i][0] = i;
		for (int j = 1; (1 << j) <= n; j++)
			for (int i = 1; i + (1 << j) - 1 <= n; i++)
			{
				mini[i][j] = a[mini[i][j - 1]] < a[mini[i + (1 << (j - 1))][j - 1]] ? mini[i][j - 1] : mini[i + (1 << (j - 1))][j - 1];
				maxi[i][j] = a[maxi[i][j - 1]] > a[maxi[i + (1 << (j - 1))][j - 1]] ? maxi[i][j - 1] : maxi[i + (1 << (j - 1))][j - 1];
			}
		printf("%d\n", work(1, n));
	}
	return 0;
}