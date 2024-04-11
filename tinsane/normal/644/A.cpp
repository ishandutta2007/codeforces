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

const int INF = 1e9 + 10;
const ll LINF = (ll) 2e18 + 10;
const ld PI = acos(-1);
const ld eps = 1e-8;
const ld EPS = 1e-12;

const int N = 101;
int n, a, b, last[2] = {-1, 0};
int res[N][N];

void solve()
{
	cin >> n >> a >> b;
	for (int i = 0; i < a; ++i)
		for (int j = 0; j < b; ++j)
		{
			int num = (i + j) % 2;
			last[num] += 2;
			res[i][j] = last[num];
		}
	if (last[0] + 2 <= n || last[1] + 2 <= n)
	{
		cout << -1;
		return;
	}
	for (int i = 0; i < a; ++i, cout << '\n')
		for (int j = 0; j < b; ++j)
			cout << (res[i][j] <= n ? res[i][j] : 0) << ' ';
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