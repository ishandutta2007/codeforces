#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

int n;
string s;
int a[15][6];
int b[6];
int d[] = {2, 3, 5, 7};

void init()
{
	for (int x = 2; x < 10; x++)
	{
		for (int i = 0; i < 4; i++)
			a[x][i] = a[x - 1][i];
		int y = x;
		for (int i = 0; i < 4; i++)
		{
			while(y % d[i] == 0)
			{
				a[x][i]++;
				y /= d[i];
			}
		}
	}
	return;
}

void solve()
{
	for (int i = 3; i >= 0; i--)
	{
		while(b[i] > 0)
		{
			printf("%d", d[i]);
			for (int j = 0; j < 4; j++)
				b[j] -= a[d[i]][j];
		}
	}
	printf("\n");
	return;
}

int main()
{
	init();
	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		int x = (int)(s[i] - '0');
		for (int j = 0; j < 4; j++)
			b[j] += a[x][j];
	}
	solve();

	return 0;
}