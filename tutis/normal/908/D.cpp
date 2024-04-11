/***
3 1 4
***/
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define MOD (1000000007ll)
ll mod(ll x)
{
	x %= MOD;
	x += MOD;
	x %= MOD;
	return x;
}
ll power(ll a, ll p)
{
	a = mod(a);
	if (p == 0)
		return 1;
	if (p == 1)
		return a;
	if (p == 2)
		return mod(a * a);
	return mod(power(power(a, p / 2), 2) * power(a, p % 2));
}
ll inv(ll a)
{
	return power(a, MOD - 2);
}
ll k, pa, pb, x, y;
ll DP_[3005][3005];
ll DP(ll a, ll ab)
{
	if (DP_[a][ab] != -1)
		return DP_[a][ab];
	if (ab >= k)
		return DP_[a][ab] = ab;
	if (a >= k)
		return DP_[a][ab] = mod(mod(mod((a + ab) + x - (a + ab) * x) * y) * inv((x - 1) * (x - 1)));
	if (a == 0)
		return DP_[a][ab] = mod(mod(x * DP(a + 1, ab)) * inv(1 - y));
	return DP_[a][ab] = mod(x * DP(a + 1, ab) + y * DP(a, ab + a));
}
int main()
{
	for (int i = 0; i < 3005; i++)
		for (int j = 0; j < 3005; j++)
			DP_[i][j] = -1;
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> k >> pa >> pb;
	x = mod(pa * inv(pa + pb));
	y = mod(pb * inv(pa + pb));
	cout << DP(0, 0);
}