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

const int N = 110;
int value[N][N];
int number[N * N];

int main()
{
	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	int id = 0;
	for (int i = 0; i < n; i++)
	{
		for (int s = 0; s < m; s++)
			value[i][s] = id++;
	}
	for (int i = 0; i < q; i++)
	{
		int t;
		scanf("%d", &t);
		if (t == 1)
		{
			int r;
			scanf("%d", &r);
			r--;
			int fst = value[r][0];
			for (int s = 0; s < m - 1; s++)
				value[r][s] = value[r][s + 1];
			value[r][m - 1] = fst;
		}
		else if (t == 2)
		{
			int c;
			scanf("%d", &c);
			c--;
			int fst = value[0][c];
			for (int s = 0; s < n - 1; s++)
				value[s][c] = value[s + 1][c];
			value[n - 1][c] = fst;
		}
		else
		{
			int r, c, x;
			scanf("%d%d%d", &r, &c, &x);
			r--, c--;
			number[value[r][c]] = x;
		}
	}

	id = 0;
	for (int i = 0; i < n; i++)
	{
		for (int s = 0; s < m; s++)
		{
			printf("%d ", number[id++]);
		}
		puts("");
	}
	return 0;
}