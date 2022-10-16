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

const int inf = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n, a, b; cin >> n >> a >> b;
    vi hs(n);
    for (auto &x: hs) cin >> x, x++;
    vvi dp(17, vi(17, inf));
    vector<vector<vector<pii>>> ops(17, vector<vector<pii>>(17, vector<pii>{}));

    dp[hs[0]][hs[1]] = 0;
    rep(i, 2, n - 1) {
        int h = hs[i];
        vvi ndp(17, vi(17, inf));
        vector<vector<vector<pii>>> nops(17, vector<vector<pii>>(17, vector<pii>{}));
        rep(x, 0, 16) rep(y, 0, 16) rep(cnt, 0, 16) {
            int nx = max(x - b * cnt, 0);
            int ny = max(y - a * cnt, 0);
            int nh = max(h - b * cnt, 0);
            if (nx == 0 && chmin(ndp[ny][nh], dp[x][y] + cnt)) {
                nops[ny][nh] = ops[x][y];
                nops[ny][nh].emplace_back(i - 1, cnt);
            }
        }
        swap(dp, ndp);
        swap(ops, nops);
    }
    printf("%d\n", dp[0][0]);
    for (auto [id, cnt]: ops[0][0]) rep(i, 1, cnt) printf("%d ", id + 1);
    puts("");
    return 0;
}