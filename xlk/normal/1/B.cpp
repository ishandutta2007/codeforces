#include <bits/stdc++.h>
using namespace std;
void F(int x)
{
	if (x > 0)
	{
		F((x - 1) / 26);
		putchar((x - 1) % 26 + 'A');
	}
}
int t, x, y;
char s[66], c[66];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%s", s);
		if (sscanf(s, "R%dC%d", &x, &y) == 2)
		{
			F(y);
			printf("%d\n", x);
		}
		else if (sscanf(s, "%[A-Z]%d", c, &x) == 2)
		{
			y = 0;
			for (int i = 0; c[i]; i++)
			{
				y = y * 26 + c[i] - 'A' + 1;
			}
			printf("R%dC%d\n", x, y);
		}
	}
	return 0;
}