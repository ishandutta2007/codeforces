#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = 105;
char a[N][N];
int n;
int ans;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf(" %s ", a[i]);
	ans = 0;
	for (int x = 0; x < n; x++)
		for (int y1 = 0; y1 < n; y1++)
			for (int y2 = y1 + 1; y2 < n; y2++)
				if (a[x][y1] == 'C' && a[x][y2] == 'C')
					ans++;
	for (int x = 0; x < n; x++)
		for (int y1 = 0; y1 < n; y1++)
			for (int y2 = y1 + 1; y2 < n; y2++)
				if (a[y1][x] == 'C' && a[y2][x] == 'C')
					ans++;
	printf("%d\n", ans);


	return 0;
}