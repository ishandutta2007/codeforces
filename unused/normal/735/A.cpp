#include <stdio.h>

char str[105];

int main()
{
	int n, k;
	scanf("%d%d%s", &n, &k, str);

	int start;
	for (start = 0; str[start] != 'G'; start++);
	for (int i = 0; start + i >= 0; i -= k)
	{
		if (str[start + i] == '#') break;
		if (str[start + i] == 'T')
		{
			printf("YES"); return 0;
		}
	}
	for (int i = 0; start + i < n; i += k)
	{
		if (str[start + i] == '#') break;
		if (str[start + i] == 'T')
		{
			printf("YES"); return 0;
		}
	}
	printf("NO");
}