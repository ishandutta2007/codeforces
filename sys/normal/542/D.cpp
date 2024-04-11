#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005;
long long A, fac[Maxn], f[Maxn], g[Maxn];
pair <long long, int> a[Maxn];
int ct, lim, cnt, prim[Maxn], B[Maxn];
map <long long, int> Ma;
bool vis[Maxn];
void init(void)
{
	for (int i = 2; i <= lim; i++)
	{
		if (!vis[i]) prim[++cnt] = i;
		for (int j = 1; j <= cnt && i * prim[j] <= lim; j++)
		{
			vis[i * prim[j]] = true;
			if (i % prim[j] == 0) break;
		}
	}
}
int get_basis(long long x)
{
	if (x <= 1) return 0;
	for (int i = 1; i <= cnt; i++)
		if (x % prim[i] == 0)
		{
			while (x % prim[i] == 0) x /= prim[i];
			if (x == 1) return prim[i];
			else return 0;
		}
	return x;
}
int main()
{
	scanf("%lld", &A);
	if (A == 2) return puts("0"), 0;
	lim = sqrt(A);
	init();
	while (prim[cnt] > lim) cnt--;
	for (int i = 1; i <= cnt; i++)
	{
		long long tmp = prim[i];
		while (tmp <= lim) B[tmp] = prim[i], tmp *= prim[i];
	}
	for (int i = 1; i <= lim; i++)
		if (A % i == 0)
			Ma[i] = 1, Ma[A / i] = 1;
	for (map <long long, int> :: iterator it = Ma.begin(); it != Ma.end(); it++)
		it -> second = ++ct, fac[ct] = it -> first;
	for (int i = 1; i <= ct; i++)
	{
		long long p = get_basis(fac[i] - 1);
		a[i] = make_pair(p, i);
	}
	sort(a + 1, a + 1 + ct);
	f[1] = 1;
	for (int i = 1; i <= ct; i++)
	{
		if (!a[i].first) continue;
		if (a[i].first != a[i - 1].first)
			memcpy(g, f, sizeof(long long[ct + 1]));
		for (int j = 1; j <= ct; j++)
			if (g[j] && (A / fac[j]) % fac[a[i].second] == 0)
				f[Ma[fac[a[i].second] * fac[j]]] += g[j];
	}
	printf("%lld", f[ct]);
	return 0;
}