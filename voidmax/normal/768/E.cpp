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

int len = 0;

map <long long, int> dp;

int func(long long mask, int sum) {
	if (dp.count(mask))
		return dp[mask];
	set <int> mex;
	for (int i = 1; i <= len - sum; ++i) {
		if (mask & (1LL << i)) continue;
		mex.insert(func(mask ^ (1LL << i), sum + i));
	}
	int cnt = 0;
	while (mex.count(cnt))
		++cnt;
	return dp[mask] = cnt;
}

int n, m;
int ans[61] = {0, 1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10};

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(0);
    srand(time(0));
    //read(FILENAME);
    // for (len = 0; len <= 60; ++len) {
    // 	ans[len] = func(0, 0);
    // 	dp.clear();
    // 	cout << ans[len] << ", ";
    // }
    // cout << endl;
    cin >> n;
    for (int i = n; i--;) {
    	int a;
    	cin >> a;
    	m ^= ans[a];
    	//cout << ans[a] << endl;
    }
    //cout << m << endl;
    if (m) {
    	cout << "NO" << endl;
    } else {
    	cout << "YES" << endl;
    }
}