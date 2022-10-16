#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, true : false; }

template<class T> using pq_min = priority_queue<T, vector<T>, greater<T>>;
template<class T> using pq_max = priority_queue<T, vector<T>, less<T>>;

const int N = 1 << 18;
const int INF = 1e9;
const ll LINF = 1e18;

struct LiChao {
    int n;
    vector<ll> ta, tb;

    LiChao() : n(N), ta(2*N, INF), tb(2*N, LINF) { }

    void add_line(int v, int vl, int vr, ll ka, ll kb) {
        const int vm = (vl + vr) / 2;
        if (ka*vm + kb < ta[v]*vm + tb[v]) swap(ka, ta[v]), swap(kb, tb[v]);

        if (vl + 1 != vr) {
            if (ka < ta[v]) add_line(2*v+1, vm, vr, ka, kb);
            if (ka > ta[v]) add_line(2*v,   vl, vm, ka, kb);
        }
    }

    void add_line(ll ka, ll kb) {
        add_line(1, 0, N, ka, kb);
    }

    ll get_min(int x) {
        ll res = numeric_limits<ll>::max();
        for (int v = x + N; v != 0; v >>= 1) {
            res = min(res, ta[v]*x + tb[v]);
        }
        return res;
    }
};

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<vector<pair<int, ll>>> go(n);
    vector<ll> dp(n, LINF); dp[0] = 0;

    for (int i = 0; i < m; ++i) {
        int a, b, w; cin >> a >> b >> w; --a, --b;
        go[a].emplace_back(b, w);
        go[b].emplace_back(a, w);
    }

    for (int it = 0; it <= k; ++it) {
        pq_min<pair<ll, int>> q;
        for (int i = 0; i < n; ++i) {
            q.emplace(dp[i], i);
        }

        while (!q.empty()) {
            auto [nd, v] = q.top(); q.pop();
            if (dp[v] != nd) continue;

            for (auto [to, w] : go[v]) {
                if (ckmin(dp[to], dp[v] + w)) q.emplace(dp[to], to);
            }
        }

        if (it == k) break;

        LiChao sgt;

        for (int i = 0; i < n; ++i) {
            sgt.add_line(-2*i, (ll)i*i + dp[i]);
        }

        for (int i = 0; i < n; ++i) {
            dp[i] = sgt.get_min(i) + (ll)i*i;
        }
    }

    for (ll x : dp) cout << x << ' '; cout << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}