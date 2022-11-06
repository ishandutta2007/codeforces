#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 10, lg = 20;
int a[maxn], gst[lg][maxn], mst[lg][maxn];
vector<int> pr;

void build(int n) {
    for (int i = 0; i < n; ++i) gst[0][i] = mst[0][i] = a[i];
    for (int i = 1; (1 << i) <= n; ++i) {
        for (int j = 0; j + (1 << i) <= n; ++j) {
            gst[i][j] = __gcd(gst[i - 1][j], gst[i - 1][j + (1 << (i - 1))]);
            mst[i][j] = min(mst[i - 1][j], mst[i - 1][j + (1 << (i - 1))]);
        }
    }
}

bool check(int len, int n) {
    vector<int> ret;
    int p = 31 - __builtin_clz(len);
    for (int l = 0; l < n; ++l) {
        int r = l + len - 1;
        if (r >= n) break;
        int g = __gcd(gst[p][l], gst[p][r - (1 << p) + 1]);
        int m = min(mst[p][l], mst[p][r - (1 << p) + 1]);
        if (g == m) ret.push_back(l);
    }
    if (ret.size()) pr = ret;
    return !ret.empty();
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    build(n);
    int ans = 0;
    int d = 1; while (d <= n) d <<= 1;
    while (d >>= 1) if (ans + d <= n) if (check(ans + d, n)) ans += d;
    cout << pr.size() << ' ' << ans - 1 << endl;
    for (auto i : pr) cout << i + 1 << ' '; cout << endl;
    return 0;
}