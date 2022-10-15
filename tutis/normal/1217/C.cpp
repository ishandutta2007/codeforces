/*input
4
0110
0101
00001000
0001000

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--)
	{
		string s;
		cin >> s;
		int ans = 0;
		for (int l = 1; l < 20; l++)
		{
			int k0 = 0;
			for (int i = 0; i + l - 1 < (int)s.size(); i++)
			{
				if (s[i] == '0')
				{
					k0++;
					continue;
				}
				int x = 0;
				for (int t = 0; t < l; t++)
				{
					x *= 2;
					x += s[i + t] - '0';
				}
				int y = x - l;
				if (0 <= y && y <= k0)
					ans++;
				k0 = 0;
			}
		}
		cout << ans << "\n";
	}
}