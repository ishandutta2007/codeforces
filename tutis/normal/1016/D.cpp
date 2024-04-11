/*input
2 3
2 9
5 3 13
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	ll a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	ll b[m];
	for (int i = 0; i < m; i++)
		cin >> b[i];
	ll X[n][m];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			X[i][j] = 0;
	for (int i = 1; i < n; i++)
		X[i][0] = a[i];
	for (int i = 1; i < m; i++)
		X[0][i] = b[i];
	ll XORB = 0;
	for (int i = 1; i < m; i++)
		XORB ^= X[0][i];
	X[0][0] = a[0] ^ XORB;
	for (int i = 0; i < n; i++)
		b[0] ^= X[i][0];
	if (b[0] == 0)
	{
		cout << "YES\n";
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				cout << X[i][j] << " ";
			cout << "\n";
		}
	}
	else
	{
		cout << "NO\n";
	}
}