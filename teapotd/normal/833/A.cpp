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

constexpr int MAX_P = 1e6+5;
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

void run() {
    int n; cin >> n;
    sieve();

    rep(i, 0, n) {
        ll a, b; cin >> a >> b;

        ll x = llround(cbrt(a*b));
        bool ok = (x*x*x == a*b);

        if (ok) {
            each(f, factorize(x)) {
                int ca = 0, cb = 0;
                while (a%f.x == 0) a /= f.x, ca++;
                while (b%f.x == 0) b /= f.x, cb++;
                if (ca*2 < cb || (ca*2-cb)%3) ok = 0;
                if (cb*2 < ca || (cb*2-ca)%3) ok = 0;
            }
        }

        cout << (ok ? "Yes\n" : "No\n");
    }
}