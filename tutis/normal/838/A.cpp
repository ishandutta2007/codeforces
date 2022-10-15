/***
3 5
00100
10110
11001
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
bool A[5000][5000];
int32_t D[5000][5000];
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ll n, m;
	cin >> n >> m;
	for (ll i = 0; i < n; i++)
	{
		for (ll j = 0; j < m; j++)
		{
			char x;
			cin >> x;
			A[i][j] = (x == '1');
		}
	}
	for (ll i = 0; i < 5000; i++)
	{
		for (ll j = 0; j < 5000; j++)
		{
			D[i][j] = A[i][j];
			if (i != 0)
				D[i][j] += D[i - 1][j];
			if (j != 0)
				D[i][j] += D[i][j - 1];
			if (i != 0 && j != 0)
				D[i][j] -= D[i - 1][j - 1];
		}
	}
	ll  ans = n * m;
	for (ll k = max(n, m); k > 1; k--)
	{
		ll l = 0;
		for (ll i = k - 1; i < n + k; i += k)
			for (ll j = k - 1; j < m + k; j += k)
			{
				ll kiek = D[i][j];
				if (i - k >= 0)
					kiek -= D[i - k][j];
				if (j - k >= 0)
				{
					kiek -= D[i][j - k];
					if (i - k >= 0)
						kiek += D[i - k][j - k];
				}
				l += min(kiek, k * k - kiek);
			}
		ans = min(ans, l);
	}
	cout << ans;
}