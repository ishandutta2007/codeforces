#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;
string str;
int cnt[Maxn], maxi, pos, Ans[Maxn];
int main()
{
	cin >> str;
	int siz = str.size();
	for (int i = 0; i < siz; i++)
		if (str[i] == ')') cnt[i] = 1;
	for (int i = siz - 1; i >= 0; i--)
		cnt[i] += cnt[i + 1];
	int now = 0;
	for (int i = 0; i < siz; i++)
	{
		if (str[i] == '(') now++;
		if (min(now, cnt[i + 1]) > maxi) maxi = min(now, cnt[i + 1]), pos = i;
	}
	if (!maxi)
	{
		puts("0");
		return 0;
	}
	else
	{
		printf("1\n%d\n", maxi * 2);
		int tmp = 0;
		for (int i = 0; i <= pos; i++)
		{
			if (str[i] == '(') tmp++, printf("%d ", i + 1);
			if (tmp == maxi) break;
		}
		tmp = 0;
		for (int i = siz; i > pos; i--)
		{
			if (str[i] == ')') Ans[++tmp] = i + 1;
			if (tmp == maxi) break;
		}
		for (int i = maxi; i >= 1; i--)
			printf("%d ", Ans[i]);
	}
	return 0;
}