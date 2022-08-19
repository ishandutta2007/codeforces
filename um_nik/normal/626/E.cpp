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
	Frac(ll x) : p(x), q(1) {}
	Frac(ll _p, ll _q)
	{
		p = _p;
		q = _q;
		if (q == 0) throw;
		if (q < 0)
		{
			p *= -1;
			q *= -1;
		}
		ll g = gcd(abs(p), q);
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
		return p * a.q < q * a.p;
	}

	void print()
	{
		printf("%lld/%lld\n", p, q);
	}
};

Frac ans = Frac(0);
int ansPos = 0, ansK = 0, ansDir = 1;

const int LOG = 19;
const int N = 200200;
int n;
ll a[N];
ll sum[N];

Frac getVal1(int p, int len)
{
	return Frac(sum[len] - sum[0] + sum[p + len + 1] - sum[p], 2 * len + 1);
}
void solve1(int p)
{
	int len = -1;
	for (int k = LOG; k >= 0; k--)
	{
		int nlen = len + (1 << k);
		if (nlen >= p || p + 1 + nlen + 1 > n) continue;
		if (getVal1(p, nlen + 1) < getVal1(p, nlen))
			len = nlen;
	}
	len++;
	Frac val = Frac(a[p]) - getVal1(p, len);
	if (ans < val)
	{
		ans = val;
		ansPos = p;
		ansK = len;
		ansDir = 1;
	}
	return;
}

Frac getVal2(int p, int len)
{
	return Frac(sum[n] - sum[n - len] + sum[p + 1] - sum[p - len], 2 * len + 1);
}
void solve2(int p)
{
	int len = -1;
	for (int k = LOG; k >= 0; k--)
	{
		int nlen = len + (1 << k);
		if (nlen >= p || p + 1 + nlen + 1 > n) continue;
		if (getVal2(p, nlen) < getVal2(p, nlen + 1))
			len = nlen;
	}
	len++;
	Frac val = getVal2(p, len) - Frac(a[p]);
	if (ans < val)
	{
		ans = val;
		ansPos = p;
		ansK = len;
		ansDir = 2;
	}
}

void printAns()
{
//	ans.print();
	printf("%d\n", 2 * ansK + 1);
	if (ansDir == 1)
	{
		for (int i = 0; i < ansK; i++)
			printf("%d ", a[i]);
		for (int i = 0; i <= ansK; i++)
			printf("%d ", a[ansPos + i]);
	}
	else
	{
		for (int i = ansK; i >= 0; i--)
			printf("%d ", a[ansPos - i]);
		for (int i = ansK; i > 0; i--)
			printf("%d ", a[n - i]);
	}
	printf("\n");
	return;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	sort(a, a + n);
	for (int i = 0; i < n; i++)
		sum[i + 1] = sum[i] + a[i];
	for (int i = 0; i < n; i++)
	{
//		solve1(i);
		solve2(i);
	}
	printAns();

	return 0;
}