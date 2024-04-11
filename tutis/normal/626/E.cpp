/*input
4
1 1 2 2

*/
#pragma GCC optimize ("O3")
//#pragma GCC target ("avx2")
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
using ull = unsigned long long;
using ll = long long;
using ld = long double;
mt19937_64 rng(123);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin >> n;
	ll a[n];
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	ll S[n + 1];
	S[0] = 0;
	for (ll i = 0; i < n; i++)
		S[i + 1] = S[i] + a[i];
	ll i_ = 0, j_ = 0, c_ = 0;
	auto f = [&](ll i, ll j, ll c)->pair<ll, ll>
	{
		assert(n - c > j && i - c >= 0);
		ll cnt = 1;
		if (i != j)
			cnt++;
		cnt += 2 * c;
		ll sum = a[i];
		if (i != j)
			sum += a[j];
		sum += S[n] - S[n - c];
		sum += S[i] - S[i - c];
		return {sum * 2 - (a[i] + a[j]) * cnt, cnt * 2};
	};
	ll c = 0;
	for (ll d : {0, 1})
		for (ll i = 0; i + d < n; i++)
		{
			ll j = i + d;
			ll cm = min(i, n - 1 - j);
			c = min(c, cm);
			bool ok = true;
			while (ok)
			{
				ok = false;
				pair<ll, ll>a = f(i, j, c);
				for (ll del : { -1, 1})
				{
					ll cc = c + del;
					if (cc >= 0 && cc <= cm)
					{
						pair<ll, ll>b = f(i, j, cc);
						if (b.first * a.second > a.first * b.second)
						{
							c = cc;
							ok = true;
						}
					}
				}
			}
			pair<ll, ll>a = f(i, j, c);
			pair<ll, ll>b = f(i_, j_, c_);
			if (b.first * a.second < a.first * b.second)
			{
				i_ = i;
				j_ = j;
				c_ = c;
			}
		}
	vector<ll>ans = {a[i_]};
	if (i_ != j_)
		ans.push_back(a[j_]);
	for (ll k = 1; k <= c_; k++)
	{
		ans.push_back(a[n - k]);
		ans.push_back(a[i_ - k]);
	}
	cout << ans.size() << "\n";
	for (ll i : ans)
		cout << i << " ";
	cout << "\n";
}