#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int mod2 = 1000000009;
const int base = 13131;
const int base2 = 1313131;
int n, q, m, l, song;
int f[100020][26];
char t[100020];
int pw2[100020];
char s[100020];
int sh1[100020];
int sh2[100020];
char w[1000020];
int pwh1[1000020];
int pwh2[1000020];
int wh1[1000020];
int wh2[1000020];
long long z;
void gao(int b, int k, int d)
{
	if (d > song)
	{
		return;
	}
	if (b >= l)
	{
		z = (z + pw2[song - d]) % mod;
		return;
	}
	// printf("gao %d %d %d\n", b, k, d);
	if (b + k >= l)
	{
		// printf("%d %d\n", b, l);
		// assert(0 <= b && b < l);
		// for (int i = d; i < song; i++)
		// {
		// 	if (t[i] == w[b])
		// 	{
		// 		z = (z + pw2[song - 1 - i]) % mod;
		// 	}
		// }
		z = (z + f[song][w[b] - 'a'] + mod - (long long)pw2[song - d] * f[d][w[b] - 'a'] % mod) % mod;
		return;
	}
	if (d >= n)
	{
		return;
	}
	bool even = true;
	for (int i = b; i < l; i += k * 2)
	{
		if (w[i] != t[d])
		{
			even = false;
			break;
		}
	}
	if (even)
	{
		gao(b + k, k * 2, d + 1);
	}
	bool odd = true;
	for (int i = b + k; i < l; i += k * 2)
	{
		if (w[i] != t[d])
		{
			odd = false;
			break;
		}
	}
	if (odd)
	{
		gao(b, k * 2, d + 1);
	}
}
bool eq(int ws, int ss, int len)
{
	int we = ws + len;
	int se = ss + len;
	if ((wh1[we] + mod - (long long)wh1[ws] * pwh1[len] % mod) % mod != (sh1[se] + mod - (long long)sh1[ss] * pwh1[len] % mod) % mod)
	{
		return false;
	}
	if ((wh2[we] + mod2 - (long long)wh2[ws] * pwh2[len] % mod2) % mod2 != (sh2[se] + mod2 - (long long)sh2[ss] * pwh2[len] % mod2) % mod2)
	{
		return false;
	}
	return true;
}
bool ok(int i)
{
	for (int j = 0; j < l;)
	{
		if ((j + m - i) % (m + 1) == m)
		{
			j++;
		}
		else
		{
			int st = (j + m - i) % (m + 1);
			int len = min(m - st, l - j);
			 // w[j, j + l) =?= s[st, st + len)
			if (!eq(j, st, len))
			{
				return false;
			}
			j += len;
			// if (w[j] != s[(j + m - i) % (m + 1)])
			// {
			// 	return false;
			// }
			// j++;
		}
	}
	return true;
}
int main()
{
	for (int i = pw2[0] = 1; i < 100010; i++)
	{
		pw2[i] = pw2[i - 1] * 2 % mod;
	}
	for (int i = pwh1[0] = 1; i < 1000010; i++)
	{
		pwh1[i] = (long long)pwh1[i - 1] * base % mod;
	}
	for (int i = pwh2[0] = 1; i < 1000010; i++)
	{
		pwh2[i] = (long long)pwh2[i - 1] * base2 % mod2;
	}
	scanf("%d%d", &n, &q);
	scanf("%s", s);
	scanf("%s", t);
	m = strlen(s);
	for (int i = 0; i < m; i++)
	{
		sh1[i + 1] = ((long long)sh1[i] * base + s[i]) % mod;
	}
	for (int i = 0; i < m; i++)
	{
		sh2[i + 1] = ((long long)sh2[i] * base2 + s[i]) % mod2;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			f[i + 1][j] = f[i][j] * 2 % mod;
		}
		f[i + 1][t[i] - 'a']++;
	}
	for (int qq = 0; qq < q; qq++)
	{
		scanf("%d%s", &song, w);
		l = strlen(w);
		for (int i = 0; i < l; i++)
		{
			wh1[i + 1] = ((long long)wh1[i] * base + w[i]) % mod;
		}
		for (int i = 0; i < l; i++)
		{
			wh2[i + 1] = ((long long)wh2[i] * base2 + w[i]) % mod2;
		}
		z = 0;
		// printf("%s\n", w);
		for (int i = 0; i <= m; i++)
		{
			if (ok(i))
			{
				// printf("qq=%d i=%d\n", qq, i);
				// ac = 0;
				// for (int j = i; j < l; j += m + 1)
				// {
				// 	a[ac++] = w[j];
				// }
				gao(i, m + 1, 0);
			}
		}
		printf("%lld\n", z);
	}
	return 0;
}