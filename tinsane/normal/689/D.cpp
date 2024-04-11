#pragma region Template
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
#include <map>
#include <cmath>
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
#include <unordered_map>
#include <unordered_set>
#pragma comment(linker, "/STACK:167772160")

using namespace std;
#pragma region TypeDefs

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef unsigned short ushort;
typedef pair<int, int> pii;
typedef vector<int>::iterator vint_iter;

#pragma endregion

const int INF = 1e9 + 10;
const ll LINF = ll(2e18) + 10;
const ld PI = acosl(-1);
const double eps = 1e-8;
const ld EPS = 1e-13;

#pragma endregion

const int N = 2e5 + 10;
const int LOGN = 20;
int sta[LOGN][N], stb[LOGN][N];
int p2[LOGN], l2[N];
int a[N], b[N];
int n;
ll ans;

void init()
{
	p2[0] = 1;
	for (int i = 1; i < LOGN; ++i)
		p2[i] = 2 * p2[i - 1];
	l2[1] = 0;
	for (int i = 2; i < N; ++i)
	{
		l2[i] = l2[i - 1];
		if (p2[l2[i] + 1] == i)
			++l2[i];
	}
	for (int i = 0; i < n; ++i)
	{
		sta[0][i] = a[i];
		stb[0][i] = b[i];
	}
	for (int i = 1; i < LOGN; ++i)
		for (int j = 0; j < n - p2[i - 1]; ++j)
		{
			sta[i][j] = max(sta[i - 1][j], sta[i - 1][j + p2[i - 1]]);
			stb[i][j] = min(stb[i - 1][j], stb[i - 1][j + p2[i - 1]]);
		}
}

inline int geta(int l, int r)
{
	int low = l2[r - l + 1];
	return max(sta[low][l], sta[low][r - p2[low] + 1]);
}

inline int getb(int l, int r)
{
	int low = l2[r - l + 1];
	return min(stb[low][l], stb[low][r - p2[low] + 1]);
}

void solve()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; ++i)
		scanf("%d", &b[i]);
	init();
	for (int i = 0; i < n; ++i)
	{
		if (a[i] > b[i] || geta(i, n - 1) < getb(i, n - 1))
			continue;
		int lb, rb;
		if (a[i] == b[i])
			lb = i;
		else
		{
			int lef = i;
			int ri = n - 1;
			while(ri - lef > 1)
			{
				int mid = (lef + ri) / 2;
				if (geta(i, mid) < getb(i, mid))
					lef = mid;
				else
					ri = mid;
			}
			lb = ri;
		}
		if (geta(i, lb) > getb(i, lb))
			continue;
		if (geta(i, n - 1) == getb(i, n - 1))
			rb = n - 1;
		else
		{
			int lef = lb;
			int ri = n - 1;
			while (ri - lef > 1)
			{
				int mid = (lef + ri) / 2;
				if (geta(i, mid) == getb(i, mid))
					lef = mid;
				else
					ri = mid;
			}
			rb = lef;
		}
		ans += rb - lb + 1;
	}
	printf("%I64d", ans);
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("tiling.in", "r", stdin);
	//freopen("tiling.out", "w", stdout);
#endif

	solve();

#ifdef LOCAL
	fprintf(stderr, "\n\nTime: %.3f", double(clock()) / CLOCKS_PER_SEC);
#endif
}