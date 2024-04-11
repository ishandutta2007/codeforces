/*input
300000000 0 0 1 0
*/
#include <bits/stdc++.h>
using namespace std;
typedef uint32_t ll;
typedef long long lll;
typedef long double ld;
bitset<50000003>P1;
bitset<50000003>P5;
lll f1(lll p, lll n)
{
	lll x = p;
	lll ans = 0;
	while (x <= n)
	{
		ans += n / x;
		x *= p;
	}
	return ans;
}
const ll o = ((1ll << 32) - 1);
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ll n, A, B, C, D;
	cin >> n >> A >> B >> C >> D;
	auto f = [&](lll x)->lll
	{
		x &= o;
		return ((D + ((x * (C + (x * (B + x * A)&o)))&o))&o);
	};
	lll ans = 0;
	for (ll  a : {2, 3})
	{
		ans += f(a) * f1(a, n);
		ans &= o;
	}
	for (ll a = 5; a <= n; a++)
	{
		bool prime = false;
		if (a % 6 == 1 && (P1[a / 6] == 0))
		{
			prime = true;
		}
		if (a % 6 == 5 && (P5[a / 6] == 0))
		{
			prime = true;
		}
		if (prime)
		{
			for (ll i = a; i <= n; i += a)
			{
				if (i % 6 == 1)
					P1[i / 6] = 1;
				if (i % 6 == 5)
					P5[i / 6] = 1;
			}
			ans += f(a) * f1(a, n);
			ans &= o;
		}
	}
	cout << ans << "\n";
}