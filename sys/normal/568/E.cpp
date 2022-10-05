#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
int n, k, m, ct, spa_ct, lis[Maxn], spa[Maxn], a[Maxn], b[Maxn], tmp[Maxn], mini[Maxn], pos[Maxn], from[Maxn];
bool used[Maxn];
int main()
{
	memset(mini, 0x3f, sizeof(mini));
	mini[0] = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	a[++n] = 0x3f3f3f3f;
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
		scanf("%d", &b[i]);
	sort(b + 1, b + 1 + m);
	for (int i = 1; i <= n; i++)
	{
		if (a[i] != -1)
		{
			int now = lower_bound(mini, mini + 1 + ct, a[i]) - mini;
			lis[i] = now;
			mini[now] = a[i];
			pos[now] = i;
			from[i] = pos[now - 1];
			if (now == ct + 1) ct++;
		}
		else
		{
			spa[++spa_ct] = i;
			memcpy(tmp, mini, sizeof(int[ct + 1]));
			int pnt = 0;
			for (int j = 1; j <= m; j++)
			{
				while (pnt <= ct && tmp[pnt] < b[j]) pnt++;
				if (b[j] <= mini[pnt])
				{
					pos[pnt] = i;
					from[i] = pos[pnt - 1];
					mini[pnt] = b[j];
					lis[i] = pnt;
				}
			}
			if (pnt == ct + 1) ct++;
		}
	}
	int las;
	for (int i = n; i >= 1; )
	{
		A:if (a[i] != -1)
			las = a[i], i = from[i];
		else
		{
			int tmp_pos = 0;
			for (int j = 1; j < i; j++)
				if (a[j] != -1 && lis[j] == lis[n] && a[j] < las)
					tmp_pos = j;
			if (tmp_pos)
			{
				i = tmp_pos;
				goto A;
			}
			else
			{
				int now = lower_bound(b + 1, b + 1 + m, las) - b - 1;
				las = a[i] = b[now];
				used[now] = true;
				for (int j = 1; j < i; j++)
					if (a[j] != -1 && lis[j] == lis[n] - 1 && a[j] < a[i])
						tmp_pos = j;
				if (!tmp_pos) tmp_pos = *(lower_bound(spa + 1, spa + 1 + spa_ct, i) - 1);
				i = tmp_pos;
			}
		}
		lis[n]--;
		if (!lis[n]) break;
	}
	int pnt = 1;
	for (int i = 1; i <= n; i++)
		if (a[i] == -1)
		{
			while (used[pnt]) pnt++;
			a[i] = b[pnt], pnt++;
		}
	for (int i = 1; i < n; i++)
		printf("%d ", a[i]);
	return 0;
}