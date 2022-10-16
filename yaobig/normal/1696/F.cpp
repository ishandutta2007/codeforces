#include "bits/stdc++.h"
#define rep(i, a, n) for (auto i = a; i <= (n); i++)
#define revrep(i, a, n) for (auto i = n; i >= (a); i--)
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
    
    int cas; cin >> cas; while (cas--) {
        int n; cin >> n;
        vector<vector<string>> str(n, vector<string>(n));
        rep(i, 0, n - 1) rep(j, i + 1, n - 1) {
            cin >> str[i][j];
            str[j][i] = str[i][j];
        }

        int found = 0;
        vector<pii> ans;
        auto check = [&](int x, int y) {
            vector<pii> ed{{x, y}};
            vi vis(n);
            vis[x] = vis[y] = 1;
            queue<pii> que;
            que.push({x, y});
            que.push({y, x});
            while (sz(que)) {
                auto [a, b] = que.front(); que.pop();
                rep(i, 0, n - 1) if (vis[i] == 0 && str[a][i][b] == '1') {
                    vis[i] = 1;
                    que.push({b, i});
                    ed.emplace_back(b, i);
                }
            }
            if (sz(ed) != n - 1) return 0;
            vvi d(n, vi(n, inf));
            rep(i, 0, n - 1) d[i][i] = 0;
            for (auto [x, y]: ed) d[x][y] = d[y][x] = 1;
            rep(k, 0, n - 1) rep(i, 0, n - 1) rep(j, 0, n - 1) chmin(d[i][j], d[i][k] + d[k][j]);
            
            int ok = 1;
            rep(i, 0, n - 1) rep(j, i + 1, n - 1) rep(k, 0, n - 1) {
                if (str[i][j][k] - '0' != (d[i][k] == d[j][k])) ok = 0;
            }
            if (ok) ans = ed;
            return ok;
        };
        rep(i, 1, n - 1) if (found == 0) {
            if (check(0, i)) found = 1;
        }
        if (found == 0) puts("No");
        else {
            puts("Yes");
            for (auto [x, y]: ans) printf("%d %d\n", x + 1, y + 1);
        }
    }
    return 0;
}