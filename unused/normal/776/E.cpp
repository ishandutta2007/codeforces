#include <bits/stdc++.h>
using namespace std;

int phi[10000001];
bool notprime[1000005];
vector<int> primes;

void euler_phi(int n, int ret[]) {
	for
		(int i = 1; i <= n; ++i) ret[i] = i;
	for
		(int i = 2; i <= n; ++i)
		if (ret[i] == i)
			for
				(int j = i; j <= n; j += i)
				ret[j] -= ret[j] / i;
}

constexpr int MOD = 1000000007;

int main()
{
	primes.push_back(2);
	for (int i = 3; i <= 1000000; i += 2)
	{
		if (notprime[i]) continue;
		primes.push_back(i);
		for (int j = i * 3; j <= 1000000; j += i * 2)
			notprime[j] = true;
	}
	long long n, k;
	scanf("%lld%lld", &n, &k);

	euler_phi(10000000, phi);
	k = (k + 1) / 2;

	while (n > 1 && k--)
	{
		if (n <= 10000000) n = phi[n];
		else
		{
			long long res = 1;
			for (int t : primes)
			{
				if (t * t > n) break;
				if (n % t) continue;
				res *= t - 1;
				n /= t;
				while (n % t == 0)
				{
					n /= t;
					res *= t;
				}
				if (n == 1) break;
			}
			if (n > 1) res *= n - 1;
			n = res;
		}
	}

	printf("%d\n", (int)(n % MOD));
}