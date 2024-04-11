/*input
18
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
bool lucky(ll x)
{
	while (x > 0)
	{
		if ((x % 10) == 8)
			return true;
		x /= 10;
	}
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	ll a;
	cin >> a;
	for (int b = 1;; b++)
	{
		if (lucky(abs(a + b)))
		{
			cout << b << "\n";
			return 0;
		}
	}

}