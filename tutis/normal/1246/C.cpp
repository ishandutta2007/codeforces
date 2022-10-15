/*input
4 4
...R
.RR.
.RR.
R...

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000000 + 7;
int main()
{
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	char M[n + 1][m + 1];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> M[i][j];
	if (min(n, m) == 1 || M[n - 1][m - 1] != '.')
	{
		ll ans = 1;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (M[i][j] != '.')
					ans = 0;
		cout << ans << "\n";
		return 0;
	}
	ll R_[n + 3][m + 3];
	ll D_[n + 3][m + 3];
	ll R[n + 3][m + 3];
	ll D[n + 3][m + 3];
	ll A[n + 3][m + 3];
	ll B[n + 3][m + 3];
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
		{
			R[i][j] = D[i][j] = 0;
			R_[i][j] = D_[i][j] = 0;
			A[i][j] = B[i][j] = 0;
		}
	for (int i = n - 1; i >= 0; i--)
		for (int j = m - 1; j >= 0; j--)
		{
			if (M[i][j] == '.')
			{
				R_[i][j]++;
				D_[i][j]++;
			}
			R_[i][j] += R_[i][j + 1];
			D_[i][j] += D_[i + 1][j];
		}
	R[0][0] = D[0][0] = 1;
	for (int ij = 0; ij <= n - 1 + m - 1; ij++)
		for (int i = 0; i < n; i++)
		{
			int j = ij - i;
			if (j < 0 || j >= m)
				continue;
			if (i > 0)
				B[i][j] += B[i - 1][j];
			if (j > 0)
				A[i][j] += A[i][j - 1];
			A[i][j] %= mod;
			B[i][j] %= mod;
			D[i][j] += A[i][j];
			R[i][j] += B[i][j];
			R[i][j] %= mod;
			D[i][j] %= mod;
			int rm = R_[i][j + 1];
			if (rm >= 1)
			{
				A[i][j + 1] += R[i][j];
				A[i][j + rm + 1] += mod - R[i][j];
				A[i][j + 1] %= mod;
				A[i][j + rm + 1] %= mod;
			}
			int dm = D_[i + 1][j];
			if (dm >= 1)
			{
				B[i + 1][j] += D[i][j]; B[i + 1][j] %= mod;
				B[i + dm + 1][j] += mod - D[i][j]; B[i + dm + 1][j] %= mod;
			}
		}
	ll ans = R[n - 1][m - 1] + D[n - 1][m - 1];
	ans %= mod;
	cout << ans << "\n";
}