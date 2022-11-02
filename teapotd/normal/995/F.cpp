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

constexpr ll MOD = 1e9+7;

ll modInv(ll a, ll m) {
    if (a == 1) return 1;
    return ((a - modInv(m%a, a))*m + 1) / a;
}

ll umod(ll a, ll m) {
    a %= m; return (a >= 0 ? a : a+m);
}

struct Zp {
    ll x;
    Zp(ll y = 0) {
        x = (y < 0 || y >= MOD ? umod(y, MOD) : y);
    }

    Zp operator+(Zp r) const { return x+r.x; }
    Zp operator-(Zp r) const { return x-r.x; }
    Zp operator*(Zp r) const { return x*r.x; }
    Zp operator/(Zp r) const {
        return x * modInv(r.x, MOD);
    }

    Zp inv() const { return modInv(x, MOD); }

    Zp pow(ll e) const {
        if (!e) return 1;
        Zp t = pow(e/2);
        return t*t * (e & 1 ? x : 1);
    }

    void print(...) { cerr << x; }

    Zp& operator+=(Zp r){ return *this=*this+r; }
    Zp& operator-=(Zp r){ return *this=*this-r; }
    Zp& operator*=(Zp r){ return *this=*this*r; }
    Zp& operator/=(Zp r){ return *this=*this/r; }
    Zp  operator-() const { return -x; }
};

template<class T>
T polyExtend(vector<T>& vec, T x) {
    int n = sz(vec);
    vector<T> fac(n, 1), suf(n, 1);

    rep(i, 1, n) fac[i] = fac[i-1] * i;
    for (int i=n; --i;) suf[i-1] = suf[i]*(x-i);

    T pref = 1, ret = 0;
    rep(i, 0, n) {
        T d = fac[i] * fac[n-i-1] * ((n-i)%2*2-1);
        ret += vec[i] * suf[i] * pref / d;
        pref *= x-i;
    }
    return ret;
}

// ---

int n, D;
vector<Vi> tree;
vector<vector<Zp>> atMost;

void dfs(int i) {
    each(e, tree[i]) {
        dfs(e);
        rep(j, 0, n+1) atMost[i][j] *= atMost[e][j];
    }
    rep(j, 1, n+1) atMost[i][j] += atMost[i][j-1];
}

void run() {
    cin >> n >> D;
    tree.resize(n);
    atMost.assign(n, vector<Zp>(n+1, 1));

    rep(i, 1, n) {
        int j; cin >> j;
        tree[j-1].pb(i);
    }

    dfs(0);
    cout << polyExtend(atMost[0], Zp(D-1)).x << endl;
}