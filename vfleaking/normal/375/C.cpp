#include <iostream>
#include <cstdio>
using namespace std;

const int NDir = 4;
const int DirX[] = {-1,  0,  0,  1};
const int DirY[] = { 0, -1,  1,  0};

const int MaxN = 20;
const int MaxM = 20;
const int MaxNT = 8;

template <class T>
inline void relax(T &a, const T &b)
{
	if (b > a)
		a = b;
}

struct item
{
	int x, y, status;
};

int main()
{
	int n, m;
	static char a[MaxN + 1][MaxM + 1];

	int sx, sy;
	int t_n = 0;
	static int tx[MaxNT + 1], ty[MaxNT + 1];
	static int tVal[MaxNT + 1];

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 'S')
			{
				sx = i, sy = j;
				a[i][j] = '.';
			}
			else if ('0' <= a[i][j] && a[i][j] <= '9')
				t_n++;
		}
	for (int i = 1; i <= t_n; i++)
		cin >> tVal[i];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (a[i][j] == 'B')
			{
				t_n++;
				tVal[t_n] = -1000000;
				a[i][j] = '0' + t_n;
			}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if ('0' <= a[i][j] && a[i][j] <= '9')
			{
				int idx = a[i][j] - '0';
				tx[idx] = i, ty[idx] = j;
			}

	static int dist[MaxN + 1][MaxM + 1][1 << MaxNT];
	for (int x = 1; x <= n; x++)
		for (int y = 1; y <= m; y++)
			for (int status = 0; status < (1 << t_n); status++)
				dist[x][y][status] = -1;

	item st;

	int top, bot;
	static item q[MaxN * MaxM * (1 << MaxNT)];

	top = bot = 0;
	st.x = sx, st.y = sy, st.status = 0, dist[st.x][st.y][st.status] = 0, q[bot++] = st;
	while (top != bot)
	{
		item v = q[top++];

		for (int dir = 0; dir < NDir; dir++)
		{
			item u;
			u.x = v.x + DirX[dir], u.y = v.y + DirY[dir], u.status = v.status;
			if (1 > u.x || u.x > n)
				continue;
			if (1 > u.y || u.y > m)
				continue;
			if (a[u.x][u.y] != '.')
				continue;
			if (v.x != u.x)
			{
				for (int i = 0; i < t_n; i++)
					if (ty[i + 1] < v.y && tx[i + 1] == min(v.x, u.x))
						u.status ^= 1 << i;
			}
			
			if (dist[u.x][u.y][u.status] == -1)
				dist[u.x][u.y][u.status] = dist[v.x][v.y][v.status] + 1, q[bot++] = u;
		}
	}

	int res = 0;
	for (int status = 0; status < (1 << t_n); status++)
		if (dist[sx][sy][status] != -1)
		{
			int cur = -dist[sx][sy][status];
			for (int i = 0; i < t_n; i++)
				if (status >> i & 1)
					cur += tVal[i + 1];
			relax(res, cur);
		}
	cout << res << endl;

	return 0;
}