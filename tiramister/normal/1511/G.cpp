#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

struct Data {
    int xsum, parity, length;

    static Data merge(const Data& a, const Data& b) {
        return Data{a.xsum ^ b.xsum ^ (a.length * b.parity),
                    a.parity ^ b.parity,
                    a.length + b.length};
    }
};

constexpr int K = 20;

void solve() {
    int n, m;
    cin >> n >> m;

    auto table = vector(K, vector(m + 1, Data{0, 0, 1}));
    while (n--) {
        int c;
        cin >> c;

        auto& d = table[0][c];
        d.parity ^= 1;
    }

    // (i-2^k,i]
    for (int k = 0; k + 1 < K; ++k) {
        for (int i = (1 << k); i <= m; ++i) {
            table[k + 1][i] = Data::merge(table[k][i - (1 << k)],
                                          table[k][i]);
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        --l;

        auto d = table[0][r];
        --r;
        int diff = r - l;
        for (int k = 0; k < K; ++k) {
            if ((diff >> k) & 1) {
                d = Data::merge(table[k][r], d);
                r -= (1 << k);
            }
        }

        cout << (d.xsum == 0 ? "B" : "A");
    }
    cout << "\n";
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    solve();

    return 0;
}