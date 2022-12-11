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
#include <cassert>
#include <complex>
#include <valarray>
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

const int N = 200;
int a[N][N];
int row_sum[N];
int col_sum[N];

int row_add[N];
int col_add[N];
int n, m;

int best_result = -1;
int best_col[N];
int best_row[N];

bool check()
{
	for (int i = 0; i < n; i++)
		for (int s = 0; s < m; s++)
		{
			if (row_add[i] < 0 || col_add[s] < 0)
				return false;
			if (a[i][s] != row_add[i] + col_add[s])
				return false;
		}
	return true;
}

void relax()
{
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += row_add[i];
	for (int s = 0; s < m; s++)
		sum += col_add[s];
	if (best_result == -1 || sum < best_result)
	{
		best_result = sum;
		for (int i = 0; i < n; i++)
			best_row[i] = row_add[i];
		for (int i = 0; i < m; i++)
			best_col[i] = col_add[i];
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int s = 0; s < m; s++)
			scanf("%d", &a[i][s]);

	for (int i = 0; i < n; i++)
		for (int s = 0; s < m; s++)
		{
			row_sum[i] += a[i][s];
			col_sum[s] += a[i][s];
		}

	for (int i = 0; i <= 500; i++)
	{
		memset(row_add, 0, sizeof(row_add));
		memset(col_add, 0, sizeof(col_add));
		row_add[0] = i;
		bool ok = true;
		for (int s = 1; s < n; s++)
		{
			int delta = row_sum[s] - row_sum[s - 1];
			if (delta % m != 0)
				ok = false;
			row_add[s] = row_add[s - 1] + delta / m;
		}
		if (!ok)
			continue;
		for (int x = 0; x < n; x++)
			for (int y = 0; y < m; y++)
				col_add[y] = a[x][y] - row_add[x];
		if (check())
			relax();
	}
	if (best_result == -1)
		puts("-1");
	else
	{
		printf("%d\n", best_result);
		for (int i = 0; i < n; i++)
			for (int s = 0; s < best_row[i]; s++)
				printf("row %d\n", i + 1);
		for (int i = 0; i < m; i++)
			for (int s = 0; s < best_col[i]; s++)
				printf("col %d\n", i + 1);
	}
	return 0;
}