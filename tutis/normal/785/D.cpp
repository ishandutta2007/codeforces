/***
)))
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll modulo = 1000000007ll;
ll mod(ll x)
{
	x %= modulo;
	x += modulo;
	x %= modulo;
	return x;
}
ll power(ll x, ll p)
{
	x = mod(x);
	if (p == 0)
		return 1;
	if (p == 1)
		return x;
	if (p == 2)
		return mod(x * x);
	return mod(power(power(x, p / 2), 2) * power(x, p % 2));
}
ll inv(ll x)
{
	return power(x, modulo - 2);
}
ll F[500000];
int main()
{
	F[0] = 1;
	for (int i = 1; i < 500000; i++)
		F[i] = mod(F[i - 1] * i);
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	string s;
	cin >> s;
	int a = 0;
	int b = 0;
	for (char x : s)
	{
		b += (x == ')');
	}
	ll ans = 0;
	for (char x : s)
	{
		if (x == ')')
			b--;
		if (x == '(')
			a++;
		if (a > 0 && b > 0)
		{
			if (x == '(')
				ans = mod(ans + F[a + b - 1] * inv(F[a] * F[b - 1]));
		}
	}
	cout << ans << "\n";
}