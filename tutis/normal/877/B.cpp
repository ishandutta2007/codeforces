/***
bab
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	string x;
	cin >> x;
	ll n = x.size();
	ll A[n + 5];
	A[0] = 0;
	for (ll i = 0; i < n; i++)
		A[i + 1] = A[i] + (x[i] == 'a');
	ll B[n + 5];
	B[0] = 0;
	for (ll i = 0; i < n; i++)
		B[i + 1] = B[i] + (x[i] == 'b');
	B[n + 1] = B[n];
	A[n + 1] = A[n];
	ll ans = 0;
	for (ll i = 1; i <= n + 1; i++)
	{
		for (ll j = i - 1; j <= n + 1; j++)
		{
			ll a1 = A[i - 1];
			ll a2 = A[n] - A[j];
			ll b = B[j] - B[i - 1];
			ans = max(ans, a1 + a2 + b);
		}
	}
	cout << ans;
}