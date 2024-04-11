#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    constexpr int K = 20;

    vector<vector<int>> pos(n);
    vector<array<int, K>> prefcnt;

    array<int, K> cnt{};
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        --x;
        pos[x].push_back(i);
        for (int k = 0; k < K; ++k) cnt[k] += x >> k & 1;
        prefcnt.push_back(cnt);
    }

    auto query_bit = [&](int b, int l, int r) {
        return prefcnt[r][b] - (l ? prefcnt[l - 1][b] : 0);
    };
    auto query = [&](int x, int l, int r) {
        if (x >= n) return 0;
        return (int)distance(lower_bound(all(pos[x]), l), upper_bound(all(pos[x]), r));
    };

    for (int z = 0; z < q; ++z) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        int x = 0, len = r - l + 1;
        for (int k = 0; k < K; ++k) {
            if (query_bit(k, l, r) > (len + 1) / 2) x |= 1 << k;
        }
        int f = query(x, l, r);
        int res = f > (len + 1) / 2 ? 2 * f - len : 1;
        cout << res << endl;
    }

    exit(0);
}