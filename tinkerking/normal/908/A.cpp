#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

char s[1010];

bool check(char c)
{
	if (c >= 'a' && c <= 'z')
	{
		return ((c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'));
	}
	return ((c - '0') % 2 == 1);
}

int main()
{
	scanf("%s",s);
	int len = strlen(s);
	int ans = 0;
	for (int i=0;i<len;i++)
	ans += (check(s[i]));
	printf("%d\n",ans);
}