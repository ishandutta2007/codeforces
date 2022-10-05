#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005, p = 998244353;
int n, m, t[Maxn], cnt[Maxn];
long long ans = 0, prod = 1, sum[Maxn];
long long get_inv(int x)
{
	return x <= 1 ? x : (p - p / x) * get_inv(p % x) % p;
}
int lowbit(int x)
{
	return x & -x;
}
void add(int x, long long y)
{
	for (int i = x; i <= 200000; i += lowbit(i))
		(sum[i] += y) %= p;
}
long long ask(int x)
{
	long long res = 0;
	for (int i = x; i; i -= lowbit(i))
		(res += sum[i]) %= p;
	return res;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1, x; i <= n; i++)
		scanf("%d", &x), cnt[x]++;
	for (int i = 1; i <= 200000; i++)
	{
		int tmp = cnt[i];
		add(i, cnt[i]);
		while (tmp) (prod *= tmp) %= p, tmp--;
	}
	prod = get_inv(prod);
	for (int i = 1; i <= n; i++) (prod *= i) %= p;
	for (int i = 1; i <= m; i++)
		scanf("%d", &t[i]);
	for (int i = 1; i <= m; i++)
	{
		if (i == n + 1)
		{
			ans = (ans + 1) % p;
			break;
		}
		(prod *= get_inv(n - i + 1)) %= p;
		(ans += prod * ask(t[i] - 1)) %= p;
		if (cnt[t[i]])
		{
			add(t[i], p - cnt[t[i]]);
			(prod *= cnt[t[i]]) %= p;
			cnt[t[i]]--;
			add(t[i], cnt[t[i]]);
		}
		else break;
	}
	printf("%lld", ans);
}