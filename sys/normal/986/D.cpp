//shabi luogu!!!
#include <bits/stdc++.h>
using namespace std;
 
const int Maxn = 1 << 20 | 5, p = 998244353;
int rev[Maxn];
long long l[Maxn];
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
	get_rev(len);
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
				int x = now[i + k] * l[k - j] % p, y = now[k];
				now[k] = x + y >= p ? x + y - p : x + y;
				now[i + k] = y - x < 0 ? y - x + p : y - x;
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
	for (; tmp < x; tmp <<= 1) ;
	return tmp;
}
struct big
{
	int val[Maxn];
	big()
	{
		memset(val, 0, sizeof(val));
	}
	big(int x)
	{
		memset(val, 0, sizeof(val));
		val[0] = x;
	}
	bool operator <= (const big &tmp) const
	{
		for (int i = 750005; i >= 0; i--)
			if (val[i] != tmp.val[i]) return val[i] < tmp.val[i];
		return true;
	}
	big operator * (const big &A) const
	{
		big result, tmp;
		result = *this, tmp = A;
		int len1 = 0, len2 = 0;
		for (int i = (1 << 20); i >= 0; i--)
		{
			if (result.val[i] && !len1) len1 = i;
			if (tmp.val[i] && !len2) len2 = i;
		}
		int len = lower(len1 + len2 + 1);
		NTT(result.val, len), NTT(tmp.val, len);
		for (int i = 0; i < len; i++)
			result.val[i] = result.val[i] * (long long) tmp.val[i] % p;
		NTT(result.val, len, true);
		for (int i = 0; i < 750005; i++)
			result.val[i + 1] += result.val[i] / 100, result.val[i] %= 100;
		return result;
	}
	big operator * (const int x) const
	{
		big result = *this;
		for (int i = 0; i < 750005; i++)
			result.val[i] *= x;
		for (int i = 0; i < 750005; i++)
			result.val[i + 1] += result.val[i] / 100, result.val[i] %= 100;
		return result;
	}
	void get(string s)
	{
		int siz = s.size();
		for (int i = 0; i < siz; i++)
			val[(siz - 1 - i) / 2] *= 10, val[(siz - 1 - i) / 2] += s[i] - '0';
	}
} n, res, now, p3[23];
big square(const big &A)
{
	big result;
	result = A;
	int len = 0;
	for (int i = (1 << 20); i >= 0; i--)
		if (result.val[i] && !len) len = i;
	len = lower(len + 1) << 1;
	NTT(result.val, len);
	for (int i = 0; i < len; i++)
		result.val[i] = result.val[i] * (long long) result.val[i] % p;
	NTT(result.val, len, true);
	for (int i = 0; i < 750005; i++)
		result.val[i + 1] += result.val[i] / 100, result.val[i] %= 100;
	return result;
}
string str;
const int pow3[] = {1, 3, 9, 27, 81, 243, 729, 2187, 6561};
big fast_pow(int y)
{
	big ans;
	ans.val[0] = 1;
	for (int i = 21; i >= 4; i--)
		if ((y >> i) & 1)
			ans = ans * p3[i];
	for (int i = 3; i >= 0; i--)
		if ((y >> i) & 1)
			ans = ans * pow3[1 << i];
	return ans;
}
int delta;
void work(int x)
{
	if (!x) now = big(0);
	else if (x == 1) now = big(1);
	else if (x % 3 == 0) now = res * pow3[x / 3 - delta];
	else if (x % 3 == 1) now = res * (pow3[x / 3 - delta - 1] * 4);
	else if (x % 3 == 2) now = res * (pow3[x / 3 - delta] * 2);
}
int main()
{
	p3[0].get("3");
	for (int i = 1; i <= 21; i++)
		p3[i] = square(p3[i - 1]), cerr << i << endl;
	cin >> str;
	n.get(str);
	int limit = 3 * ((str.size() - 1) * log(10) / log(3) + log(str[0] - '0') / log(3));
	delta = max(0, limit / 3 - 1);
	res = fast_pow(delta);
	for (int i = limit; ; i++)
		if (work(i), n <= now)
		{
			printf("%d\n", i);
			return 0;
		}
}