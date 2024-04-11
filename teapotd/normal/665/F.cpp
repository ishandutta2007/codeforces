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

constexpr int MAX_P = 1e7;
vector<ll> pis, prl;

void initPi() {
    pis.assign(MAX_P+1, 1);
    pis[0] = pis[1] = 0;

    for (int i = 2; i*i <= MAX_P; i++)
        if (pis[i])
            for (int j = i*i; j <= MAX_P; j += i)
                pis[j] = 0;

    rep(i, 1, sz(pis)) {
        if (pis[i]) prl.pb(i);
        pis[i] += pis[i-1];
    }
}

ll partial(ll x, ll a) {
    static vector<unordered_map<ll, ll>> big;
    big.resize(sz(prl));
    if (!a) return (x+1) / 2;
    if (big[a].count(x)) return big[a][x];
    ll ret = partial(x, a-1) - partial(x / prl[a], a-1);
    return big[a][x] = ret;
}

ll pi(ll x) {
    static unordered_map<ll, ll> big;
    if (x < sz(pis)) return pis[x];
    if (big.count(x)) return big[x];

    ll a = 0;
    while (prl[a]*prl[a]*prl[a]*prl[a] < x) a++;

    ll ret = 0, b = --a;

    while (++b < sz(prl) && prl[b]*prl[b] < x) {
        ll w = x / prl[b];
        ret -= pi(w);
        for (ll j = b; prl[j]*prl[j] <= w; j++)
            ret -= pi(w / prl[j]) - j;
    }

    ret += partial(x, a) + (b+a-1)*(b-a)/2;
    return big[x] = ret;
}

void run() {
    initPi();
    ll n; cin >> n;

    ll ans = 0;
    each(p, prl) {
        if (ll(p)*p*p > n) break;
        ans++;
    }

    rep(i, 0, sz(prl)) {
        ll p = prl[i];
        if (p*p > n) break;
        ans += pi(n/p) - i - 1;
    }

    cout << ans << '\n';
}