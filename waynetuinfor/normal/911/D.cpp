#include <bits/stdc++.h>
using namespace std;

const int maxn = 1500 + 10;
int a[maxn];
long long pre[maxn][maxn], suf[maxn][maxn];

int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int inv = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j > 0; --j) pre[i][j] = pre[i][j + 1] + (a[j] > a[i]);
        for (int j = i; j <= n; ++j) suf[i][j] = suf[i][j - 1] + (a[j] > a[i]);
        inv ^= (pre[i][1] & 1);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) pre[i][j] += pre[i - 1][j];
    }
    for (int i = n; i > 0; --i) {
        for (int j = 1; j <= n; ++j) suf[i][j] += suf[i + 1][j];
    }
    int m; cin >> m; while (m--) {
        int l, r; cin >> l >> r;
        // cout << "t = " << t << endl;
        // cout << suf[l][r] << ' ' << pre[r][l] << endl;
        int a = (pre[r][l] - pre[l - 1][l]) & 1, b = (suf[l][r] - suf[r + 1][r]) & 1;
        if (a != b) inv ^= 1;
        if (inv) cout << "odd" << endl;
        else cout << "even" << endl;
    }
    return 0;
}