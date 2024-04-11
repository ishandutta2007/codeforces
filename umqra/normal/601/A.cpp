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

const int N = 450;
const int INF = (int)1e8 + 10;

int g1[N][N];
int g2[N][N];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int s = 0; s < n; s++)
		{
			g1[i][s] = INF;
			g2[i][s] = 1;
		}
		g1[i][i] = g2[i][i] = 0;
	}
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;
		g1[a][b] = g1[b][a] = 1;
		g2[a][b] = g2[b][a] = INF;
	}
	for (int i = 0; i < n; i++)
	{
		for (int s = 0; s < n; s++)
		{
			for (int q = 0; q < n; q++)
			{
				g1[s][q] = min(g1[s][q], g1[s][i] + g1[i][q]);
				g2[s][q] = min(g2[s][q], g2[s][i] + g2[i][q]);
			}
		}
	}
	if (g1[0][n - 1] > INF / 2 || g2[0][n - 1] > INF / 2)
		puts("-1");
	else
		printf("%d", max(g1[0][n - 1], g2[0][n - 1]));
	return 0;
}