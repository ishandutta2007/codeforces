/*input
4
1 1 1 1
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int ans = 0;
	for (int i = 2; i < n; i++)
	{
		if (a[i - 1] == 0 && a[i - 2] == 1 && a[i] == 1)
		{
			a[i] = 0;
			ans++;
		}
	}
	cout << ans << "\n";
}