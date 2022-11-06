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
#define write(FileName) freopen((FileName + ".in").c_str(), "w", stdout)
using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }

const string FILENAME = "input";
typedef long long base;

const int MAXN = 101, MAXK = 21, p = 1e9 + 7;

int n, k;

int sum(int a, int b) {
    a += b;
    if (a >= p)
        a -= p;
    return a;
}

int mul(long long a, int b) {
    return (a * b) % p;
}

int up[101][22][2];
int down[101][22][2];
vector <int> edge[101];

void dfs(int i, int p) {
    //cout << i << ' '  << p << endl;
    for (int j: edge[i]) {
        if (j == p) continue;
        //cout << i << '!' << j << endl;
        dfs(j, i);
    }
    up[i][k][1] = 1;
    for (int j: edge[i]) {
        if (j == p) continue;
        int res = 0;
        for (int q = 0; q < k; ++q) {
            res = sum(res, down[j][q][1]);
        }
        for (int q = 0; q <= k; ++q) {
            res = sum(res, up[j][q][1]);
        }
        up[i][k][1] = mul(up[i][k][1], res);
    }
    for (int q = 0; q < k; ++q) {
        up[i][q][0] = 1;
        for (int j: edge[i]) {
            if (j == p) continue;
            int res0 = 0, res1 = 0;
            for (int r = 0; r <= q + 1; ++r) {
                if (r == q + 1) {
                    res1 = sum(res1, up[j][r][1]);
                } else {
                    res0 = sum(res0, up[j][r][1]);
                }
            }
            for (int r = 0; r < q; ++r) {
                res0 = sum(res0, down[j][r][1]);
            }
            int L = up[i][q][0], R = up[i][q][1];
            up[i][q][0] = mul(L, res0);
            up[i][q][1] = sum(mul(L, res1), mul(R, sum(res0, res1)));
        }
    }
    for (int q = 0; q < k; ++q) {
        down[i][q][0] = 1;
        if (q == 0)
            down[i][q][1] = 1;
        for (int j: edge[i]) {
            if (j == p) continue;
            int res0 = 0, res1 = 0;
            for (int r = 0; r <= q; ++r) {
                res0 = sum(res0, up[j][r][1]);
            }
            for (int r = 0; r < q; ++r) {
                if (r == q - 1) {
                    res1 = sum(res1, down[j][r][1]);
                } else {
                    res0 = sum(res0, down[j][r][1]);
                }
            }
            int L = down[i][q][0], R = down[i][q][1];
            down[i][q][0] = mul(L, res0);
            down[i][q][1] = sum(mul(L, res1), mul(R, sum(res0, res1)));
        }
    }
    //cout << i << endl;
    //cout << i << ' ' << up[i][0][1] << ' ' << up[i][1][1] << ' ' << down[i][0][1] << ' ' << down[i][1][1] << endl;
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    //read(FILENAME);
    cin >> n >> k;
    for (int i = 1; i < n; ++i) {
        int L, R;
        cin >> L >> R;
        --L, --R;
        edge[L].pb(R);
        edge[R].pb(L);
    }
    dfs(0, -1);
    int res = 0;
    for (int i = 0; i <= k; ++i) {
        res = sum(res, up[0][i][1]);
    }
    cout << res << endl;
}
//27,35,51,57,65,77,87,93,95,[Finished in 0.5s]