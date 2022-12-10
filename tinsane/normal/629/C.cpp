#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <vector>
#include <map>
#include <string>
#include <cstring>
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

int sum(int a, int b)
{
	a += b;
	if (a >= P)
		return a - P;
	return a;
}

int sub(int a, int b)
{
	return sum(a, P - b);
}

int mul(int a, int b)
{
	return (ll)a * b % P;
}

const int N = 1e5 + 10;
const int D = 2e3 + 10;
int n, m, open, close, balance, ans, dp[D][D];
string seq;

void solve()
{
	for (int i(0); i < D; ++i)
		dp[i][0] = 1;
	for (int j(1); j < D; ++j)
		for (int i(j); i < D; ++i)
			dp[i][j] = sum(dp[i - 1][j], dp[i][j - 1]);
	cin >> n >> m >> seq;
	for (auto bracket : seq)
		if (bracket == '(')
			++balance;
		else if (balance > 0)
			--balance;
	close = balance;
	reverse(seq.begin(), seq.end());
	balance = 0;
	for(auto bracket : seq)
		if (bracket == ')')
			++balance;
		else if (balance > 0)
			--balance;
	open = balance;
	int addition = (n - m - open - close);
	if (addition < 0 || addition % 2 == 1)
	{
		cout << 0;
		return;
	}

	for (int lost = 0; lost <= addition / 2; ++lost)
	{
		int beg = open + addition / 2 - lost;
		int end = close + addition / 2 - lost;
		for (int i(0); i <= lost; ++i)
			ans = sum(ans, mul(dp[beg + i][i], dp[end + lost - i][lost - i]));
	}

	cout << ans;
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("teleports.in", "r", stdin);
	//freopen("teleports.out", "w", stdout);
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