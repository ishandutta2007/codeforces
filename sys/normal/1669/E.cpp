#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int T, n, cnt1[27], cnt2[27], cnt[27 * 27];
string str;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		long long ans = 0;
		memset(cnt1, 0, sizeof(cnt1)), memset(cnt2, 0, sizeof(cnt2)), memset(cnt, 0, sizeof(cnt));
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			string str;
			cin >> str;
			cnt1[str[0] - 'a']++, cnt2[str[1] - 'a']++, cnt[(str[0] - 'a') * 26 + (str[1] - 'a')]++;
		}
		for (int i = 0; i < 26; i++)
		{
			ans += cnt1[i] * (cnt1[i] - 1LL) / 2 + cnt2[i] * (cnt2[i] - 1LL) / 2;
			for (int j = 0; j < 26; j++)
				ans -= cnt[i * 26 + j] * (cnt[i * 26 + j] - 1LL);
		}
		printf("%lld\n", ans);
	}
	return 0;
}