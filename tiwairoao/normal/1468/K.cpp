#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 5005
int n, A[N];
char S[N];
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s", S + 1);
		n = strlen(S + 1);
		for (int i = 1; i <= n; i++)
		{
			if (S[i] == 'U')A[i] = 0;
			if (S[i] == 'D')A[i] = 1;
			if (S[i] == 'R')A[i] = 2;
			if (S[i] == 'L')A[i] = 3;
		}
		int x = 0, y = 0, flg = 0;
		for (int i = 1; i <= n; i++)
		{
			x += dir[A[i]][0];
			y += dir[A[i]][1];
			if (!x && !y)
				continue;
			int p = 0, q = 0;
			for (int j = 1; j <= n; j++)
			{
				if (p + dir[A[j]][0] != x || q + dir[A[j]][1] != y)
				{
					p += dir[A[j]][0];
					q += dir[A[j]][1];
				}
			}
			if (!p && !q)
			{
				printf("%d %d\n", x, y);
				flg = 1;
				break;
			}
		}
		if (!flg)
			puts("0 0");
	}
}