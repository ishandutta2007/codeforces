/*input
10 3 10
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll modulo = 1000 * 1000 * 1000 + 7;
map<ll, ll>A1;
ll ilgis(ll n)
{
	if (n <= 1)
		return 1;
	if (A1.count(n))
		return A1[n];
	return A1[n] = 2 * ilgis(n / 2) + 1;
}
map<ll, ll>A2;
ll suma(ll n)
{
	if (n <= 1)
		return n % 2;
	if (A2.count(n))
		return A2[n];
	return A2[n] = 2 * suma(n / 2) + n % 2;
}
ll answer(ll n, ll k)
{
	if (k <= 0)
		return 0;
	if (n == 1)
		return k >= 1;
	if (n == 0)
		return 0;
	if (k == ilgis(n / 2) + 1)
		return suma(n / 2) + n % 2;
	if (k == ilgis(n / 2))
		return suma(n / 2);
	if (ilgis(n / 2) >= k)
		return answer(n / 2, k);
	return suma(n / 2) + n % 2 + answer(n / 2, k - ilgis(n / 2) - 1);
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ll l, n, r;
	cin >> n >> l >> r;
	cout << answer(n, r) - answer(n, l - 1) << "\n";
}