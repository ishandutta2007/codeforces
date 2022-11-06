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
 
int n, m;

bool used[MAXN];
int p[MAXN];
set <pair <int, int>> cost[3];

int main() {
    srand(time(0));
    //read(FILENAME);
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    for (int t = 0; t < 2; ++t) {
        for (int i = 0; i < n; ++i) {
            int c; cin >> c;
            cost[c - 1].insert({p[i], i});
        }
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int c; cin >> c;
        --c;
        while (cost[c].size()) {
            auto v = *cost[c].begin();
            if (used[v.y]) {
                cost[c].erase(cost[c].begin());
            } else {
                break;
            }
        }
        if (cost[c].size() == 0) {
            cout << -1 << ' ';
        } else {
            auto v = *cost[c].begin();
            used[v.y] = true;
            cout << v.x << ' ';
        }
    }
    cout << endl;
}