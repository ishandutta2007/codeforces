// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
//#include "grader.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <deque>
#include <cassert>
#define For(i, a, b) for (int i = a; i < b; ++i)
#define Out(i, a, b) for (int i = a - 1; i >= b; --i)
#define pb push_back
#define x first
#define y second
#define files(FileName) read(FileName); write(FileName)
#define read(FileName) freopen((FileName + ".in").c_str(), "r", stdin)
#define write(FileName) freopen((FileName + ".out").c_str(), "w", stdout)
using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }

using namespace std;

const string FILENAME = "input";
const int MAXN = 1e6 + 1, p = 1e9 + 7;

typedef long long base;
typedef pair <long double, long double> point;

int n;
vector <point> arr;

point operator - (point a, point b) {
	return {a.x - b.x, a.y - b.y};
}

long double cross(point a, point b) {
	return a.x * b.y - a.y * b.x;
}

long double dist(point a, point b) {
	return hypot(a.x - b.x, a.y - b.y);
}

long double dist(point a, point b, point c) {
	//cout << dist(a, b) << endl;
	return abs(cross(a - b, c - a) / dist(a, b));
}



int main() {
	srand(time(0));
	ios::sync_with_stdio(0);
	//read(FILENAME);
	cin >> n;
	arr.resize(n + 2);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i].x >> arr[i].y;
	}
	arr[n] = arr[0];
	arr[n + 1] = arr[1];
	long double ans = 2e9;
	for (int i = 1; i <= n; ++i) {
		long double d = dist(arr[i - 1], arr[i + 1], arr[i]);
		chkmin(ans, d / 2);
	}
	cout << fixed << ans << endl;
}