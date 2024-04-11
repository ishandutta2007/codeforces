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

    int n, m;
    cin >> n >> m;

    constexpr int K = 20;
    vector<array<int, K>> go(m), odd(m);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        --x;
        odd[x][0] ^= 1;
    }
    for (int x = 0; x + 1 < K; ++x) {
        for (int j = 0; j + (1 << (x + 1)) <= m; ++j) {
            go[j][x + 1] = go[j][x] ^ go[j + (1 << x)][x];
            if (odd[j + (1 << x)][x]) go[j][x + 1] ^= 1 << x;
            odd[j][x + 1] = odd[j][x] ^ odd[j + (1 << x)][x];
        }
    }

    int q;
    cin >> q;

    string res(q, 'B');
    for (int z = 0; z < q; ++z) {
        int l, r;
        cin >> l >> r;
        --l, --r;

        vector<pair<int, int>> A;
        for (int x = K - 1; x >= 0; --x) {
            if (l + (1 << x) <= r + 1) {
                A.emplace_back(l, x);
                l += 1 << x;
            }
        }
        assert(l == r + 1);

        reverse(all(A));
        int xorsum = 0, o = 0;
        for (auto [l, x] : A) {
            xorsum = go[l][x] ^ xorsum;
            if (o) xorsum ^= 1 << x;
            o ^= odd[l][x];
        }

        if (xorsum) res[z] = 'A';
    }

    cout << res << endl;

    exit(0);
}