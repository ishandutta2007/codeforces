/*input
4 3
4 7
15 1
3 6
6 8
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(false);
	ll n, k;
	cin >> n >> k;
	pair<ll, ll>x[n];
	for (auto &i : x)
		cin >> i.first >> i.second;
	sort(x, x + n, [](pair<ll, ll>a, pair<ll, ll>b) {
		return a.second > b.second;
	});
	ll ans = 0;
	multiset<ll>T;
	ll ts = 0;
	for (auto i : x)
	{
		ts += i.first;
		T.insert(i.first);
		while (T.size() > k)
		{
			auto it = T.begin();
			ts -= (*it);
			T.erase(it);
		}
		ans = max(ans, ts * i.second);
	}
	cout << ans << "\n";
}