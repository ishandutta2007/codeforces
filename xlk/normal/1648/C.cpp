#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
const int l = 200000;
int n, m;
int s[200020];
int t[200020];
int c[200020];
int v[200020];
long long u = 1, z;
void change(int x, int y)
{
	for (int i = x; i <= l; i += i & -i)
	{
		c[i] += y;
	}
}
int query(int x)
{
	int re = 0;
	for (int i = x; i > 0; i -= i & -i)
	{
		re += c[i];
	}
	return re;
}
int main()
{
	scanf("%d%d", &n, &m);
	v[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		v[i] = (long long)v[p % i] * (p - p / i) % p;
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &s[i]);
		u = u * i % p * v[++c[s[i]]] % p;
	}
	for (int i = 1; i <= l; i++)
	{
		if (i + (i & -i) <= l)
		{
			c[i + (i & -i)] += c[i];
		}
	}
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", &t[i]);
	}
	for (int i = 1; i <= m; i++)
	{
		u = u * v[n - i + 1] % p;
		int q = query(t[i] - 1);
		z = (z + u * q + (i > n)) % p;
		int w = query(t[i]) - q;
		if (w > 0)
		{
			u = u * w % p;
			change(t[i], -1);
		}
		else
		{
			break;
		}
	}
	printf("%lld\n", z);
	return 0;
}