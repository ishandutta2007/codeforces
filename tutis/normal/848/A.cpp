/***
1000
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll D[100009];
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	D[0] = 0;
	D[1] = 0;
	D[2] = 1;
	for (ll i = 3; i < 100009; i++)
		D[i] = (i / 2) * (i - i / 2) + D[i / 2] + D[i - i / 2];
	ll k;
	cin >> k;
	if (k == 0)
	{
		cout << "a";
		return 0;
	}
	for (char a = 'a'; a <= 'z'; a++)
	{
		ll t = 0;
		while (D[t + 1] <= k)
			t++;
		k -= D[t];
		if (t == 1)
			t = 0;
		for (ll i = 0; i < t; i++)
			cout << a;
	}
}