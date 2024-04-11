#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> t3l;
typedef tuple<ll, ll, ll, ll> t4l;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

#define FOR(i, a, b) for (ll (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (ll (i) = (a); (i) >= (b); (i)--)
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
ll MOD = 998'244'353;
ll M(ll n) {return (n % MOD + MOD) % MOD;}
ll pow2(ll n) {return 1ll << n;}

vvl G1, G2;

vl dfn, rgt;
ll crt;
void dfs0(ll u) {
    dfn[u] = ++crt;
    for (auto v : G2[u]) {
        dfs0(v);
    }
    rgt[u] = crt;
}

#define Node seg[node]
#define LC seg[2*node]
#define RC seg[2*node+1]
const ll SIZE = 2e5+3;

// TODO: segment definition
struct Seg {
  int l, r, mid;
  ll val, lazy = 0;
} seg[SIZE*8];

void update(int l, int r, int type, int node);

// TODO: pushdown & pushup process
void pDown(int node) {
    if (Node.lazy && Node.l != Node.r) {
        update(Node.l, Node.mid, Node.lazy, node*2);
        update(Node.mid+1, Node.r, Node.lazy, node*2+1);
        Node.lazy = 0;
    }
}

void pUp(int node) {
    // Node.val = LC.val + RC.val;
}

void build(int l, int r, int node = 1) {
    Node.l = l, Node.r = r, Node.mid = (l+r)>>1, Node.lazy = 0;
    if (l == r) {
        Node.val = -1; // TODO: init value
    } else {
        build(l, Node.mid, 2*node); build(Node.mid+1, r, 2*node+1);
        pUp(node);
    }
}

void update(int l, int r, int type, int node = 1) {
    if (l <= Node.l && Node.r <= r) {
        // TODO: update 
        Node.lazy = Node.val = type;
    } else {
        pDown(node);
        if (l <= Node.mid) update(l, r, type, 2*node); 
        if (r > Node.mid) update(l, r, type, 2*node+1);
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
        if (l <= Node.mid) ret = query(l, r, 2*node);
        if (r > Node.mid) ret = query(l, r, 2*node+1);
        return ret;
    }
}

ll n;
void status() {
    cout << "Status: ";
    FOR(i, 1, n) {
        cout << query(i, i) << " ";
    }ln;
}

ll ans;
void dfs1(ll u, ll cnt) {
    ll val = query(dfn[u], dfn[u]);
    if (val != -1 && dfn[val] < dfn[u]) {
        update(dfn[val], rgt[val], -1);
        update(dfn[u], rgt[u], u);
    }
    if (val == -1) {
        update(dfn[u], rgt[u], u);
        cnt++;
    }

    chkmax(ans, cnt);
    // status();

    for (auto v : G1[u]) {
        dfs1(v, cnt);
    }

    if (val == -1) {
        cnt--;
        update(dfn[u], rgt[u], -1);
    }
    if (val != -1 && dfn[val] < dfn[u]) {
        update(dfn[val], rgt[val], val);
    }
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    REP(I, T) {
        cin >> n;
        G1 = vvl(n+2), G2 = vvl(n+2);
        FOR(i, 2, n) {
            ll par; cin >> par;
            G1[par].eb(i);
        }
        FOR(i, 2, n) {
            ll par; cin >> par;
            G2[par].eb(i);
        }

        dfn = vl(n+2), rgt = vl(n+2), crt = 0;
        dfs0(1);
        dbg(dfn); dbg(rgt);

        build(1, n);
        ans = 0;
        dfs1(1, 0);
        dbg(ans);
        cout << ans << endl;
    }
    return 0;
}