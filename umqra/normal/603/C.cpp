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

const int N = 10;
const int K = (int)1e6 + 10;
int dp[N];
int a[K];
int k;

int mex(int a, int b)
{
	for (int i = 0;; i++)
	{
		if (i != a && i != b)
			return i;
	}
}

int get(int x)
{
	if (x < N)
		return dp[x];
	if (k % 2 == 0)
		return !(x % 2);
	if (x % 2 == 1)
		return 0;
	return mex(0, get(x / 2));
}

int main()
{
	int n;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	dp[0] = 0;
	for (int i = 1; i < N; i++)
	{
		int a = dp[i - 1];
		int b = a;
		if (i % 2 == 0)
			b = dp[i / 2] * (k & 1);
		for (int s = 0;; s++)
		{
			if (a != s && b != s)
			{
				dp[i] = s;
				break;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
		ans ^= get(a[i]);
	printf("%s", ans ? "Kevin" : "Nicky");

	return 0;
}