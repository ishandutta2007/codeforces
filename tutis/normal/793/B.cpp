#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);


	int N, M;
	cin >> N >> M;
	char A[N + 2][M + 2];
	int D[N + 2][M + 2][4];
	pair<int, int>Krypt[4];
	Krypt[0] = make_pair(0, 1);
	Krypt[1] = make_pair(0, -1);
	Krypt[2] = make_pair(1, 0);
	Krypt[3] = make_pair(-1, 0);
	int sX;
	int sY;
	int fX;
	int fY;
	for (int i = 0; i <= N + 1; i++)
	{
		for (int j = 0; j <= M + 1; j++)
		{
			A[i][j] = '*';
			D[i][j][0] = 3;
			D[i][j][1] = 3;
			D[i][j][2] = 3;
			D[i][j][3] = 3;
		}
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> A[i][j];
			if (A[i][j] == 'S')
			{
				sX = i;
				sY = j;
			}
			if (A[i][j] == 'T')
			{
				fX = i;
				fY = j;
			}
		}
	}
	D[sX][sY][0] = 0;
	D[sX][sY][1] = 0;
	D[sX][sY][2] = 0;
	D[sX][sY][3] = 0;
	queue<int>x;
	queue<int>y;
	queue<int>kr;
	{
		x.push(sX);
		x.push(sX);
		x.push(sX);
		x.push(sX);

		y.push(sY);
		y.push(sY);
		y.push(sY);
		y.push(sY);

		kr.push(0);
		kr.push(1);
		kr.push(2);
		kr.push(3);
	}
	while (!x.empty())
	{
		int a = x.front();
		int b = y.front();
		int c = kr.front();
		x.pop();
		y.pop();
		kr.pop();
		for (int i = 0; i < 4; i++)
		{
			int kaina = 1;
			if (c == i)
				kaina = 0;
			int aa = a + Krypt[i].first;
			int bb = b + Krypt[i].second;
			if (A[aa][bb] != '*' and D[a][b][c] + kaina < D[aa][bb][i])
			{
				D[aa][bb][i] = D[a][b][c] + kaina;
				x.push(aa);
				y.push(bb);
				kr.push(i);
			}
		}
	}
	int X = min(D[fX][fY][0], min(D[fX][fY][1], min(D[fX][fY][2], D[fX][fY][3])));
	if (X < 3)
	{
		cout << "YES\n";
	}
	else
		cout << "NO\n";
	return 0;
}