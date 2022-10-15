/*input
10 9 82
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	ll n, k, s;
	cin >> n >> k >> s;
	n--;
	if (n * k < s || k > s)
	{
		cout << "NO\n";
		return 0;
	}
	ll x = 1;
	vector<ll>ans;
	while (k > 0)
	{
		ll a = min(n, s - (k - 1));
		if (a <= 0)
			break;
		if (x == 1)
		{
			ans.push_back(x + a);
			x = ans.back();
		}
		else
		{
			ans.push_back(x - a);
			x = ans.back();
		}
		k--;
		s -= a;
	}
	while (s == k && k > 0)
	{
		if (x + 1 != n + 1)
		{
			x++;
		}
		else
		{
			x--;
		}
		ans.push_back(x);
		s--;
		k--;
	}
	if (s != k)
	{
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	for (int i : ans)
		cout << i << " ";
}