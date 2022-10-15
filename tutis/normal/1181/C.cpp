/*input
10 10
aaaaarpppp
bbbbsssssu
cciiiiiiqq
ddmmgggggg
eeebbbbbbb
fffffqoooo
gxxxxrrrrr
hhfuuuuuuu
iiillqqqqq
jjjjjppwww
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	ll n, m;
	cin >> n >> m;
	ll ans = 0;
	string s[n];
	for (ll i = 0; i < n; i++)
		cin >> s[i];
	map<pair<pair<char, pair<char, char>>, pair<ll, ll>>, ll>K;
	for (ll c = 0; c < m; c++)
	{
		deque<pair<char, ll>>v;
		set<pair<pair<char, pair<char, char>>, pair<ll, ll>>>yra;
		for (ll r = 0; r < n; r++)
		{
			ll k = r;
			if (v.size() > 0 && v.back().first == s[r][c])
			{
				k = v.back().second;
				v.pop_back();
			}
			v.push_back({s[r][c], k});
			while (v.size() > 3)
				v.pop_front();
			if (v.size() == 3)
			{
				pair<char, pair<char, char>> col = {v[0].first, {v[1].first, v[2].first}};
				ll k0 = v[1].second - v[0].second;
				ll k1 = v[2].second - v[1].second;
				ll k2 = r - v[2].second + 1;
				if (k2 >= k1 && k0 >= k1)
				{
					ll a = v[1].second;
					ll b = v[2].second;
					yra.insert({col, {a, b}});
				}
			}
		}
		for (auto it = K.begin(); it != K.end();)
		{
			if (yra.count(it->first))
			{
				it++;
			}
			else
				it = K.erase(it);
		}
		for (auto i : yra)
		{
			if (K.count(i))
				K[i]++;
			else
				K[i] = 1;
			ans += K[i];
		}
	}
	cout << ans << "\n";
}