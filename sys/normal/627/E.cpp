#include <bits/stdc++.h>
using namespace std;

const int Maxn = 3005;
int r, c, n, k, ct[Maxn], cnt[Maxn], dis[Maxn], nxt[Maxn], pre[Maxn];
vector <int> Ve[Maxn];
long long sum, ans;
void cal(int x, int w)
{
	if (!x) return ;
	int u = dis[x];
	while (ct[x] < k)
	{
		u = nxt[u];
		if (!u)
		{
			dis[x] = c + 1;
			return ;
		}
		ct[x] += cnt[u];
	}
	dis[x] = u;
	sum += (long long) w * (x - pre[x]) * (c - dis[x] + 1);
}
int main()
{
	scanf("%d%d%d%d", &r, &c, &n, &k);
	for (int i = 1; i <= n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		Ve[x].push_back(y);
	}
	for (int i = 1; i <= r; i++)
	{
		sum = 0;
		memset(ct, 0, sizeof(int[c + 1]));
		for (int j = i; j <= r; j++)
			for (vector <int> :: iterator it = Ve[j].begin(); it != Ve[j].end(); it++)
				cnt[*it]++;
		int las = 0;
		for (int j = 1; j <= c; j++)
			if (cnt[j]) nxt[las] = j, pre[j] = las, las = j;
		for (int j = 1; j <= c; j++)
			if (cnt[j])
			{
				int now = j, tmp = cnt[j];
				while (tmp < k)
				{
					now = nxt[now];
					if (!now) break;
					tmp += cnt[now];
				}
				if (now) sum += (j - pre[j]) * (c - now + 1LL), dis[j] = now, ct[j] = tmp;
				else dis[j] = c + 1;
			}
		for (int j = r; j >= i; j--)
		{
			ans += sum;
			for (vector <int> :: iterator it = Ve[j].begin(); it != Ve[j].end(); it++)
			{
				int now = *it;
				cnt[*it]--;
				if (!cnt[*it])
				{
					cal(*it, -1), cal(nxt[*it], -1);
					if (pre[*it]) nxt[pre[*it]] = nxt[*it];
					if (nxt[*it]) pre[nxt[*it]] = pre[*it];
					cal(nxt[*it], 1);
					now = pre[*it];
				}
				while (now && dis[now] >= *it)
				{
					cal(now, -1);
					ct[now]--;
					cal(now, 1);
					now = pre[now];
				}
			}
		}
	}
	printf("%lld", ans);
	return 0;
}