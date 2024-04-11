#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005;
int T, n, x, ct, cnt[35], a[Maxn];
vector <int> Ve[Maxn];
bool vis[Maxn];
map <int, int> Ma;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		Ma.clear();
		ct = 0;
		int ans = 0;
		scanf("%d%d", &n, &x);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			int c = 0;
			while (a[i] % x == 0) a[i] /= x, c++;
			if (!Ma[a[i]]) Ma[a[i]] = ++ct;
			Ve[Ma[a[i]]].push_back(c);
		}
		for (int i = 1; i <= ct; i++)
		{
			memset(cnt, 0, sizeof(cnt));
			for (auto u : Ve[i]) cnt[u]++;
			Ve[i].clear();
			for (int i = 0; i <= 30; i++)
			{
				int c = min(cnt[i], cnt[i + 1]);
				cnt[i] -= c, cnt[i + 1] -= c, ans += 2 * c;
			}
		}
		printf("%d\n", n - ans);
	}
	return 0;
}