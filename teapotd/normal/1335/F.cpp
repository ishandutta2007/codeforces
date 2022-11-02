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

Vi nxt, dist, kekB, kekW;
vector<Vi> inv;
vector<bool> black, seen;

void dfs(int v, int d) {
    if (dist[v] != -1) return;
    seen[v] = 1;
    dist[v] = d;
    (black[v] ? kekB : kekW).pb(d);
    each(e, inv[v]) dfs(e, d+1);
}

void solve() {
    int n, m; cin >> n >> m;

    black.resize(n*m);
    rep(i, 0, n) {
        string s; cin >> s;
        rep(j, 0, m) black[i*m+j] = s[j] == '0';
    }

    vector<string> board(n);
    each(s, board) cin >> s;

    nxt.resize(n*m);
    black.resize(n*m);

    rep(i, 0, n) rep(j, 0, m) {
        char c = board[i][j];
        int i2 = i, j2 = j;
        if (c == 'U') i2--;
        else if (c == 'D') i2++;
        else if (c == 'L') j2--;
        else if (c == 'R') j2++;
        nxt[i*m+j] = i2*m+j2;
    }

    inv.assign(n*m, {});
    rep(i, 0, n*m) inv[nxt[i]].pb(i);

    seen.assign(n*m, 0);
    dist.assign(n*m, -1);

    int ans1 = 0, ans2 = 0;

    rep(i, 0, n*m) if (!seen[i]) {
        int j = i;
        while (!seen[j]) seen[j] = 1, j = nxt[j];
        kekB.clear(); kekW.clear();
        dfs(j, 0);

        int mod = dist[nxt[j]]+1;
        Vi cnt(mod);
        each(k, kekW) cnt[k%mod] = 1;
        each(k, kekB) cnt[k%mod] = 2;

        each(c, cnt) {
            if (c == 1) ans1++;
            else if (c == 2) ans1++, ans2++;
        }
    }

    cout << ans1 << ' ' << ans2 << '\n';
}

void run() {
    int t; cin >> t;
    while (t--) solve();
}