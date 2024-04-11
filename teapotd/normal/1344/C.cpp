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

vector<Vi> in, out;
Vi seen, small, small2;

void dfs2(int v) {
    if (seen[v]) return;
    seen[v] = 1;
    small[v] = min(small[v], v);
    each(e, out[v]) {
        dfs2(e);
        small[v] = min(small[v], small[e]);
    }
}

void dfs(int v) {
    if (seen[v]) {
        if (seen[v] == 1) {
            cout << "-1" << endl;
            exit(0);
        }
        return;
    }
    seen[v] = 1;
    each(e, out[v]) dfs(e);
    seen[v] = 2;
}

void run() {
    int n, m;
    cin >> n >> m;

    in.resize(n);
    out.resize(n);

    rep(i, 0, m) {
        int j, k; cin >> j >> k;
        j--; k--;
        out[j].pb(k);
        in[k].pb(j);
    }

    seen.resize(n);
    rep(i, 0, n) {
        if (!seen[i]) {
            dfs(i);
        }
    }

    small.resize(n, 2e9);
    small2.resize(n, 2e9);

    rep(j, 0, 2) {
        seen.assign(n, 0);
        rep(i, 0, n) {
            if (!seen[i]) {
                dfs2(i);
            }
        }
        in.swap(out);
        small.swap(small2);
    }

    string ans;
    rep(i, 0, n) {
        ans.pb(small[i] == i && small2[i] == i ? 'A' : 'E');
    }

    cout << count(all(ans), 'A') << '\n';
    cout << ans << '\n';
}