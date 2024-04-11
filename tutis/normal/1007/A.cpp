/*input
5
1 1 1 1 1
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
	ll a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[ans] < a[i])
		{
			ans++;
		}
	}
	cout << ans << "\n";

}