#include <bits/stdc++.h>
using namespace std;

const int Maxn = 405;
int n, m, l, cnt, head[Maxn], col[Maxn];
bool flag;
string result, str, T, tmp_str1, tmp_str2;
struct edg
{
	int nxt, to;
} edge[2 * Maxn * Maxn];
void add(int x, int y)
{
	edge[++cnt] = (edg){head[x], y};
	head[x] = cnt;
}
void dfs(int u)
{
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (col[to >> 1] == -1)
		{
			col[to >> 1] = to & 1;
			dfs(to);
			if (!flag) return ;
		}
		else if (col[to >> 1] != (to & 1))
		{
			flag = false;
			return ;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin >> T >> n >> m;
	l = T.size();
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> tmp_str1 >> y >> tmp_str2;
		add(2 * (x - 1) + (tmp_str1[0] == 'V'), 2 * (y - 1) + (tmp_str2[0] == 'V'));
		add(2 * (y - 1) + (tmp_str2[0] == 'C'), 2 * (x - 1) + (tmp_str1[0] == 'C'));
	}
	cin >> str;
	for (int i = n - 1; i >= -1; i--)
	{
		result = "";
		flag = true;
		bool done = false;
		memset(col, -1, sizeof(int[n]));
		for (int j = 0; j <= i; j++)
		{
			if (col[j] != -1 && col[j] != (T[str[j] - 'a'] == 'V'))
				goto END;
			col[j] = (T[str[j] - 'a'] == 'V');
			dfs(2 * j + col[j]);
			if (!flag) goto END;
			result += str[j];
		}
		if (i + 1 < n)
		{
			for (int j = str[i + 1] - 'a' + 1; j < l; j++)
			{
				for (int k = i + 2; k < n; k++) col[k] = -1;
				col[i + 1] = (T[j] == 'V');
				flag = true;
				dfs(2 * (i + 1) + col[i + 1]);
				if (flag)
				{
					result += j + 'a';
					done = true;
					break;
				}
			}
			if (!done) goto END;
		}
		for (int j = i + 2; j < n; j++)
		{
			done = false;
			for (int k = 0; k < l; k++)
			{
				for (int q = j + 1; q < n; q++) col[q] = -1;
				col[j] = (T[k] == 'V');
				flag = true;
				dfs(2 * j + col[j]);
				if (flag)
				{
					result += k + 'a';
					done = true;
					break;
				}
			}
			if (!done) goto END;
		}
		cout << result << endl;
		return 0;
		END:;
	}
	cout << -1 << endl;
	return 0;
}