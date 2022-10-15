/*input
6 6
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
vector<pair<ll, ll>>factors(ll n)
{
	vector<pair<ll, ll>>ret;
	for (ll i = 2; i * i <= n; i++)
	{
		int kiek = 0;
		while (n % i == 0)
		{
			kiek++;
			n /= i;
		}
		if (kiek > 0)
			ret.push_back({i, kiek});
	}
	if (n > 1)
		ret.push_back({n, 1});
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll x, y;
	cin >> x >> y;
	vector<pair<ll, ll>>AA = factors(x);
	vector<pair<ll, ll>>BB = factors(y);
	for (auto &i : AA)
		i.second *= y;
	for (auto &i : BB)
		i.second *= x;
	if (AA == BB)
	{
		cout << "=\n";
		return 0;
	}
	ld A = ld(y) * log(x);
	ld B = ld(x) * log(y);
	if (A > B)
		cout << ">\n";
	else
		cout << "<\n";
}