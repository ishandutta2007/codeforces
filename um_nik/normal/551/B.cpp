#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;

const int N = 100100;
const int A = 26;
char s[3][N];
int a[3][A];
int x, y;
int b[A];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int i = 0; i < 3; i++)
	{
		scanf(" %s ", s[i]);
		int l = strlen(s[i]);
		for (int j = 0; j < l; j++)
			a[i][(int)(s[i][j] - 'a')]++;
	}
	x = y = -1;
	for (int c = 0; c < N; c++)
	{
		bool ok = true;
		for (int i = 0; i < A; i++)
		{
			b[i] = a[0][i] - a[1][i] * c;
			if (b[i] < 0)
			{
				ok = false;
				break;
			}
		}
		if (!ok) break;
		int p = N;
		for (int i = 0; i < A; i++)
			if (a[2][i] != 0)
				p = min(p, b[i] / a[2][i]);
		if (c + p > x + y)
		{
			x = c;
			y = p;
		}
	}
	for (int i = 0; i < A; i++)
	{
		int z = a[0][i] - x * a[1][i] - y * a[2][i];
		for (int j = 0; j < z; j++)
			printf("%c", (char)('a' + i));
	}
	for (int i = 0; i < x; i++)
		printf("%s", s[1]);
	for (int i = 0; i < y; i++)
		printf("%s", s[2]);
	printf("\n");

	return 0;
}