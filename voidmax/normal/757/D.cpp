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

const int p = 1e9 + 7, q = 163941, r = 20;

const string FILENAME = "input";

void sum(int &a, int b) {
    a += b;
    if (a >= p)
        a -= p;
}

int mul(long long a, int b) {
    return (a * b) % p;
}

int n;
string s;
int ans = 0;
int dp[76][1 << r];

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(0);
    //read(FILENAME);
    srand(time(0));
    cin >> n;
    cin >> s;
    for (int i = 0; i <= n; ++i) {
        sum(dp[i][0], 1);
        int k = 0, j = i;
        vector <pair <int, int>> can;
        for (int j = i; j < n; ++j) {
            k *= 2;
            k += s[j] - '0';
            if (k > r) break;
            if (k != 0) can.pb({k, j + 1});
        }
        for (int j = 0; j < (1 << r); ++j) {
            for (auto q: can) {
                sum(dp[q.y][j | (1 << (q.x - 1))], dp[i][j]);
            }
        }
        for (int j = 1; j <= r; ++j) {
            sum(ans, dp[i][(1 << j) - 1]);
        }
    }
    cout << ans << endl;
}