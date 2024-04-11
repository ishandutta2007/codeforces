/*
dis = 1 : gcd(a, b) != 1
dis = 2 : minfac(a) * minfac(b) <= n
dis = 3 : 2 * max(minfac(a), minfac(b)) <= n

dis = 0 : 2 * max(minfac(a), minfac(b)) > n && dis != 1
*/
#include <bits/stdc++.h>
using namespace std;

const int Maxn = 10000005;
int n, cnt, prim[Maxn], phi[Maxn], ct[Maxn], mini[Maxn];
bool vis[Maxn];
long long cnt1, cnt2, cnt3, cnt0, ans;
void init(void)
{
	for (int i = 2; i <= n; i++)
	{
		if (!vis[i]) prim[++cnt] = i, phi[i] = i - 1, mini[i] = i;
		for (int j = 1; j <= cnt && i * prim[j] <= n; j++)
		{
			vis[i * prim[j]] = true;
			mini[i * prim[j]] = min(mini[i], prim[j]);
			if (i % prim[j] == 0)
			{
				phi[i * prim[j]] = phi[i] * prim[j];
				break;
			}
			phi[i * prim[j]] = phi[i] * (prim[j] - 1);
		}
	}
	cnt1 = n * (n - 1LL) / 2;
	for (int i = 1; i <= n; i++)
		ct[mini[i]]++, cnt1 -= phi[i];
	for (int i = 1; i <= n; i++)
		ct[i] += ct[i - 1];
	for (int i = 1; i <= cnt; i++)
	{
		if (prim[i] <= n / 2) cnt3 += (ct[prim[i]] - ct[prim[i] - 1]) * (long long) (ct[n / 2] - ct[max(n / prim[i], prim[i])]);
		cnt0 += (ct[prim[i]] - ct[prim[i] - 1]) * (long long) (ct[n] - ct[max(n / 2, prim[i])]);
	}
	cnt2 = (n - 2) * (n - 1LL) / 2 - cnt1 - cnt3 - cnt0;
}
int main()
{
	scanf("%d", &n);
	init();
	printf("%lld", cnt1 + cnt2 * 2 + cnt3 * 3);
	return 0;
}