#include <stdio.h>
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	bool bw = true;
	for (;;)
	{
		char ch;
		if (scanf(" %c", &ch) != 1) break;
		if (ch != 'W'&&ch != 'B'&&ch != 'G') bw = false;
	}
	if (!bw)printf("#Color");
	else printf("#Black&White");
}