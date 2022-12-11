#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <sstream>
#include <fstream>
#include <functional>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

const int N = 120;
char table[4][N];
int dp[4][N];

int n = 3, m, k;

void read()
{
	scanf("%d%d", &m, &k);
	for (int i = 0; i < 3; i++)
		scanf(" %s", table[i]);
}

bool check(int x, int y)
{
	if (x < 0 || x >= 3)
		return false;
	if (y >= m)
		return true;
	return table[x][y] == '.' || table[x][y] == 's';
}

bool solve()
{
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < 3; i++)
		if (table[i][0] == 's')
			dp[i][0] = 1;

	for (int s = 0; s < m; s++)
		for (int i = 0; i < 3; i++)
		{
			if (!dp[i][s])
				continue;
			if (check(i, s + 1))
			{
				for (int d = -1; d <= 1; d++)
				{
					int ni = i + d;
					if (check(ni, s + 1) && check(ni, s + 2) && check(ni, s + 3))
						dp[ni][s + 3] = 1;
				}
			}
		}
	for (int i = 0; i < 3; i++)
		for (int s = m; s < m + 5; s++)
			if (dp[i][s])
				return true;
	return false;
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		read();
		printf("%s\n", solve() ? "YES" : "NO");
	}
	return 0;
}