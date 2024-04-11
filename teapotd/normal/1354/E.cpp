#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#ifdef LOC
#include "debuglib.h"
#else
#define deb(...)
#define DBP(...)
#endif
using namespace std;
using   ll         = long long;
using   Vi         = vector<int>;
using   Pii        = pair<int, int>;
#define pb           push_back
#define mp           make_pair
#define x            first
#define y            second
#define rep(i, b, e) for (int i = (b); i < (e); i++)
#define each(a, x)   for (auto& a : (x))
#define all(x)       (x).begin(), (x).end()
#define sz(x)        int((x).size())

int uplg(int n) { return 32-__builtin_clz(n); }
int uplg(ll n)  { return 64-__builtin_clzll(n); }
void run();

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cout << fixed << setprecision(18);
    run();
    return 0;
}

int dp[5005][5005]; // prefix, cnt -> last

vector<Vi> G, parts[2];
Vi col;

void nope() {
    cout << "NO" << endl;
    exit(0);
}

void dfs(int v, int c) {
    if (col[v] != -1) {
        if (col[v] != c) nope();
        return;
    }
    col[v] = c;
    parts[c].back().pb(v);
    each(e, G[v]) dfs(e, !c);
}

void run() {
    int n, m; cin >> n >> m;
    int n1, n2, n3; cin >> n1 >> n2 >> n3;
    G.resize(n);

    rep(i, 0, m) {
        int u, v; cin >> u >> v;
        u--; v--;
        G[u].pb(v);
        G[v].pb(u);
    }

    col.resize(n, -1);

    rep(i, 0, n) {
        if (col[i] == -1) {
            parts[0].emplace_back();
            parts[1].emplace_back();
            dfs(i, 0);
        }
    }

    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;

    rep(len, 1, sz(parts[0])+1) {
        int zero = sz(parts[0][len-1]);
        int one = sz(parts[1][len-1]);
        rep(cnt, 0, n2+1) {
            if (cnt >= zero && dp[len-1][cnt-zero] != -1) {
                dp[len][cnt] = 0;
            } else if (cnt >= one && dp[len-1][cnt-one] != -1) {
                dp[len][cnt] = 1;
            }
        }
    }

    int len = sz(parts[0]);
    int cnt = n2;
    if (dp[len][cnt] == -1) nope();

    string ans(n, '3');

    while (len > 0) {
        auto& vec = parts[dp[len][cnt]][len-1];
        each(k, vec) ans[k] = '2';
        cnt -= sz(vec);
        len--;
    }

    each(c, ans) {
        if (c == '3' && n1 > 0) {
            c = '1';
            n1--;
        }
    }

    cout << "YES\n";
    cout << ans << '\n';
}