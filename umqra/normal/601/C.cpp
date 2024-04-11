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

const int M = 1010;
const int N = 110;

int n, m;
int tSum = 0;

double dp[2][N * M];
double forSum[2][N * M];
int x[N];

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x[i]);
		tSum += x[i];
	}
	if (m == 1)
	{
		printf("%.10lf\n", 1.0);
		return 0;
	}

	forSum[0][0] = 1;
	forSum[0][1] = -1;
	for (int i = 0; i <= n; i++)
	{
		int cur = (i & 1);
		int nxt = 1 - cur;
		for (int s = 0; s <= i * m; s++)
		{
			forSum[cur][s] += (s == 0 ? 0 : forSum[cur][s - 1]);
			dp[cur][s] = forSum[cur][s];
		}
		for (int s = 0; s <= (i + 1) * m; s++)
			forSum[cur][s] = forSum[nxt][s] = 0;
		if (i == n)
			break;

		for (int s = 0; s <= i * m; s++)
		{
			forSum[nxt][s + 1] += dp[cur][s] / (m - 1);
			forSum[nxt][s + x[i]] -= dp[cur][s] / (m - 1);

			forSum[nxt][s + x[i] + 1] += dp[cur][s] / (m - 1);
			forSum[nxt][s + m + 1] -= dp[cur][s] / (m - 1);
		}
	}
	double prob = 0;
	for (int i = 0; i < tSum; i++)
		prob += dp[n & 1][i];
	prob *= (m - 1);
	printf("%.10lf\n", prob + 1);

	return 0;
}