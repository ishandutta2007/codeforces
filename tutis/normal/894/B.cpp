/***
2529756051797760 2682355969139391 -1
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD (1000000007ll)
#define mod(x) ((((x)%MOD)+MOD)%MOD)
ll power(ll a, ll p)
{
	p %= MOD - 1;
	a = mod(a);
	if (p == 0)
		return 1;
	if (p == 1)
		return a;
	if (p == 2)
		return mod(a * a);
	return mod(power(power(a, p / 2), 2) * power(a, p % 2));
}
int main()
{
	ll n, m, k;
	cin >> n >> m >> k;
	if (k == -1 && n % 2 != m % 2)
		cout << 0;
	else
		cout << mod(power(2, ((m - 1) % (MOD - 1)) * ((n - 1) % (MOD - 1))));
}