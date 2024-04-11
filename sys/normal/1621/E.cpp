#include <bits/stdc++.h>
using namespace std;
 
const int Maxn = 100005;
int T, n, m, k[Maxn], rk[Maxn], ok1[Maxn], ok2[Maxn], ok3[Maxn], ord[Maxn];
vector <int> v[Maxn];
long long a[Maxn], sum[Maxn];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
			scanf("%lld", &a[i]);
		sort(a + 1, a + 1 + n);
		reverse(a + 1, a + 1 + n);
		reverse(a + 1, a + 1 + m);
		for (int i = 1; i <= m; i++)
		{
			sum[i] = 0;
			ord[i] = i;
			scanf("%d", &k[i]);
			v[i].resize(k[i] + 1);
			for (int j = 1; j <= k[i]; j++)
				scanf("%d", &v[i][j]), sum[i] += v[i][j];
		}
		sort(ord + 1, ord + 1 + m, [](int x, int y){return sum[x] * k[y] < sum[y] * k[x];});
		for (int i = 1; i <= m; i++) rk[ord[i]] = i;
		for (int i = 1; i <= m; i++)
			ok1[i] = ok1[i - 1] + (sum[ord[i]] > k[ord[i]] * a[i]);
		for (int i = 2; i <= m; i++)
			ok2[i] = ok2[i - 1] + (sum[ord[i]] > k[ord[i]] * a[i - 1]);
		for (int i = 1; i < m; i++)
			ok3[i] = ok3[i - 1] + (sum[ord[i]] > k[ord[i]] * a[i + 1]);
		for (int i = 1; i <= m; i++)
		{
			int pos1 = rk[i], pos2;
			for (int j = 1; j <= k[i]; j++)
			{
				int lt = 1, rt = m + 1;
				while (lt + 1 <= rt)
				{
					int mid = (lt + rt) >> 1;
					if ((sum[i] - v[i][j]) * k[ord[mid]] < sum[ord[mid]] * (k[i] - 1)) rt = mid;
					else lt = mid + 1;
				}
				pos2 = lt;
				if (pos1 < pos2) putchar((a[pos2 - 1] * (k[i] - 1) < sum[i] - v[i][j]) | ok1[pos1 - 1] | (ok1[m] - ok1[pos2 - 1]) | (ok2[pos2 - 1] - ok2[pos1]) ? '0' : '1');
				else if (a[pos2] * (k[i] - 1) < sum[i] - v[i][j]) putchar('0');
				else if (pos1 == pos2) putchar(ok1[m] - (a[pos1] * k[i] < sum[i]) ? '0' : '1');
				else putchar(ok1[pos2 - 1] | (ok1[m] - ok1[pos1]) | (ok3[pos1 - 1] - ok3[pos2 - 1]) ? '0' : '1');
			}
		}
		puts("");
	}
	return 0;
}