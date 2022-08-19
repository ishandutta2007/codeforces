#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int INF = (int)2e9 + 3;

char s[5][5];
int d[5][5];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			s[i][j] = '.';
			d[i][j] = INF;
		}
	int n;
	int X, Y;
	scanf("%d%d%d", &n, &X, &Y);
	while(n--)
	{
		char c;
		int x, y;
		scanf(" %c %d%d", &c, &x, &y);
		x -= X;
		y -= Y;
		if (x != 0 && y != 0 && abs(x) != abs(y)) continue;
		int l = max(abs(x), abs(y));
		if (x != 0) x /= abs(x);
		if (y != 0) y /= abs(y);
		x++;y++;
		if (l < d[x][y])
		{
			d[x][y] = l;
			s[x][y] = c;
		}
	}
	for (int x = -1; x <= 1; x++)
		for (int y = -1; y <= 1; y++)
		{
			if (s[x + 1][y + 1] == '.') continue;
			if (s[x + 1][y + 1] == 'Q')
			{
				printf("YES\n");
				return 0;
			}
			if ((s[x + 1][y + 1] == 'R') ^ (x != 0 && y != 0))
			{
				printf("YES\n");
				return 0;
			}
		}
	printf("NO\n");


	return 0;
}