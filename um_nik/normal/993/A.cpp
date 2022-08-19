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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int C = 10000;
int a[2][10];

bool insideA(int x, int y) {
	int xl = C, xr = -C, yl = C, yr = -C;
	for (int i = 0; i < 8; i++) {
		if (i % 2 == 0) {
			xl = min(xl, a[0][i]);
			xr = max(xr, a[0][i]);
		} else {
			yl = min(yl, a[0][i]);
			yr = max(yr, a[0][i]);
		}
	}
	return xl <= x && x <= xr && yl <= y && y <= yr;
}
bool insideB(int x, int y) {
	int X = x + y, Y = x - y;
	int XL = C, XR = -C, YL = C, YR = -C;
	for (int i = 0; i < 4; i++) {
		x = a[1][2 * i] + a[1][2 * i + 1];
		y = a[1][2 * i] - a[1][2 * i + 1];
		XL = min(XL, x);
		XR = max(XR, x);
		YL = min(YL, y);
		YR = max(YR, y);
	}
	return XL <= X && X <= XR && YL <= Y && Y <= YR;
}
int sgn(int x) {
	if (x > 0) return 1;
	if (x < 0) return -1;
	return 0;
}
bool intersect(int X, int Y1, int Y2, int x1, int y1, int x2, int y2) {
	if (x1 > x2) {
		swap(x1, x2);
		swap(y1, y2);
	}
	if (x1 > X || x2 < X) return false;
	int dy = sgn(y2 - y1);
	int y = y1 + dy * (X - x1);
	if (Y1 > Y2) swap(Y1, Y2);
	return Y1 <= y && y <= Y2;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 8; j++)
			cin >> a[i][j];
		for (int j = 0; j < 2; j++)
			a[i][j + 8] = a[i][j];
	}
	bool ans = false;
	for (int i = 0; i < 4; i++) {
		ans |= insideA(a[1][2 * i], a[1][2 * i + 1]);
		ans |= insideB(a[0][2 * i], a[0][2 * i + 1]);
	}
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++) {
			if (a[0][2 * i] == a[0][2 * i + 2]) {
				ans |= intersect(a[0][2 * i], a[0][2 * i + 1], a[0][2 * i + 3], a[1][2 * j], a[1][2 * j + 1], a[1][2 * j + 2], a[1][2 * j + 3]);
			} else {
				ans |= intersect(a[0][2 * i + 1], a[0][2 * i], a[0][2 * i + 2], a[1][2 * j + 3], a[1][2 * j + 2], a[1][2 * j + 1], a[1][2 * j]);
			}
		}
	if (ans)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}