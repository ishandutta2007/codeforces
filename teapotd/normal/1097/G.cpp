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

constexpr int MOD = 1e9+7;

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
    #define OP(c,d) Zp& operator c##=(Zp r) { x = x d; return *this; } Zp operator c(Zp r) const { Zp t = *this; return t c##= r; }
    OP(+, +r.x - MOD*(x+r.x >= MOD));
    OP(-, -r.x + MOD*(x-r.x < 0));
    OP(*, *r.x % MOD);
    OP(/, *r.inv().x % MOD);
    Zp inv() const { return pow(MOD-2); }
    Zp pow(ll e) const{ return modPow(x,e,MOD); }
    void print() { cerr << x; }
};

constexpr int MAX_N = 2e5+5;

Zp fac[MAX_N], facInv[MAX_N];

int n, k;
vector<Vi> G;
vector<vector<Zp>> dp;
vector<Zp> cnt;
Vi siz;

vector<Zp> conv(const vector<Zp>& A, const vector<Zp>& B) {
    vector<Zp> ret(min(sz(A)+sz(B)-1, k+1));
    rep(i, 0, sz(A)) {
        int lim = min(sz(ret)-i, sz(B));
        rep(j, 0, lim) {
            ret[i+j] += A[i]*B[j];
        }
    }
    return ret;
}

vector<Zp> conv2(vector<Zp> A, vector<Zp> B) {
    rep(i, 0, sz(A)) A[i] *= facInv[i];
    rep(i, 0, sz(B)) B[i] *= facInv[i];
    vector<Zp> ret = conv(A, B);
    rep(i, 0, sz(ret)) ret[i] *= fac[i];
    return ret;
}

void dfs(int v, int p) {
    vector<Zp> kek = {2};
    siz[v] = 1;

    each(e, G[v]) if (e != p) {
        dfs(e, v);
        kek = conv(kek, dp[e]);
        siz[v] += siz[e];
    }

    dp[v] = kek;
    dp[v].insert(dp[v].begin(), 0);
    if (sz(dp[v]) > k+1) dp[v].resize(k+1);
    dp[v][1] -= 1;

    rep(i, 0, sz(dp[v])) {
        cnt[i] -= dp[v][i];
    }

    rep(i, 0, sz(kek)) {
        dp[v][i] += kek[i];
    }
}

void run() {
    fac[0] = facInv[0] = 1;
    rep(i, 1, MAX_N) {
        fac[i] = fac[i-1] * i;
        facInv[i] = fac[i].inv();
    }

    cin >> n >> k;
    G.resize(n);

    rep(i, 1, n) {
        int u, v; cin >> u >> v;
        G[u-1].pb(v-1);
        G[v-1].pb(u-1);
    }

    dp.resize(n);
    siz.resize(n);
    cnt.resize(k+1);

    rep(v, 0, n) {
        if (sz(G[v]) == 1) {
            int e = G[v][0];
            dfs(e, v);
            rep(i, 0, sz(dp[e])) {
                cnt[i] += dp[e][i]*2;
            }
            break;
        }
    }

    Zp ans = 0;
    vector<Zp> ways = {1};
    vector<Zp> xd(k+1, 1);
    xd[0] = 0;

    rep(i, 1, k+1) {
        ways = conv2(ways, xd);
        ans += cnt[i]*ways[k];
    }

    cout << ans.x << '\n';
}