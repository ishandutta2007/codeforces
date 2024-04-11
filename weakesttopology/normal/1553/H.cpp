#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename T> bool chmin(T& x, T y) { return y < x ? (x = y, true) : false; }
template<typename T> bool chmax(T& x, T y) { return x < y ? (x = y, true) : false; }
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    const int inf = 1 << (k + 1);
    vector<int> ans(1 << k, inf), mx(1 << k, -inf), mn(1 << k, +inf);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        mx[a] = mn[a] = 0;
    }
    for (int l = 0; l < k; ++l) {
        for (int mask = 0; mask < (1 << k); ++mask) {
            if (mask >> l & 1) continue;
            int nmask = mask | 1 << l;
            int cur = min(ans[mask], ans[nmask]);
            chmin(ans[mask], min(cur, (1 << l) + mn[nmask] - mx[mask]));
            chmin(ans[nmask], min(cur, (1 << l) + mn[mask] - mx[nmask]));
            int mmx[2] = {mx[mask], mx[nmask]};
            int mmn[2] = {mn[mask], mn[nmask]};
            for (int t : {0, 1}) {
                chmin(mn[mask | t << l], mmn[t ^ 1] + (1 << l));
                chmax(mx[mask | t << l], mmx[t ^ 1] + (1 << l));
            }
        }
    }
    for (int mask = 0; mask < (1 << k); ++mask) {
        cout << ans[mask] << ' ';
    }
    cout << '\n';
    exit(0);
}