/*input
7 7
4 5 1 6 2 3 7
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll modulo = 998244353;
int n, m;
int c[555];
ll DP[555][555];
ll dp(int l, int r)
{
	if (l - 1 == r)
		return 1;
	if (l == r)
		return 1;
	if (l > r)
		return 0;
	if (DP[l][r] != 0)
		return DP[l][r];
	int p = min_element(c + l, c + r + 1) - c;
	ll ans = 0;
	ll suma = 0;
	for (int r_ = p; r_ <= r; r_++)
	{
		suma += ((dp(r_ + 1, r) * dp(p + 1, r_)) % modulo);
		suma %= modulo;
	}
	for (int l_ = p; l_ >= l; l_--)
	{
		ans += ((dp(l, l_ - 1) * dp(l_, p - 1)) % modulo) * suma;
		ans %= modulo;
	}
	return DP[l][r] = ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> c[i];
	}
	cout << dp(1, m) << "\n";
}