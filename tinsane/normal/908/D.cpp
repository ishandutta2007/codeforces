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
#include <random>
#include <complex>
#include <regex>
#include <numeric>
#include <typeinfo>
#include <type_traits>
#include <fstream>
#pragma comment(linker, "/STACK:167772160")

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) (void)0
#endif

using namespace std;

using ll = long long;

const int P = 1e9 + 7;
int sum(int a, int b)
{
	a += b;
	return a >= P ? a - P : a;
}
int mul(int a, int b)
{
	return (ll)a * b % P;
}
int bpow(int x, int p)
{
	int res = 1;
	for (; p > 0; p /= 2, x = mul(x, x))
		if (p % 2 == 1)
			res = mul(res, x);
	return res;
}
int inv(int x)
{
	return bpow(x, P - 2);
}

const int N = 1010;
int k, pa, pb, ipb, one;
int dp[N][N];

void solve()
{
	cin >> k >> pa >> pb;
	one = inv(sum(pa, pb));
	pa = mul(pa, one);
	pb = mul(pb, one);
	ipb = inv(pb);
	for (int i = 1; i < N; ++i)
		dp[i][i] = sum(i, mul(pa, ipb));
	for (int i = 1; i < N; ++i)
		for (int a = i - 1; a > 0; --a)
		{
			if (i - a >= a)
				dp[i][a] = sum(mul(pa, dp[i][a + 1]), mul(pb, sum(a, dp[i - a][a])));
			else
				dp[i][a] = sum(mul(pa, dp[i][a + 1]), mul(pb, sum(2 * a, mul(pa, ipb))));
		}
	//for (int i = 0; i <= k; ++i, eprintf("\n"))
	//	for (int a = 0; a <= i; ++a)
	//		eprintf("%d ", dp[i][a]);
	cout << dp[k][1] << endl;
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("err.txt", "w", stderr);
#else
	//freopen("sum.in", "r", stdin);
	//freopen("sum.out", "w", stdout);
#endif

	solve();
	eprintf("\n\nTime: %.3lf\n", double(clock()) / CLOCKS_PER_SEC);
	return 0;
}