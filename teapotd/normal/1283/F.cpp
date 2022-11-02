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
vector<bool> seen;

bool dfs(int v) {
    if (seen[v]) return 0;
    seen[v] = 1;
    each(e, G[v]) if (!dfs(e)) return 0;
    return 1;
}

void nope() {
    cout << -1 << endl;
    exit(0);
}

void run() {
    int n; cin >> n;
    Vi code(n-1);

    each(k, code) {
        cin >> k;
        k--;
    }

    reverse(all(code));

    Vi cnt(n);
    each(v, code) cnt[v]++;

    Vi par(n, -1), imp(n);
    iota(all(imp), 0);

    priority_queue<Pii, vector<Pii>, greater<Pii>> que; // imp, root
    rep(i, 0, n) if (cnt[i] == 0) que.push({imp[i], i});

    each(root, code) {
        if (que.empty()) nope();

        Pii top = que.top();
        que.pop();

        par[top.y] = root;
        imp[root] = max(imp[root], top.x);

        if (--cnt[root] == 0) {
            que.push({imp[root], root});
        }
    }

    if (count(all(par), -1) != 1) {
        nope();
    }

    int root = -1;
    G.resize(n);
    seen.resize(n);

    rep(i, 0, n) {
        if (par[i] == -1) {
            root = i;
        } else {
            G[par[i]].pb(i);
        }
    }

    if (!dfs(root) || count(all(seen), 1) != n) {
        nope();
    }

    cout << root+1 << '\n';
    rep(i, 0, n) each(e, G[i]) cout << i+1 << ' ' << e+1 << '\n';
}