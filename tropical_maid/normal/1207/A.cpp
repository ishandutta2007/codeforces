#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

/*
Author : Tropical_maid
Created : 2019/08/22, 23:35:34
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
        int b, p, f, h, c;
        cin >> b >> p >> f >> h >> c;
        int ans = 0;
        for (int i = 0; i + i <= b && i <= p; ++i) {
            for (int j = 0; i + i + j + j <= b && j <= f; ++j) {
                ans = max(ans, i * h + j * c);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}