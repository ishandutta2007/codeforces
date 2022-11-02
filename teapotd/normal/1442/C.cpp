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

constexpr int LEVELS = 21;
constexpr int INF = 1e9;

int n, m;
vector<Vi> G[2];
vector<Pii> dist[LEVELS];

struct Entry {
    int vert, lvl;
    Pii dist;
    bool operator<(const Entry& r) const {
        return dist > r.dist;
    }
};

void run() {
    cin >> n >> m;
    G[0].resize(n);
    G[1].resize(n);

    rep(i, 0, m) {
        int u, v; cin >> u >> v;
        G[0][u-1].pb(v-1);
        G[1][v-1].pb(u-1);
    }

    rep(i, 0, LEVELS) {
        dist[i].resize(n, mp(INF, INF));
    }

    priority_queue<Entry> que;
    dist[0][0] = {0, 0};
    que.push({0, 0, dist[0][0]});

    auto relax = [&](int vert, int lvl, Pii d) {
        if (dist[lvl][vert] > d) {
            dist[lvl][vert] = d;
            que.push({vert, lvl, d});
        }
    };

    Pii best = {-1, -1};

    while (!que.empty()) {
        int vert = que.top().vert;
        int lvl = que.top().lvl;
        Pii d = que.top().dist;
        que.pop();

        if (vert == n-1) {
            best = d;
            break;
        }

        each(e, G[lvl%2][vert]) {
            relax(e, lvl, {d.x, d.y+1});
        }

        if (lvl < LEVELS-2) {
            relax(vert, lvl+1, {d.x, d.y + (1 << lvl)});
        } else {
            int nextLvl = (lvl == LEVELS-2 ? lvl+1 : lvl-1);
            relax(vert, nextLvl, {d.x+1, d.y});
        }
    }

    deb(best);

    Zp ans = best.y;
    ans += Zp(2).pow(best.x+LEVELS-2) - Zp(2).pow(LEVELS-2);

    cout << ans.x << '\n';
}