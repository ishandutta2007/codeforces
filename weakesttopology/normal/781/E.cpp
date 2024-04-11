#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

constexpr ll mod = 1e9 + 7;

template<typename T>
struct SegmentTree {
    int n;
    T Id;
    vector<set<T>> st;
    SegmentTree(int n, T Id) : n(n), Id(Id), st(2 * n, {Id}) {}
    T query(int p) {
        T res = Id;
        for (p += n; p; p >>= 1) res = max(res, *rbegin(st[p]));
        return res;
    }
    void update(int l, int r, T value) {
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                auto [iter, b] = st[l].insert(value);
                if (not b) st[l].erase(iter);
                ++l;
            }
            if (r & 1) {
                --r;
                auto [iter, b] = st[r].insert(value);
                if (not b) st[r].erase(iter);
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int h, w, n;
    cin >> h >> w >> n;

    enum State { entering = 0, leaving = 1 };
    vector<tuple<int, State, int>> events;

    vector<int> L(n), R(n), u(n), s(n);

    for (int i = 0; i < n; ++i) {
        cin >> u[i] >> L[i] >> R[i] >> s[i];
        --u[i], --L[i], --R[i];
        events.emplace_back(u[i], entering, i);
        if (u[i] + s[i] < h) events.emplace_back(u[i] + s[i], leaving, i);
    }
    sort(all(events));

    vector<ll> dp(n + 1, 0);
    dp[n] = 1;
    SegmentTree<pair<int, int>> st(w, pair(-1, n));

    for (auto [x, state, i] : events) {
        if (state == leaving) {
            st.update(L[i], R[i], pair(u[i], i));
        }
        else {
            if (L[i] == 0) {
                int r = st.query(R[i] + 1).second;
                dp[i] = 2 * dp[r] % mod;
            }
            else if (R[i] == w - 1) {
                int l = st.query(L[i] - 1).second;
                dp[i] = 2 * dp[l] % mod;
            }
            else {
                int l = st.query(L[i] - 1).second;
                int r = st.query(R[i] + 1).second;
                dp[i] = dp[l] + dp[r];
                dp[i] %= mod;
            }
            st.update(L[i], R[i], pair(u[i], i));
        }
    }

    ll ans = 0;
    for (int x = 0; x < w; ++x) {
        int i = st.query(x).second;
        ans += dp[i];
        ans %= mod;
    }
    cout << ans << endl;

    exit(0);
}