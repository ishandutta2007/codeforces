#include <bits/stdc++.h>
using namespace std;

const int maxn = 20;
int a[1 << maxn], tmp[1 << maxn], tag[maxn];
long long ans[2][maxn];

void dq(int l, int r, int dep) {
    if (r - l == 1) return;
    int m = (l + r) >> 1;
    dq(l, m, dep + 1); dq(m, r, dep + 1);
    int p = l, it = l;
    for (int i = m; i < r; ++i) {
        while (p < m && a[p] < a[i]) tmp[it++] = a[p++];
        ans[1][dep] += p - l;
        tmp[it++] = a[i];
    }
    while (p < m) tmp[it++] = a[p++];
    p = m;
    for (int i = l; i < m; ++i) {
        while (p < r && a[p] < a[i]) ++p;
        ans[0][dep] += p - m;
    } 
    for (int i = l; i < r; ++i) a[i] = tmp[i];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < (1 << n); ++i) cin >> a[i];
    dq(0, 1 << n, 0);
    long long inv = 0;
    for (int i = 0; i < n; ++i) inv += ans[0][i];
    int q; cin >> q; while (q--) {
        int h; cin >> h; h = n - h;
        for (int i = h; i < n; ++i) inv += ans[tag[i] ^ 1][i] - ans[tag[i]][i], tag[i] ^= 1;
        cout << inv << endl;
    }
}