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
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }
 
using namespace std;
 
typedef long long base;
typedef pair <int, int> point;
 
const string FILENAME = "input";
const int MAXN = 1e5 + 1;
const int cost[6][2] = {{3000, 32}, {2500, 16}, {2000, 8}, {1500, 4}, {1000, 2}, {500, 1}};


int n;
int cnt[5];
int arr[120][5];

int f(int t, int m, int n) {
    if (t == -1) return 0;
    for (int i = 0; i < 6; ++i) {
        if (m * cost[i][1] <= n) {
            //cout << m << ' ' << n << ' '<< cost[i][0] << endl;
            return cost[i][0] / 250 * (250 - t);
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    //read(FILENAME);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin >> arr[i][j];
            if (arr[i][j] != -1)
                ++cnt[j];
        }
    }
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        for (int j = 0; j < 5; ++j) {
            cnt += f(arr[i][j], ::cnt[j], n);
        }
        //cout << cnt << endl;
    }
    for (int c = 0; c <= 32 * n; ++c) {
        int delta = 0;
        for (int j = 0; j < 5; ++j) {
            if (arr[0][j] == -1) {
                delta += f(arr[1][j], cnt[j], n + c);
            } else {
                int best_delta = 1e9;
                int lst = 0;
                for (int q = 0; q < 6; ++q) {
                    int solved = (n + c) / cost[q][1];
                    if (lst > cnt[j] + c) break;
                    if (solved < cnt[j]) {
                        lst = solved + 1;
                        continue;
                    }
                    chkmin(best_delta, f(arr[1][j], lst, n + c) - f(arr[0][j], lst, n + c));
                    lst = solved + 1;
                }
                delta += best_delta;
            }
        }
        if (delta < 0) {
            cout << c << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}