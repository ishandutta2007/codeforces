#include <bits/stdc++.h>
using namespace std;

int T, n;
char ch[205];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%s", &n, ch);
		sort(ch, ch + n);
		printf("%s\n", ch);
	}
	return 0;
}