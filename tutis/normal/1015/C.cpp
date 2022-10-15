/*input
4 21
10 8
7 4
3 1
5 4
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
	pair<ll, ll> X[n];
	for (int i = 0; i < n; i++)
		cin >> X[i].first >> X[i].second;
	sort(X, X + n, [&](pair<ll, ll>a, pair<ll, ll>b) {return a.first - a.second > b.first - b.second;});
	ll suma = 0;
	for (auto i : X)
		suma += i.first;
	if (suma <= m)
	{
		cout << 0 << "\n";
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		suma -= X[i].first;
		suma += X[i].second;
		if (suma <= m)
		{
			cout << i + 1 << "\n";
			return 0;
		}
	}
	cout << "-1\n";
}