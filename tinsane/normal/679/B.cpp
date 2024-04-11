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

const int N = 1e5 + 10;
//const int N = 5;
ll m;
ll cubes[N];
int ans[N], val[N];

pair<ll, ll> solve(ll m)
{
	if (m < N)
		return make_pair(ans[val[m]], val[m]);
	ll bigs = upper_bound(cubes, cubes + N, m) - cubes - 1;
	auto f = solve(m - cubes[bigs]);
	auto s = solve(cubes[bigs] - 1 - cubes[bigs - 1]);
	if (f.first >= s.first)
		return make_pair(f.first + 1, cubes[bigs] + f.second);
	return make_pair(s.first + 1, cubes[bigs - 1] + s.second);
}

void solve()
{
	for (ll i = 1; i < N; ++i)
		cubes[i] = i * i * i;
	cin >> m;
	val[1] = ans[1] = 1;
	int mav = 1;
	for (int i = 2, now = 1; i < N; ++i)
	{
		if ((now + 1) * (now + 1) * (now + 1) == i)
		{
			ans[i] = 1;
			++now;
			if (ans[i] >= ans[mav])
				mav = i;
			val[i] = mav;
			continue;
		}
		ans[i] = 1 + ans[i - now * now * now];
		if (ans[i] >= ans[mav])
			mav = i;
		val[i] = mav;
	}
	auto res = solve(m);
	cout << res.first << ' ' << res.second;
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