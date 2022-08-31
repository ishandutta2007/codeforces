#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;

const int N = 105;
int a[N];
string s;
bool g[N][N];
int ans[N];
int m;
int n;

int check()
{
	for (int i = 0; i < n; i++)
		if (a[i] == 0)
			return i;
	return -1;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int j = 0; j < n; j++)
			g[i][j] = (s[j] == '1');
	}
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int x;
	while(true)
	{
		x = check();
		if (x == -1) break;
		ans[m++] = x + 1;
		for (int i = 0; i < n; i++)
			if (g[x][i])
				a[i]--;
	}
	printf("%d\n", m);
	for (int i = 0; i < m; i++)
		printf("%d ", ans[i]);
	printf("\n");

	return 0;
}