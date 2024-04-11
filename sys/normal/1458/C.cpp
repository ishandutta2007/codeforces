#include <bits/stdc++.h>
using namespace std;
 
const int Maxn = 1005;
int T, n, m, a[Maxn][Maxn], b[Maxn][Maxn];
string str;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf("%d", &a[i][j]), a[i][j]--;
		cin >> str;
		int x = 0, y = 0, z = 0, * X, * Y, * Z;
		X = &x, Y = &y, Z = &z;
		for (int i = 0; i < m; i++)
		{
			if (str[i] == 'R') (*Y)++;
			if (str[i] == 'L') (*Y)--;
			if (str[i] == 'D') (*X)++;
			if (str[i] == 'U') (*X)--;
			if (str[i] == 'I') swap(Y, Z);
			if (str[i] == 'C') swap(X, Z);
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				int resx = ((i + x) % n + n) % n, resy = ((j + y) % n + n) % n, resz = ((a[i][j] + z) % n + n) % n;
				if ((X == &x) && (Y == &y) && (Z == &z)) b[resx][resy] = resz;
				if ((X == &x) && (Y == &z) && (Z == &y)) b[resx][resz] = resy;
				if ((X == &y) && (Y == &x) && (Z == &z)) b[resy][resx] = resz;
				if ((X == &y) && (Y == &z) && (Z == &x)) b[resy][resz] = resx;
				if ((X == &z) && (Y == &x) && (Z == &y)) b[resz][resx] = resy;
				if ((X == &z) && (Y == &y) && (Z == &x)) b[resz][resy] = resx;
			}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				printf("%d ", b[i][j] + 1);
			puts("");
		}
		puts("");
	}
	return 0;
}