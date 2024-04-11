#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

/*
Author : Tropical_maid
Created : 2019/08/23, 00:17:09
*/

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

const int B = 800;
llong A[500001];
llong S[B][B];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1) {
            A[x] += y;
            for (int i = 1; i < B; ++i) S[i][x % i] += y;
        }
        else {
            llong ret = 0;
            if (x < B) ret = S[x][y];
            else {
                for (int i = y; i <= 500000; i += x) {
                    ret += A[i];
                }
            }
            printf("%lld\n", ret);
        }
    }
    return 0;
}