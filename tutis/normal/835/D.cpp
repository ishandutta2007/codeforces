/***
abaCbba
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define MAX_N 5009
string s;
short A[MAX_N][MAX_N];
bool palind(ll i, ll j)
{
	if (A[i][j] != -1)
		return A[i][j];
	if (i >= j)
	{
		A[i][j] = true;
		return A[i][j];
	}
	if (s[i] == s[j])
	{
		A[i][j] = palind(i + 1, j - 1);
		return A[i][j];
	}
	A[i][j] = false;
	return A[i][j];
}
bool PAL[MAX_N][MAX_N][3];
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> s;
	ll n = s.size();
	for (ll i = 0; i < MAX_N; i++)
		for (ll j = 0; j < MAX_N; j++)
		{
			A[i][j] = -1;
		}
	ll ans[n];
	fill_n(ans, n, 0);
	for (ll i = 0; i < n; i++)
	{
		for (ll j = i; j < n; j++)
		{
			PAL[i][j][0] = palind(i, j);
			ans[0] += PAL[i][j][0];
		}
	}
	for (ll k = 1; k < 15; k++)
		for (ll i = 0; i < n; i++)
		{
			for (ll j = i; j < n; j++)
			{
				ll sz = j - i + 1;
				ll sz2 = sz / 2;
				if (sz2)
					PAL[i][j][k % 3] = palind(i, j) && PAL[i][i + sz2 - 1][(k - 1) % 3];
				else
					PAL[i][j][k % 3] = 0;
				ans[k] += PAL[i][j][k % 3];
			}
		}
	for (ll i = 0; i < n; i++)
		cout << ans[i] << " ";
}