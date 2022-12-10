#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <complex>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
using namespace std;

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) (void)0
#endif

typedef long long ll;
typedef pair<int, int> pii;

struct Guy
{
	int p, s, id;
};

const int N = 3010;
int n;
Guy g[N];
int dp[N][N];
bool anc[N][N];
int p, s;

void relax(int i, int j, int val, bool grabbed)
{
	if (dp[i][j] < val)
	{
		dp[i][j] = val;
		anc[i][j] = grabbed;
	}
}

void solve()
{
	scanf("%d%d%d", &n, &p, &s);
	for (int i = 0; i < n; ++i)
		scanf("%d", &g[i].p);
	for (int i = 0; i < n; ++i)
	{
		g[i].id = i;
		scanf("%d", &g[i].s);
	}
	sort(g, g + n, [](Guy a, Guy b) { return a.p > b.p; });
	for(int i = 0; i < n; ++i)
		for (int j = 0; j <= min(s, i); ++j)
		{
			int now_p = i - j;
			if (now_p < p)
				relax(i + 1, j, dp[i][j] + g[i].p, false);
			else
				relax(i + 1, j, dp[i][j], false);
			if (j < s)
				relax(i + 1, j + 1, dp[i][j] + g[i].s, true);
		}
	printf("%d\n", dp[n][s]);
	int i = n, j = s;
	vector<int> sp, pr;
	for (; i > 0; --i)
	{
		if (anc[i][j])
		{
			--j;
			sp.push_back(g[i - 1].id + 1);
		}
		else if (i - j <= p)
			pr.push_back(g[i - 1].id + 1);
	}
	for (auto e : pr)
		printf("%d ", e);
	puts("");
	for (auto e : sp)
		printf("%d ", e);
	puts("");
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
#endif

	solve();

	eprintf("\n\ntime: %.3lf\n", (double)clock() / CLOCKS_PER_SEC);

	return 0;
}