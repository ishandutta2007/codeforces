#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005, p = 1e9 + 7;
int n, a[Maxn], cnt1[Maxn], cnt2[Maxn], pos[Maxn], val[Maxn], to[Maxn], from[Maxn];
long long ans = 1, fac[Maxn];
vector <int> F[Maxn];
void init(void)
{
	fac[0] = 1;
	for (int i = 1; i <= n; i++) val[i] = 1, fac[i] = fac[i - 1] * i % p;
	for (int i = 2; i <= n; i++)
		if (!F[i].size())
		{
			cnt2[n / i]++, pos[i] = n / i;
			for (int j = i; j <= n; j += i)
				F[j].push_back(i), val[j] *= i;
		}
	for (int i = 1; i <= n; i++)
		cnt1[val[i]]++;
	pos[1] = 1;
	cnt2[1]++;
	F[1].push_back(1);
}
int main()
{
	scanf("%d", &n);
	init();
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
		if (a[i])
		{
			cnt1[val[a[i]]]--;
			if (F[i].size() != F[a[i]].size())
			{
				puts("0");
				return 0;
			}
			for (int j = 0; j < (int) F[i].size() - 1; j++)
				if (F[i][j] != F[a[i]][j])
				{
					puts("0");
					return 0;
				}
			int x = *F[i].rbegin(), y = *F[a[i]].rbegin();
			if (pos[x] != pos[y])
			{
				puts("0");
				return 0;
			}
			if (to[x] && to[x] != y)
			{
				puts("0");
				return 0;
			}
			if (from[y] && from[y] != x)
			{
				puts("0");
				return 0;
			}
			if (!from[y] && !to[x]) cnt2[pos[x]]--;
			from[y] = x, to[x] = y;
		}
	for (int i = 1; i <= n; i++)
		(ans *= fac[cnt1[i]] * fac[cnt2[i]] % p) %= p;
	printf("%lld", ans);
	return 0;
}