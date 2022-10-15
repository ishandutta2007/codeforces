/*input
4
1 4 2 2
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll K[101];
bitset<10001>V[101];
bitset<10001>D[101];
int main()
{
	V[0][0] = 1;
	ll n;
	n = 100;
	cin >> n;
	ll kiekis = 0;
	ll suma = 0;
	ll ans = 0;
	for (ll i = 0; i < n; i++)
	{
		ll w;
		w = rand() % 100 + 1;
		cin >> w;
		K[w]++;
		if (K[w] == 1)
			kiekis++;
		suma += w;
	}
	for (ll w = 1; w <= 100; w++)
	{
		if (K[w] >= 1)
		{
			bitset<10001>V_[101];
			bitset<10001>D_[101];
			for (ll a = 1; a <= K[w]; a++)
			{
				for (ll k = 100 - a; k >= 0; k--)
				{
					D_[k + a] |= (V_[k + a] & (V[k] << (a * w)));
					D_[k + a] |= (D[k] << (a * w));
					V_[k + a] |= (V[k] << (a * w));
				}
			}
			for (ll k = 0; k <= 100; k++)
			{
				D[k] |= (V[k] & V_[k]);
				D[k] |= D_[k];
				V[k] |= V_[k];
			}
		}
	}
	if (kiekis <= 2)
	{
		ans = n;
	}
	for (ll w = 1; w <= 100; w++)
	{
		for (ll k = 1; k <= K[w]; k++)
		{
			ll k_ = n - k;
			ll sum_ = suma - w * k;
			if (V[k_][sum_] && (!D[k_][sum_]))
			{
				ans = max(ans, k);
			}
		}
	}
	for (ll w = 1; w <= 100; w++)
	{
		for (ll k = 1; k <= K[w]; k++)
		{
			if (V[k][w * k] && (!D[k][w * k]))
			{
				ans = max(ans, k);
			}
		}
	}

	cout << ans << "\n";
}