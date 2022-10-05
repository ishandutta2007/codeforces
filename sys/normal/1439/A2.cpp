#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;
int T, n, m, ct;
char ch[Maxn][Maxn];
struct tri
{
	pair <int, int> v1, v2, v3;
} ans[Maxn * Maxn];
void flip(char &c)
{
	c = ((c - '0') ^ 1) + '0';
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		ct = 0;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
			{
				ch[i][j] = getchar();
				while (ch[i][j] != '0' && ch[i][j] != '1') ch[i][j] = getchar();
			}
		for (int i = 1; i < n; i++)
			for (int j = 1; j <= m; j++)
			{
				if (i == n - 1 && j >= m - 1) break;
				if (ch[i][j] == '1')
				{
					if (j == 1) ans[++ct] = (tri){make_pair(i, j), make_pair(i + 1, j), make_pair(i + 1, j + 1)}, flip(ch[i][j]), flip(ch[i + 1][j]), flip(ch[i + 1][j + 1]);
					else ans[++ct] = (tri){make_pair(i, j), make_pair(i + 1, j - 1), make_pair(i + 1, j)}, flip(ch[i][j]), flip(ch[i + 1][j - 1]), flip(ch[i + 1][j]);
				}
			}
		for (int j = 1; j <= m - 2; j++)
			if (ch[n][j] == '1' && ch[n - 1][j] == '1') ans[++ct] = (tri){make_pair(n, j), make_pair(n - 1, j), make_pair(n, j + 1)}, flip(ch[n][j]), flip(ch[n - 1][j]), flip(ch[n][j + 1]);
			else if (ch[n][j] == '1') ans[++ct] = (tri){make_pair(n, j), make_pair(n - 1, j + 1), make_pair(n, j + 1)}, flip(ch[n][j]), flip(ch[n - 1][j + 1]), flip(ch[n][j + 1]);
			else if (ch[n - 1][j] == '1') ans[++ct] = (tri){make_pair(n - 1, j), make_pair(n - 1, j + 1), make_pair(n, j + 1)}, flip(ch[n - 1][j]), flip(ch[n - 1][j + 1]), flip(ch[n][j + 1]);
		int tmp = (ch[n - 1][m - 1] == '1') + (ch[n - 1][m] == '1') + (ch[n][m - 1] == '1') + (ch[n][m] == '1');
		if (tmp == 3)
		{
			int cnt = 0;
			pair <int, int> T[6];
			for (int i = n - 1; i <= n; i++)
				for (int j = m - 1; j <= m; j++)
					if (ch[i][j] == '1') T[++cnt] = make_pair(i, j);
			ans[++ct] = (tri){T[1], T[2], T[3]};
			flip(ch[T[1].first][T[1].second]);
			flip(ch[T[2].first][T[2].second]);
			flip(ch[T[3].first][T[3].second]); 
		}
		if (tmp == 4)
		{
			int cnt = 0;
			pair <int, int> T[6];
			for (int i = n - 1; i <= n; i++)
				for (int j = m - 1; j <= m; j++)
					if (ch[i][j] == '1') T[++cnt] = make_pair(i, j);
			ans[++ct] = (tri){T[1], T[2], T[3]};
			flip(ch[T[1].first][T[1].second]);
			flip(ch[T[2].first][T[2].second]);
			flip(ch[T[3].first][T[3].second]); 
			tmp = 1;
		}
		if (tmp == 1)
		{
			int cnt1 = 0, cnt2 = 0;
			pair <int, int> T[6], H[6];
			for (int i = n - 1; i <= n; i++)
				for (int j = m - 1; j <= m; j++)
					if (ch[i][j] == '1') T[++cnt1] = make_pair(i, j);
					else H[++cnt2] = make_pair(i, j);
			ans[++ct] = (tri){T[1], H[1], H[2]};
			flip(ch[T[1].first][T[1].second]);
			flip(ch[H[1].first][H[1].second]);
			flip(ch[H[2].first][H[2].second]); 
			tmp = 2;
		}
		if (tmp == 2)
		{
			int cnt1 = 0, cnt2 = 0;
			pair <int, int> T[6], H[6];
			for (int i = n - 1; i <= n; i++)
				for (int j = m - 1; j <= m; j++)
					if (ch[i][j] == '1') T[++cnt1] = make_pair(i, j);
					else H[++cnt2] = make_pair(i, j);
			ans[++ct] = (tri){T[1], H[1], H[2]};
			ans[++ct] = (tri){T[2], H[1], H[2]};
			flip(ch[T[1].first][T[1].second]);
			flip(ch[T[2].first][T[2].second]);
		}
		printf("%d\n", ct);
		for (int i = 1; i <= ct; i++)
			printf("%d %d %d %d %d %d\n", ans[i].v1.first, ans[i].v1.second, ans[i].v2.first, ans[i].v2.second, ans[i].v3.first, ans[i].v3.second);
	}
	return 0;
}