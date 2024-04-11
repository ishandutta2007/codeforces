#include <bits/stdc++.h>
using namespace std;

int n, T, sum;
char ch[505][505];
void print(int l1, int l2, int l3)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i % 3 == 1 && j % 3 == l1 && ch[i][j] == 'X') putchar('O');
			else if (i % 3 == 2 && j % 3 == l2 && ch[i][j] == 'X') putchar('O');
			else if (i % 3 == 0 && j % 3 == l3 && ch[i][j] == 'X') putchar('O');
			else putchar(ch[i][j]);
		}
		puts("");
	}
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		sum = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				ch[i][j] = getchar();
				while (ch[i][j] != 'X' && ch[i][j] != '.' && ch[i][j] != 'O') ch[i][j] = getchar();
				sum += ch[i][j] == 'X';
			}
		for (int l1 = 0; l1 <= 2; l1++)
			for (int l2 = 0; l2 <= 2; l2++)
				for (int l3 = 0; l3 <= 2; l3++)
					if (l1 != l2 && l2 != l3 && l1 != l3)
					{
						int tot = 0;
						for (int i = 1; i <= n; i++)
							for (int j = 1; j <= n; j++)
							{
								if (i % 3 == 1 && j % 3 == l1) tot += ch[i][j] == 'X';
								if (i % 3 == 2 && j % 3 == l2) tot += ch[i][j] == 'X';
								if (i % 3 == 0 && j % 3 == l3) tot += ch[i][j] == 'X';
							}
						if (tot <= sum / 3)
						{
							print(l1, l2, l3);
							goto END;
						}
					}
		END:;
	}
	return 0;
}