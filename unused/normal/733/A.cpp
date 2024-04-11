#include <stdio.h>
#include <algorithm>
#include <string.h>

char ch[1005];

int main()
{
	ch[0] = 'A';
	scanf("%s", ch + 1);
	int len = strlen(ch);
	ch[len++] = 'A';
	int last = 0;
	int ans = 0;
	for (int i = 1; i < len; i++)
	{
		if (ch[i] == 'A' || ch[i] == 'E' || ch[i] == 'O' || ch[i] == 'U' || ch[i] == 'I' ||
			ch[i] == 'Y')
		{
			ans = std::max(ans, i - last);
			last = i;
		}
	}
	printf("%d", ans);
}