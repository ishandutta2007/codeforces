#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r
#define getm int m = (l + r) >> 1
#define LL long long
#define ULL unsigned long long
#define pii pair <LL, LL>

using namespace std;

const int N = 510, mod = 1e9 + 7;

int dp[N][N], a[N];

int d (int l, int r) {
    if (dp[l][r] != -1) return dp[l][r];
    if (l == r) return dp[l][r] = 1;
//    int dp2[N];
//    memset (dp2, 0, sizeof dp2);
    dp[l][r] = d (l + 1, r);
    for (int i = l + 2; i <= r; i++) {
        if (a[l + 1] < a[i]) {
            (dp[l][r] += 1LL * d(l + 1, i - 1) * d (i - 1, r) % mod) %= mod;
        }
//        cout << l << ',' << r << ' ' << j - 1 - l << " += " << i - 1 - l << "*(" << i << ',' << j - 1 << ')' << endl;
//        (dp2[j - 1] += 1LL * dp2[i - 1] * d (i, j - 1) % mod) %= mod;
    }
//    cout << l << ' ' << r << endl;
//    for (int i = l; i <= r; i++) cout << dp2[i] << ' '; cout << endl;
    return dp[l][r];
}

int main () {
//    freopen ("in.txt", "r", stdin);
    memset (dp ,-1, sizeof dp);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &a[i]);
    }
    cout << d(1, n) << endl;
//    int l, r;
//    while (cin >> l >> r) cout << d(l, r) << endl;
}