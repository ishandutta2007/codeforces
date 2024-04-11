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
typedef pair<int, int> pii;
typedef vector< vector<int> > vvint;

#pragma endregion

const int INF = 1e9 + 10;
const ll LINF = ll(2e18) + 10;
const ld PI = acosl(-1);
const double eps = 1e-8;
const ld EPS = 1e-12;

const int N = 110;
int n;
int p[N];

void solve()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> p[i];
	int f = -1, s;
	for (int i = 0; i < n; ++i)
		if (p[i] == 1 || p[i] == n)
			if (f != -1)
				s = i;
			else
				f = i;
	cout << max(s, n - f - 1);
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("chocolate.in", "r", stdin);
	//freopen("chocolate.out", "w", stdout);
#endif
	solve();

#ifdef LOCAL
	fprintf(stderr, "\n\nTime: %.3f", double(clock()) / CLOCKS_PER_SEC);
#endif
	return 0;
}