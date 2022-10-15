/*input
1
10
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	ll n;
	cin >> n;
	ll a[n];
	for (ll &i : a)
		cin >> i;
	ll suma = accumulate(a, a + n, 0ll);
	auto i = min_element(a, a + n) - a;
	if (a[i] < suma - a[i])
	{
		cout << "1\n" << i + 1 << "\n";
	}
	else
	{
		cout << "-1\n";
	}
}