#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int T, n, m, x, y, Free, ord[Maxn], c[Maxn], ans[Maxn], ans2[Maxn], cnt[Maxn], b[Maxn];
vector <int> Ve[Maxn];
struct cmp
{
	bool operator () (const int x, const int y)
	{
		if (cnt[x] == cnt[y]) return x < y;
		return cnt[x] < cnt[y];
	}
};
priority_queue <int, vector <int>, cmp> Pr;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d", &n, &x, &y);
		memset(cnt, 0, sizeof(int[n + 2]));
		memset(ans, 0, sizeof(int[n + 1]));
		for (int i = 1; i <= n + 1; i++) Ve[i].clear();
		while (!Pr.empty()) Pr.pop();
		m = 0;
		if (x > y)
		{
			puts("NO");
			continue;
		}
		y -= x;
		for (int i = 1; i <= n; i++)
			scanf("%d", &b[i]), Ve[b[i]].push_back(i), cnt[b[i]]++;
		for (int i = 1; i <= n + 1; i++)
			if (!cnt[i]) Free = i;
		for (int i = 1; i <= n + 1; i++)
			Pr.push(i);
		while (x--)
		{
			int now = Pr.top();
			Pr.pop();
			cnt[now]--;
			ans[*Ve[now].rbegin()] = now;
			Ve[now].pop_back();
			Pr.push(now);
		}
		memset(cnt, 0, sizeof(int[n + 3]));
		for (int i = 1; i <= n; i++)
			if (!ans[i]) c[++m] = b[i];
		for (int i = m - y; i >= 1; i--)
			c[++m] = Free;
		int maxi = 0;
		for (int i = 1; i <= m; i++)
		{
			cnt[c[i]]++;
			if (cnt[c[i]] > cnt[maxi]) maxi = c[i];
		}
		if (2 * cnt[maxi] > m)
		{
			puts("NO");
			continue;
		}
		puts("YES");
		for (int i = 1; i <= m; i++)
			ord[i] = i;
		sort(ord + 1, ord + 1 + m, [](int x, int y){return c[x] < c[y];});
		for (int i = 1; i <= m; i++)
			ans2[ord[(i + m / 2 - 1) % m + 1]] = c[ord[i]];
		int tmp_ct = 0;
		for (int i = 1; i <= n; i++)
			if (!ans[i]) ans[i] = ans2[++tmp_ct];
		for (int i = 1; i <= n; i++)
			printf("%d ", ans[i]);
		puts("");
	}
	return 0;
}