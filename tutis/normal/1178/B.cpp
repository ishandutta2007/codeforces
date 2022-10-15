/*input
vvvovvv

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	ll ans = 0;
	ll k = 0;
	ll d = 0;
	for (int i = 1; i < s.size(); i++)
		if (s[i] == 'v' && s[i - 1] == 'v')
			k++;
	for (int i = 1; i < s.size(); i++)
	{
		if (s[i] == 'v' && s[i - 1] == 'v')
		{
			k--;
			d++;
		}
		if (s[i] == 'o')
		{
			ans += (k * d);
		}
	}
	cout << ans << "\n";
}