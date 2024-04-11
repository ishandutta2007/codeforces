/*input
6 1 5
10 30 30 70 10 10
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
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	ll Su[n + 1][x + 1];
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= x; j++)
		{
			Su[i][j] = -1e18;
		}
	}
	Su[0][0] = 0;
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j < x; j++)
		{
			for (int k = i + 1; k <= n && k - i <= K; k++)
			{
				Su[k][j + 1] = max(Su[k][j + 1], Su[i][j] + a[k]);
			}
		}
	}

	ll maxi = 0;
	for (int i = 1; i <= n; i++)
	{
		if (n - i < K)
			maxi = max(maxi, Su[i][x]);
	}
	if (maxi <= 0)
		maxi = -1;
	cout << maxi << "\n";
}