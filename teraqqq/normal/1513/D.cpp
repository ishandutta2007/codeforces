#include <bits/stdc++.h>

#define F first
#define S second

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())

using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

template<class T> bool ckmin(T& a, T b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, T b) { return a < b ? a = b, true : false; }

template<class T> using pq_min = priority_queue<T, vector<T>, greater<T>>;
template<class T> using pq_max = priority_queue<T, vector<T>, less<T>>;

struct Dsu {
    vector<int> p, c, r;
    int cnt;

    Dsu (int n) : p(n), c(n, 1), r(n), cnt(n) {
        iota(p.begin(), p.end(), 0);
        iota(r.begin(), r.end(), 0);
    }

    int get_root(int v) {
        return v == p[v] ? v : p[v] = get_root(p[v]);
    }

    void unite(int a, int b) {
        a = get_root(a);
        b = get_root(b);
        if (a != b) {
            if (c[a] < c[b]) swap(a, b);
            c[a] += c[b];
            p[b] = a;
            r[a] = max(r[a], r[b]);
            --cnt;
        }
    }

    int get_next(int v) {
        v = get_root(v);
        return r[v] + 1;
    }
};

void solve() {
    int n, p; cin >> n >> p;
    Dsu dsu(n);
    ll ans = 0;

    vector<int> a(n); for (int& x : a) cin >> x;
    vector<int> v(n); iota(v.begin(), v.end(), 0);
    sort(v.begin(), v.end(), [&](int l, int r) { return a[l] < a[r]; });
    vector<char> used(n);
    vector<int> lastUse(n, -1);

    for (int i : v) {
        if (a[i] >= p) break;
        if (lastUse[i] == a[i]) continue;

        int l = i, r = i;
        while (l > 0 && a[l-1] % a[i] == 0 && !used[l-1]) --l;
        while (r < n && a[r] % a[i] == 0 && !used[r]) ++r;

        for (int j = l; j < r; ++j) lastUse[j] = a[i];
        
        for (int j = l; j < r; ) {
            int s = dsu.get_next(j);
            if (s >= r) break;

            dsu.unite(j, s);
            ans += a[i];

            j = s;
        }

        used[i] = true;
    }

    ans += (ll) (dsu.cnt - 1) * p;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}