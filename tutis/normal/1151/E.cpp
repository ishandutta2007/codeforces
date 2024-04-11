/*input
10
1 5 2 5 5 3 10 6 5 1

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll f(ll a, ll n)
{
	return (a) * (n - a + 1);
}
ll f(ll a, ll b, ll n)
{
	ll ret = (a) * (n - b + 1);
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	ll a[n];
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	ll ret = 0;
	for (int i = 1; i <= n; i++)
		ret += f(a[i], n);
	for (int i = 1; i < n; i++)
	{
		int j = i + 1;
		ret -= f(min(a[i], a[j]), max(a[i], a[j]), n);
	}
	cout << ret << "\n";
}