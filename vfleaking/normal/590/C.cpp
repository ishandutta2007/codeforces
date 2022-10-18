#include <iostream>
#include <cstdio>
using namespace std;

const int INF = 100000000;

const int DX[] = {-1, 0, 0, 1};
const int DY[] = {0, -1, 1, 0};

const int MaxN = 1000;
const int MaxM = 1000;

template <class T>
inline void tense(T &a, const T &b)
{
	if (b < a)
		a = b;
}

int n, m;
char a[MaxN + 1][MaxM + 2];
int dist[4][MaxN + 1][MaxM + 1];

void calc_dist(int c)
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			dist[c][i][j] = a[i][j] == '0' + c ? 0 : INF;

	int q_n = 0;
	static pair<int, int> q[MaxN * MaxM];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (a[i][j] == '0' + c)
				q[q_n++] = make_pair(i, j);
	for (int i = 0; i < q_n; i++)
	{
		pair<int, int> v = q[i];
		for (int d = 0; d < 4; d++)
		{
			int ux = v.first + DX[d], uy = v.second + DY[d];
			if (1 <= ux && ux <= n && 1 <= uy && uy <= m && a[ux][uy] != '#' && dist[c][ux][uy] == INF)
			{
				dist[c][ux][uy] = dist[c][v.first][v.second] + 1;
				q[q_n++] = make_pair(ux, uy);
			}
		}
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%s", a[i] + 1);

	for (int c = 1; c <= 3; c++)
		calc_dist(c);

	int qd[4][4];
	for (int c = 1; c <= 3; c++)
		for (int d = 1; d <= 3; d++)
		{
			qd[c][d] = INF;
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= m; j++)
					if (a[i][j] == '0' + d)
						tense(qd[c][d], dist[c][i][j] - 1);
		}

	int res = INF;
	tense(res, qd[1][2] + qd[2][3]);
	tense(res, qd[1][3] + qd[2][3]);
	tense(res, qd[1][2] + qd[1][3]);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			tense(res, dist[1][i][j] - 1 + dist[2][i][j] - 1 + dist[3][i][j] - 1 + 1);

	if (res > INF / 2)
		res = -1;
	cout << res << endl;

	return 0;
}