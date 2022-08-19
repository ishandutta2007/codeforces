#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef long long ll;

ll ans;
ll x;

int main()
{
	cin >> x;
	ans = 0;
	ll p = 9;
	ll c = 1;
	while(x > 0)
	{
		ll z = min(x, p);
		ans += z * c;
		x -= z;
		p *= 10LL;
		c++;
	}
	cout << ans << endl;

	return 0;
}