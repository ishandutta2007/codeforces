#include<bits/stdc++.h>
using namespace std;
const int N = 160;

int n;
char s1[N][N], s[N][N], ans[N][N];
bool flag[N][N];
vector <pair <int, int> > v, v1;

bool out (int x, int y)
{
	return x < 0 || y < 0 || x >= 3 * n - 2|| y >= 3 * n - 2;
}

bool in (int x, int y)
{
	return x >= 0 && y >= 0 && x < 2 * n - 1 && y < 2 * n - 1;
}

bool check (int x, int y)
{
	return s[x][y] == 'x' || s[x][y] == 'o';
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%s", s1[i]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (s1[i][j] == 'o')
				v.push_back({i, j});
	pair <int, int> a = v[0];
	a.first += n - 1;
	a.second += n - 1;
	for (int i = v.size() - 1; i >= 0; i--)
	{
		v[i].first -= v[0].first;
		v[i].second -= v[0].second;
	}
	for (int i = 0; i < 3 * n - 2; i++)
		for (int j = 0; j < 3 * n - 2; j++)
			s[i][j] = 'x';
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			s[i + n - 1][j + n - 1] = s1[i][j];
	for (int i = 0; i < 3 * n - 2; i++)
		for (int j = 0; j < 3 * n - 2; j++)
		{
			int cnt = 0;
			for (int k = 0; k < v.size(); k++)
			{
				if (out(v[k].first + i, v[k].second + j) || !check(v[k].first + i, v[k].second + j))
					break;
				cnt++;
			}
			if (cnt == v.size())
			{
				v1.push_back({i - a.first, j - a.second});
				for (int k = 0; k < v.size(); k++)
					if (!out(v[k].first + i, v[k].second + j))
						flag[v[k].first + i][v[k].second + j] = true;
			}
		}
	for (int i = n - 1; i < 2 * n - 1; i++)
		for (int j = n - 1; j < 2 * n - 1; j++)
			if (s[i][j] == 'x' && !flag[i][j])
				return printf("NO\n"), 0;
	for (int i = 0; i < 2 * n - 1; i++)
		for (int j = 0; j < 2 * n - 1; j++)
			ans[i][j] = '.';
	for (int i = 0; i < v1.size(); i++)
		if (in(v1[i].first + n - 1, v1[i].second + n - 1))
			ans[v1[i].first + n - 1][v1[i].second + n - 1] = 'x';
	ans[n - 1][n - 1] = 'o';
	printf("YES\n");
	for (int i = 0; i < 2 * n - 1; i++)
		printf("%s\n", ans[i]);
	return 0;
}