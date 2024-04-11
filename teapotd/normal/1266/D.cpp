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

vector<vector<Pii>> in, out;

void run() {
    int n, m; cin >> n >> m;
    in.resize(n);
    out.resize(n);

    rep(i, 0, m) {
        int a, b, c; cin >> a >> b >> c;
        a--; b--;
        out[a].pb({b, c});
        in[b].pb({a, c});
    }

    vector<pair<ll, int>> left, right;

    rep(i, 0, n) {
        ll tmp = 0;
        each(e, in[i]) tmp += e.y;
        each(e, out[i]) tmp -= e.y;

        if (tmp > 0) {
            right.pb({tmp, i});
        } else {
            left.pb({-tmp, i});
        }
    }

    vector<pair<Pii, ll>> ans;

    each(p, left) {
        while (p.x > 0) {
            while (right.back().x == 0) right.pop_back();
            ll val = min(p.x, right.back().x);
            ans.pb({{p.y, right.back().y}, val});
            p.x -= val;
            right.back().x -= val;
        }
    }

    cout << sz(ans) << '\n';
    each(e, ans) cout << e.x.x+1 << ' ' << e.x.y+1 << ' ' << e.y << '\n';
}