/*input
5
0 4 6 2 4
4 0 6 2 4
6 6 0 3 6
2 2 3 0 2
4 4 6 2 0
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
	ll a[n][n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	ll y = a[0][1] * a[0][2] / a[1][2];
	ll x = sqrtl(y);
	while (x * x < y)
		x++;
	while (x * x > y)
		x--;
	cout << x << " ";
	for (int i = 1; i < n; i++)
	{
		cout << a[i][0] / x << " ";
	}
}