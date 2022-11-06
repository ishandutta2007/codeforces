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
 
int n, c, d;
int b[MAXN];
vector <int> res[2][MAXN];
vector <pair <int, int>> cost[2];

bool cmp(int i, int j) {
    return b[i] > b[j];
} 

int main() {
    srand(time(0));
    //read(FILENAME);
    ios::sync_with_stdio(0);
    cin >> n >> c >> d;
    for (int i = 0; i < n; ++i) {
        int a, b;
        char c;
        cin >> b >> a >> c;
        int id = c != 'C';
        ::b[i] = b;
        res[id][a].pb(i);
        cost[id].pb({a, i});
    }
    int ans = 0;
    for (int t = 0; t < 2; ++t) {
        for (int i = 0; i < MAXN; ++i) {
            if (i) for (int j: res[t][i - 1]) res[t][i].pb(j);
            sort(res[t][i].begin(), res[t][i].end(), cmp);
            if (res[t][i].size() > 2)
                res[t][i].resize(2);
        }
    }
    if (res[0][c].size() && res[1][d].size()) {
        chkmax(ans, b[res[0][c][0]] + b[res[1][d][0]]);
    } 
    for (auto i: cost[0]) {
        if (c >= i.x) {
            for (int j: res[0][c - i.x]) {
                if (i.y != j) {
                    chkmax(ans, b[i.y] + b[j]);
                }
            }
        }
    }
    for (auto i: cost[1]) {
        if (d >= i.x) {
            for (int j: res[1][d - i.x]) {
                if (i.y != j) {
                    chkmax(ans, b[i.y] + b[j]);
                }
            }
        }
    }
    cout << ans << endl;
}