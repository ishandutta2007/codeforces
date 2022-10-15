#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

template<typename T>
struct PersistentArray {
    vector<vector<pair<int, T>>> A;
    PersistentArray(const vector<int>& a) : A(size(a)) {
        for (size_t i = 0; i < size(a); ++i) A[i].emplace_back(-INF, a[i]);
    }
    T operator[](int x) const { return A[x].back().second; }
    T get(int i, int x) const {
        auto iter = lower_bound(all(A[x]), i, [](auto p, int i){ return p.first < i; });
        if (iter == end(A[x]) || iter->first > i) --iter;
        return iter->second;
    };
    void set(int i, int x, T value) { A[x].emplace_back(i, value); }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> h(n);
    for (auto& x : h) cin >> x;

    PersistentArray<int> dpleft(vector<int>(n + 1, INF)), dpright(vector<int>(n + 1, 0));
    dpleft.set(-1, 0, 0);
    dpright.set(-1, 0, INF);

    vector<int> I(n + 1);
    iota(all(I), 0);

    vector<array<int, 2>> upd(n);

    int opt = -1;
    for (int i = 0; i < n; ++i) {
        auto iter = lower_bound(all(I), h[i], [&](int y, int x){ return dpleft[y] < x; });
        dpleft.set(i, *iter, h[i]);
        opt = max(opt, *iter);
        upd[i][0] = *iter;
    }
    for (int i = n - 1; i >= 0; --i) {
        auto iter = lower_bound(all(I), h[i], [&](int y, int x){ return -dpright[y] < -x; });
        dpright.set(n - 1 - i, *iter, h[i]);
        upd[i][1] = opt - *iter;
    }

    auto f = [&](int k, int i) {
        return dpleft.get(i - 1, k) < dpright.get(n - 1 - (i + 1), opt - k);
    };
    vector<bool> can(n, false), pref(opt + 1, false);
    pref[0] = true;
    int tot = 1;
    for (int i = 0; i < n; ++i) {
        for (auto j : {i-1, i, i+1}) if (0 <= j && j < n) {
            for (auto x : upd[j]) {
                if (pref[x] != f(x, i)) {
                    pref[x] = !pref[x];
                    tot += pref[x] ? +1 : -1;
                }
            }
        }
        can[i] = !!tot;
    }

    for (int z = 0; z < q; ++z) {
        int i, x;
        cin >> i >> x;
        --i;

        int ans = opt - 1;

        // using x
        auto iterl = prev(lower_bound(all(I), x, [&](int x, int y){ return dpleft.get(i - 1, x) < y; }));
        auto iterr = prev(lower_bound(all(I), x, [&](int x, int y){ return dpright.get(n - 1 - (i + 1), x) > y; }));
        ans = max(ans, *iterl + 1 + *iterr);

        // not using x
        if (can[i]) ans = max(ans, opt);

        cout << ans << endl;
    }

    exit(0);
}