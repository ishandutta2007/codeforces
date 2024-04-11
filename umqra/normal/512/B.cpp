#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <cmath>
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

const int N = 400;
const int INF = (int)1e9 + 1000;

int gcd(int a, int b)
{
	return (b == 0 ? a : gcd(b, a % b));
}

int a[N];
int cost[N];
int dp[N][1 << 11];
vector <int> primesD[N];
vector <int> indices;
int maskKill[N];

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	int n;
	scanf("%d", &n);

	int g = 0;

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		g = gcd(g, a[i]);
	}

	if (g != 1)
	{
		puts("-1");
		return 0;
	}

	for (int i = 0; i < n; i++)
		scanf("%d", &cost[i]);

	for (int i = 0; i < n; i++)
	{
		int x = a[i];
		for (int s = 2; s * s <= a[i]; s++)
		{
			int cnt = 0;
			while (x % s == 0)
			{
				cnt++;
				x /= s;
			}
			if (cnt > 0)
				primesD[i].push_back(s);
		}
		if (x != 1)
			primesD[i].push_back(x);
	}

	int ans = INF;
	for (int i = 0; i < n; i++)
	{
		indices.clear();
		int countD = (int)primesD[i].size();
		for (int s = 0; s < n; s++)
		{
			if (i == s)
				continue;
			indices.push_back(s);
			maskKill[s] = 0;
			for (int d = 0; d < countD; d++)
			{
				int value = primesD[i][d];
				if (a[s] % value != 0)
					maskKill[s] |= (1 << d);
			}
		}
		for (int s = 0; s <= n; s++)
			for (int mask = 0; mask < (1 << countD); mask++)
				dp[s][mask] = INF;
		dp[0][0] = cost[i];
		for (int s = 0; s < n - 1; s++)
		{
			int index = indices[s];
			for (int mask = 0; mask < (1 << countD); mask++)
			{
				dp[s + 1][mask] = min(dp[s + 1][mask], dp[s][mask]);
				dp[s + 1][mask | maskKill[index]] = min(dp[s + 1][mask | maskKill[index]], dp[s][mask] + cost[index]);
			}
		}
		ans = min(ans, dp[n - 1][(1 << countD) - 1]);
	}
	cout << ans;

	return 0;
}