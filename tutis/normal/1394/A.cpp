/*input
20 2 16
20 5 8 2 18 16 2 16 16 1 5 16 2 13 6 16 4 17 21 7

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename K>
using ordered_map = tree<T, K, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	ll n, d, m;
	cin >> n >> d >> m;
	ll a[n];
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	vector<ll>D, M;
	for (ll i = 0; i < n; i++)
	{
		if (a[i] > m)
			D.push_back(a[i]);
		else
			M.push_back(a[i]);
	}
	sort(D.begin(), D.end(), greater<ll>());
	sort(M.begin(), M.end(), greater<ll>());
	ll X[M.size() + 1];
	X[0] = 0;
	for (int i = 1; i <= M.size(); i++)
		X[i] = X[i - 1] + M[i - 1];
	ll ans = 0;
	for (ll i : M)
		ans += i;
	ll sum = 0;
	for (int k = 1; k <= (int)D.size(); k++)
	{
		sum += D[k - 1];
		ll kiek = (d + 1) * (k - 1) + 1;
		if (kiek <= n)
		{
			ll kiek1 = min(n - kiek, (ll)M.size());
			ans = max(ans, sum + X[kiek1]);
		}
	}
	cout << ans << "\n";
	return 0;
}