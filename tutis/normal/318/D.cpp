/*input
6 5
0 -2
0 -1
0 0
0 1
0 2
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int M[5000][5000];
bool G[5000][5000];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, t;
	cin >> n >> t;
	queue<pair<int, int>>Q;
	M[2500][2500] = n;
	Q.push({2500, 2500});
	G[2500][2500] = true;
	int dx[4] = {0, 0, 1, -1};
	int dy[4] = {1, -1, 0, 0};
	while (!Q.empty())
	{
		int x = Q.front().first;
		int y = Q.front().second;
		//cout << x << " " << y << " " << M[x][y] << endl;
		Q.pop();
		G[x][y] = false;
		int k = M[x][y] / 4;
		M[x][y] -= 4 * k;
		for (int t = 0; t < 4; t++)
		{
			M[x + dx[t]][y + dy[t]] += k;
			if (M[x + dx[t]][y + dy[t]] >= 4 && G[x + dx[t]][y + dy[t]] == false)
			{
				G[x + dx[t]][y + dy[t]] = true;
				Q.push({x + dx[t], y + dy[t]});
			}
		}
	}
	while (t--)
	{
		int x, y;
		cin >> x >> y;
		x += 2500;
		y += 2500;
		if (0 <= x && x < 5000)
		{
			if (0 <= y && y < 5000)
			{
				cout << M[x][y] << "\n";
			}
			else
				cout << "0\n";
		}
		else
			cout << "0\n";
	}
}