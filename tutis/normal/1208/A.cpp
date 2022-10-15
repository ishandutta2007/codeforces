/*input
3
3 4 2
4 5 0
325 265 1231232
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--)
	{
		ll a, b, n;
		cin >> a >> b >> n;
		n %= 3;
		if (n == 0)
			cout << a << "\n";
		if (n == 1)
			cout << b << "\n";
		if (n == 2)
			cout << (a^b) << "\n";
	}
}