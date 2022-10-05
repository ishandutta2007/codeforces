#include <bits/stdc++.h>
using namespace std;


int T, n, cnt[27];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		memset(cnt, 0, sizeof(cnt));
		string str;
		cin >> str;
		for (int i = 0; i < (int) str.size(); i++)
			cnt[str[i] - 'a']++;
		for (int i = 0; i < (int) str.size(); i++)
			if (!(--cnt[str[i] - 'a']))
			{
				for (int j = i; j < (int) str.size(); j++) putchar(str[j]);
				break;
			}
		puts("");
	}
}