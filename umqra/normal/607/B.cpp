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

const int N = 600;
int n;
int dp[N][N];
bool used[N][N];
int a[N];

int solve(int l, int r)
{
	if (l > r)
		return 0;
	if (l == r)
		return 1;
	if (used[l][r])
		return dp[l][r];
	used[l][r] = 1;
	dp[l][r] = solve(l + 1, r) + 1;
	if (l < r && a[l] == a[l + 1])
		dp[l][r] = min(solve(l + 2, r) + 1, dp[l][r]);
	for (int i = l + 2; i <= r; i++)
	{
		if (a[i] == a[l])
			dp[l][r] = min(dp[l][r], solve(l + 1, i - 1) + solve(i + 1, r));
	}
	return dp[l][r];
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("%d\n", solve(0, n - 1));
	return 0;
}