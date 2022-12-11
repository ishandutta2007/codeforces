#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	int ans = 1;
	int x = 0, y = 0;
	for (int i = 0; i < n; i++)
	{
		char ch;
		scanf(" %c", &ch);
		int xx = 0, yy = 0;
		if (ch == 'R') xx++;
		if (ch == 'L') xx--;
		if (ch == 'U') yy++;
		if (ch == 'D') yy--;

		if ((xx && x && x != xx) ||
			(yy && y && y != yy))
		{
			ans++;
			x = 0; y = 0;
		}

		if (xx) x = xx;
		if (yy) y = yy;
	}
	printf("%d", ans);
}