/*input
9
1 2 2 2 1 1 2 2 2

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int main()
{
	int n;
	cin >> n;
	ll x[n + 1], y[n + 1];
	vector<int>b(n + 1, 0);
	for (int i = 0; i <= n; i++)
	{
		x[i] = rng();
		y[i] = rng();
	}
	ll h[n + 1];
	h[0] = 0;
	vector<int>P[n + 1];
	ll ans = 0;
	map<ll, ll>M;
	int id = 0;
	M[h[0]]++;
	for (int i = 1; i <= n; i++)
	{
		h[i] = h[i - 1];
		int a;
		cin >> a;
		b[a]++;
		if (b[a] % 3 == 0)
			h[i] ^= x[a];
		else if (b[a] % 3 == 1)
			h[i] ^= y[a];
		else {
			h[i] ^= x[a];
			h[i] ^= y[a];
		}

		if (P[a].size() >= 4)
		{
			int x = P[a][P[a].size() - 4];
			while (id + 1 <= x)
			{
				M[h[id]]--;
				id++;
			}
		}
		ans += M[h[i]];
		M[h[i]]++;



		P[a].push_back(i);
	}
	cout << ans << "\n";
}