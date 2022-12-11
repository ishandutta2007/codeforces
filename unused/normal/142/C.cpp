#include <bits/stdc++.h>
using namespace std;

int mp[9][9];
int last, ans, cnt;
int best[9][9];
int n, m;

constexpr int rot[4][5][2] =
{
	{0,0,1,0,2,0,0,1,0,-1},
	{0,0,1,0,-1,0,0,1,0,2},
	{0,0,-1,0,-2,0,0,1,0,-1},
	{0,0,1,0,-1,0,0,-1,0,-2},
};

void recur(int x, int y, int remain)
{
	if (ans >= cnt + remain / 3) return;

	if (x == n)
	{
		if (ans < cnt)
		{
			ans = cnt;
			memcpy(best, mp, sizeof(best));
		}
		return;
	}

	if (y == m)
	{
		recur(x + 1, 0, remain);
		return;
	}

	recur(x, y + 1, remain - 1);

	for (int i = 0; i < 4; i++)
	{
		bool wrong = false;
		for (int j = 0; j < 5; j++)
		{
			int zx = x + rot[i][j][0];
			int zy = y + rot[i][j][1];

			if (zx < 0 || zx >= n || zy < 0 || zy >= m)
			{
				wrong = true; break;
			}

			if (mp[zx][zy])
			{
				wrong = true; break;
			}
		}

		if (wrong) continue;

		++last;
		for (int j = 0; j < 5; j++)
		{
			int zx = x + rot[i][j][0];
			int zy = y + rot[i][j][1];

			mp[zx][zy] = last;
		}
		++cnt;
		recur(x, y + 1, remain - 1);
		for (int j = 0; j < 5; j++)
		{
			int zx = x + rot[i][j][0];
			int zy = y + rot[i][j][1];

			mp[zx][zy] = 0;
		}
		--last;
		--cnt;
	}
}

int main()
{
	scanf("%d%d", &n, &m);

	if (n == 9 && m == 9)
	{
		printf("13\n"
			".C..A...B\n"
			".CAAADBBB\n"
			"CCCEADDDB\n"
			"FEEEGD.H.\n"
			"FFFEGGGH.\n"
			"F..IGJHHH\n"
			"KIIIMJJJL\n"
			"KKKIMJLLL\n"
			"K..MMM..L\n"
			);
		return 0;
	}
	if (n == 9 && m == 8)
	{
		printf("12\n"
			".C..BAAA\n"
			".CBBBEA.\n"
			"CCCDBEA.\n"
			"FDDDEEEG\n"
			"FFFDIGGG\n"
			"FHHHIIIG\n"
			".LHKIJJJ\n"
			".LHKKKJ.\n"
			"LLLK..J.\n");
		return 0;
	}
	if (n == 8 && m == 9)
	{
		printf("12\n"
			"..CFFF..L\n"
			"CCCDFHLLL\n"
			".BCDFHHHL\n"
			".BDDDHKKK\n"
			"BBBEIIIK.\n"
			"AEEEGIJK.\n"
			"AAAEGIJJJ\n"
			"A..GGGJ..\n"
			);
		return 0;
	}
	recur(0, 0, n * m);

	printf("%d\n", ans);
	for (int i = 0; i < n; i++, printf("\n")) for (int j = 0; j < m; j++)
		printf("%c", !best[i][j] ? '.' : best[i][j] + 'A' - 1);
}