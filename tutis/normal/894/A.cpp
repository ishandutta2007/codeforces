/***
QAQQQZZYNOIWIN
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	string s;
	cin >> s;
	ll n = s.size();
	ll ans = 0;
	for (ll i = 0; i < n; i++)
	{
		for (ll j = i + 1; j < n; j++)
		{
			for (ll k = j + 1; k < n; k++)
			{
				if (s[i] == 'Q' && s[j] == 'A' && s[k] == 'Q')
					ans++;
			}
		}
	}
	cout << ans;
}