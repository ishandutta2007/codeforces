#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;
int T, ct, t[Maxn];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		string s;
		cin >> s;
		ct = 0;
		for (int i = 0; i < 10; i++)
			if (s[i] == '?') ct++;
		int maxi = 1 << ct, mini = 9;
		for (int i = 0; i < maxi; i++)
		{
			ct = 0;
			int cnt[2] = {0, 0}, times[2] = {5, 5};
			for (int j = 0; j < 10; j++)
			{
				if (s[j] == '?') t[j] = (i >> ct) & 1, ct++;
				else t[j] = s[j] - '0';
				if (t[j] == 1) cnt[j & 1]++;
				times[j & 1]--;
				if (cnt[j & 1] > cnt[(j & 1) ^ 1] + times[(j & 1) ^ 1] || cnt[(j & 1) ^ 1] > cnt[j & 1] + times[j & 1])
				{
					mini = min(mini, j);
					break;
				}
			}
		}
		printf("%d\n", mini + 1);
	}
	return 0;
}