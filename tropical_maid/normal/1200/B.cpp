#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

/*
Author : Tropical_maid
Created : 2019/08/11, 21:39:23
*/

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

int n, m, k;
int H[101];
bool solve() {
    cin >> n >> m >> k;
    llong bag = m;
    for (int i = 1; i <= n; ++i) cin >> H[i];
    for (int i = 2; i <= n; ++i) {
        int L = H[i - 1], R = H[i];
        if (L + k < R) {
            bag -= R - L - k;
            if (bag < 0) return 0;
        }
        else bag += min((llong)L + k - R, (llong)L);
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) printf(solve() ? "YES\n" : "NO\n");
    return 0;
}