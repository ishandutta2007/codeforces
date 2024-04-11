/*input
1 100
99
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ll n, m;
	cin >> n >> m;
	ll prirase = 0;
	while (n--)
	{
		prirase %= m;
		ll a;
		cin >> a;
		prirase += a;
		cout << prirase / m << " ";
	}
}