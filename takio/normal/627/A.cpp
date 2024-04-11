#include <bits/stdc++.h>
#define LL long long
#define pii pair <LL, LL>
#define xx first
#define yy second
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r
using namespace std;

const int M = 1010, N = 100100;

int a[N], b[N], nn;
LL dp[N][2];

LL dfs (int k, int c) {
    if (k > nn) {
        return c == 0;
    }
//    int e1 = flag1 ?
    if (dp[k][c] != -1) return dp[k][c];
    LL &res = dp[k][c];
    res = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) if ((i ^ j) == b[k]) {
            int num = (i + j + c) % 2;
            if (num == a[k]) res += dfs (k + 1, (i + j + c) / 2);
        }
    }
    return res;
}

int main () {
//    freopen ("in.txt", "r", stdin);
    memset (dp, -1, sizeof dp);
    LL n, m;
    int an = 0, bn = 0;
    cin >> n >> m;
    int tmp = 0;
    if (n == m) tmp = -2;
    while (n) {
        a[++an] = n % 2;
        n /= 2;
    }
    while (m) {
        b[++bn] = m % 2;
        m /= 2;
    }
    nn = max (an, bn);
    cout << dfs (1, 0) + tmp;
}