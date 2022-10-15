/*input
4
4
-><-
5
>>>>>
3
<--
2
<>
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		string s;
		cin >> s;
		int ans = 0;
		bool a = true;
		bool b = true;
		for (int i = 0; i < n; i++)
		{
			int j = (i + 1) % n;
			if (s[i] == '<')
				a = false;
			if (s[i] == '>')
				b = false;
			if (s[i] == '-' || s[j] == '-')
				ans++;
		}
		if (a || b)
			ans = n;
		cout << ans << "\n";
	}
}