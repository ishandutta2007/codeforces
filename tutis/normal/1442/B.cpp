/*input
3
5 3
1 2 3 4 5
3 2 5
4 3
4 3 2 1
4 3 1
7 4
1 4 7 3 6 2 5
3 2 4 5

*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const ll mod = 998244353;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t;
	cin >> t;
	while (t--)
	{
		ll n, k;
		cin >> n >> k;
		map<ll, ll>A;
		ll kur[n + 1];
		for (ll i = 1; i <= n; i++)
		{
			ll x;
			cin >> x;
			A[i] = x;
			kur[x] = i;
		}
		ll ret = 1;
		ll b[k];
		vector<bool>ger(n + 1, true);
		for (ll i = 0; i < k; i++)
		{
			cin >> b[i];
			ger[b[i]] = false;
		}
		for (ll i = 0; i < k; i++)
		{
			ll id = kur[b[i]];
			auto it = A.upper_bound(id);
			auto it1 = A.find(id);
			ll cnt = 0;
			if (it != A.end() && ger[it->second])
				cnt++;
			if (it1 != A.begin())
			{
				it1--;
				if (ger[it1->second])
					cnt++;
			}
			if (cnt == 0)
			{
				ret = 0;
				break;
			}
			else
			{
				ret *= cnt;
				while (ret >= mod)
					ret -= mod;
			}
			A.erase(id);
		}
		cout << ret << "\n";
	}
}