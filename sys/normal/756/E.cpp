#include <bits/stdc++.h>
using namespace std;

const int Maxn = 600004, p = 1e9 + 7;
int n, b[Maxn], c[Maxn];
long long a[Maxn], f[Maxn], g[Maxn], sum[Maxn];
string str;
struct big
{
	int pos, val[1205];
	big()
	{
		memset(val, 0, sizeof(val));
		val[0] = 1;
	}
	big operator + (const big &x) const
	{
		big result;
		result.val[0] = 0;
		for (int i = 0; i <= 1200; i++)
		{
			result.val[i] += val[i] + x.val[i];
			if (result.val[i] >= 1000000000) result.val[i] -= 1000000000, result.val[i + 1]++;
		}
		return result;
	}
	big operator - (const big &x) const
	{
		big result;
		result.val[0] = 0;
		for (int i = 0; i <= 1200; i++)
		{
			result.val[i] += val[i] - x.val[i];
			if (result.val[i] < 0) result.val[i] += 1000000000, result.val[i + 1]--;
		}
		return result;
	}
	big operator * (long long x) const
	{
		big result;
		result.val[0] = 0;
		for (int i = 0; i <= 1200; i++)
		{
			long long tmp = val[i] * x;
			result.val[i] += tmp % 1000000000, result.val[i + 1] += tmp / 1000000000;
			if (result.val[i] >= 1000000000) result.val[i] -= 1000000000, result.val[i + 1]++;
		}
		return result;
	}
	big operator / (long long x)
	{
		big result;
		result.val[0] = 0;
		result.pos = pos;
		long long tmp = 0;
		for (int i = pos; i >= 0; i--)
		{
			result.val[i] = (tmp + val[i]) / x;
			tmp = (tmp + val[i]) % x * 1000000000;
			if (!result.val[i] && i == result.pos) result.pos--;
		}
		return result;
	}
	void get(string s)
	{
		int siz = s.size();
		val[0] = 0;
		for (int i = 0; i < siz; i++)
		{
			for (int j = 1200; j >= 0; j--)
			{
				long long tmp = val[j] * 10LL;
				val[j] = tmp % 1000000000;
				val[j + 1] += tmp / 1000000000;
			}
			val[0] += s[i] - '0';
			for (int j = 0; j <= 1200; j++)
				if (val[j] >= 1000000000)
					val[j] -= 1000000000, val[j + 1]++;
		}
		pos = 1200;
	}
	bool empty(void)
	{
		for (int i = 0; i <= 1200; i++)
			if (val[i]) return false;
		return true;
	}
} m, D[10005];
int main()
{
	scanf("%d", &n);
	a[1] = 1;
	for (int i = 2; i <= n; i++)
		scanf("%lld", &a[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &b[i]);
	cin >> str;
	m.get(str);
	big now = m;
	for (int i = 2; i <= n; i++)
	{
		if (now.empty())
		{
			n = i - 1;
			break;
		}
		if (a[i] != 1)
		{
			big tmp = now / a[i];
			c[i] = (now - tmp * a[i]).val[0];
			now = tmp;
		}
	}
	int limit = 0;
	f[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		memcpy(g, f, sizeof(long long[limit + 1]));
		memset(f, 0, sizeof(long long[limit + 1]));
		for (int j = c[i]; j <= limit; j += a[i])
			f[j / a[i]] = g[j];
		limit = limit / a[i] + b[i];
		for (int j = 1; j <= limit + 1; j++)
			sum[j] = (sum[j - 1] + f[j - 1]) % p;
		for (int j = 0; j <= limit; j++)
			f[j] = (sum[j + 1] - sum[max(0, j - b[i])] + p) % p;
	}
	for (int i = 1; i <= 1200; i++)
		if (now.val[i])
		{
			puts("0");
			return 0;
		}
	if (now.val[0] > limit)
	{
		puts("0");
		return 0;
	}
	printf("%lld", f[now.val[0]]);
	return 0;
}