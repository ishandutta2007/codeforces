/*input
2 3
1 2
3 4
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	int n, k;
	cin >> n >> k;
	int sum = 0;
	while (n--)
	{
		int l, r;
		cin >> l >> r;
		sum += r - l + 1;
		sum %= k;
	}
	int ans = 0;
	while (sum % k != 0)
	{
		sum++;
		ans++;
	}
	cout << ans << "\n";
	return 0;
}