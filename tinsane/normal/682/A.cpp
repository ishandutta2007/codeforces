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
typedef vector< vector<int> > vvint;

#pragma endregion

const int INF = 1e9 + 10;
const ll LINF = ll(2e18) + 10;
const ld PI = acosl(-1);
const double eps = 1e-8;
const ld EPS = 1e-12;

#pragma endregion

void solve()
{
	ll n, m;
	cin >> n >> m;
	ll cnt1[5], cnt2[5];
	ll x = n / 5;
	for (int i = 0; i < n % 5; ++i)
		cnt1[i] = x + 1;
	for (int i = n % 5; i < 5; ++i)
		cnt1[i] = x;
	x = m / 5;
	for (int i = 0; i < m % 5; ++i)
		cnt2[i] = x + 1;
	for (int i = m % 5; i < 5; ++i)
		cnt2[i] = x;
	ll ans = 0;
	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
			if ((i + j) % 5 == 3)
				ans += cnt1[i] * cnt2[j];
	cout << ans;
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("input.txt", "r", stdin);
	//freopen("chocolate.out", "w", stdout);
#endif

	solve();

#ifdef LOCAL
	fprintf(stderr, "\n\nTime: %.3f", double(clock()) / CLOCKS_PER_SEC);
#endif
	return 0;
}