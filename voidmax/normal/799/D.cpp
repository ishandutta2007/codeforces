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
 
typedef long long base;
 
const string FILENAME = "input";
const int MAXN = 2e5 + 1;
const base Pi = acos(-1);
 
int a, b, w, h, n;
vector <int> arr;
int ans = 42;

int dp[MAXN][41];

int main() {
    srand(time(0));
    //read(FILENAME);
    ios::sync_with_stdio(0);
    cin >> a >> b >> w >> h >> n;
    arr.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr.rbegin(), arr.rend());
    chkmin(n, 40);
    arr.resize(n);
    for (int t = 0; t < 2; ++t) {
        int L = (a - 1) / w + 1, R = (b - 1) / h + 1;
        for (int i = 0; i < MAXN; ++i) {
            for (int j = 0; j <= n; ++j) {
                dp[i][j] = 1e9;
            }
        }
        //cout << L << ' ' << R << endl;
        dp[L][0] = R;
        for (int j = 0; j <= n; ++j) {
            if (j != n) {
                for (int i = 1; i < MAXN; ++i) {
                    if (dp[i][j] == 1e9) continue;
                    //if (i <= L) cout << i << ' ' << j << ' ' << dp[i][j] << ' ' << (dp[i][j] - 1) / arr[j] + 1 << endl;
                    chkmin(dp[i][j + 1], (dp[i][j] - 1) / arr[j] + 1);
                    //if (i <= L) cout << "?!" << dp[i][j + 1] << endl;
                    chkmin(dp[(i - 1) / arr[j] + 1][j + 1], dp[i][j]);
                }
            }
            if (dp[1][j] == 1) {
                chkmin(ans, j);
                break;
            }
        }
        //cout << endl;
        swap(a, b);
    }
    if (ans == 42) ans = -1;
    cout << ans << endl;
}