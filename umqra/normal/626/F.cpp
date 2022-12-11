/*
	Team: Dandelion
	Room: 258
*/

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

const int mod = (int)1e9 + 7;
const int N = 205;
const int K = 1010;
int arr[N];
int sum[N];
int n, k;

int add(int a, int b)
{
	a += b;
	if (a < 0)
		return a + mod;
	if (a < mod)
		return a;
	return a - mod;
}

int mult(int a, int b)
{
	return (1LL * a * b) % mod;
}

void fadd(int &a, int b)
{
	a = add(a, b);
}

int getSum(int pos)
{
	return pos < 0 ? 0 : sum[pos];
}

int getSum(int l, int r)
{
	return getSum(r) - getSum(l - 1);
}

bool isValidValue(int pos, int slots, int delta)
{
	if (n - pos < slots)
		return false;
	int curSum = getSum(pos, pos + slots - 1);
	if (delta < -curSum)
		return false;
	if (delta > k - curSum)
		return false;
	return true;
}

int dp[N][N][K];

void setDp(int pos, int slots, int delta, int value)
{
	if (!isValidValue(pos, slots, delta))
		return;
	int minValue = -getSum(pos, pos + slots - 1);
	dp[pos][slots][delta - minValue] = value;
}

void addDp(int pos, int slots, int delta, int value)
{
	if (!isValidValue(pos, slots, delta))
		return;
	int minValue = -getSum(pos, pos + slots - 1);
	fadd(dp[pos][slots][delta - minValue], value);
}

int getDp(int pos, int slots, int delta)
{
	if (!isValidValue(pos, slots, delta))
		return 0;
	int minValue = -getSum(pos, pos + slots - 1);
	return dp[pos][slots][delta - minValue];
}

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + n);
	sum[0] = arr[0];
	for (int i = 1; i < n; i++)
		sum[i] = sum[i - 1] + arr[i];

	setDp(0, 0, 0, 1);
	for (int i = 0; i < n; i++)
	{
		for (int slots = 0; slots <= min(n - i, i); slots++)
		{
			int value = getSum(i, i + slots - 1);
			for (int delta = -value; delta <= -value + k; delta++)
			{
				if (getDp(i, slots, delta) == 0)
					continue;
				if (slots > 0)
					addDp(i + 1, slots - 1, delta + arr[i], mult(slots, getDp(i, slots, delta)));
				addDp(i + 1, slots + 1, delta - arr[i], getDp(i, slots, delta));
				if (slots > 0)
				{
					addDp(i + 1, slots, delta, mult(slots, getDp(i, slots, delta)));
				}
				addDp(i + 1, slots, delta, getDp(i, slots, delta));
			}
		}
	}
	int ans = 0; 
	for (int i = 0; i <= k; i++)
	{
		ans = add(ans, getDp(n, 0, i));
	}
	printf("%d\n", ans);
	return 0;
}