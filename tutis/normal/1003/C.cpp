/*input
4 3
3 4 1 2
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n >> k;
	ld a[n + 1];
	a[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		a[i] += a[i - 1];
	}
	ld ans = 0.0;
	for (int l = 1; l <= n; l++)
	{
		for (int r = l; r <= n; r++)
		{
			if (r - l + 1 >= k)
			{
				ans = max(ans, (a[r] - a[l - 1]) / (r - l + 1));
			}
		}
	}
	cout << fixed << setprecision(20) << ans << "\n";

}