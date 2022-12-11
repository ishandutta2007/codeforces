/*
	Team: Dandelion
	Room: 258
*/

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

const int N = 100;
int p[N];
int a[N][N];
bool used[N];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int s = 0; s < n; s++)
			scanf("%d", &a[i][s]);

	for (int i = 1; i <= n; i++)
	{
		int maxCnt = -1;
		int r = 0;
		for (int s = 0; s < n; s++)
		{
			int curCnt = 0;
			for (int q = 0; q < n; q++)
			{
				if (q == s)
					continue;
				if (a[q][s] == i)
					curCnt++;
				if (a[s][q] == i)
					curCnt++;
			}
			if (maxCnt < curCnt && !used[s])
			{
				r = s;
				maxCnt = curCnt;
			}
		}
		used[r] = 1;
		p[r] = i;
	}
	for (int i = 0; i < n; i++)
		printf("%d ", p[i]);
	return 0;
}