#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

/*
Author : Tropical_maid
Created : 2019/09/15, 19:36:14
*/

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, x, y, c;
    cin >> n >> m >> x >> y >> c;
    int mn = 1e9, mx = 0;
    for (int i = 0; i <= c; ++i) {
        int j = c - i;
        if (i > n * x || j > m * y) continue;
        mn = min(mn, min(max(i - n * (x - 1), 0), n) + min(max(j - m * (y - 1), 0), m));
        mx = max(mx, min(i / x, n) + min(j / y, m));
    }
    printf("%d %d\n", mn, mx);
    return 0;
}