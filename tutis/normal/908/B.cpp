/***
6 6
......
......
..SE..
......
......
......
01232123212302123021
***/
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
int n, m;
char X[100][100];
bool ok(pair<int, int>x)
{
	if (X[x.first][x.second] == '#')
		return false;
	return true;
}
pair<int, int> operator+(pair<int, int>a, pair<int, int>b)
{
	return make_pair(a.first + b.first, a.second + b.second);
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			X[i][j] = '#';
		}
	}
	pair<int, int>beg;
	pair<int, int>end;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> X[i][j];
			if (X[i][j] == 'S')
				beg = make_pair(i, j);
			if (X[i][j] == 'E')
				end = make_pair(i, j);
		}
	}
	string s;
	cin >> s;
	vector<pair<int, int>>A = {make_pair(0, 1), make_pair(1, 0), make_pair(0, -1), make_pair(-1, 0)};
	map<char, pair<int, int>>B;
	int ans = 0;
	for (pair<int, int>a : A)
	{
		for (pair<int, int>b : A)
		{
			for (pair<int, int>c : A)
			{
				for (pair<int, int>d : A)
				{
					B['0'] = a;
					B['1'] = b;
					B['2'] = c;
					B['3'] = d;
					if (a == b)
						continue;
					if (a == c)
						continue;
					if (a == d)
						continue;
					if (b == c)
						continue;
					if (b == d)
						continue;
					if (c == d)
						continue;
					pair<int, int>co = beg;
					bool gerai = true;
					for (char x : s)
					{
						co = co + B[x];
						if (!ok(co))
							gerai = false;
						if (co == end && gerai)
						{
							ans++;
							break;
						}
					}
				}
			}
		}
	}
	cout << ans;
}