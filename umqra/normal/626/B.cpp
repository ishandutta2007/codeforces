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

const int N = 201;
bool used[N][N][N];
int cnt[3];

int getId(char c)
{
	if (c == 'R')
		return 0;
	if (c == 'G')
		return 1;
	return 2;
}

int ans[10];

void solve(int a, int b, int c)
{
	if (a == 0 && b == 0)
		ans[2] = 1;
	if (a == 0 && c == 0)
		ans[1] = 1;
	if (b == 0 && c == 0)
		ans[0] = 1;

	if (used[a][b][c])
		return;
	used[a][b][c] = 1;
	if (a > 1)
		solve(a - 1, b, c);
	if (b > 1)
		solve(a, b - 1, c);
	if (c > 1)
		solve(a, b, c - 1);

	if (a > 0 && b > 0)
		solve(a - 1, b - 1, c + 1);
	if (a > 0 && c > 0)
		solve(a - 1, b + 1, c - 1);
	if (b > 0 && c > 0)
		solve(a + 1, b - 1, c - 1);
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		char c;
		scanf(" %c", &c);
		cnt[getId(c)]++;
	}
	solve(cnt[0], cnt[1], cnt[2]);
	for (char c : {'B', 'G', 'R'})
	{
		if (ans[getId(c)])
			putchar(c);
	}
	return 0;
}