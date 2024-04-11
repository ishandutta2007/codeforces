/*input
100 10 10
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int a[3];
	cin >> a[0] >> a[1] >> a[2];
	sort(a, a + 3);
	int ans = 0;
	while (a[2] >= a[0] + a[1])
	{
		a[0]++;
		ans++;
		sort(a, a + 3);
	}
	cout << ans << "\n";
}