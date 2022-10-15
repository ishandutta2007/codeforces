/*input
4 100 2
20 30 75 80

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	ll n, m, k;
	cin >> n >> m >> k;
	ll p[n];
	for (int i = 0; i < n; i++)
		cin >> p[i];
	ll ans = n;
	vector<ll>x;
	for (int i = 1; i < n; i++)
		x.push_back(p[i] - p[i - 1] - 1);
	sort(x.begin(), x.end());
	for (int i = 0; i < n - k; i++)
		ans += x[i];
	cout << ans << "\n";
}