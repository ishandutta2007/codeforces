/*input
2
10 3 1 1
1000000000 1 1000000000 1
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		ll s, a, b, c;
		cin >> s >> a >> b >> c;
		ll ans = s / c;
		ans += (ans / a) * b;
		cout << ans << "\n";
	}
}