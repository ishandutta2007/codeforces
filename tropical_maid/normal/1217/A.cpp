#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

/*
Author : Tropical_maid
Created : 2019/09/05, 23:35:47
*/

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int st, in, ex;
        cin >> st >> in >> ex;
        int s = 0, e = ex + 1;
        while (s < e) {
            int m = (s + e) / 2;
            if (st + m > in + ex - m) e = m;
            else s = m + 1;
        }
        if (s > ex) printf("0\n");
        else printf("%d\n", ex - s + 1);
    }
    return 0;
}