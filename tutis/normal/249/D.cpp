/*input
15
1/3 2/1
3 1
6 2
4 2
2 5
4 5
6 6
3 4
1 6
2 1
7 4
9 3
5 3
1 3
15 5
12 4
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
pair<ll, ll>conv(string a)
{
	string x;
	string y;
	bool buvo = false;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] == '/')
		{
			buvo = true;
		}
		else if (!buvo)
			x.push_back(a[i]);
		else
			y.push_back(a[i]);
	}
	return {stoll(x), stoll(y)};
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	string ab;
	string cd;
	cin >> ab >> cd;
	ll a = conv(ab).first;
	ll b = conv(ab).second;
	ll c = conv(cd).first;
	ll d = conv(cd).second;
	swap(a, b);
	swap(c, d);
	pair<ll, ll>X[n];
	for (pair<ll, ll> &i : X)
	{
		ll x, y;
		cin >> x >> y;
		i = { -(x * b - a * y), x*d - c * y};
		//cout<<x<<" "<<y<<" "<<i.first<<" "<<i.second<<endl;
	}
	sort(X, X + n, greater<pair<ll, ll>>());
	map<ll, ll>V;
	ll ans = 0;
	deque<pair<ll, pair<ll, ll>>>GG;
	for (pair<ll, ll> &i : X)
	{
		while (!GG.empty() && GG.front().first > i.first)
		{
			ll y = GG.front().second.first;
			ll g = GG.front().second.second;
			GG.pop_front();
			while (true)
			{
				auto it = V.lower_bound(y);
				if (it != V.begin())
				{
					it--;
					if (it->second <= g)
						V.erase(it);
					else
						break;
				}
				else
					break;
			}
			V[y] = g;
		}
		ll gal = 0;
		auto it = V.upper_bound(i.second);
		if (it != V.end())
			gal = max(gal, it->second);
		gal++;
		if (i.first > 0 && i.second > 0)
			ans = max(ans, gal);
		GG.push_back({i.first, {i.second, gal}});
	}
	cout << ans << "\n";
}