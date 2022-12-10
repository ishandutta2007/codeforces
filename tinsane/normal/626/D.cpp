#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <stack>
#include <set>
#include <algorithm>
#include <bitset>
#include <cassert>
#include <functional>
#include <unordered_set>
#pragma comment(linker, "/STACK:167772160")

using namespace std;

#ifdef LOCAL
#define eprintf(...) printf(__VA_ARGS__)
#else
#define eprintf(...) ;
#endif

typedef long long ll;
typedef unsigned int uint;
typedef pair<int, int> pii;

const double PI = 3.1415926535897932384626433;
const int INF = 1e9 + 10;
const ll LINF = 2e18 + 10;
const double eps = 1e-9;
const int P = 1e9 + 7;

const int S = 15e3 + 10;
const int N = 2e3 + 10;
int n, nums[N];
ll sub1[S], sub2[S], gr[S];

void solve()
{
	cin >> n;
	for (int i(0); i < n; ++i)
		cin >> nums[i];
	sort(nums, nums + n);
	for (int i(0); i < n; ++i)
		for (int j(i + 1); j < n; ++j)
			++sub1[nums[j] - nums[i]];
	for (int i(0); i < S; ++i)
		for (int j(0); j < S; ++j)
			sub2[i + j] += sub1[i] * sub1[j];
	for (int i(0); i < n; ++i)
		--gr[nums[i]];
	gr[0] = n;
	for (int i(1); i < S; ++i)
		gr[i] += gr[i - 1];
	ll ans = 0;
	for (int i(0); i < n; ++i)
		for (int j(0); j < S; ++j)
			ans += gr[nums[i] + j] * sub2[j];
	ll vars = n * (n - 1) / 2;
	vars = vars * vars * vars;
	cout << setprecision(12) << fixed << (long double) ans / vars;
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0); cin.tie(0);

	solve();

	eprintf("\nTime : %.3lf\n", (double)clock() / CLOCKS_PER_SEC);

	return 0;
}