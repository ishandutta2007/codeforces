#include <bits/stdc++.h>
using namespace std;
int n, m;
int px[60], py[60];
int a[20][20];
int b[20][20];
char s[] = "CDHS";
char r[] = "KA23456789TJQ";
bool ok(int x, int y)
{
	set<int> r, s;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			r.insert(a[x + i][y + j] % 13);
			s.insert(a[x + i][y + j] / 13);
		}
	}
	return s.size() == 1 || r.size() == 9;
}
void gao()
{
	for (int j1 = 0; j1 < 52; j1++) // j1 -> ?
	{
		if (px[j1] != -1)
		{
			continue;
		}
		for (int j2 = 0; j2 < 52; j2++) // j2 -> ?
		{
			if (px[j2] != -1)
			{
				continue;
			}
			if (j1 == j2)
			{
				continue;
			}
			if (px[52] != -1)
			{
				a[px[52]][py[52]] = j1;
			}
			if (px[53] != -1)
			{
				a[px[53]][py[53]] = j2;
			}
			for (int i = 0; i + 2 < n; i++)
			{
				for (int j = 0; j + 2 < m; j++)
				{
					b[i][j] = ok(i, j);
				}
			}
			for (int i = 0; i + 2 < n; i++)
			{
				for (int j = 0; j + 2 < m; j++)
				{
					if (!b[i][j])
					{
						continue;
					}
					for (int k = 0; k + 2 < n; k++)
					{
						for (int l = 0; l + 2 < m; l++)
						{
							if (!b[k][l])
							{
								continue;
							}
							if (abs(i - k) < 3 && abs(j - l) < 3)
							{
								
							}
							else
							{
								printf("Solution exists.\n");
								if (px[52] == -1 && px[53] == -1)
								{
									printf("There are no jokers.\n");
								}
								else if (px[52] == -1 && px[53] != -1)
								{
									printf("Replace J2 with %c%c.\n", r[j2 % 13], s[j2 / 13]);
								}
								else if (px[52] != -1 && px[53] == -1)
								{
									printf("Replace J1 with %c%c.\n", r[j1 % 13], s[j1 / 13]);
									
								}
								else
								{
									printf("Replace J1 with %c%c and J2 with %c%c.\n", r[j1 % 13], s[j1 / 13], r[j2 % 13], s[j2 / 13]);
								}
								printf("Put the first square to (%d, %d).\n", i + 1, j + 1);
								printf("Put the second square to (%d, %d).\n", k + 1, l + 1);
								return;
							}
						}
					}
				}
			}
		}
	}
	printf("No solution.\n");
}
int card(string s)
{
	if (s == "J1" || s == "J2")
	{
		return 52 + s[1] - '1';
	}
	int re = 0;
	if (s[0] == 'K')
	{
		re = 0;
	}
	else if (s[0] == 'A')
	{
		re = 1;
	}
	else if (s[0] == 'T')
	{
		re = 10;
	}
	else if (s[0] == 'J')
	{
		re = 11;
	}
	else if (s[0] == 'Q')
	{
		re = 12;
	}
	else
	{
		re = s[0] - '0';
	}
	if (s[1] == 'C')
	{
		re += 0;
	}
	else if (s[1] == 'D')
	{
		re += 13;
	}
	else if (s[1] == 'H')
	{
		re += 26;
	}
	else if (s[1] == 'S')
	{
		re += 39;
	}
	return re;
}
int main()
{
	cin >> n >> m;
	memset(px, -1, sizeof px);
	memset(py, -1, sizeof py);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			string s;
			cin >> s;
			a[i][j] = card(s);
			px[a[i][j]] = i;
			py[a[i][j]] = j;	
		}
	}
	gao();
	return 0;
}