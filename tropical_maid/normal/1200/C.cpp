#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

/*
Author : Tropical_maid
Created : 2019/08/11, 21:50:39
*/

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

llong gcd(llong x, llong y) {
    for (; y; swap(x, y)) x %= y;
    return x;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    llong n, m;
    int q;
    cin >> n >> m >> q;
    llong g = gcd(n, m);
    while (q--) {
        llong sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        --sx, --sy, --ex, --ey;
        if (sx) sy /= m / g;
        else sy /= n / g;
        if (ex) ey /= m / g;
        else ey /= n / g;
        printf(sy == ey ? "YES\n" : "NO\n");
    }
    return 0;
}