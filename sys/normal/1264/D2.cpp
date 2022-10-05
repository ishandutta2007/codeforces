#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005, p = 998244353;
int n, cntl, cntr, cnt1, cnt2;
long long ans, fac[Maxn], inv[Maxn];
string str;
long long get_inv(long long x)
{
	if (x <= 1) return 1;
	return (p - p / x) * get_inv(p % x) % p;
}
void init(void)
{
	fac[0] = inv[0] = 1;
	for (int i = 1; i <= n; i++)
		fac[i] = fac[i - 1] * i % p;
	inv[n] = get_inv(fac[n]);
	for (int i = n - 1; i >= 0; i--)
		inv[i] = inv[i + 1] * (i + 1) % p;
}
long long C(int x, int y)
{
	if (x < y || x < 0 || y < 0) return 0;
	return fac[x] * inv[y] % p * inv[x - y] % p;
}
int main()
{
	cin >> str;
	n = str.size();
	init();
	for (int i = 0; i < n; i++)
	{
		if (str[i] == '?') cnt2++;
		if (str[i] == ')') cntr++;
	}
	for (int i = 0; i < n; i++)
	{
		(ans += cntl * C(cnt1 + cnt2, cnt2 + cntr - cntl) + cnt1 * C(cnt1 + cnt2 - 1, cnt2 - cntl + cntr - 1)) %= p;
		if (str[i] == ')') cntr--;
		if (str[i] == '(') cntl++;
		if (str[i] == '?') cnt1++, cnt2--;
	}
	printf("%lld", ans);
	return 0;
}