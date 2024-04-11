#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl
#define real zxcv

/*
Author : Tropical_maid
Created : 2019/08/22, 23:38:34
*/

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

int n, m;
int grid[51][51];
int real[51][51];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    vector<pii> ans;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> grid[i][j];
            if (i == 1 || j == 1) continue;
            if (grid[i][j] == 0) continue;
            if (grid[i][j - 1] == 0) continue;
            if (grid[i - 1][j] == 0) continue;
            if (grid[i - 1][j - 1] == 0) continue;
            ans.emplace_back(i - 1, j - 1);
            real[i - 1][j - 1] = 1;
            real[i - 1][j] = 1;
            real[i][j - 1] = 1;
            real[i][j] = 1;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (grid[i][j] != real[i][j]) {
                printf("-1\n");
                return 0;
            }
        }
    }
    printf("%u\n", ans.size());
    for (pii i : ans) printf("%d %d\n", i.fs, i.se);
    return 0;
}