#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1 << 21 | 5, p = 998244353, inv2 = (p + 1) / 2;
void FWT(int now[], int n)
{
	for (int i = 1; i < n; i <<= 1)
		for (int j = 0; j < n; j += (i << 1))
			for (int k = j; k < i + j; k++)
			{
				int x = now[k], y = now[i + k];
				now[k] = (x + y) % p;
				now[i + k] = (x - y + p) % p;
			}
}
void IFWT(int now[], int n)
{
	for (int i = 1; i < n; i <<= 1)
	for (int j = 0; j < n; j += (i << 1))
		for (int k = j; k < i + j; k++)
		{
			int x = now[k], y = now[i + k];
			now[k] = (x + y) % p * (long long) inv2 % p;
			now[i + k] = (x - y + p) % p * (long long) inv2 % p;
		}
}
int n, m, a[Maxn], b[Maxn], ans[Maxn], val[Maxn], cnt[Maxn], mini = 0x3f3f3f3f;
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			int x;
			scanf("%1d", &x);
			val[j] |= x << i;
		}
	for (int i = 0; i < m; i++)
		a[val[i]]++;
	for (int i = 0; i < (1 << n); i++)
		cnt[i] = cnt[i >> 1] + (i & 1);
	for (int i = 0; i < (1 << n); i++)
		b[i] = min(cnt[i], n - cnt[i]);
	FWT(a, 1 << n), FWT(b, 1 << n);
	for (int i = 0; i < (1 << n); i++)
		ans[i] = a[i] * (long long) b[i] % p;
	IFWT(ans, 1 << n);
	for (int i = 0; i < (1 << n); i++)
		mini = min(mini, ans[i]);
	printf("%d", mini);
	return 0;
}