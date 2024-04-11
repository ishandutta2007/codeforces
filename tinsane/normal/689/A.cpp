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

const int N = 10;
int n;
string num;
char keys[4][3];
int posx[] = {3, 0, 0, 0, 1, 1, 1, 2, 2, 2};
int posy[] = {1, 0, 1, 2, 0, 1, 2, 0, 1, 2}; 

bool is_ok(int x, int y)
{
	return 0 <= x && x < 4 &&
		0 <= y && y < 3 &&
		keys[x][y];
}

void solve()
{
	cin >> n >> num;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			keys[i][j] = '1' + i * 3 + j;
	keys[3][1] = '0';
	for (int bx = 0; bx < 4; ++bx)
		for (int by = 0; by < 3; ++by)
		{
			if (!is_ok(bx, by) || keys[bx][by] == num[0])
				continue;
			int x = bx;
			int y = by;
			bool ok = true;
			for (int i = 1; i < n; ++i)
			{
				int dx = posx[num[i] - '0'] - posx[num[i - 1] - '0'];
				int dy = posy[num[i] - '0'] - posy[num[i - 1] - '0'];
				x += dx;
				y += dy;
				if (!is_ok(x, y))
				{
					ok = false;
					break;
				}
			}
			if (ok)
			{
				puts("NO");
				return;
			}
		}
	puts("YES");
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