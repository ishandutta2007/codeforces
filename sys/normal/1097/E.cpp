#include <bits/stdc++.h>
using namespace std;
 
const int Maxn = 100005;
int T, n, k, ct, pnt, a[Maxn], mini[Maxn], from[Maxn];
bool type, vis[Maxn];
vector <int> tmp, Ve[Maxn];
void work(void)
{
	pnt = 0;
	a[0] = type ? 0x3f3f3f3f : -0x3f3f3f3f;
	mini[1] = 0;
	for (int i = 1; i <= n; i++)
	{
		int pos = lower_bound(mini + 1, mini + 1 + pnt, i, [](int x, int y){return (type ? a[x] : -a[x]) < (type ? a[y] : -a[y]);}) - mini;
		mini[pos] = i;
		from[i] = mini[pos - 1];
		if (pos == pnt + 1) pnt++;
	}
}
void cal(void)
{
	ct++;
	memset(vis, 0, sizeof(bool[n + 1]));
	Ve[ct].clear();
	int u = mini[pnt];
	while (u)
	{
		vis[u] = true;
		u = from[u];
	}
	for (int i = 1; i <= n; i++)
		if (vis[i]) Ve[ct].push_back(a[i]);
	tmp.clear();
	for (int i = 1; i <= n; i++)
		if (!vis[i]) tmp.push_back(a[i]);
	n = tmp.size();
	for (int i = 1; i <= n; i++)
		a[i] = tmp[i - 1];
}
set <pair <int, int> > Se;
void work2(int limit)
{
	Se.clear();
	for (int i = 1; i <= limit; i++)
		Se.insert(make_pair(0, ++ct)), Ve[ct].clear();
	for (int i = 1; i <= n; i++)
	{
		pair <int, int> now = *(--Se.lower_bound(make_pair(a[i], 0)));
		Se.erase(now);
		Ve[now.second].push_back(a[i]);
		Se.insert(make_pair(a[i], now.second));
	}
}
int Rand(int x)
{
	return (rand() * RAND_MAX + rand()) % x;
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		ct = 0;
		scanf("%d", &n);
		int k = 0;
		while (k * (k + 1) / 2 < n) k++;
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		type = false;
		while (n)
		{
			work();
			if (pnt < k && !type)
			{
				work2(pnt);
				break;
			}
			else cal(), k--;
		}
		printf("%d\n", ct);
		for (int i = 1; i <= ct; i++)
		{
			printf("%d ", (int) Ve[i].size());
			for (vector <int> :: iterator it = Ve[i].begin(); it != Ve[i].end(); it++)
				printf("%d ", *it);
			puts("");
		}
	}
	return 0;
}