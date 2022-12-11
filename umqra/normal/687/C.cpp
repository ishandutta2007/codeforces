#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <ctime>
#include <cmath>
#include <algorithm>

#include <valarray>
#include <complex>
#include <functional>
#include <cassert>

using namespace std;
typedef long long ll;

const int N = 550;
int arr[N];
int n, k;

void read()
{
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
}

int dp[N][N];

set <int> res = {};

void solve()
{
	dp[0][0] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int a = k - arr[i]; a >= 0; a--)
			for (int b = k - arr[i] - a; b >= 0; b--)
			{
				if (dp[a][b])
				{
					dp[a + arr[i]][b] = 1;
					dp[a][b + arr[i]] = 1;
				}
			}
	}
	for (int i = 0; i < N; i++)
		for (int s = 0; s < N; s++)
		{
			if (i + s == k && dp[i][s])
				res.insert(i);
		}
	printf("%d\n", (int)res.size());
	for (int x : res)
		printf("%d ", x);
	puts("");
}

int main()
{
	read();
	solve();
    return 0;
}