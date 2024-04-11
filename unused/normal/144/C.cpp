#include <bits/stdc++.h>
using namespace std;

char s1[100005], s2[100005];
int cnt[256];
int len;

int main()
{
	scanf("%s%s", s1, s2);

	int overflow = 0;
	int ans = 0;

	for (len = 0; s2[len]; len++)
	{
		cnt[s2[len]]++;
	}

	for (int i = 0; i < len; i++)
	{
		if (s1[i] == '?') continue;
		if (--cnt[s1[i]] == -1) ++overflow;
	}

	for (int i = len;; i++)
	{
		// check
		if (overflow == 0) ++ans;

		if (s1[i - len] != '?' && ++cnt[s1[i - len]] == 0) --overflow;
		if (!s1[i]) break;
		if (s1[i] == '?') continue;
		if (--cnt[s1[i]] == -1) ++overflow;
	}

	printf("%d\n", ans);
}