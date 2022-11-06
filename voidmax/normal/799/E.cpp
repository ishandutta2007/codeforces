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
const int MAXN = 1 << 18;
const base Pi = acos(-1);
 
struct seg_tree {
    pair <int, long long> tree[MAXN * 2];
    seg_tree() {}
    long long get(int i, int k) {
        if (k <= 0) return 0;
        if (tree[i].x <= k) {
            return tree[i].y;
        }
        return get(i * 2, k) + get(i * 2 + 1, k - tree[i * 2].x);
    }
    void change(int i, pair <int, long long>  d) {
        //cout << i << '?' << d.x << ' ' << d.y << endl;
        i += MAXN;
        //cout << tree[i].x << ' ' << tree[i].y << endl;
        tree[i] = d;

        while (i > 1) {
            i >>= 1;
            tree[i].x = tree[i * 2].x + tree[i * 2 + 1].x;
            tree[i].y = tree[i * 2].y + tree[i * 2 + 1].y;
        }
        //cout << tree[1].x << ' ' << tree[1].y << endl;
    }   
};

int n, m, k, a, b;
bool good[MAXN][2];
int cost[MAXN];
int p[MAXN];
int it[3];
long long ans = 1e18;
long long sum[3];
vector <int> arr;
vector <int> que[3];
seg_tree box;

bool cmp(int i, int j) {
    return cost[i] < cost[j];
}

int main() {
    srand(time(0));
    //read(FILENAME);
    ios::sync_with_stdio(0);
    cin >> n >> m >> k;
    it[0] = n;
    it[1] = 0;
    it[2] = 0;
    for (int i = 0; i < n; ++i) {
        cin >> cost[i];
        arr.pb(i);
    }
    sort(arr.begin(), arr.end(), cmp);
    for (int i = 0; i < n; ++i) p[arr[i]] = i;
    for (int t = 0; t < 2; ++t) {
        cin >> a;
        for (int i = 0; i < a; ++i) {
            int j;
            cin >> j;
            --j;
            good[j][t] = true;
        }
    }
    for (int i: arr) {
        if (good[i][0] && good[i][1]) {
            sum[0] += cost[i];
            que[0].pb(i);
        } else {
            box.change(p[i], {1, cost[i]});
            if (good[i][0]) {
                que[1].pb(i);
            } else if (good[i][1]) {
                que[2].pb(i);
            } else {
            }
        }
    }
    while (it[0] >= 0) {
        if (it[0] <= que[0].size()) {
            int lst1 = it[1], lst2 = it[2];
            it[1] = max(0, k - it[0]);
            it[2] = max(0, k - it[0]);
            if (it[1] > que[1].size()) break;
            if (it[2] > que[2].size()) break;
            while (lst1 < it[1]) {
                if (lst1 < que[1].size()) {
                    int res = que[1][lst1];
                    sum[1] += cost[res];
                    box.change(p[res], {0, 0});
                }
                ++lst1;
            }
            while (lst2 < it[2]) {
                if (lst2 < que[2].size()) {
                    int res = que[2][lst2];
                    sum[2] += cost[res];
                    box.change(p[res], {0, 0});
                }
                ++lst2;
            }
            if (it[0] + it[1] + it[2] <= m) {
                if ((box.tree[1].x) >= (m - it[0] - it[1] - it[2])) {
                    //cout << it[0] << ' ' << it[1] << ' ' << it[2] << ' ' << sum[0] + sum[1] + sum[2] + box.get(1, m - it[0] - it[1] - it[2]) << ' ' <<  m - it[0] - it[1] - it[2] << endl;
                    chkmin(ans, sum[0] + sum[1] + sum[2] + box.get(1, m - it[0] - it[1] - it[2]));
                }
            }
            if (it[0] != 0) {
                sum[0] -= cost[que[0][it[0] - 1]];
            }
        } 
        --it[0];
    }
    if (ans == 1e18) ans = -1;
    cout << ans << endl;
}