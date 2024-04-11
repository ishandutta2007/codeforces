/**
12 1
**/
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef unsigned long long ll;
typedef double d;
typedef long l;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ll n, s;
	cin >> n >> s;
	ll k = 0;
	ll lo = 1;
	ll hi = n + 1;
	while (lo < hi)
	{
		ll i = (lo + hi) / 2;
		ll N = i;
		ll S = 0;
		while (N > 0)
		{
			S += N % 10;
			N /= 10;
		}
		if (i >= s + S)
			hi = i;
		else
			lo = i + 1;
	}
	cout << n - lo + 1;
	return 0;
}