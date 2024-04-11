#include <bits/stdc++.h>

#define F first
#define S second

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;

template<class T> bool ckmin(T& a, T b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, T b) { return a < b ? a = b, true : false; }

template<class T> using pq_min = priority_queue<T, vector<T>, greater<T>>;
template<class T> using pq_max = priority_queue<T, vector<T>, less<T>>;

const ll LINF = 1e18;
const int INF = 1e9+7;

struct SegmentTree {
    int n;
    vector<ll> tmax, tadd;

    SegmentTree(int n) : n(n), tmax(4*n), tadd(4*n) { }

    void add(int v, int vl, int vr, int l, int r, ll x) {
        if (l <= vl && vr <= r) {
            tmax[v] += x;
            tadd[v] += x;
        } else if (vl < r && l < vr) {
            int vm = (vl + vr) / 2;
            add(2*v, vl, vm, l, r, x);
            add(2*v+1, vm, vr, l, r, x);
            tmax[v] = ::max(tmax[2*v], tmax[2*v+1]) + tadd[v];
        }
    }

    void add(int l, int r, ll x) {
        return add(1, 0, n, l, r, x);
    }

    ll max(int v, int vl, int vr, int l, int r) {
        if (l <= vl && vr <= r) return tmax[v];
        if (r <= vl || vr <= l) return -LINF;
        int vm = (vl + vr) / 2;
        return ::max(max(2*v, vl, vm, l, r), max(2*v+1, vm, vr, l, r)) + tadd[v];
    }

    ll max(int l, int r) {
        return max(1, 0, n, l, r);
    }
};

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    vector<ll> dp(n+1);
    SegmentTree sgt(n+1);

    vector<pair<pi, int>> mx { { {-1, 0}, INF } };
    vector<pair<pi, int>> mn { { {-1, 0}, -INF } };

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        while (mx.back().S < a[i]) {
            auto [l, r] = mx.back().F;
            sgt.add(l, r, -mx.back().S);
            mx.pop_back();
        }

        sgt.add(mx.back().F.S, i+1, +a[i]);
        mx.emplace_back( pi { mx.back().F.S, i+1 }, a[i] );

        while (mn.back().S > a[i]) {
            auto [l, r] = mn.back().F;
            sgt.add(l, r, +mn.back().S);
            mn.pop_back();
        }

        sgt.add(mn.back().F.S, i+1, -a[i]);
        mn.emplace_back( pi { mn.back().F.S, i+1 }, a[i] );

        dp[i+1] = sgt.max(0, i+1);
        sgt.add(i+1, i+2, dp[i+1]);
    }

    cout << dp[n] << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    // cin >> t; 
    while(t--) solve();
}