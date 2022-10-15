/*input
6
OO|OX
XO|XX
OX|OO
XX|OX
OO|OO
OO|XX
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	string a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < 5; j++)
		{
			if (a[i][j] == a[i][j - 1] && a[i][j] == 'O')
			{
				a[i][j] = a[i][j - 1] = '+';
				cout << "YES\n";
				for (string i : a)
					cout << i << "\n";
				return 0;
			}
		}
	}
	cout << "NO\n";
}