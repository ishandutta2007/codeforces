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
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
using namespace std;
  
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }


const string FILENAME = "input";
typedef pair<long double, long double> point;
typedef long double base;

const int p = 1e9 + 7;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int k;
int A, B, f1, f2;

pair<int, int> dp[2001][2001];

int sum(int a, int b) {
    a += b;
    return a >= p ? a - p : a;
}

int mul(long long a, int b) {
    return a * b % p;
}

pair<int, int> sum(pair<int, int> a, pair<int, int> b) {
    a.x = mul(a.x, b.y);
    b.x = mul(b.x, a.y);
    a.y = mul(a.y, b.y);
    return {sum(a.x, b.x), a.y};
}

pair<int, int> mul(pair<int, int> a, pair<int, int> b) {
    return {mul(a.x, b.x), mul(a.y, b.y)};
}

int powx(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = mul(a, ans);
        a = mul(a, a);
        b >>= 1;
    }
    return ans;
}

point v1, v2;

int main() {
	srand(time(0));
    //read(FILENAME);
	ios::sync_with_stdio(0);
	cin >> k >> f1 >> f2;
    v1 = {f1, f1 + f2};
    v2 = {f2, f1 + f2};
    for (int j = k; j >= 0; --j) { 
        dp[j][k] = {k, 1};
        if (j == k) {
            for (int i = k - 1; i >= 0; --i) {
                dp[j][i] = sum({mul(v1.x, v2.y), mul(v1.y, v2.x)}, {i + k, 1});
            }   
            //x = v1 * (1 + x) + v2 * (i + k);
        } else if (j == 0) {
            for (int i = k - 1; i >= 0; --i) {
                dp[j][i] = {0, 1};
            }        
            dp[0][0] = dp[1][0];
        } else {
            for (int i = k - 1; i >= 0; --i) {
                dp[j][i] = mul(v1, dp[j + 1][i]);
                if ((i + j) < k) {
                    dp[j][i] = sum(dp[j][i], mul(v2, dp[j][i + j]));
                } else {
                    dp[j][i] = sum(dp[j][i], mul(v2, {i + j, 1}));
                }
            }
        } 
    }
    // for (int i = 0; i <= k; ++i) {
    //     for (int j = 0; j <= k; ++j) {
    //         cout << i << ' ' << j << ' ' << dp[i][j].x << ' ' << dp[i][j].y << endl;
    //     }
    // }
    //cout << dp[0][0].x << ' ' << dp[0][0].y << endl;
    cout << mul(dp[0][0].x, powx(dp[0][0].y, p - 2)) << endl;
}