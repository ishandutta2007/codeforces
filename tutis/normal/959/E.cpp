/*input
1000000000000
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll ats(ll n)
{
	ll ret = 0;
	for (ll w = 1; w <= 2 * n; w *= 2)
	{
		ret += w * ((n) / (w * 2));
		if (n % (2 * w) > w)
			ret += w;
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ll n;
	cin >> n;
	cout << ats(n) << endl;
	return 0;
}