#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt")

#include <bits/stdc++.h>

#define F first
#define S second

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using pi = pair<int, int>;
using vi = vector<int>;
using ll = long long;

template<class T> bool ckmin(T&a, const T& b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T&a, const T& b) { return a < b ? a = b, true : false; }

template<class T> using pq_max = priority_queue<T, vector<T>, less<T>>;
template<class T> using pq_min = priority_queue<T, vector<T>, greater<T>>;

const int INF = 1e9+7;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;

    const int h = __lg(n);
    vector t(h+1, vi(n));
    iota(t[0].begin(), t[0].end(), 0);

    for (int u = 1; u <= h; ++u) {
        const int len = 1 << u - 1;
        for (int i = 0; i + (1 << u) <= n; ++i) {
            t[u][i] = a[t[u-1][i]] < a[t[u-1][i+len]] ? t[u-1][i] : t[u-1][i+len];
        }
    }

    auto get_min = [&](int l, int r) {
        const int u = __lg(r - l);
        return a[t[u][l]] < a[t[u][r-(1<<u)]] ? t[u][l] : t[u][r-(1<<u)];
    };

    int q; cin >> q;
    while (q--) {
        int l, r; cin >> l >> r; --l;

        vector<int> v;
        pq_min<pair<pi, pi>> q;

        auto push = [&] (int l, int r) {
            if (l >= r) return;

            int i = get_min(l, r);
            q.emplace(pi { a[i], i }, pi {l, r});
        };

        push(l, r);

        while (v.size() <= 30 && !q.empty()) {
            auto [i, seg] = q.top(); q.pop();
            v.push_back(i.first);
            auto [l, r] =  seg;
            push(l, i.S);
            push(i.S+1, r);
        }

        int ans = numeric_limits<int>::max();

        for (int i = 0; i < v.size(); ++i)
        for (int j = 0; j < i; ++j) {
            ckmin(ans, v[i] | v[j]);
        }

        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}