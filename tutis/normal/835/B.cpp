/***
3
99
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ll k;
	string n;
	cin >> k >> n;
	ll kiek[10];
	fill_n(kiek, 10, 0);
	for (char i : n)
		kiek[i - '0']++;
	ll suma = 0;
	for (ll i = 0; i < 10; i++)
		suma += i * kiek[i];
	ll ans = 0;
	while (suma < k)
	{
		for (ll i = 0; i < 10; i++)
		{
			if (kiek[i])
			{
				kiek[i]--;
				suma += 9 - i;
				ans++;
				break;
			}
		}
	}
	cout << ans;
}