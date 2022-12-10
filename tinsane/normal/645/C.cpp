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
#pragma region TypeDefs

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef vector< vector<int> > vvint;

#pragma endregion

const int INF = 1e9 + 10;
const ll LINF = (ll) 2e18 + 10;
const ld PI = acos(-1);
const ld eps = 1e-8;
const ld EPS = 1e-12;

const int N = 1e5 + 10;
int n, k, ans(INF), fleft[N], fright[N];
string rooms;

void relax(int begin, int end)
{
	int m = (begin + end - 1) / 2;
	int lef = fleft[m];
	int ri = fright[m];
	ans = min(ans, max(lef - begin, end - lef - 1));
	ans = min(ans, max(ri - begin, end - ri - 1));
	if (m + 1 != end)
	{
		int lef = fleft[m + 1];
		int ri = fright[m + 1];
		ans = min(ans, max(lef - begin, end - lef - 1));
		ans = min(ans, max(ri - begin, end - ri - 1));
	}
	if (m != begin)
	{
		int lef = fleft[m - 1];
		int ri = fright[m - 1];
		ans = min(ans, max(lef - begin, end - lef - 1));
		ans = min(ans, max(ri - begin, end - ri - 1));
	}
}

void solve()
{
	cin >> n >> k >> rooms;
	++k;
	for (auto& r : rooms)
		r -= '0';
	if (rooms[0])
		fleft[0] = -INF;
	for (int i = 1; i < n; ++i)
		if (rooms[i])
			fleft[i] = fleft[i - 1];
		else
			fleft[i] = i;
	if (rooms[n - 1])
		fright[n - 1] = INF;
	for (int i = n - 2; i >= 0; --i)
		if (rooms[i])
			fright[i] = fright[i + 1];
		else
			fright[i] = i;
	int begin = 0;
	int end = 0;
	for (; k > 0; ++end)
		if (!rooms[end])
			--k;
	relax(begin, end);
	for (++begin; true; ++begin)
	{
		if (!rooms[begin - 1])
		{
			++k;
			for (; k > 0 && end < n; ++end)
				if (!rooms[end])
					--k;
			if (k)
				break;
		}
		relax(begin, end);
	}
	cout << ans;
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
	fprintf(stderr, "\n\nTime: %.3f", (double) clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}