/*input
6 4
4 8 15 16 23 42
1000 1000 1000 1000
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	int c[n];
	for (int i = 0; i < n; i++)
		cin >> c[i];
	int a[m];
	for (int i = 0; i < m; i++)
		cin >> a[i];
	int ans = 0;
	for (int C : c)
	{
		for (int &x : a)
		{
			if (x >= C)
			{
				ans++;
				x = -1;
				break;
			}
			if (x > 0)
				break;
		}
	}
	cout << ans << "\n";



}