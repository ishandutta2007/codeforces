#include <bits/stdc++.h>
using namespace std;

const int Maxn = 20000005;
int T, cnt, prim[Maxn], ct[Maxn];
bool vis[Maxn];
long long ans;
void init(void)
{
	for (int i = 2; i <= 2e7; i++)
	{
		if (!vis[i]) prim[++cnt] = i, ct[i] = 1;
		for (int j = 1; j <= cnt && i * prim[j] <= 2e7; j++)
		{
			vis[i * prim[j]] = true;
			if (i % prim[j] == 0)
			{
				ct[i * prim[j]] = ct[i];
				break;
			}
			ct[i * prim[j]] = ct[i] + 1;
		}
	}
}
long long c, d;
int x;
void work(int g)
{
	if ((x + d * g) % c) return ;
	long long l = (x + d * g) / c;
	if (l % g == 0) ans += 1 << ct[l / g];
}
int main()
{
	init();
	scanf("%d", &T);
	while (T--)
	{
		ans = 0;
		scanf("%lld%lld%d", &c, &d, &x);
		int maxi = sqrt(x);
		for (int j = 1; j <= maxi; j++)
		{
			if (x % j == 0)
			{
				work(j);
				if (j * j != x) work(x / j);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}