#include "bits/stdc++.h"
#define rep(i, a, n) for (auto i = a; i <= (n); ++i)
#define revrep(i, a, n) for (auto i = n; i >= (a); --i)
#define all(a) a.begin(), a.end()
#define sz(a) (int)(a).size()
template<class T> inline bool chmax(T &a, T b) { if(a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, T b) { if(b < a) { a = b; return 1; } return 0; }
using namespace std;

template<class A, class B> string to_string(pair<A, B> p);
string to_string(const string &s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string) s); }
string to_string(char c) { return "'" + string(1, c) + "'"; }
string to_string(bool x) { return x ? "true" : "false"; }
template<class A> string to_string(A v) {
    bool first = 1;
    string res = "{";
    for (const auto &x: v) {
        if (!first) res += ", ";
        first = 0;
        res += to_string(x);
    }
    res += "}";
    return res;
}
template<class A, class B> string to_string(pair<A, B> p) { return "(" + to_string(p.FI) + ", " + to_string(p.SE) + ")"; }

void debug_out() { cerr << endl; }
template<class Head, class... Tail> void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}
#ifndef ONLINE_JUDGE
    #define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
    #define debug(...) if(0) puts("No effect.")
#endif

using ll = long long;
// using LL = __int128;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using db = double;

template<class T> struct TPoint {
    using P = TPoint;
    static constexpr T eps = static_cast<T>(1e-9);

    T x, y;
    P operator -(P a) const { return P{x - a.x, y - a.y}; }
    T cross(P b) const { return x * b.y - y * b.x; }
};
using T = ll;
using P = TPoint<T>;


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n; cin >> n;
    vi as(n);
    rep(i, 0, n - 1) cin >> as[i];

    vector<ll> ps(n + 1);
    rep(i, 0, n - 1) ps[i + 1] = ps[i] + as[i];
    vector<P> que{P{-1, 0}};
    rep(i, 0, n - 1) {
        P p{i, ps[i + 1]};
        while (sz(que) >= 2 && (p - que.end()[-1]).cross(que.end()[-1] - que.end()[-2]) >= -P::eps) que.pop_back();
        que.push_back(p);
    }
    auto bins = [&](P p) {
        int l = 0, r = sz(que) - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (p.cross(que[mid + 1] - que[mid]) >= -P::eps) r = mid;
            else l = mid + 1;
        }
        return l;
    };
    ll ans = 0;
    rep(i, 0, n - 1) {
        P p{1, as[i]};
        int ind = bins(p), j = que[ind].x;
        chmax(ans, 1ll * (j - i) * as[i] - (ps[j + 1] - ps[i + 1]));
    }
    rep(i, 0, n - 1) ans += 1ll * as[i] * (i + 1);
    printf("%lld\n", ans);
    return 0;
}