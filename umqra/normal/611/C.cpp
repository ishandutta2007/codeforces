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

const int Q = (int)2e5 + 10;
const int N = 600;

char table[N][N];
int r1[Q], c1[Q], r2[Q], c2[Q];
int n, m, q;

int sumHor[N][N];
int sumVer[N][N];

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf(" %s", table[i]);
	scanf("%d", &q);
	for (int i = 0; i < q; i++)
	{
		scanf("%d%d%d%d", &r1[i], &c1[i], &r2[i], &c2[i]);
		r1[i]--, r2[i]--;
		c1[i]--, c2[i]--;
	}
	for (int i = 0; i < n; i++)
	{
		for (int s = 0; s < m; s++)
		{
			sumHor[i][s] = (s == 0 ? 0 : sumHor[i][s - 1]);
			if (s > 0 && table[i][s] == '.' && table[i][s - 1] == '.')
				sumHor[i][s]++;
		}
	}
	for (int s = 0; s < m; s++)
	{
		for (int i = 0; i < n; i++)
		{
			sumVer[s][i] = (i == 0 ? 0 : sumVer[s][i - 1]);
			if (i > 0 && table[i][s] == '.' && table[i - 1][s] == '.')
				sumVer[s][i]++;
		}
	}
	for (int i = 0; i < q; i++)
	{
		int ans = 0;
		for (int a = r1[i]; a <= r2[i]; a++)
			ans += sumHor[a][c2[i]] - sumHor[a][c1[i]];
		for (int a = c1[i]; a <= c2[i]; a++)
			ans += sumVer[a][r2[i]] - sumVer[a][r1[i]];
		printf("%d\n", ans);
	}
	return 0;
}