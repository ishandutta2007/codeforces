#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

/*
Author : Tropical_maid
Created : 2019/08/20, 23:40:53
*/

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, l, r;
    cin >> n >> l >> r;
    llong mn = 0, mx = 0;
    for (int i = 0; i < n; ++i) {
        mn += 1 << (i < l ? i : 0);
        mx += 1 << min(i, r - 1);
    }
    printf("%lld %lld\n", mn, mx);
    return 0;
}