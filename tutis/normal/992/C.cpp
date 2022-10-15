/*input
1000000007 10
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll modulo = 1000000007;
ll power(ll x, ll a)
{
	x %= modulo;
	if (a == 0)
		return 1;
	if (a == 1)
		return x;
	if (a == 2)
		return (x * x) % modulo;
	return (power(power(x, a / 2), 2) * power(x, a % 2)) % modulo;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	ll x, k;
	cin >> x >> k;
	if (x == 0)
	{
		cout << "0\n";
		return 0;
	}
	x %= modulo;
	ll ans1 = (power(2, k) + 1) % modulo;
	ll skirt = (power(2, k + 1) * ((x - 1 + modulo) % modulo)) % modulo;
	cout << (ans1 + skirt) % modulo << "\n";
}