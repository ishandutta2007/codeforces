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

constexpr int MAX_P = 2e5 + 50;
Vi factor(MAX_P+1);

void sieve() {
    for (int i = 2; i*i <= MAX_P; i++)
        if (!factor[i])
            for (int j = i*i; j <= MAX_P; j += i)
                if (!factor[j])
                    factor[j] = i;

    rep(i,0,MAX_P+1) if (!factor[i]) factor[i]=i;
}

vector<Pii> factorize(ll n) {
    vector<Pii> ret;
    while (n > 1) {
        int f = factor[n];
        if (ret.empty() || ret.back().x != f)
            ret.pb({ f, 1 });
        else
            ret.back().y++;
        n /= f;
    }
    return ret;
}

ll po(ll a, ll b) {
    ll r = 1;
    rep(i, 0, b) r *= a;
    return r;
}

void run() {
    int n; cin >> n;
    Vi elems(n);
    each(e, elems) cin >> e;

    vector<Vi> kek(MAX_P+1);
    sieve();

    each(e, elems) {
        each(f, factorize(e)) {
            kek[f.x].pb(f.y);
        }
    }

    ll ans = 1;

    rep(p, 2, MAX_P+1) {
        auto& vec = kek[p];
        sort(all(vec));

        int d = n - sz(vec);

        if (d == 0) {
            ans *= po(p, vec[1]);
        } else if (d == 1) {
            ans *= po(p, vec[0]);
        }
    }

    cout << ans << endl;
}