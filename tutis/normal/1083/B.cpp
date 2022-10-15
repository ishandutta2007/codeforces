/*input
3 3
aba
bba
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	ll n, k;
	cin >> n >> k;
	string s, t;
	cin >> s >> t;
	ll ans = 0;
	bool vienodi = true;
	ll kiekis = 0;
	for (int i = 0; i < n; i++)
	{
		if (vienodi)
		{
			if (s[i] != t[i])
			{
				if (k > 1)
					ans++;
				vienodi = false;
			}
			ans++;
			continue;
		}
		kiekis *= 2;
		if (s[i] == 'a')
			kiekis++;
		if (t[i] == 'b')
			kiekis++;
		ans += min(kiekis + 2, k);
		kiekis = min(kiekis, k + 2);
	}
	cout << ans << "\n";
}