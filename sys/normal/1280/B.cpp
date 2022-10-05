#include <bits/stdc++.h>
using namespace std;

const int Maxn = 65;
int T, n, m;
string str[Maxn];
bool vis1[Maxn], vis2[Maxn], tag;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		tag = true;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
			vis1[i] = true;
		for (int i = 0; i < m; i++)
			vis2[i] = true;
		for (int i = 1; i <= n; i++)
			cin >> str[i];
		for (int i = 1; i <= n; i++)
			for (int j = 0; j < m; j++)
				if (str[i][j] == 'P') vis1[i] = false, vis2[j] = false, tag = false;
		if (tag)
		{
			puts("0");
			goto END;
		}
		if (vis1[1] || vis1[n] || vis2[0] || vis2[m - 1])
		{
			puts("1");
			goto END;
		}
		for (int i = 2; i <= n - 1; i++)
			if (vis1[i])
			{
				puts("2");
				goto END;
			}
		for (int i = 1; i < m - 1; i++)
			if (vis2[i])
			{
				puts("2");
				goto END;
			}
		if (str[1][0] == 'A' || str[1][m - 1] == 'A' || str[n][0] == 'A' || str[n][m - 1] == 'A')
		{
			puts("2");
			continue;
		}
		for (int i = 2; i <= n - 1; i++)
			if (str[i][0] == 'A' || str[i][m - 1] == 'A')
			{
				puts("3");
				goto END;
			}
		for (int i = 1; i < m - 1; i++)
		{
			if (str[1][i] == 'A' || str[n][i] == 'A')
			{
				puts("3");
				goto END;
			}
		}
		for (int i = 1; i <= n; i++)
			for (int j = 0; j < m; j++)
				if (str[i][j] == 'A')
				{
					puts("4");
					goto END;
				}
		puts("MORTAL");
		END:;
	}
	return 0;
}