#include <bits/stdc++.h>
using namespace std;

const int Maxn = 800005;
int T, n, ans, res, s, l[Maxn], r[Maxn], a[Maxn], ct, cnt, lt[Maxn], rt[Maxn], sum[Maxn];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		ans = -1;
		res = cnt = s = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d%d", &l[i], &r[i]), a[2 * i - 1] = l[i], a[2 * i] = r[i];
		sort(a + 1, a + 1 + 2 * n);
		int ct = unique(a + 1, a + 1 + 2 * n) - a - 1;
		memset(sum, 0, sizeof(int[2 * ct + 2]));
		for (int i = 1; i <= n; i++)
		{
			l[i] = lower_bound(a + 1, a + 1 + ct, l[i]) - a;
			r[i] = lower_bound(a + 1, a + 1 + ct, r[i]) - a;
			sum[2 * l[i]]++, sum[2 * r[i] + 1]--;
		}
		for (int i = 1; i <= 2 * ct + 1; i++)
		{
			sum[i] += sum[i - 1];
			if (sum[i] != sum[i - 1] && sum[i - 1] == 1)
				lt[++cnt] = s, rt[cnt] = i - 1;
			if (sum[i] != sum[i - 1] && !sum[i - 1]) res++;
			if (sum[i] != sum[i - 1])
				s = i;
		}
		if (!cnt)
		{
			printf("%d\n", res);
			continue;
		}
		for (int i = 1; i <= n; i++)
		{
			int tmp = (int)(upper_bound(rt + 1, rt + 1 + cnt, 2 * r[i]) - rt) - (int)(lower_bound(lt + 1, lt + 1 + cnt, 2 * l[i]) - lt);
			if (!sum[2 * l[i] - 1] && sum[2 * l[i]] == 1) tmp--;
			if (!sum[2 * r[i] + 1] && sum[2 * r[i]] == 1) tmp--;
			ans = max(ans, tmp);
		}
		printf("%d\n", ans + res);
	}
	return 0;
}