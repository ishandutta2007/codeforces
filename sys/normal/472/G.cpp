#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1 << 19 | 5, p = 998244353;
string s, t;
int n, m, q, per, bloc, l[Maxn], bel[Maxn], rev[Maxn], dis[130][Maxn / 2];
void get_rev(int len)
{
	for (int i = 0; i < len; i++)
		rev[i] = (rev[i >> 1] >> 1) | ((i & 1) * (len >> 1));
}
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
void NTT(int now[], int len, bool type = false)
{
	l[0] = 1;
	for (int i = 0; i < len; i++)
		if (i < rev[i]) swap(now[i], now[rev[i]]);
	for (int i = 1; i < len; i <<= 1)
	{
		long long w = fast_pow(type ? 332748118 : 3, (p - 1) / (i << 1));
		for (int j = 1; j < i; j++)
			l[j] = l[j - 1] * w % p;
		for (int j = 0; j < len; j += (i << 1))
			for (int k = j; k < i + j; k++)
			{
				int x = now[i + k] * (long long) l[k - j] % p, y = now[k];
				now[k] = (x + y) % p;
				now[i + k] = (y - x + p) % p;
			}
	}
	if (type)
	{
		long long inv = fast_pow(len, p - 2);
		for (int i = 0; i < len; i++)
			now[i] = now[i] * inv % p;
	}
}
int lower(int x)
{
	int tmp = 1;
	for (; tmp < x; tmp <<= 1);
	return tmp;
}
int A[Maxn], B[Maxn];
int main()
{
	cin >> s >> t;
	n = s.size(), m = t.size();
	bloc = sqrt(n / log(n)) * 0.8, per = n / bloc + 1;
	for (int i = 1; i <= n; i++)
		bel[i] = (i - 1) / per + 1;
	for (int i = 0; i < m; i++)
		B[m - i - 1] = t[i] == '1' ? 1 : p - 1;
	int len = lower(m + per + 1);
	get_rev(len);
	NTT(B, len);
	for (int i = 1; i <= bloc; i++)
	{
		int tmp_len = i == bloc ? n - per * (bloc - 1) : per;
		memset(A, 0, sizeof(int[len]));
		for (int j = (i - 1) * per; j <= min(n, i * per) - 1; j++)
			A[j - (i - 1) * per] = s[j] == '1' ? 1 : p - 1;
		NTT(A, len);
		for (int j = 0; j < len; j++)
			A[j] = A[j] * (long long) B[j] % p;
		NTT(A, len, true);
		for (int j = 0; j < m - tmp_len; j++)
			dis[i][j] = (tmp_len - A[m - 1 - j] + p) % p / 2;
	}
	scanf("%d", &q);
	while (q--)
	{
		int x, y, l, ans = 0;
		scanf("%d%d%d", &x, &y, &l);
		x++, y++;
		if (l <= 2 * per)
		{
			for (int i = 0; i < l; i++)
				if (s[x - 1 + i] != t[y - 1 + i]) ans++;
			printf("%d\n", ans);
			continue;
		}
		for (int i = x; i <= bel[x] * per; i++)
			if (s[i - 1] != t[i - x + y - 1]) ans++;
		for (int i = bel[x] + 1; i < bel[x + l - 1]; i++)
			ans += dis[i][(i - 1) * per - x + y];
		for (int i = (bel[x + l - 1] - 1) * per + 1; i <= x + l - 1; i++)
			if (s[i - 1] != t[i - x + y - 1]) ans++;
		printf("%d\n", ans);
	}
	return 0;
}