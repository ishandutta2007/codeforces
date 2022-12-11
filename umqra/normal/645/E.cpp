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

const int N = (int)2e6 + 10;
const int A = 27;
const int mod = (int)1e9 + 7;

int add(int a, int b)
{
	a += b;
	return a < mod ? a : a - mod;
}


char str[N];
int cnt[A];
int dp[A];
int lastPos[A];

int getId(char c)
{
	return c - 'a' + 1;
}

int n, k;
int len;
void read()
{
	scanf("%d%d", &n, &k);
	scanf(" %s", str);
	len = strlen(str);
}

void solve()
{
	dp[0] = 1;
	memset(lastPos, -1, sizeof(lastPos));
	for (int i = 0; i < len; i++)
	{
		cnt[getId(str[i])]++;
		int sum = 0;
		for (int s = 0; s < A; s++)
			sum = add(dp[s], sum);
		dp[getId(str[i])] = sum;
		lastPos[getId(str[i])] = i;
	}

	for (int i = 0; i < n; i++)
	{
		int minPos = 1;
		for (int s = 1; s <= k; s++)
		{
			if (lastPos[s] < lastPos[minPos])
				minPos = s;
		}
		lastPos[minPos] = i + len;
		int sum = 0;
		for (int s = 0; s < A; s++)
			sum = add(dp[s], sum);
		dp[minPos] = sum;
	}
	int ans = 0;
	for (int i = 0; i < A; i++)
		ans = add(ans, dp[i]);
	printf("%d\n", ans);
}

int main()
{
	read();
	solve();
	return 0;
}