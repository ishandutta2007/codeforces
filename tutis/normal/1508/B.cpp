/*input
5
1 1
1 2
3 3
6 5
3 4
*/
#pragma GCC optimize ("O3")
#pragma GCC target ("avx2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename X>
using ordered_map = tree<T, X, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename X>
using fast_map = cc_hash_table<T, X>;
//using ull = __ull128_t;
using ull = unsigned long long;
using ll = long long;
using ld = double;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template<typename T>
void sort_unique(T x) {sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()), x.end());}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	ll t;
	cin >> t;
	while (t--)
	{
		ll n, k;
		cin >> n >> k;
		ll lo = 1;
		ll hi = n;
		vector<ll>ans;
		while (ans.size() < n)
		{
			bool ok = false;
			for (ll c = lo; c <= hi; c++)
			{
				ll cnt = c - lo + 1;
				ll liko = (hi - lo + 1) - cnt - 1;
				ll kiek = liko < 0 ? 1 : (liko <= 62 ? (1ll << liko) : k + 1);
				if (kiek < k)
				{
					k -= kiek;
				}
				else
				{
					for (ll i = 0; i < cnt; i++)
					{
						ans.push_back(lo + cnt - i - 1);
					}
					lo += cnt;
					ok = true;
					break;
				}
			}
			if (!ok)
				break;
		}
		if (ans.size() == n)
		{
			for (ll i : ans)
				cout << i << " ";
			cout << "\n";
		}
		else
			cout << "-1\n";
	}



}