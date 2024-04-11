#include <bits/stdc++.h>
using namespace std;

int T, n, ans, cnt[30][30];
string s, t;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		ans = 0;
		memset(cnt, 0, sizeof(cnt));
		scanf("%d", &n);
		cin >> s >> t;
		for (int i = 0; i < n; i++)
		{
			if (s[i] > t[i])
			{
				puts("-1");
				goto END;
			}
			if (s[i] != t[i]) cnt[s[i] - 'a'][t[i] - 'a']++;
		}
		for (int i = 0; i < 20; i++)
			for (int j = i + 1; j < 20; j++)
				if (cnt[i][j])
				{
					ans++;
					for (int k = j + 1; k < 20; k++)
						if (cnt[i][k])
							cnt[j][k] += cnt[i][k], cnt[i][k] = 0;
				}
		printf("%d\n", ans);
		END:;		
	}
	return 0;
}