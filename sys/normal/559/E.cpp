#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;
int n, ans, f[Maxn][Maxn][3];
struct line
{
	int a, l;
	bool operator < (const line &tmp) const
	{
		return a < tmp.a;
	}
}L[Maxn];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &L[i].a, &L[i].l);
	sort(L + 1, L + 1 + n);
	L[0].a = -0x3f3f3f3f;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= i; j++)
			for (int p = 0; p <= 1; p++)
			{
				ans = max(ans, f[i][j][p]);
				int res = L[j].a + p * L[j].l, maxi = -0x3f3f3f3f, x, y;
				for (int k = i + 1; k <= n; k++)
					for (int q = 0; q <= 1; q++)
					{
						int now = L[k].a + q * L[k].l;
						if (now > maxi) maxi = now, x = k, y = q;
						f[k][x][y] = max(f[k][x][y], f[i][j][p] + min(L[k].l, now - res) + maxi - now);
					}
			}
	printf("%d", ans);
	return 0;
}