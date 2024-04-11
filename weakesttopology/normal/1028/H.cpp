#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

auto sieve(int N) {
    vector<int> lp(N + 1, 0), pr;
    for (int i = 2; i <= N; ++i) {
        if (lp[i] == 0) pr.push_back(lp[i] = i);
        for (auto p : pr) {
            if (p > lp[i] || i * p > N) break;
            lp[i * p] = p;
        }
    }
    return pair(lp, pr);
}

template<typename T>
struct BIT {
    T inf = numeric_limits<T>::max();
    int n;
    vector<T> ft;
    BIT(int n) : n(n), ft(n + 1, inf) {}
    T query(int p) {
        T res = inf;
        for (p += 1; p <= n; p += p & -p) res = min(res, ft[p]);
        return res;
    }
    void update(int p, T value) {
        for (p += 1; p >= 1; p -= p & -p) ft[p] = min(ft[p], value);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    constexpr int amax = 6e6;
    auto [lp, pr] = sieve(amax);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    map<int, vector<int>> f;

    for (auto& x : a) {
        cin >> x;
        if (not f.count(x)) {
            for (int y = x, p = lp[y]; y > 1; p = lp[y]) {
                int cnt = 0;
                while (y % p == 0) y /= p, cnt ^= 1;
                if (cnt) f[x].push_back(p);
            }
        }
    }

    vector<vector<pair<int, int>>> Q(n);
    for (int z = 0; z < q; ++z) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        Q[r].emplace_back(l, z);
    }

    constexpr int emax = 10;
    int p[1 << emax], popcount[1 << emax]{};
    p[0] = 1;
    for (int mask = 1; mask < (1 << emax); ++mask) {
        popcount[mask] = 1 + popcount[mask & (mask - 1)];
    }

    BIT<int> bit(n);

    vector<vector<pair<int, int>>> div(amax + 1);
    vector<int> ans(q);

    for (int i = 0; i < n; ++i) {
        const auto& F = f[a[i]];
        int e = (int)size(F);
        for (int j = 0; j < e; ++j) p[1 << j] = F[j];
        for (int mask = 0; mask < (1 << e); ++mask) {
            int lsb = mask & -mask;
            int d = p[mask] = p[mask ^ lsb] * p[lsb];
            int cur = e - popcount[mask];
            for (auto [cost, l] : div[d]) bit.update(l, cost + cur);
            while (not empty(div[d]) && div[d].back().first >= cur) div[d].pop_back();
            div[d].emplace_back(cur, i);
        }
        for (auto [l, z] : Q[i]) ans[z] = bit.query(l);
    }

    for (int z = 0; z < q; ++z) {
        cout << ans[z] << endl;
    }

    exit(0);
}