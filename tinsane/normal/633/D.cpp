#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <utility>
#include <stack>
#include <set>
#include <algorithm>
#include <bitset>
#include <functional>
#include <ctime>
#include <cassert>
#include <valarray>
#pragma comment(linker, "/STACK:167772160")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef vector< vector<int> > vvint;

#ifdef LOCAL
#define eprint() debugOutput()
#else
#define eprint() ;
#endif

const int P = (int) 1e9 + 7;
const int INF = 1e9 + 10;
const ll LINF = (ll) 2e18 + 10;
const double pi = 2 * atan2(1, 0);
const ld PI = 2 * atan2l(1, 0);
const double eps = 1e-8;
const ld EPS = 1e-12;
void debugOutput();

const int N = 1e3 + 10;
int n, nums[N], dp[N][N];
int used[N], cnt[N], ind[N];

void solve()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> nums[i];
	sort(nums, nums + n);
	int cnt0 = 0;
	for (int i = 0; i < n; ++i)
		cnt0 += nums[i] == 0;
	if (cnt0 > n / 2 + 3)
	{
		cout << cnt0;
		return;
	}
	for (int i = 0; i < n; ++i)
		++cnt[ind[i] = lower_bound(nums, nums + n, nums[i]) - nums];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (i != j || nums[i] == nums[j])
			{
				int ptr = lower_bound(nums, nums + n, nums[i] + nums[j]) - nums;
				if (ptr != n && nums[ptr] == nums[i] + nums[j])
					dp[i][j] = ptr;
				else
					dp[i][j] = -1;
			}
			else
				dp[i][j] = -1;
	int best = 2;
	for (int i = 0; i < n; ++i)
	for (int j = 0; j < n; ++j)
	{
		int res = 1;
		memset(used, 0, sizeof used);
		used[ind[i]] = 1;
		for (int a = i, b = j; b != -1; a = dp[a][b], swap(a, b))
		{
			if (used[ind[b]] == cnt[ind[b]])
				break;
			++res;
			++used[ind[b]];
		}
		best = max(best, res);
	}
	cout << best;
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("sequence.in", "r", stdin);
	//freopen("sequence.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0), cin.tie(0);

	solve();

#ifdef LOCAL
	fprintf(stderr, "\n\nTime: %.3f", (double)clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}

void debugOutput()
{}