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
    cout << fixed << setprecision(12);
    run();
    cout << flush; _Exit(0);
}

constexpr ll MOD = 1e9+7;

ll modInv(ll a, ll m) {
    if (a == 1) return 1;
    return ((a - modInv(m%a, a))*m + 1) / a;
}

ll modPow(ll a, ll e, ll m) {
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
    #define OP(c,d) Zp& operator c##=(Zp r) { \
            x = x d; return *this; } \
        Zp operator c(Zp r) const { \
            Zp t = *this; return t c##= r; }
    OP(+, +r.x - MOD*(x+r.x >= MOD));
    OP(-, -r.x + MOD*(0 > x-r.x));
    OP(*, *r.x % MOD);
    OP(/, *r.inv().x % MOD);
    Zp operator-() const { return Zp(0)-*this; }
    Zp inv() const { return pow(MOD-2); }
    Zp pow(ll e) const{ return modPow(x,e,MOD); }
    void print() { cerr << x; }
};

vector<ll> seq, longestDiff;
vector<pair<ll, vector<ll>>> pos;

bool contains(ll b, ll e, ll val) {
    auto vec = lower_bound(all(pos), val, [](const pair<ll, vector<ll>>& l, ll r) { return l.x < r; });
    if (vec == pos.end() || vec->x != val) return 0;
    auto it = lower_bound(all(vec->y), b);
    return it != vec->y.end() && *it < e;
}

bool pairwiseDiff(ll b, ll e) {
    return longestDiff[b] >= e;
}

void run() {
    ll n, q; cin >> n >> q;
    seq.resize(n);
    each(e, seq) cin >> e;

    map<ll, vector<ll>> pos2;
    rep(i, 0, n) pos2[seq[i]].pb(i);
    pos = {all(pos2)};

    map<ll, ll> nxt;
    longestDiff.resize(n+1, n);

    for (ll i = n-1; i >= 0; i--) {
        if (nxt.count(seq[i])) {
            longestDiff[i] = min(longestDiff[i+1], nxt[seq[i]]);
        } else {
            longestDiff[i] = longestDiff[i+1];
        }
        nxt[seq[i]] = i;
    }

    while (q--) {
        ll begin, end, d;
        cin >> begin >> end >> d;
        begin--;

        bool ans;

        if (pairwiseDiff(begin, end)) {
            ll cnt;
            if (contains(begin, end, 0) && contains(begin, end, MOD-d)) {
                ll start, finish;

                {
                    ll b = MOD-n-5, e = MOD;
                    while (b+1 < e) {
                        ll m = (b+e-1) / 2;
                        if (contains(begin, end, ll(ll(m)*d % MOD))) {
                            e = m+1;
                        } else {
                            b = m+1;
                        }
                    }
                    start = b;
                }

                {
                    ll b = 0, e = MOD+n+5;
                    while (b+1 < e) {
                        ll m = (b+e) / 2;
                        if (contains(begin, end, ll(ll(m)*d % MOD))) {
                            b = m;
                        } else {
                            e = m;
                        }
                    }
                    finish = b+1;
                }

                cnt = finish + MOD-start;
            } else {
                ll inside = ll((Zp(d).inv() * seq[begin]).x);
                ll start, finish;

                {
                    ll b = max(0ll, inside-n-5), e = inside+1;
                    while (b+1 < e) {
                        ll m = (b+e-1) / 2;
                        if (contains(begin, end, ll(ll(m)*d % MOD))) {
                            e = m+1;
                        } else {
                            b = m+1;
                        }
                    }
                    start = b;
                }

                {
                    ll b = inside, e = min(MOD, inside+n+5);
                    while (b+1 < e) {
                        ll m = (b+e) / 2;
                        if (contains(begin, end, ll(ll(m)*d % MOD))) {
                            b = m;
                        } else {
                            e = m;
                        }
                    }
                    finish = b+1;
                }

                cnt = finish - start;
            }
            ans = (cnt == end-begin);
        } else {
            ans = 0;
        }

        cout << (ans ? "Yes\n" : "No\n");
    }
}