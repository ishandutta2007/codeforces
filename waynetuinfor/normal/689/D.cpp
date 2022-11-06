#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10, lg = 30;
int a[maxn], b[maxn];

struct sparse {
    int arr[2][lg][maxn];
    void init(int n) {
        for (int i = 0; i < n; ++i) {
            arr[0][0][i] = a[i];
            arr[1][0][i] = b[i];
        }
        for (int i = 1; (1 << i) <= n; ++i) {
            for (int j = 0; j + (1 << i) <= n; ++j) {
                arr[0][i][j] = max(arr[0][i - 1][j], arr[0][i - 1][j + (1 << (i - 1))]);
                arr[1][i][j] = min(arr[1][i - 1][j], arr[1][i - 1][j + (1 << (i - 1))]);
            }
        }
    }
    pair<int, int> query(int l, int r) {
        int p = 31 - __builtin_clz(r - l + 1);
        return make_pair(max(arr[0][p][l], arr[0][p][r - (1 << p) + 1]), min(arr[1][p][l], arr[1][p][r - (1 << p) + 1]));
    }
} sp;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    sp.init(n);
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        int rr = i, rl = i, trr = i, trl = i;
        int d = 262144; while (d >>= 1) {
            if (rr + d < n) {
                auto p = sp.query(i, rr + d);
                if (p.first == p.second) trr = rr + d;
                if (p.first <= p.second) rr += d;
            }
            if (rl + d < n) {
                auto p = sp.query(i, rl + d);
                if (p.first == p.second) trl = rl + d;
                if (p.first < p.second) rl += d;
            }
        } 
        if (sp.query(i, i).first == sp.query(i, i).second) trl = i;
        if (sp.query(i, trl).first != sp.query(i, trl).second || sp.query(i, trr).first != sp.query(i, trr).second) continue;
        ans += max(0, trr - trl + 1);
    } 
    cout << ans << endl;
    return 0;
}