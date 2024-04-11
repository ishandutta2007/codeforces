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
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	int ans = 0;
	int a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] == 1)
			ans++;
	}
	cout << ans << "\n";
	for (int i = 0; i < n; i++)
	{
		if (i == n - 1 || a[i + 1] == 1)
			cout << a[i] << " ";
	}


}