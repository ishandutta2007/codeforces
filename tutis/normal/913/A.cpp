/***
98765432
23456789
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	ll n, m;
	cin >> n >> m;
	bool keisti = true;
	ll k = 1;
	while (n--)
	{
		k *= 2;
		if (k > m)
			keisti = false;
	}
	if (keisti)
		m %= k;
	cout << m << endl;
}