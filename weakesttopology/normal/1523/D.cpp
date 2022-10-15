#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

const int FIXED_RANDOM = (int)chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(FIXED_RANDOM);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, p;
    cin >> n >> m >> p;

    vector<string> s(n);
    for (auto& x : s) cin >> x;

    const int pmax = 15;
    vector<int> popcount(1 << pmax);
    for (int mask = 1; mask < (1 << pmax); ++mask) {
        int lsb = mask & -mask;
        popcount[mask] = 1 + popcount[mask ^ lsb];
    }

    auto solve = [&](string y) {
        vector<int> J;
        for (int j = 0; j < m; ++j) {
            if (y[j] == '1') J.push_back(j);
        }
        int k = (int)size(J);

        vector<int> sz(1 << k, 0);
        for (auto x : s) {
            int mask = 0;
            for (int j = 0; j < k; ++j) {
                if (x[J[j]] == '0') mask |= 1 << j;
            }
            sz[mask] += 1;
        }
        for (int j = 0; j < k; ++j) {
            for (int mask = 0; mask < (1 << k); ++mask) {
                if (mask >> j & 1) sz[mask] += sz[mask ^ (1 << j)];
            }
        }

        int optmask = (1 << k) - 1;
        for (int mask = 0; mask < (1 << k); ++mask) {
            if (sz[mask] >= (n + 1) / 2 && popcount[mask] < popcount[optmask]) {
                optmask = mask;
            }
        }

        vector<int> I;
        for (int j = 0; j < k; ++j) {
            if ((optmask >> j & 1) == 0) I.push_back(J[j]);
        }

        return pair(k - popcount[optmask], I);
    };

    uniform_int_distribution<int> unif(0, n - 1);

    int opt = 0;
    string ans(m, '0');
    for (int t = 0; t < 40; ++t) {
        auto [optcur, I] = solve(s[unif(rng)]);
        if (optcur > opt) {
            opt = optcur;
            fill(all(ans), '0');
            for (auto i : I) ans[i] = '1';
        }
    }

    cout << ans << endl;

    exit(0);
}