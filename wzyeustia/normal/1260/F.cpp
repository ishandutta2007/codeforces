#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll, ll, ll> t3l;
typedef tuple<ll, ll, ll, ll> t4l;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define ef emplace_front
#define em emplace
#define mp make_pair
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
#define _1 first
#define _2 second

// FILL by byte!!!
#define FILL(arr, num) memset(arr, num, sizeof(arr))
#define ln cout << endl;

#ifndef ONLINE_JUDGE
#define dbg(x...) do { cout << "\033[32;1m " << #x << " -> "; err(x); } while (0)
void err() { cout << "\033[39;0m" << endl; }
template<template<typename...> class T, typename t, typename... A>
void err(T<t> a, A... x) { for (auto v: a) cout << v << ' '; err(x...); }
template<typename T, typename... A>
void err(T a, A... x) { cout << a << ' '; err(x...); }
#else
#define dbg(...)
#define err(...)
#endif
// end

template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using MaxHeap = priority_queue<T>;

const ld PI = 3.14159265358979323846;
const ld E = 2.718281828459;
ll MOD = 1e9+7;
ll M(ll n) {return (n % MOD + MOD) % MOD;}
ll pow2(ll n) {return 1ll << n;}

mt19937_64 rng((unsigned ll) chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<ll>(a, b)(rng)

ll getInv(ll a, ll p) {
 return (a == 1 ? 1 : (1 - p * getInv(p % a, a)) / a + p);
}

const ll MX = 1e5+2;
const ll IN = 0, OUT = 1;

vvl G;

const ll maxn = MX;

// precalculated value in O(N)
int top[maxn], son[maxn], // top: 1st node of current heavy link. son: heavy son 
    dep[maxn], fa[maxn], siz[maxn], // just what you think.
    dfn[maxn], rnk[maxn], // dfn(rnk(x)) = x, dfn goes to heavy son first.
    cnt;
void dfs1(int u, int par) {
    son[u] = -1, siz[u] = 1;
    for (auto v : G[u]) if (v != par) {
        dep[v] = dep[u] + 1, fa[v] = u;
        dfs1(v, u);
        siz[u] += siz[v];
        if (son[u] == -1 || siz[v] > siz[son[u]]) son[u] = v;
    }
}
void dfs2(int u, int t) {
    top[u] = t, dfn[u] = ++cnt, rnk[cnt] = u;
    if (son[u] == -1) return;
    dfs2(son[u], t); // heavy son first
    // then other sons
    for (auto v : G[u]) if (v != son[u] && v != fa[u])
        dfs2(v, v);
}

// inpersistent segtree
// just do what you want.
#define Node seg[node]
#define LC seg[2*node]
#define RC seg[2*node+1]
const ll SIZE = 2e5+3;

// TODO: segment definition
struct Seg {
  int l, r, mid;
  ll val, lazy = 0;
} seg[SIZE << 2];

void update(int l, int r, ll delta, int node);

// TODO: pushdown & pushup process
void pDown(int node) {
    if (Node.lazy && Node.l != Node.r) {
        update(Node.l, Node.mid, Node.lazy, node*2);
        update(Node.mid+1, Node.r, Node.lazy, node*2+1);
        Node.lazy = 0;
    }
}

void pUp(int node) {
    Node.val = (LC.val + RC.val)%MOD;
}

void build(int l, int r, int node = 1) {
    Node.l = l, Node.r = r, Node.mid = (l+r)>>1, Node.lazy = 0;
    if (l == r) {
        Node.val = 0; // TODO: init value
    } else {
        build(l, Node.mid, 2*node); build(Node.mid+1, r, 2*node+1);
        pUp(node);
    }
}

void update(int l, int r, ll delta, int node = 1) {
    if (l <= Node.l && Node.r <= r) {
        ll sz = Node.r-Node.l+1;
        Node.val = (Node.val + delta*sz)%MOD;
        Node.lazy = (Node.lazy + delta)%MOD;
    } else {
        pDown(node);
        if (l <= Node.mid) update(l, r, delta, 2*node); 
        if (r > Node.mid) update(l, r, delta, 2*node+1);
        pUp(node);
    }
}

ll query(int l, int r, int node = 1) {
    // dbg(Node.l, Node.r, node);
    if (l <= Node.l && Node.r <= r) {
        return Node.val;
    } else {
        pDown(node);
        // TODO: combine 
        ll ret = 0;
        if (l <= Node.mid) ret += query(l, r, 2*node);
        if (r > Node.mid) ret += query(l, r, 2*node+1);
        return ret%MOD;
    }
}

void modify(int u, ll val) {
    while (u) {
        update(dfn[top[u]], dfn[u], val);
        u = fa[top[u]];
    }
}
ll calc(int u) {
    ll ret = MOD - query(1, 1);
    while (u) {
        // dbg(dfn[top[u]], dfn[u]);
        ret = (ret + query(dfn[top[u]], dfn[u]) )%MOD;
        u = fa[top[u]];
    }
    return ret;
}

void status(ll n) {
    cout << "Status: ";
    FOR(i, 1, n) {
        cout << query(i, i) << " ";
    }ln;
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    
    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll n; cin >> n;

        ll tot = 1;
        vector<vector<pll>> ops(MX);
        vl w(n+1);
        FOR(i, 1, n) {
            ll l, r; cin >> l >> r;
            tot = (tot * (r-l+1))%MOD;
            w[i] = getInv(r-l+1, MOD);
            ops[l].eb(i, IN), ops[r+1].eb(i, OUT);
        }
        G = vvl(n+2);
        REP(i, n-1) {
            ll u, v; cin >> u >> v;
            G[u].eb(v), G[v].eb(u);
        }

        // dbg(w);

        dep[1] = 0, cnt = 0; dfs1(1, 0); // wtf??? need to be packed.
        dfs2(1, 1);
        build(1, n);

        ll TMP = 1e5;
        ll ans = 0, crt = 0, d1 = 0, d2 = 0, offset = 0;
        FOR(col, 1, TMP) {
            for (auto [u, type] : ops[col]) {
                ll k1 = w[u]*dep[u]%MOD;
                if (type == IN) {
                    d1 = (d1 + k1)%MOD, d2 = (d2 + w[u])%MOD;
                    offset = (offset + k1*w[u])%MOD;

                    ll delta = 2*w[u]*calc(u) %MOD;
                    crt = (crt + delta)%MOD;
                    modify(u, w[u]);
                }
                else {
                    d1 = (d1 + MOD-k1)%MOD, d2 = (d2 + MOD-w[u])%MOD;
                    offset = (offset + MOD-k1*w[u]%MOD)%MOD;

                    modify(u, MOD-w[u]);
                    ll delta = 2*w[u]*calc(u) %MOD;
                    crt = (crt + MOD-delta)%MOD;
                }
                // dbg(d1, d2);
                
                // dbg(u, type, crt);
                // status(4);
            } ans = (ans + d1*d2%MOD + MOD-crt + MOD-offset)%MOD;
            // dbg(earn, crt);
        }

        ans = (ans * tot)%MOD;
        cout << ans << endl;
    }
    return 0;
}