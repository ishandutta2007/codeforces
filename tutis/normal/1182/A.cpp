/*input
4

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 gen(12938712983ll);
int main()
{
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	if (n % 2 == 1)
		cout << "0\n";
	else
	{
		ll ans = 1;
		for (int i = 0; i < n; i += 2)
			ans *= 2;
		cout << ans << "\n";
	}

}