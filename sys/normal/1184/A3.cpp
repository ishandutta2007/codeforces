#include <bits/stdc++.h>
using namespace std;

const int Maxn = 500005;
int n, m, C[Maxn], D[Maxn];
string A, B;
bool prime(int x)
{
	int maxi = sqrt(x);
	for (int i = 2; i <= maxi; i++)
		if (x % i == 0) return false;
	return true;
}
long long fast_pow(long long x, long long y, int p)
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
int main()
{
	mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
	scanf("%d%d", &n, &m);
	cin >> A >> B;
	for (int i = 0; i < n; i++)
		C[i] = A[i] - B[i];
	for (int d = 3; ; d++)
	{
		for (int i = 0; i < d; i++)
		{
			D[i] = 0;
			for (int j = i; j < n; j += d)
				D[i] += C[j];
		}
		int times = 0;
		if (!prime(d)) continue;
		for (int p = (m / d + 1) * d + 1; ; p += d)
			if (prime(p))
			{
				times++;
				if (times == 5000) break;
				long long r0;
				r0 = rd() % (p - 3) + 2;
				while (fast_pow(r0, (p - 1) / d, p) == 1) r0 = rd() % (p - 3) + 2;
				r0 = fast_pow(r0, (p - 1) / d, p);
				for (long long r = r0; r != 1; (r *= r0) %= p)
				{
					long long now = 1, Hash = 0;
					for (int q = 0; q < d; q++)
						(Hash += now * D[q] % p + p) %= p, (now *= r) %= p;
					if (!Hash)
					{
						printf("%d %lld\n", p, r);
						return 0;
					}
				}
			}
	}
}