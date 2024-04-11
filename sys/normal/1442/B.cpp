#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005, p = 998244353;
int T, n, k, pos[Maxn], x[Maxn];
bool vis[Maxn];
struct cmp
{
	bool operator () (const int x, const int y) const
	{
		return pos[x] < pos[y];
	}
};
set <int, cmp> Se;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		long long ans = 1;
		scanf("%d%d", &n, &k);
		Se.clear();
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			pos[x] = i;
			Se.insert(x);
		}
		for (int i = 1; i <= k; i++)
		{
			scanf("%d", &x[i]);
			vis[x[i]] = true;
		}
		for (int i = 1; i <= k; i++)
		{
			int cnt = 0, now;
			set <int> :: iterator it = Se.find(x[i]);
			if (*it != *Se.rbegin())
			{
				it++;
				if (!vis[*it]) now = *it, cnt++;
				it--;
			}
			if (it != Se.begin())
			{
				it--;
				if (!vis[*it]) now = *it, cnt++;
				it++;
			}
			Se.erase(now);
			(ans *= cnt) %= p;
			vis[x[i]] = false;
		}
		printf("%lld\n", ans);
	}
	return 0;
}