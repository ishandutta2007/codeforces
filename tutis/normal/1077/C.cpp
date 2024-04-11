/*input
5
2 5 1 2 2
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	ll a[n + 1];
	ll suma = 0;
	map<ll, ll>K;
	for (ll i = 1; i <= n; i++)
	{
		cin >> a[i];
		suma += a[i];
		K[a[i]]++;
	}
	vector<ll>ans;
	for (ll i = 1; i <= n; i++)
	{
		K[a[i]]--;
		suma -= a[i];
		if (K[suma / 2] > 0 && suma % 2 == 0)
			ans.push_back(i);
		suma += a[i];
		K[a[i]]++;
	}
	cout << ans.size() << "\n";
	for (ll i : ans)
		cout << i << " ";
}