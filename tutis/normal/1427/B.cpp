/*input
8
5 2
WLWLL
6 5
LLLWWL
7 1
LWLWLWL
15 5
WWWLLLWWWLLLWWW
40 7
LLWLWLWWWLWLLWLWWWLWLLWLLWLLLLWLLWWWLWWL
1 0
L
1 1
L
6 1
WLLWLW

*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		int cnt = 0;
		for (char c : s)
			if (c == 'L')
				cnt++;
		if (cnt == n)
		{
			cout << max(0, 2 * k - 1) << "\n";
			continue;
		}
		k = min(k, cnt);
		int ans = 0;
		bool w = false;
		vector<int>X;
		cnt = 0;
		for (int i = 0; i < n; i++)
		{
			char c = s[i];
			if (c == 'L')
			{
				cnt++;
				if (i + 1 == n || s[i + 1] == 'W')
				{
					if (cnt == i + 1 || i == n - 1)
						X.push_back(n + 1);
					else
						X.push_back(cnt);
				}
				w = false;
			}
			else
			{
				cnt = 0;
				if (w)
					ans += 2;
				else
					ans++;
				w = true;
			}
		}
		int dar = 0;
		sort(X.begin(), X.end());
		for (int i : X)
		{
			if (k > 0)
			{
				if (k >= i)
				{
					ans += 2 * i + 1;
					k -= i;
				}
				else
				{
					ans += 2 * k;
					break;
				}
			}
		}
		cout << ans + dar << "\n";
	}
}