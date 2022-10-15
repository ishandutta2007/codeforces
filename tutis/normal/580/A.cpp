/*input
6
2 2 1 3 4 1
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll dp[2][500 + 1][500 + 1];
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int a[n];
	for (int &i : a)
		cin >> i;
	int ans = 0;
	int suma = 0;
	for (int i = 1; i < n; i++)
	{
		if (a[i] >= a[i - 1])
		{
			suma++;
			ans = max(ans, suma);
		}
		else
		{
			suma = 0;
		}
	}
	cout << ans + 1 << "\n";
}