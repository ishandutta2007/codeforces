#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


struct Move {
	int x1, y1, x2, y2;

	Move() : x1(), y1(), x2(), y2() {}
	Move(int _x1, int _y1, int _x2, int _y2) : x1(_x1), y1(_y1), x2(_x2), y2(_y2) {}

	void print() {
		cout << x1 + 1 << " " << y1 + 1 << " " << x2 + 1 << " " << y2 + 1 << "\n";
	}
};

const int N = 321;
const int M = 500500;
Move ans[M];
int ansSz;
string s[N][N];
int n, m;

bool onSide1(int x, int y) {
	if (x == 0 && y == m - 1) return false;
	if (x == 0) return true;
	if (y == m - 1) return true;
	return false;
}
bool onSide2(int x, int y) {
	if (x == n - 1 && y == 0) return false;
	if (x == n - 1) return true;
	if (y == 0) return true;
	return false;
}

void solve1(int x, int y) {
	int L = (int)s[x][y].length();
	for (int i = L - 1; i >= 0; i--) {
		if (s[x][y][i] == '0') {
			if (onSide1(x, y)) {
				ans[ansSz++] = Move(x, y, 0, m - 1);
				ans[ansSz++] = Move(0, m - 1, 0, 0);
				continue;
			}
			if (onSide2(x, y)) {
				ans[ansSz++] = Move(x, y, n - 1, 0);
				ans[ansSz++] = Move(n - 1, 0, 0, 0);
				continue;
			}
			if (x != 0)
				ans[ansSz++] = Move(x, y, 0, y);
			if (y != 0)
				ans[ansSz++] = Move(0, y, 0, 0);
		} else {
			if (onSide1(x, y)) {
				ans[ansSz++] = Move(x, y, 0, m - 1);
				ans[ansSz++] = Move(0, m - 1, n - 1, m - 1);
				continue;
			}
			if (onSide2(x, y)) {
				ans[ansSz++] = Move(x, y, n - 1, 0);
				ans[ansSz++] = Move(n - 1, 0, n - 1, m - 1);
				continue;
			}
			if (x != n - 1)
				ans[ansSz++] = Move(x, y, n - 1, y);
			if (y != m - 1)
				ans[ansSz++] = Move(n - 1, y, n - 1, m - 1);
		}
	}
}
void solve2(int x, int y) {
	int L = (int)s[x][y].length();
	for (int i = L - 1; i >= 0; i--) {
		if (s[x][y][i] == '0') {
			if (onSide1(x, y)) {
				ans[ansSz++] = Move(0, 0, 0, m - 1);
				ans[ansSz++] = Move(0, m - 1, x, y);
				continue;
			}
			if (onSide2(x, y)) {
				ans[ansSz++] = Move(0, 0, n - 1, 0);
				ans[ansSz++] = Move(n - 1, 0, x, y);
				continue;
			}
			if (x != 0)
				ans[ansSz++] = Move(0, 0, x, 0);
			if (y != 0)
				ans[ansSz++] = Move(x, 0, x, y);
		} else {
			if (onSide1(x, y)) {
				ans[ansSz++] = Move(n - 1, m - 1, 0, m - 1);
				ans[ansSz++] = Move(0, m - 1, x, y);
				continue;
			}
			if (onSide2(x, y)) {
				ans[ansSz++] = Move(n - 1, m - 1, n - 1, 0);
				ans[ansSz++] = Move(n - 1, 0, x, y);
				continue;
			}
			if (x != n - 1)
				ans[ansSz++] = Move(n - 1, m - 1, x, m - 1);
			if (y != m - 1)
				ans[ansSz++] = Move(x, m - 1, x, y);
		}
	}
	
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> s[i][j];

	solve1(0, m - 1);
	solve1(n - 1, 0);
	for (int y = 0; y < m - 1; y++)
		solve1(0, y);
	for (int x = 1; x < n; x++)
		solve1(x, m - 1);
	for (int x = 1; x < n - 1; x++)
		solve1(x, 0);
	for (int y = 1; y < m - 1; y++)
		solve1(n - 1, y);
	for (int x = 1; x < n - 1; x++)
		for (int y = 1; y < m - 1; y++)
			solve1(x, y);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> s[i][j];
	for (int x = 1; x < n - 1; x++)
		for (int y = 1; y < m - 1; y++)
			solve2(x, y);
	for (int y = 1; y < m - 1; y++)
		solve2(n - 1, y);
	for (int x = 1; x < n - 1; x++)
		solve2(x, 0);
	for (int x = 1; x < n; x++)
		solve2(x, m - 1);
	for (int y = 0; y < m - 1; y++)
		solve2(0, y);
	solve2(n - 1, 0);
	solve2(0, m - 1);

	cout << ansSz << "\n";
	for (int i = 0; i < ansSz; i++)
		ans[i].print();

	return 0;
}