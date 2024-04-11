/*input
3 3
###
###
###
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
	char A[n][m];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> A[i][j];
	char B[n][m];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			B[i][j] = '.';
	for (int i = 2; i < n; i++)
	{
		for (int j = 2; j < m; j++)
		{
			if (
			    A[i][j] == '#' && A[i - 1][j] == '#' && A[i - 2][j] == '#' &&
			    A[i][j - 1] == '#' && A[i - 2][j - 1] == '#' &&
			    A[i][j - 2] == '#' && A[i - 1][j - 2] == '#' && A[i - 2][j - 2] == '#'
			)
			{
				B[i][j] = '#'; B[i - 1][j] = '#'; B[i - 2][j] = '#';
				B[i][j - 1] = '#'; B[i - 2][j - 1] = '#';
				B[i][j - 2] = '#'; B[i - 1][j - 2] = '#'; B[i - 2][j - 2] = '#';
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (A[i][j] != B[i][j])
			{
				cout << "NO\n";
				return 0;
			}
		}
	}
	cout << "YES\n";
}