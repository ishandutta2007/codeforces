/*input
5
3 2 2 2 1

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	ll K[2] = {0, 0};
	for (int i = 0; i < n; i++)
	{
		ll a;
		cin >> a;
		ll x = a / 2;
		ll y = a - x;
		if (i % 2 == 0)
		{
			K[0] += x;
			K[1] += y;
		}
		else
		{
			K[1] += x;
			K[0] += y;
		}
	}



	cout << min(K[0], K[1]) << "\n";
}