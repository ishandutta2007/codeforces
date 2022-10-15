/*input
4 3 1
1 100 1 1
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	ll n, K, x;
	cin >> n >> K >> x;
	ll a[n + 1];
	for (ll i = 1; i <= n; i++)
		cin >> a[i];
	ll Su[n + 1][x + 1];
	for (ll i = 0; i <= n; i++)
	{
		for (ll j = 0; j <= x; j++)
		{
			Su[i][j] = -1e18;
		}
	}
	Su[0][0] = 0;
	for (ll j = 1; j <= x; j++)
	{
		deque<ll>Q;
		for (ll i = 1; i <= n; i++)
		{
			while (!Q.empty() && Su[Q.back()][j - 1] <= Su[i - 1][j - 1])
				Q.pop_back();
			Q.push_back(i - 1);
			while (true)
			{
				if (Q.empty())
					break;
				if (i - Q.front() > K)
					Q.pop_front();
				else
					break;
			}
			if (!Q.empty())
			{
				ll k = Q.front();
				Su[i][j] = max(Su[i][j], Su[k][j - 1]);
			}
			Su[i][j] += a[i];
		}
	}

	ll maxi = 0;
	for (ll i = 1; i <= n; i++)
	{
		if (n - i < K)
			maxi = max(maxi, Su[i][x]);
	}
	if (maxi <= 0)
		maxi = -1;
	cout << maxi << "\n";
}