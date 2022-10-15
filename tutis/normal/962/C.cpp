/*input
333
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long ld;
bool square(ll x)
{
	ll a = sqrtl(x);
	return a * a == x;
}
string X(ll n)
{
	if (n < 10)
	{
		string a;
		a.push_back('0' + n);
		return a;
	}
	return X(n / 10) + X(n % 10);
}
ll num(string a)
{
	ll ret = 0;
	ll w = 1;
	for (ll i = a.size() - 1; i >= 0; i--)
	{
		ret += w * ll(a[i] - '0');
		w *= 10;
	}
	return ret;
}
ll kiek(string a)
{
	if (a[0] == '0')
		return INT_MAX;
	ll ans = INT_MAX;
	if (square(num(a)))
		return 0;
	if (a.size() == 1)
		return INT_MAX;
	for (int i = 0; i < a.size(); i++)
	{
		string C;
		for (int j = 0; j < a.size(); j++)
		{
			if (j != i)
				C.push_back(a[j]);
		}
		ans = min(ans, 1 + kiek(C));
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ll n;
	cin >> n;
	ll ans = INT_MAX;
	ans = min(ans, kiek(X(n)));
	if (ans > 180)
		ans = -1;
	cout << ans;


}