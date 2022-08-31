#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

const int N = 105;
int a[N][N];
int ans;
string s;
int n, m;

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			a[i][j] = (s[j] == 'W' ? 1 : -1);
		}
	}
	ans = 0;
	for (int i = n - 1; i >= 0; i--)
		for (int j = m - 1; j >= 0; j--)
		{
			if (a[i][j] == 0) continue;
			ans++;
			for (int x = 0; x <= i; x++)
				for (int y = 0; y <= j; y++)
					a[x][y] -= a[i][j];
		}
	printf("%d\n", ans);

	return 0;
}