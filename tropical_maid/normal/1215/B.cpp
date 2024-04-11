#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

/*
Author : Tropical_maid
Created : 2019/09/15, 19:43:43
*/

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    int sum = 1;
    int cntn = 0, cntp = 1;
    llong ansn = 0, ansp = 0;
    while (n--) {
        int a;
        cin >> a;
        if (a < 0) {
            sum = -sum;
        }
        if (sum > 0) {
            ansn += cntn;
            ansp += cntp;
            ++cntp;
        }
        else {
            ansn += cntp;
            ansp += cntn;
            ++cntn;
        }
    }
    printf("%lld %lld\n", ansn, ansp);
    return 0;
}