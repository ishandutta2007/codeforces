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

template<class T> void fwt(vector<T> &a, int is_inv) {
    int N = sz(a);
    for (int s = 1; s < N; s <<= 1)
        for (int i = 0; i < N; i += s << 1)
            rep(j, 0, s - 1) {
                T x = a[i + j], y = a[i + j + s];
                a[i + j] = x + y; 
                a[i + j + s] = x - y;
            }
 
    if (is_inv) {
        for(auto &x: a) x = x / N;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n, m; cin >> n >> m;
    vector<string> str(n);
    for (auto &s: str) cin >> s;
    
    int N = 1 << n;
    vector<ll> popc(N), cnt(N);
    rep(i, 0, N - 1) popc[i] = min(__builtin_popcount(i), n - __builtin_popcount(i));
    rep(i, 0, m - 1) {
        int x = 0;
        rep(j, 0, n - 1) x |= int(str[j][i] - '0') << j;
        cnt[x]++;
    }

    fwt(popc, 0);
    fwt(cnt, 0);
    vector<ll> res(N);
    rep(i, 0, N - 1) res[i] = popc[i] * cnt[i];
    fwt(res, 1);
    ll ans = *min_element(all(res));
    printf("%lld\n", ans);
    return 0;
}