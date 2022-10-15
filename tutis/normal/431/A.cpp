/*input
1 2 3 4
123214
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	ll a[5];
	for (int t = 1; t <= 4; t++)
		cin >> a[t];
	string s;
	cin >> s;
	ll ans = 0;
	for (char c : s)
	{
		ans += a[c - '0'];
	}
	cout << ans << "\n";
}