#include <bits/stdc++.h>
using namespace std;
const int Maxn = 105;
int cnt, T, n, m, k, val[Maxn], bel[Maxn][Maxn];
string str[Maxn];
char ch[100];
int main()
{
	for (int i = 1; i <= 26; i++)
		ch[i] = 'A' + i - 1;
	for (int i = 27; i <= 52; i++)
		ch[i] = 'a' + i - 27;
	for (int i = 53; i <= 62; i++)
		ch[i] = '0' + i - 53;
	scanf("%d", &T);
	while (T--)
	{
		cnt = 0;
		scanf("%d%d%d", &n, &m, &k);
		for (int i = 1; i <= n; i++)
			cin >> str[i];
		for (int i = 1; i <= n; i++)
			for (int j = 0; j < m; j++)
				if (str[i][j] == 'R') cnt++;
		int per = cnt / k, Left = cnt % k;
		for (int i = 1; i <= Left; i++)
			val[i] = per + 1;
		for (int i = Left + 1; i <= k; i++)
			val[i] = per;
		int now = 1;
		for (int i = 1; i <= n; i++)
			if (i & 1)
				for (int j = 0; j < m; j++)
				{
					bel[i][j] = ch[now];
					if (str[i][j] == 'R')
					{
						val[now]--;
						if (now != k && val[now] == 0) now++;
					}
				}
			else
				for (int j = m - 1; j >= 0; j--)
				{
					bel[i][j] = ch[now];
					if (str[i][j] == 'R')
					{
						val[now]--;
						if (now != k && val[now] == 0) now++;
					}
				}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < m; j++)
				printf("%c", bel[i][j]);
			printf("\n");
		}
	}
	return 0;
}