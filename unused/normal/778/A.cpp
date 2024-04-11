#include <bits/stdc++.h>
using namespace std;

char s1[200005], s2[200005];
constexpr int MOD = 1000000007;

int len;
int perm[200005];
bool del[200005];

bool check(int t)
{
	memset(del, 0, len);
	for (int i = 0; i < t; i++)
	{
		del[perm[i]] = true;
	}
	for (int i = 0, j = 0; s2[j]; j++)
	{
		while (i < len)
		{
			if (del[i] || s1[i] != s2[j])
			{
				i++;
				continue;
			}
			break;
		}
		if (i == len) return false;
		++i;
	}
	return true;
}

int main()
{
	scanf("%s%s", s1, s2);
	len = strlen(s1);
	for (int i = 0; i < len; i++)
	{
		scanf("%d", &perm[i]);
		perm[i]--;
	}

	int lo = 0, hi = len, ans = -1;
	while (lo <= hi)
	{
		int mid = (lo + hi) / 2;
		if (check(mid))
		{
			ans = mid;
			lo = mid + 1;
		}
		else
		{
			hi = mid - 1;
		}
	}
	printf("%d\n", ans);
}