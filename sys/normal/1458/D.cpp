#include <bits/stdc++.h>
using namespace std;

const int Maxn = 500005;
int T, pool[2 * Maxn], * cnt = pool + Maxn;
string str;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		cin >> str;
		int siz = str.size(), now = 0;
		for (int i = 0; i < siz; i++)
		{
			if (str[i] == '1') now--;
			cnt[now]++;
			if (str[i] == '0') now++;
		}
		now = 0;
		for (int i = 0; i < siz; i++)
			if (cnt[now] && !(cnt[now] == 1 && cnt[now - 1])) putchar('0'), --cnt[now++];
			else putchar('1'), --cnt[--now];
		puts("");
	}
	return 0;
}