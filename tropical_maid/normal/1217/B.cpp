#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

/*
Author : Tropical_maid
Created : 2019/09/05, 23:40:14
*/

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

int solve() {
    int n, x;
    cin >> n >> x;
    int mxd = 0, mxe = 0;
    while (n--) {
        int d, h;
        cin >> d >> h;
        mxd = max(mxd, d - h);
        mxe = max(mxe, d);
    }
    x -= mxe;
    if (x <= 0) return 1;
    if (mxd == 0) return -1;
    return (x + mxd - 1) / mxd + 1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) printf("%d\n", solve());
    return 0;
}