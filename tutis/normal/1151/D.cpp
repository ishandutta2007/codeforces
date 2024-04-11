/*input
10
5 10
12 4
31 45
20 55
30 17
29 30
41 32
7 1
5 5
3 15

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
	pair<ll, ll>a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i].first >> a[i].second;
	sort(a, a + n, [](pair<ll, ll>a, pair<ll, ll>b) {
		return a.second - a.first < b.second - b.first;
	});
	ll ret = 0;
	for (ll i = 0; i < n; i++)
	{
		ret += a[i].first * i + a[i].second * (n - i - 1);
	}
	cout << ret << "\n";
}