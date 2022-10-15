/*input
3
0 0 3 3
3 3 4 4
10 10 60 50
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
	ll x1[n];
	ll y1[n];
	ll x2[n];
	ll y2[n];
	for (ll i = 0; i < n; i++)
		cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
	ll mxx1a[n];
	ll mxx1b[n];
	ll mnx2a[n];
	ll mnx2b[n];
	ll mxy1a[n];
	ll mxy1b[n];
	ll mny2a[n];
	ll mny2b[n];
	mxx1a[0] = x1[0];
	mnx2a[0] = x2[0];
	mxy1a[0] = y1[0];
	mny2a[0] = y2[0];

	mxx1b[n - 1] = x1[n - 1];
	mnx2b[n - 1] = x2[n - 1];
	mxy1b[n - 1] = y1[n - 1];
	mny2b[n - 1] = y2[n - 1];
	for (ll i = 1; i < n; i++)
	{
		mxx1a[i] = max(mxx1a[i - 1], x1[i]);
		mnx2a[i] = min(mnx2a[i - 1], x2[i]);
		mxy1a[i] = max(mxy1a[i - 1], y1[i]);
		mny2a[i] = min(mny2a[i - 1], y2[i]);
	}
	for (ll i = n - 2; i >= 0; i--)
	{
		mxx1b[i] = max(mxx1b[i + 1], x1[i]);
		mnx2b[i] = min(mnx2b[i + 1], x2[i]);
		mxy1b[i] = max(mxy1b[i + 1], y1[i]);
		mny2b[i] = min(mny2b[i + 1], y2[i]);
	}
	for (ll i = 0; i < n; i++)
	{
		ll xa = -1e10, xb = 1e12;
		ll ya = -1e10, yb = 1e12;
		if (i - 1 >= 0)
		{
			xa = max(xa, mxx1a[i - 1]);
			xb = min(xb, mnx2a[i - 1]);
		}
		if (i + 1 < n)
		{
			xa = max(xa, mxx1b[i + 1]);
			xb = min(xb, mnx2b[i + 1]);
		}
		if (i - 1 >= 0)
		{
			ya = max(ya, mxy1a[i - 1]);
			yb = min(yb, mny2a[i - 1]);
		}
		if (i + 1 < n)
		{
			ya = max(ya, mxy1b[i + 1]);
			yb = min(yb, mny2b[i + 1]);
		}
		if (xa <= xb && ya <= yb)
		{
			cout << xa << " " << ya << "\n";
			return 0;
		}
	}
}