#include <iostream>
#include <cstdio>
using namespace std;

const int M = 1000000007;

int modpow(int a, int n, int p)
{
	int res = 1;
	for (int i = n; i > 0; i >>= 1)
	{
		if (i & 1)
			res = (long long)res * a % p;
		a = (long long)a * a % p;
	}
	return res;
}

int main()
{
	int p, k;
	cin >> p >> k;

	int res;
	if (k == 0)
		res = modpow(p, p - 1, M);
	else
	{
		int dk = p - 1;
		for (int d = 1; d * d <= p - 1; d++)
			if ((p - 1) % d == 0)
			{
				if (modpow(k, d, p) == 1)
					dk = min(dk, d);
				if (modpow(k, (p - 1) / d, p) == 1)
					dk = min(dk, (p - 1) / d);
			}
		if (k != 1)
			res = modpow(p, (p - 1) / dk, M);
		else
			res = modpow(p, (p - 1) / dk + 1, M);
	}
	cout << res << endl;


	return 0;
}