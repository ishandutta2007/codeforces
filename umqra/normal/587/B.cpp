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

const int mod = (int)1e9 + 7;
const int N = (int)1e6 + 10;
int dp[2][N];
pii start[N];
int arr[N];
int countLess[N];

int add(int a, int b)
{
	a += b;
	if (a < mod)
		return a;
	return a - mod;
}

int mult(int a, int b)
{
	return ((ll)a * b) % mod;
}

int main()
{
	int n;
	ll l;
	int k;
	cin >> n >> l >> k;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &start[i].X);
		start[i].Y = i;
	}
	sort(start, start + n);
	for (int i = 0; i < n; i++)
		arr[i] = start[i].X;
	for (int i = 0; i < n; i++)
		countLess[i] = upper_bound(arr, arr + n, arr[i]) - arr;

	int ans = (l % mod);

	ll fullBlocks = l / n;
	ll lastBlock = l % n;
	for (int i = 0; i < n; i++)
	{
		dp[0][i] = 1;
	}
	for (int i = 1; i < k; i++)
	{
		int cur = (i & 1);
		int p = 1 - cur;
		int it = 0;
		int sum = 0;
		for (int s = 0; s < n; s++)
		{
			while (it < n && arr[it] <= arr[s])
			{
				sum = add(sum, dp[p][it]);
				it++;
			}
			dp[cur][s] = sum;
			if (start[s].Y < lastBlock && fullBlocks + 1 >= i + 1)
				ans = add(ans, dp[cur][s]);
			if (fullBlocks >= i + 1)
				ans = add(ans, mult(dp[cur][s], (fullBlocks - i) % mod));
		}
	}
	cout << ans;	

	return 0;
}