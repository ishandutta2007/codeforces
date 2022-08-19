#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <cassert>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef pair<int, int> pii;
typedef long long ll;

#define X first
#define Y second
#define mp make_pair

const int INF = (int)1e9;
const int N = (int)2e3 + 100;
const int H = 200;
int t[N], q[N];
vector <int> groupByTime[N];


int dp[H][N];

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	int n, T;
	scanf("%d%d", &n, &T);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &t[i], &q[i]);
		groupByTime[T - t[i]].push_back(q[i]);
	}
	for (int i = 0; i <= T; i++)
		sort(groupByTime[i].begin(), groupByTime[i].end(), greater<int>());

	for (int i = 0; i < H; i++)
		for (int s = 0; s <= n; s++)
			dp[i][s] = -INF;
	dp[H - 1][0] = 0;
	for (int h = H - 1; h >= 1; h--)
	{
		for (int cnt = 0; cnt <= n; cnt++)
		{
			if (dp[h][cnt] == -INF)
				continue;
			int addSum = 0;
			for (int newCnt = 0; newCnt <= (int)groupByTime[h - 1].size(); newCnt++)
			{
				dp[h - 1][(cnt + 1) / 2 + newCnt] = max(dp[h - 1][(cnt + 1) / 2 + newCnt], 
														dp[h][cnt] + addSum);
				if (newCnt < (int)groupByTime[h - 1].size())
					addSum += groupByTime[h - 1][newCnt];
			}
		}
	}
	printf("%d\n", dp[0][1]);

	return 0;
}