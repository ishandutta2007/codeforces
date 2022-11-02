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

constexpr int MOD = 998244353;

ll modPow2(ll a, ll e, ll m) {
    ll t = 1 % m;
    while (e) {
        if (e % 2) t = t*a % m;
        e /= 2; a = a*a % m;
    }
    return t;
}

struct Zp {
    ll x;
    Zp() : x(0) {}
    Zp(ll a) : x(a%MOD) { if (x < 0) x += MOD; }
    #define OP(c,d) Zp& operator c##=(Zp r) { x = x d; return *this; } Zp operator c(Zp r) const { Zp t = *this; return t c##= r; }
    OP(+, +r.x - MOD*(x+r.x >= MOD));
    OP(-, -r.x + MOD*(x-r.x < 0));
    OP(*, *r.x % MOD);
    OP(/, *r.inv().x % MOD);
    Zp inv() const { return pow(MOD-2); }
    Zp pow(ll e) const{ return modPow2(x,e,MOD); }
    void print() { cerr << x; }
};

ll modAdd(ll x, ll y, ll m) {
    x += y;
    return x < m ? x : x-m;
}

ll modSub(ll x, ll y, ll m) {
    x -= y;
    return x >= 0 ? x : x+m;
}

ll modMul(ll a, ll b, ll m) {
    ll c = ll((long double)a * b / m);
    ll r = (a*b - c*m) % m;
    return r < 0 ? r+m : r;
}

ll modPow(ll x, ll e, ll m) {
    ll t = 1;
    while (e) {
        if (e & 1) t = modMul(t, x, m);
        e >>= 1;
        x = modMul(x, x, m);
    }
    return t;
}

constexpr ll BASES[] = {
    2,325,9375,28178,450775,9780504,1795265022
};

bool isPrime(ll p) {
    if (p == 2) return true;
    if (p <= 1 || p%2 == 0) return false;

    ll d = p-1, times = 0;
    while (d%2 == 0) d /= 2, times++;

    each(a, BASES) if (a%p) {
        ll b = modPow(a%p, d, p);
        if (b == 1 || b == p-1) continue;

        rep(i, 1, times) {
            b = modMul(b, b, p);
            if (b == p-1) break;
        }

        if (b != p-1) return false;
    }

    return true;
}

using Factor = pair<ll, int>;

void rho(vector<ll>& out, ll n) {
    if (n <= 1) return;
    if (isPrime(n)) out.pb(n);
    else if (n%2 == 0) rho(out,2), rho(out,n/2);
    else for (ll a = 2;; a++) {
        ll x = 2, y = 2, d = 1;
        while (d == 1) {
            x = modAdd(modMul(x, x, n), a, n);
            y = modAdd(modMul(y, y, n), a, n);
            y = modAdd(modMul(y, y, n), a, n);
            d = __gcd(abs(x-y), n);
        }
        if (d != n) {
            rho(out, d);
            rho(out, n/d);
            return;
        }
    }
}

vector<Factor> factorize(ll n) {
    vector<Factor> ret;
    vector<ll> raw;
    rho(raw, n);
    sort(all(raw));
    each(f, raw) {
        if (ret.empty() || ret.back().x != f)
            ret.pb({ f, 1 });
        else
            ret.back().y++;
    }
    return ret;
}

ll D;
vector<Factor> factors;
vector<Zp> factorial, invFactorial;

Zp choose(int n, int k) {
    return factorial[n] * invFactorial[k] * invFactorial[n-k];
}

Vi facFast(ll n) {
    Vi ret;
    each(f, factors) {
        int cnt = 0;
        while (n%f.x == 0) {
            n /= f.x;
            cnt++;
        }
        ret.pb(cnt);
    }
    return ret;
}

ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

Zp get(ll u, ll v) {
    Vi fac1 = facFast(u);
    Vi fac2 = facFast(v);

    int seen = 0;
    Zp ways = 1;

    rep(i, 0, sz(fac1)) {
        int k = abs(fac1[i]-fac2[i]);
        seen += k;
        ways *= choose(seen, k);
    }

    return ways;
}

void run() {
    cin >> D;
    factors = factorize(D);
    int t; cin >> t;
    deb(D, factors);

    factorial.resize(1000, 1);
    invFactorial.resize(1000, 1);
    rep(i, 2, sz(factorial)) {
        factorial[i] = factorial[i-1] * i;
        invFactorial[i] = factorial[i].inv();
    }

    while (t--) {
        ll u, v; cin >> u >> v;
        ll lc = gcd(u, v);
        Zp ways = get(u, lc) * get(v, lc);
        cout << ways.x << '\n';
    }
}