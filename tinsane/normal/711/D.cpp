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
#define mp make_pair

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef unsigned short ushort;
typedef pair<int, int> pii;
typedef vector<int>::iterator vint_iter;

const int INF = 1e9 + 10;
const ll LINF = ll(2e18) + 10;
const double PI = acosl(-1);
const double eps = 1e-8;
const ld EPS = 1e-13;

#pragma endregion

const int P = 1e9 + 7;
int sum(int a, int b)
{
	a += b;
	return a >= P ? a - P : a;
}
int sub(int a, int b)
{
	return sum(a, P - b);
}
int mul(int a, int b)
{
	return (ll) a * b % P;
}
int bpow(int x, int p)
{
	int res = 1;
	for (; p > 0; p /= 2, x = mul(x, x))
		if (p % 2 == 1)
			res = mul(res, x);
	return res;
}
const int N = 2e5 + 10;
int n, p[N];
bool used[N];
int wave[N], wsi;

void solve()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &p[i]);
		--p[i];
	}
	int ans = 1;
	for (int i = 0; i < n; ++i)
		if (!used[i])
		{
			wsi = 0;
			int v = i;
			for (; !used[v]; v = p[v])
			{
				used[v] = true;
				wave[wsi++] = v;
			}
			bool ok = false;
			for (int j = 0; j < wsi; ++j)
				if (wave[j] == v)
				{
					ok = true;
					int len = wsi - j;
					ans = mul(ans, sub(bpow(2, len), 2));
					ans = mul(ans, bpow(2, wsi - len));
					break;
				}
			if (!ok)
				ans = mul(ans, bpow(2, wsi));
		}
	printf("%d\n", ans);
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("bandits.in", "r", stdin);
	//freopen("bandits.out", "w", stdout);
#endif

	solve();

#ifdef LOCAL
	fprintf(stderr, "\n\nTime: %.3lf", double(clock()) / CLOCKS_PER_SEC);
#endif
}