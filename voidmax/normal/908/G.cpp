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

void sum(int &a, int b) {
    a += b;
    if (a >= p) { 
        a -= p;
    }
}

int mul(long long a, int b) {
    return a * b % p;
}

int n;
int ans;
string num;
int f[11][701];
int dp[701][701][2];

int main() {
    srand(time(0));
    //read(FILENAME);
    ios::sync_with_stdio(0);
    cin >> num;
    n = num.size();
    for (int i = 0; i < n; ++i) num[i] -= '0';
    for (int c = 0; c < 10; ++c) {
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) {
                dp[i][j][0] = dp[i][j][1] = 0;
            }
        }
        dp[0][0][0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                for (int d = 0; d < num[i]; ++d) {
                    sum(dp[i + 1][j + (d >= c)][1], dp[i][j][0]);
                }
                sum(dp[i + 1][j + (num[i] >= c)][0], dp[i][j][0]);
                for (int d = 0; d < 10; ++d) {
                    sum(dp[i + 1][j + (d >= c)][1], dp[i][j][1]);
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                sum(f[c][i], dp[n][j + 1][0]);
                sum(f[c][i], dp[n][j + 1][1]);
            }
        }
    }
    int r = 1;
    for (int i = 0; i < n; ++i) {
        for (int c = 0; c < 10; ++c) {
            sum(f[c][i], p - f[c + 1][i]);
            sum(ans, mul(f[c][i], mul(c, r)));
        }
        r = mul(r, 10);
    }
    cout << ans << endl;
}