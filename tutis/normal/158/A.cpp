/*input
8 5
10 9 8 7 7 7 5 5
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	int a[n + 1];
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans += (a[i] > 0 && a[i] >= a[k]);
	cout << ans << "\n";
}