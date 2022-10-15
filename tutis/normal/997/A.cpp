/*input
7 2 3
1111111
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ll n, x, y;
	cin >> n >> x >> y;
	string s;
	cin >> s;
	int a = 0;
	int b = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (i == 0 || s[i] != s[i - 1])
		{
			if (s[i] == '1')
				a++;
			else
				b++;
		}
	}
	ll ans = 0;
	while (a >= 2 && b >= 2)
	{
		ans += min(x, y);
		a--;
		b--;
	}
	if (a == 1)
	{
		if (b == 1)
		{
			ans += y;
		}
		else if (b == 2)
		{
			ans += min(x, y) + y;
		}
	}
	else if (a == 0)
	{
		if (b > 0)
			ans += y;
	}
	else if (a == 2)
	{
		ans += y;
	}
	cout << ans << "\n";
}