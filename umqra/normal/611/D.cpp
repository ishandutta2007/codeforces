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
#define equal askdjalds

const int N = (int)5e3 + 10;
const int mod = (int)1e9 + 7;

int add(int a, int b)
{
	a += b;
	if (a < mod)
		return a;
	return a - mod;
}

int mult(int a, int b)
{
	return (1LL * a * b) % mod;
}

char str[N];

int equal[N][N];
int dp[N][N];

int main()
{
	int n;
	scanf("%d %s", &n, str);
	for (int i = n - 1; i >= 0; i--)
		for (int s = n - 1; s >= 0; s--)
		{
			if (str[i] == str[s])
				equal[i][s] = equal[i + 1][s + 1] + 1;
			else
				equal[i][s] = 0;
		}

	dp[0][1] = 1;
	for (int prev = 0; prev < n; prev++)
	{
		for (int pos = 0; pos <= n; pos++)
			dp[prev][pos] = add(dp[prev][pos], (pos > 0 ? dp[prev][pos - 1] : 0));

		int it = prev + 2;
		for (int pos = prev + 1; pos <= n; pos++)
		{
			while (it <= n)
			{
				if (pos - prev > it - pos)
				{
					it++;
					continue;
				}
				if (pos - prev < it - pos)
					break;
				int e = equal[prev][pos];
				int curLen = it - pos;
				if (e < curLen && str[pos + e] > str[prev + e])
					break;
				it++;
			}
			if (str[pos] != '0')
				dp[pos][it] = add(dp[pos][it], dp[prev][pos]);
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = add(ans, dp[i][n]);
	printf("%d\n", ans);
	return 0;
}