#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

/*
Author : Tropical_maid
Created : 2019/09/19, 23:43:15
*/

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

int solve() {
    int c, m, x;
    cin >> c >> m >> x;
    int s = 0, e = 1e8;
    while (s < e) {
        int mid = (s + e + 1) / 2;
        if (mid <= c && mid <= m && 3 * mid <= c + m + x) s = mid;
        else e = mid - 1;
    }
    return s;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) printf("%d\n", solve());
    return 0;
}