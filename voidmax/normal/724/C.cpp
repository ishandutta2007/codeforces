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
#define point pair <int, int>
#define x first
#define y second
#define files(FileName) read(FileName); write(FileName)
#define read(FileName) freopen((FileName + ".in").c_str(), "r", stdin)
#define write(FileName) freopen((FileName + ".out").c_str(), "w", stdout)
using namespace std;
  
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }

const string FILENAME = "input";

int n, m, k;
map <point, long long> ans[4];

int dirx[4] = {1, 1, -1, -1};
int diry[4] = {1, -1, 1, -1};
int DX = 1, DY = 1;

long long t = 0;
int dir = 0;
point coor = {0, 0};

void update_dir() {
	For(i, 0, 4) {
		if (DX == dirx[i] && DY == diry[i]) {
			dir = i;
			return;
		}
	}
}

bool get() {
	int a, b;
	if (DX > 0) a = n;
	else a = 0;
	if (DY > 0) b = m;
	else b = 0;
	a = (a - coor.x) / DX;
	b = (b - coor.y) / DY;
	coor = {coor.x + DX * min(a, b), coor.y + DY * min(a, b)};
	t += min(a, b);
	if (ans[dir].count(coor) == 0) {
		ans[dir][coor] = t;
	}
	if (a == b) return false;
	if (a < b) DX *= -1;
	else DY *= -1;
	update_dir();
	return true;
}

long long getf() {
	int a, b;
	if (DX > 0) a = n;
	else a = 0;
	if (DY > 0) b = m;
	else b = 0;
	a = (a - coor.x) / DX;
	b = (b - coor.y) / DY;
	coor = {coor.x + DX * min(a, b), coor.y + DY * min(a, b)};
	t += min(a, b);
	//cout << dir << ' ' << coor.x << ' ' << coor.y << endl;
	if (ans[dir].count(coor) == 0) {
		return 1e18;
	} else {
		return ans[dir][coor] - min(a, b);
	}
}

long long get(point a) {
	long long ans = 1e18;
	For(i, 0, 4) {
		DX = dirx[i];
		DY = diry[i];
		dir = i;
		coor = a;
		long long k = getf();
		//cout << k << endl;
		ans = min(ans, k);
	}
	if (ans == 1e18) ans = -1;
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	//read(FILENAME);
	cin >> n >> m >> k;
	while (get()) {continue;}
	For(i, 0, k) {
		point a;
		cin >> a.x >> a.y;
		cout << get(a) << endl;
	}
}