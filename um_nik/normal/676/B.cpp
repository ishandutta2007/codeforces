#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef long long ll;
ll gcd(ll x, ll y)
{
	return (y == 0 ? x : gcd(y, x % y));
}

struct Frac
{
	ll p, q;

	Frac() : p(0), q(1) {}
	Frac(ll _x) : p(_x), q(1) {}
	Frac(ll _p, ll _q)
	{
		p = _p;
		q = _q;
		if (q == 0) throw;
		if (q < 0)
		{
			q *= -1;
			p *= -1;
		}
		ll g = gcd(q, abs(p));
		p /= g;
		q /= g;
	}

	Frac operator + (const Frac &a) const
	{
		return Frac(p * a.q + q * a.p, q * a.q);
	}
	Frac operator - (const Frac &a) const
	{
		return Frac(p * a.q - q * a.p, q * a.q);
	}
	Frac operator * (const Frac &a) const
	{
		return Frac(p * a.p, q * a.q);
	}
	Frac operator / (const Frac &a) const
	{
		return Frac(p * a.q, q * a.p);
	}
	bool operator < (const Frac &a) const
	{
		return p * a.q < a.p * q;
	}
};

const int N = 15;
int n;
Frac a[N][N];
int m;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	while(m--)
	{
		a[0][0] = a[0][0] + Frac(1);
		for (int i = 0; i < n; i++)
			for (int j = 0; j <= i; j++)
			{
				if (Frac(1) < a[i][j])
				{
					Frac Q = a[i][j] - Frac(1);
					a[i][j] = Frac(1);
					Q = Q / Frac(2);
					a[i + 1][j] = a[i + 1][j] + Q;
					a[i + 1][j + 1] = a[i + 1][j + 1] + Q;
				}
			}
	}
	int ans = n * (n + 1) / 2;
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++)
			if (a[i][j] < Frac(1))
				ans--;
	printf("%d\n", ans);

	return 0;
}