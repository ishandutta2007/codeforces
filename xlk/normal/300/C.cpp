#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int a, b, n;
int f[1000020];
int pw(int x, int y)
{
	int re = 1;
	for (; y > 0; y >>= 1)
	{
		if (y & 1)
		{
			re = (long long)re * x % p;
		}
		x = (long long)x * x % p;
	}
	return re;
}
int C(int n, int m)
{
	return (long long)f[n] * pw(f[m], p - 2) % p * pw(f[n - m], p - 2) % p;
}
int main()
{
	cin >> a >> b >> n;
	f[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		f[i] = (long long)f[i - 1] * i % p;
	}
	int z = 0;
	for (int i = 0; i <= n; i++)
	{
		int s = a * i + b * (n - i);
		int f = 1;
		for (; s > 0; s /= 10)
		{
			if (s % 10 != a && s % 10 != b)
			{
				f = 0;
			}
		}
		if (f)
		{
			z = (z + C(n, i)) % p;
		}
	}
	cout << z << endl;
	return 0;
}