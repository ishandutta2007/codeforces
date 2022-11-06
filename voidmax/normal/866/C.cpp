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
#include <iomanip>
#include <bitset>
#include <cassert>
#include <queue>
#include <deque>
#include <cassert>
#include <random>  
#include <ctime>
#define pb push_back
#define x first
#define y second
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
using namespace std;

template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }
typedef long long base;
typedef pair <int, int> point;


const string FILENAME = "input";
const int MAXN = 5201;

typedef long double ld;

int n, k;
int s[50], f[50];
ld p[50];
ld dp[51][MAXN];

bool check(ld M) {
	for (int i = n; i >= 0; i--) {
		for (int j = 0; j < MAXN; ++j) {
			dp[i][j] = M;
		}
	}
	for (int j = 0; j <= k; ++j) {
		dp[n][j] = 0;
	}
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j <= k; ++j) {
			dp[i][j] = min(M, (dp[i + 1][j + f[i]] + f[i]) * p[i] + (dp[i + 1][j + s[i]] + s[i]) * (1 - p[i]));
		}
	}
	return dp[0][0] < M;
}

int main() {
	ios::sync_with_stdio(0);
	srand(time(0));
	//read(FILENAME);
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> f[i] >> s[i] >> p[i];
		p[i] /= 100;
	}
	ld L = 0, R = 1e9;
	for (int i = 0; i < 60; ++i) {
		ld M = (L + R) / 2;
		if (check(M)) {
			R = M;
		} else {
			L = M;
		}
	}
	cout << setprecision(9) << fixed << R << endl;
}