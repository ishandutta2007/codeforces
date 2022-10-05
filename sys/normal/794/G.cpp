#include <bits/stdc++.h>
using namespace std;

const int Maxn = 600005, p = 1e9 + 7;
string s, t;
bool vis[Maxn];
int n, cnt, cnt1, cnt2, c1, c2, prim[Maxn];
long long ans, sum, S[Maxn], mu[Maxn], fac[Maxn], inv[Maxn];
long long fast_pow(long long x, long long y)
{
	long long ans = 1, now = x;
	while (y)
	{
		if (y & 1) ans = ans * now % p;
		now = now * now % p;
		y >>= 1;
	}
	return ans;
}
void init(void)
{
	S[0] = 1;
	for (int i = 1; i <= 300000; i++)
		S[i] = (S[i - 1] * 2 + 1) % p;
	fac[0] = 1;
	for (int i = 1; i <= 600000; i++)
		fac[i] = fac[i - 1] * i % p;
	inv[600000] = fast_pow(fac[600000], p - 2);
	for (int i = 600000 - 1; i >= 0; i--)
		inv[i] = inv[i + 1] * (i + 1) % p;
	mu[1] = 1;
	for (int i = 2; i <= 600000; i++)
	{
		if (!vis[i]) prim[++cnt] = i, mu[i] = p - 1;
		for (int j = 1; j <= cnt && i * prim[j] <= 600000; j++)
		{
			vis[i * prim[j]] = true;
			if (i % prim[j] == 0) break;
			mu[i * prim[j]] = (p - mu[i]) % p;
		}
	}
}
long long C(int x, int y)
{
	if (x < y) return 0;
	return fac[x] * inv[y] % p * inv[x - y] % p;
}
long long f(int x, int y)
{
	if (!x && !y) return sum;
	if (x * (long long) y >= 0) return 0;
	x = abs(x), y = abs(y);
	return S[n / max(x / __gcd(x, y), y / __gcd(x, y))] - 1;
}
int main()
{
	cin >> s >> t >> n;
	init();
	long long now = 1;
	for (int d = 1; d <= n; d++)
	{
		(now *= 2) %= p;
		for (int i = d; i <= n; i += d)
			(sum += (n / i) * (long long) (n / i) % p * now % p * mu[i / d] % p) %= p;
	}
	int sizS = s.size(), sizT = t.size();
	for (int i = 0; i < sizS; i++)
		if (s[i] == 'A') cnt1++;
		else if (s[i] == 'B') cnt2++;
		else c1++;
	for (int i = 0; i < sizT; i++)
		if (t[i] == 'A') cnt1--;
		else if (t[i] == 'B') cnt2--;
		else c2++;
	for (int i = -c2; i <= c1; i++)
		(ans += f(cnt1 + i, cnt2 + c1 - c2 - i) * C(c1 + c2, c1 - i)) %= p;
	if (sizS == sizT)
	{
		int tmp_cnt = 0;
		for (int i = 0; i < sizS; i++)
		{
			if (s[i] == '?' && t[i] == '?') tmp_cnt++;
			if (s[i] == 'A' && t[i] == 'B') goto END;
			if (s[i] == 'B' && t[i] == 'A') goto END;
		}
		for (int i = 0; i <= tmp_cnt; i++)
			(ans += ((S[n] - 1) * (S[n] - 1) % p - sum + p) * C(tmp_cnt, i)) %= p;
	}
	END:printf("%lld", ans);
	return 0;
}