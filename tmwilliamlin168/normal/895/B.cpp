#include <iostream>
#include <algorithm>
 
using namespace std;
typedef long long ll;
 
ll n, x, k;
ll a[100100];
ll ans;
 
ll solve(ll le, ll ri)
{
	if (le > a[n - 1] || ri < a[0])
		return 0;
	ll res = 0;
	int l = 0;
	int r = n - 1;
	int m;
	while (r - l > 1)
	{
		m = (l + r) / 2;
		if (a[m] >= le)
			r = m;
		else
			l = m;
	}
	if (a[l] >= le)
		m = l;
	else
		m = r;
	res = m;
	l = 0;
	r = n - 1;
	while (r - l > 1)
	{
		m = (l + r) / 2;
		if (a[m] <= ri)
			l = m;
		else
			r = m;
	}
	if (a[r] <= ri)
		m = r;
	else
		m = l;
	return m - res + 1;
}
 
int main()
{
	cin >> n >> x >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	for (int i = 0; i < n; i++)
	{
		ll y = a[i] - 1;
		y /= x;
		ll le = max(x*(k + y), a[i]);
		ll ri = x*(k + y + 1) - 1;
		ans += solve(le, ri);
	}
	cout << ans << endl;
}