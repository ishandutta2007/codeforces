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
#include <iomanip>      
#define pb push_back
#define x first
#define y second
#define mp make_pair
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
using namespace std;
  
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }
  
typedef long double base;
typedef pair<base, base> point;

const string FILENAME = "input";

const int MAXN = 5e3 + 2, p = 1e9 + 7;

int mul(long long a, int b) {
	return a * b % p;
}

int sum(int a, int b) {
	a += b;
	return a >= p ? a - p : a;
}

int powx(int a, int b) {
	int ans = 1;
	while (b) {
		if (b & 1) ans = mul(ans, a);
		a = mul(a, a);
		b >>= 1;
	}
	return ans;
}

int n, k;
int dp[MAXN][MAXN];

int get(int a, int b, int c) {
	if (dp[a][b]) return dp[a][b];
	if (a == 0) {
		return dp[a][b] = powx(2, c);
	}
	if (c == 0) {
		return dp[a][b] = powx(b, a);
	}
	return dp[a][b] = sum(mul(b, get(a - 1, b, c)), mul(c, get(a - 1, b + 1, c - 1)));
}

int main() {
	ios::sync_with_stdio(0);
	srand(time(0));
	//read(FILENAME);
	cin >> n >> k;
	cout << get(k, 0, n) << endl;
}