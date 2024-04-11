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
    cout << flush; _Exit(0);
}

vector<Vi> G;
Vi st, dp;

bool dfs(int v) {
    if (st[v]) return (st[v] != 1);
    st[v] = 1;
    each(e, G[v]) {
        if (!dfs(e)) return 0;
        dp[v] = max(dp[v], dp[e] + (e > v));
    }
    st[v] = 2;
    return 1;
}

void run() {
    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        G.assign(n, {});

        rep(i, 0, n) {
            int k; cin >> k;
            while (k--) {
                int j; cin >> j;
                G[i].pb(j-1);
            }
        }

        bool ok = 1;
        st.assign(n, 0);
        dp.assign(n, 0);

        rep(i, 0, n) if (!dfs(i)) {
            ok = 0;
            break;
        }

        cout << (ok ? *max_element(all(dp))+1 : -1) << '\n';
    }
}