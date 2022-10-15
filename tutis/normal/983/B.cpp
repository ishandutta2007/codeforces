/*input
6
1 2 4 8 16 32
4
1 6
2 5
3 4
1 2
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n;
	cin >> n;
	ll a[n + 1];
	for (ll i = 1; i <= n; i++)
		cin >> a[i];
	ll A[n + 1][n + 1];
	a[0] = 0;
	for (ll i = 1; i <= n; i++)
		A[i][i] = a[i];
	for (int sz = 2; sz <= n; sz++)
	{
		for (int l = 1; l + sz - 1 <= n; l++)
		{
			int r = l + sz - 1;
			A[l][r] = A[l][r - 1] ^ A[l + 1][r];
		}
	}
	for (ll i = n; i >= 1; i--)
	{
		for (ll j = i + 1; j <= n; j++)
		{
			if (i + 1 <= n)
			{
				A[i][j] = max({A[i][j], A[i + 1][j], A[i][j - 1]});
			}
		}
	}
	ll q;
	cin >> q;
	while (q--)
	{
		ll l, r;
		cin >> l >> r;
		cout << A[l][r] << "\n";
	}
}