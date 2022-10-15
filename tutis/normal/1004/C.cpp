/*input
7
1 2 1 1 1 3 2
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll kiek[100009];
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	ll n;
	cin >> n;
	ll a[n];
	set<ll>X;
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
		X.insert(a[i]);
		kiek[a[i]]++;
	}
	ll ans = 0;
	set<ll>K;
	for (ll i = 0; i < n; i++)
	{
		kiek[a[i]]--;
		if (kiek[a[i]] == 0)
			X.erase(a[i]);
		if (K.count(a[i]))
			continue;
		K.insert(a[i]);
		ans += X.size();
	}
	cout << ans << "\n";

}