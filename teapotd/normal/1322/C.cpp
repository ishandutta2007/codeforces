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

using ull = unsigned long long;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

void solve() {
    int n, m; cin >> n >> m;

    vector<ll> elems(n);
    each(e, elems) cin >> e;

    vector<ull> group(n), ghash(n);
    each(k, ghash) k = rnd();

    rep(i, 0, m) {
        int u, v; cin >> u >> v;
        u--; v--;
        group[v] ^= ghash[u];
    }

    vector<pair<ull, ll>> parts(n);
    rep(i, 0, n) parts[i] = {group[i], elems[i]};
    sort(all(parts));

    ll ans = 0;

    rep(i, 0, n) {
        if (i > 0 && parts[i].x == parts[i-1].x) {
            continue;
        }

        ll sum = 0;

        rep(j, i, n) {
            if (parts[i].x != parts[j].x) break;
            sum += parts[j].y;
        }

        if (parts[i].x != 0) {
            ans = gcd(ans, sum);
        }
    }

    cout << ans << '\n';
}

void run() {
    int t; cin >> t;
    while (t--) solve();
}