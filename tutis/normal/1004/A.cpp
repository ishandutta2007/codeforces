/*input
5 2
4 8 11 18 19
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, d;
	cin >> n >> d;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	int ans = 2;
	for (int i = 1; i < n; i++)
	{
		if (a[i] - a[i - 1] == 2 * d)
			ans++;
		if (a[i] - a[i - 1] > 2 * d)
			ans += 2;
	}
	cout << ans << "\n";



}