#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int MaxM = 400;
const int L = 100;
const int ML = L + 1 + L * 2 + 2;

const int ND = 4;
const int DX[] = {-1,  0, 0, 1};
const int DY[] = { 0, -1, 1, 0};

int main()
{
	int vx, vy, sx, sy;
	cin >> vx >> vy >> sx >> sy;

	int m;
	static pair<int, int> obs[MaxM];
	static bool a[ML + 1 + ML][ML + 1 + ML];
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		a[ML + x][ML + y] = true;
		obs[i] = make_pair(x, y);
	}

	if (m == 0)
	{
		printf("-1\n");
		return 0;
	}

	queue<int> curQ;
	while (make_pair(vx, vy) != make_pair(sx, sy))
	{
		if (vx == -L - 2)
		{
			while (!curQ.empty())
				curQ.pop();
			int p = 0;
			for (int i = 1; i < m; i++)
				if (obs[i].first > obs[p].first)
					p = i;
			while (vy != ML)
				putchar('U'), vy++, sy++;
			while (sx != obs[p].first + 1)
				putchar('R'), vx++, sx++;
			while (sy != obs[p].second)
				putchar('D'), vy--, sy--;
			while (vx != sx)
				putchar('L'), vx--;
			while (vy < -L - 1)
				putchar('U'), vy++, sy++;
			while (vy > L + 1)
				putchar('D'), vy--, sy--;
		}
		else if (vx == L + 2)
		{
			while (!curQ.empty())
				curQ.pop();
			int p = 0;
			for (int i = 1; i < m; i++)
				if (obs[i].first < obs[p].first)
					p = i;
			while (vy != ML)
				putchar('U'), vy++, sy++;
			while (sx != obs[p].first - 1)
				putchar('L'), vx--, sx--;
			while (sy != obs[p].second)
				putchar('D'), vy--, sy--;
			while (vx != sx)
				putchar('R'), vx++;
			while (vy < -L - 1)
				putchar('U'), vy++, sy++;
			while (vy > L + 1)
				putchar('D'), vy--, sy--;
		}
		else if (vy == -L - 2)
		{
			while (!curQ.empty())
				curQ.pop();
			int p = 0;
			for (int i = 1; i < m; i++)
				if (obs[i].second > obs[p].second)
					p = i;
			while (vx != ML)
				putchar('R'), vx++, sx++;
			while (sy != obs[p].second + 1)
				putchar('U'), vy++, sy++;
			while (sx != obs[p].first)
				putchar('L'), vx--, sx--;
			while (vy != sy)
				putchar('D'), vy--;
			while (vx < -L - 1)
				putchar('R'), vx++, sx++;
			while (vx > L + 1)
				putchar('L'), vx--, sx--;
		}
		else if (vy == L + 2)
		{
			while (!curQ.empty())
				curQ.pop();
			int p = 0;
			for (int i = 1; i < m; i++)
				if (obs[i].second < obs[p].second)
					p = i;
			while (vx != ML)
				putchar('R'), vx++, sx++;
			while (sy != obs[p].second - 1)
				putchar('D'), vy--, sy--;
			while (sx != obs[p].first)
				putchar('L'), vx--, sx--;
			while (vy != sy)
				putchar('U'), vy++;
			while (vx < -L - 1)
				putchar('R'), vx++, sx++;
			while (vx > L + 1)
				putchar('L'), vx--, sx--;
		}
		else
		{
			if (curQ.empty())
			{
				static int from[ML + 1 + ML][ML + 1 + ML];
				int q_n = 0;
				static pair<int, int> q[(ML + 1 + ML) * (ML + 1 + ML)];

				for (int x = -ML; x <= ML; x++)
					for (int y = -ML; y <= ML; y++)
						from[ML + x][ML + y] = -1;

				from[ML + sx][ML + sy] = 4, q[q_n++] = make_pair(sx, sy);
				bool found = false;
				for (int i = 0; i < q_n; i++)
				{
					pair<int, int> cur = q[i];
					for (int d = 0; d < ND; d++)
					{
						pair<int, int> next(cur.first + DX[d], cur.second + DY[d]);
						if (next.first < -ML || next.first > ML)
							continue;
						if (next.second < -ML || next.second > ML)
							continue;
						if (!a[ML + next.first][ML + next.second] && from[ML + next.first][ML + next.second] == -1)
						{
							from[ML + next.first][ML + next.second] = d, q[q_n++] = next;
							if (next == make_pair(vx, vy))
							{
								found = true;
								break;
							}
						}
					}
					if (found)
						break;
				}
				if (!found)
				{
					printf("-1\n");
					return 0;
				}

				int x = vx, y = vy;
				while (from[ML + x][ML + y] != 4)
				{
					int d = 3 - from[ML + x][ML + y];
					x += DX[d], y += DY[d];
					curQ.push(d);
				}
			}

			int d = curQ.front();
			curQ.pop();
			if (d == 0)
				putchar('L');
			else if (d == 1)
				putchar('D');
			else if (d == 2)
				putchar('U');
			else
				putchar('R');
			vx += DX[d], vy += DY[d];
			if (!a[ML + min(max(sx + DX[d], -L - 2), L + 2)][ML + min(max(sy + DY[d], -L - 2), L + 2)])
			{
				curQ.push(d);
				sx += DX[d], sy += DY[d];
			}
		}
	}

	return 0;
}