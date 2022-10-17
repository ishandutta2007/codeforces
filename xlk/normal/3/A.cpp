#include <bits/stdc++.h>
using namespace std;
char s[3], e[3];
int d[9][9];
int px[9][9];
int py[9][9];
int pd[9][9];
int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
string ds[] = {"R", "RU", "U", "LU", "L", "LD", "D", "RD"};
queue<pair<int, int> > q;
bool in(int x, int y)
{
	return 0 <= x && x < 8 && 0 <= y && y < 8;
}
void print(int x, int y)
{
	if (d[x][y] == 0)
	{
		return;
	}
	print(px[x][y], py[x][y]);
	cout << ds[pd[x][y]] << endl;
	return;
}
int main()
{
	scanf("%s%s", s, e);
	memset(d, -1, sizeof d);
	d[s[0] - 'a'][s[1] - '1'] = 0;
	q.push(make_pair(s[0] - 'a', s[1] - '1'));
	while (q.size() > 0)
	{
		pair<int, int> u = q.front();
		q.pop();
		for (int i = 0; i < 8; i++)
		{
			int nx = u.first + dx[i];
			int ny = u.second + dy[i];
			if (in(nx, ny))
			{
				if (d[nx][ny] == -1)
				{
					d[nx][ny] = d[u.first][u.second] + 1;
					px[nx][ny] = u.first;
					py[nx][ny] = u.second;
					pd[nx][ny] = i;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	printf("%d\n", d[e[0] - 'a'][e[1] - '1']);
	print(e[0] - 'a', e[1] - '1');
	return 0;
}