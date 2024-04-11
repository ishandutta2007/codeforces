/*input
50 100 3 30
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	ll l, r, x, y;
	cin >> l >> r >> x >> y;
	if (y % x != 0)
	{
		cout << "0\n";
		return  0;
	}
	vector<ll>factors;
	set<pair<int, int>>G;
	ll c = y / x;
	for (ll a = 1; a * a <= c; a++)
	{
		if (c % a == 0)
		{
			ll b = c / a;
			if (__gcd(x * a, x * b) == x && l <= x * a && x * a <= r && l <= x * b && x * b <= r)
			{
				G.insert({x * a, x * b});
				G.insert({x * b, x * a});
			}
		}
	}
	cout << G.size() << "\n";
}