#include <bits/stdc++.h>
using namespace std;
int n, k;
char s[2][100020];
int d[2][100020];
queue<pair<int, int> > q;
int main()
{
	scanf("%d%d%s%s", &n, &k, s[0], s[1]);
	memset(d, -1, sizeof d);
	d[0][0] = 0;
	q.push(make_pair(0, 0));
	while (q.size() > 0)
	{
		pair<int, int> u = q.front();
		if (u.second + k >= n)
		{
			break;
		}
		q.pop();
		if (u.second > 0 && s[u.first][u.second - 1] == '-')
		{
			if (d[u.first][u.second - 1] == -1 && d[u.first][u.second] + 1 <= u.second - 1)
			{
				d[u.first][u.second - 1] = d[u.first][u.second] + 1;
				q.push(make_pair(u.first, u.second - 1));
			}
		}
		if (s[u.first][u.second + 1] == '-')
		{
			if (d[u.first][u.second + 1] == -1)
			{
				d[u.first][u.second + 1] = d[u.first][u.second] + 1;
				q.push(make_pair(u.first, u.second + 1));
			}
		}
		if (s[u.first ^ 1][u.second + k] == '-')
		{
			if (d[u.first ^ 1][u.second + k] == -1)
			{
				d[u.first ^ 1][u.second + k] = d[u.first][u.second] + 1;
				q.push(make_pair(u.first ^ 1, u.second + k));
			}
		}
	}
	puts(q.size() ? "YES" : "NO");
	return 0;
}