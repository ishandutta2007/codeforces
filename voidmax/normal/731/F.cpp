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
#define point pair <long double, long double>
#define x first
#define y second
#define files(FileName) read(FileName); write(FileName)
#define read(FileName) freopen((FileName + ".in").c_str(), "r", stdin)
#define write(FileName) freopen((FileName + ".out").c_str(), "w", stdout)
using namespace std;
  
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }

typedef long long base;

const string FILENAME = "input";
const int MAXD = 2e5;

int n;
int pref[400001];

long long get_ans(long long a) {
	long long ans = 0;
	long long L = a;
	while (L <= MAXD) {
		ans += L * (pref[L + a - 1] - pref[L - 1]);
		L += a;
	}
	return ans;
}

int main() {
	//read(FILENAME);
	ios::sync_with_stdio(false);
	cin >> n;
	For(i, 0, n) {
		int a;
		cin >> a;
		++pref[a];
	}
	For(i, 1, 2 * MAXD + 1) pref[i] += pref[i - 1];
	long long ans = 0;
	For(i, 1, MAXD + 1) {
		if (pref[i] - pref[i - 1] == 0) {
			continue;
		}
		chkmax(ans, get_ans(i));
 	}
 	cout << ans;
}