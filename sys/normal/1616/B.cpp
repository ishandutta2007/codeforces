#include <bits/stdc++.h>
using namespace std;

int T, n, cnt[105];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		string str, ans = "";
		scanf("%d", &n);
		cin >> str;
		ans += str[0];
		for (int i = 1; i <= n; i++)
		{
			if (i != n && str[i] <= str[i - 1]) ans += str[i];
			else
			{
				for (int j = i - 1; j >= 0; j--)
					ans += str[j];
				break;
			}
		}
		string tmp = "";
		tmp += str[0], tmp += str[0];
		if (tmp < ans)
			cout << tmp << endl;
		else cout << ans << endl;
	}
	return 0;
}