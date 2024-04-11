/*input
11001100

*/
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	ll ans = 0;
	for (int l = 0; l < s.size(); l++)
	{
		int r = l + 1;
		while (true)
		{
			r++;
			if (r < s.size())
			{
				bool ok = false;
				for (int k = 1; r - 2 * k >= l; k++)
				{
					if (s[r] == s[r - k] && s[r] == s[r - 2 * k])
					{
						ok = true;
						break;
					}
				}
				if (ok)
				{
					ans += ll(s.size()) - ll(r);
					break;
				}
			}
			else
				break;
		}
	}
	cout << ans << "\n";
}