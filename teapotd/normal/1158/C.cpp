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

vector<Vi> G;
Vi post;
int cnt;

void dfs(int v) {
    if (post[v] != -1) return;
    post[v] = 0;
    each(e, G[v]) dfs(e);
    post[v] = cnt--;
}

void solve() {
    int n; cin >> n;
    Vi nxt(n);

    rep(i, 0, n) {
        cin >> nxt[i];
        if (nxt[i] > 0) nxt[i]--;
    }

    Vi tail;
    G.assign(n, {});

    for (int i = n-1; i >= 0; i--) {
        if (nxt[i] != -1) {
            while (!tail.empty() && tail.back() < nxt[i]) {
                int j = tail.back();
                G[j].pb(i);
                tail.pop_back();
            }
            if (nxt[i] != n) {
                if (tail.empty() || tail.back() != nxt[i]) {
                    cout << "-1\n";
                    return;
                }
                G[i].pb(tail.back());
            }
        }
        tail.pb(i);
    }

    post.assign(n, -1);
    cnt = n;
    rep(i, 0, sz(G)) dfs(i);

    each(k, post) cout << k << ' ';
    cout << '\n';
}

void run() {
    int t; cin >> t;
    while (t--) solve();
}