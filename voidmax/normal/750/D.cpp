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
#define write(FileName) freopen((FileName + ".in").c_str(), "w", stdout)
#define less less228
#define more more228
using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }

const string FILENAME = "input";
const int MAXH = 20000;

int dirx[8] = {-1, -1, -1,  0,  1,  1,  1,  0};
int diry[8] = {-1,  0,  1,  1,  1,  0, -1, -1};

int n;
int t[31];
bool can[500][500];
bool used[500][500][31][8];

void res(int X, int Y, int n, int d) {
	if (used[X][Y][n][d]) return;
	if (n == -1) return;
	used[X][Y][n][d] = true;
	for (int i = 0; i < t[n]; ++i) {
		X += dirx[d];
		Y += diry[d];
		can[X][Y] = true;
	}
	res(X, Y, n - 1, (d + 7) % 8);
	res(X, Y, n - 1, (d + 1) % 8);
}

int main(int argc, char const *argv[]) {
    srand(time(0));
    ios::sync_with_stdio(0);
   	//read(FILENAME);   
    cin >> n;
    for (int i = n; i--;) {
    	cin >> t[i];
    }
    res(250, 250, n - 1, 1);
    int cnt = 0;
    for (int i = 0; i < 500; ++i) {
    	for (int j = 0; j < 500; ++j) {
    		cnt += can[i][j];
    	}
    }
    cout << cnt << endl;
}