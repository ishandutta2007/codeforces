/*input
5 1 2 3
1 2 3 4 5
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ll n, p, q, r;
	cin >> n >> p >> q >> r;
	ll A = -1e18;
	ll AB = -2e18;
	ll ABC = -3e18;
	while (n--)
	{
		ll a;
		cin >> a;
		A = max(A, a * p);
		AB = max(AB, A + a * q);
		ABC = max(ABC, AB + a * r);
	}
	cout << ABC << "\n";
}