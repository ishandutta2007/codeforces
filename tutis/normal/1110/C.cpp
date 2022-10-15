/*input
3
2
3
5
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
map<ll, ll>M;
ll f(ll a)
{
	ll a_ = a + 1;
	if ((a_ & (-a_)) == a_)
	{
		if (M.count(a))
			return M[a];
		ll ret = 0;
		for (ll b = 1; b < a; b++)
		{
			ret = max(ret, __gcd(a ^ b, a & b));
		}
		return M[a] = ret;
	}
	a *= 2;
	while (a != (a & (-a)))
		a -= (a & (-a));
	return a - 1;
}
int main()
{
	M[1] = 0;
	M[3] = 1;
	M[7] = 1;
	M[15] = 5;
	M[31] = 1;
	M[63] = 21;
	M[127] = 1;
	M[255] = 85;
	M[511] = 73;
	M[1023] = 341;
	M[2047] = 89;
	M[4095] = 1365;
	M[8191] = 1;
	M[16383] = 5461;
	M[32767] = 4681;
	M[65535] = 21845;
	M[131071] = 1;
	M[262143] = 87381;
	M[524287] = 1;
	M[1048575] = 349525;
	M[2097151] = 299593;
	M[4194303] = 1398101;
	M[8388607] = 178481;
	M[16777215] = 5592405;
	M[33554431] = 1082401;
	ios_base::sync_with_stdio(false);
	ll q;
	cin >> q;
	while (q--)
	{
		ll a;
		cin >> a;
		cout << f(a) << "\n";
	}
}