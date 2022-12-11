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

const int N = (int)1e6 + 10;
pii a[N];
int dp[N];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &a[i].X, &a[i].Y);
	}
	sort(a, a + n);
	
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int pos = a[i].X - a[i].Y;
		int id = lower_bound(a, a + n, mp(pos, -1)) - a - 1;
		if (id < 0)
			dp[i] = 1;
		else
			dp[i] = 1 + dp[id];
		ans = max(ans, dp[i]);
	}
	printf("%d", n - ans);

	return 0;
}