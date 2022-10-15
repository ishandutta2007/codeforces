/*input
3
2
<>
3
><<
1
>
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		string s;
		cin >> n >> s;
		int ans = n - 1;
		for (int i = 0; i < n; i++)
		{
			if (s[i] == '>')
				ans = min(ans, i);
			if (s[i] == '<')
				ans = min(ans, n - i - 1);
		}
		cout << ans << "\n";
	}
}