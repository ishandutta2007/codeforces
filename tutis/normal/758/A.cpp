/*input
5
0 1 2 3 4
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	ll suma = 0;
	ll maxi = 0;
	for (int i = 0; i < n; i++)
	{
		ll a;
		cin >> a;
		suma += a;
		maxi = max(maxi, a);
	}
	cout << maxi*n - suma << "\n";
}