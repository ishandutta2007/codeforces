#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll MOD = (ll)1e6 + 3;
const ll M = MOD - 1;
ll n, k;
ll a[100];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	cin >> n >> k;

	if (n < 62 && k > (1LL << n))
	{
		printf("1 1\n");
		return 0;
	}
	k--;
	ll q = (n % M) * (k % M) % M;
	ll kk = k >> 1;
	while(kk > 0)
	{
		q = (q + M - (kk % M)) % M;
		kk >>= 1;
	}
	ll Q = 1;
	for (int i = 0; i < q; i++)
	{
		Q += Q;
		if (Q >= MOD) Q -= MOD;
	}
	ll P = 0;
	if (k < MOD)
	{
		ll nn = n % M;
		ll z = 1;
		while(nn--)
		{
			z += z;
			if (z >= MOD) z -= MOD;
		}
		P = 1;
		a[0] = 1;
		a[1] = (MOD + 1) / 2;
		for (int i = 2; i < 100; i++)
			a[i] = (a[i - 1] * a[1]) % MOD;
		for (int i = 1; i <= k; i++)
		{
			ll x = z - i;
			//printf("%lld\n", x);
			if (x < 0) x += MOD;
			int w = 0;
			int ii = i;
			while(ii % 2 == 0)
			{
				w++;
				ii >>= 1;
			}
			//printf("%d\n", w);
			P = (P * x * a[w]) % MOD;
		}
	}
	P = Q - P;
	if (P < 0) P += MOD;
	printf("%lld %lld\n", P, Q);

	return 0;
}