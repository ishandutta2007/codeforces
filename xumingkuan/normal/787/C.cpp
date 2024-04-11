#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 7070, Win = 1, Lose = 2;
int n, k[2], s[2][MAXN];
int f[2][MAXN];
int num[2][MAXN];
void update(int x, int y, int v)
{
//	printf("update %d %d %s\n", x, y, v == Win ? "Win" : "Lose");
	if(f[x][y])
		return;
	f[x][y] = v;
	if(v == Lose)
	{
		for(int i = 1; i <= k[!x]; i++)
			update(!x, (y + s[!x][i]) % n, Win);
	}
	else
	{
		for(int i = 1; i <= k[!x]; i++)
			if(!--num[!x][(y + s[!x][i]) % n])
				update(!x, (y + s[!x][i]) % n, Lose);
	}
}
int main()
{
	scanf("%d", &n);
	for(int i = 0; i <= 1; i++)
	{
		scanf("%d", &k[i]);
		for(int j = 1; j <= k[i]; j++)
			scanf("%d", &s[i][j]);
		for(int j = 0; j < n; j++)
			num[i][j] = k[i];
	}
	memset(f, 0, sizeof(f));
	f[0][0] = f[1][0] = Lose;
//	update(0, 0, Lose);
//	update(1, 0, Lose);
	for(int x = 0; x <= 1; x++)
		for(int i = 1; i <= k[x]; i++)
			update(x, s[x][i], Win);
	for(int i = 0; i <= 1; i++)
	{
		for(int j = n - 1; j >= 1; j--)
			if(f[i][j] == Win)
				printf("Win ");
			else if(f[i][j] == Lose)
				printf("Lose ");
			else
				printf("Loop ");
		printf("\n");
	}
	return 0;
}