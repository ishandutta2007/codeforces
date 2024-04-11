/*input
5 4
5 -1 3 4 -1
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll solve(int l, int r, ll* Pre, ll* Suff, ll suma, ll t)
{
	if (r - l + 1 <= 4)
	{
		ll ans = 0;
		for (int a = l; a <= r; a++)
		{
			for (int b = a; b <= r; b++)
			{
				if (suma - Pre[a - 1] - Suff[b + 1] < t)
					ans++;
			}
		}
		return ans;
	}
	int i = (l + r) / 2;
	ll ans = 0;
	vector<ll>y;
	for (int b = i; b <= r; b++)
		y.push_back(Suff[b + 1]);
	sort(y.begin(), y.end());
	for (int a = l; a <= i; a++)
		ans += y.end() - upper_bound(y.begin(), y.end(), suma - t - Pre[a - 1]);
	return ans + solve(l, i - 1, Pre, Suff, suma, t) + solve(i + 1, r, Pre, Suff, suma, t);
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	ll n, t;
	cin >> n >> t;
	ll A[n + 2];
	for (int i = 1; i <= n; i++)
		cin >> A[i];
	A[0] = A[n + 1] = 0;
	ll Pre[n + 2];
	Pre[0] = 0;
	ll Suff[n + 2];
	Suff[n + 1] = 0;
	for (int i = 1; i <= n + 1; i++)
		Pre[i] = Pre[i - 1] + A[i];
	for (int i = n; i >= 0; i--)
		Suff[i] = Suff[i + 1] + A[i];
	ll suma = Suff[0];
	cout << solve(1, n, Pre, Suff, suma, t) << "\n";
}