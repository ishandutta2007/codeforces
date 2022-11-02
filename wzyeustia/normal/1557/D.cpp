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
#define lb_pos(arr, key) lower_bound(all(arr), key) - (arr).begin()
#define ub_pos(arr, key) upper_bound(all(arr), key) - (arr).begin()

// FILL by byte!!!
#define FILL(arr, num) memset(arr, num, sizeof(arr))

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

template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using MaxHeap = priority_queue<T>;

const ld PI = 3.14159265358979323846;
const ld E = 2.718281828459;
ll MOD = (1ll << 31) - 1;
ll M(ll n) {return (n % MOD + MOD) % MOD;}
ll pow2(ll n) {return 1ll << n;}

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

// inpersistent segtree
// just do what you want.
#define Node seg[node]
#define LC seg[2*node]
#define RC seg[2*node+1]
const ll SIZE = 6e5+3;

// TODO: segment definition
struct Seg {
  int l, r, mid;
  ll val, lazy = 0, from = 0;
} seg[SIZE << 2];

void update(int l, int r, int type, int from, int node);

// TODO: pushdown & pushup process
void pDown(int node) {
    if (Node.lazy && Node.l != Node.r) {
        update(Node.l, Node.mid, Node.lazy, Node.from, node*2);
        update(Node.mid+1, Node.r, Node.lazy, Node.from, node*2+1);
        Node.lazy = 0;
    }
}

void pUp(int node) {
    if (LC.val >= RC.val) {
        Node.val = LC.val, Node.from = LC.from;
    } else Node.val = RC.val, Node.from = RC.from;
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

void update(int l, int r, int type, int from, int node = 1) {
    if (l <= Node.l && Node.r <= r) {
        // TODO: update 
        Node.val = Node.lazy = type;
        Node.from = from;
    } else {
        pDown(node);
        if (l <= Node.mid) update(l, r, type, from, 2*node); 
        if (r > Node.mid) update(l, r, type, from, 2*node+1);
        pUp(node);
    }
}

pll query(int l, int r, int node = 1) {
    // dbg(Node.l, Node.r, node);
    if (l <= Node.l && Node.r <= r) {
        return {Node.val, Node.from};
    } else {
        pDown(node);
        // TODO: combine 
        ll ret = 0, from = 0;
        if (l <= Node.mid) {
            auto [val, fr] = query(l, r, 2*node);
            if (val > ret) ret = val, from = fr;
        }
        if (r > Node.mid) {
            auto [val, fr] = query(l, r, 2*node+1);
            if (val > ret) ret = val, from = fr;
        }
        return {ret, from};
    }
}

const ll IN = 0, OUT = 1;

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll n, m; cin >> n >> m;
        vector<t3l> seq;
        REP(i, m) {
            ll row, l, r; cin >> row >> l >> r;
            seq.eb(l, row, IN);
            seq.eb(r, row, OUT);
        } sort(all(seq));

        vector<pll> line[n+2];
        ll pos = 0, last = -1;
        for (auto [p, row, type] : seq) {
            if (p != last) pos++;
            line[row].eb(pos, type);
            last = p;
        }

        build(1, pos);

        vl from(n+2, 0);
        FOR(row, 1, n) {
            ll crt = 0, lo = -1, mx = 0;
            for (auto [p, type] : line[row]) {
                if (type == IN) {
                    if (crt == 0) lo = p;
                    crt++;
                } else {
                    crt--;
                    if (crt == 0) {
                        auto [val, fr] = query(lo, p);
                        if (val > mx) mx = val, from[row] = fr;
                    }
                }
            }

            mx++;

            crt = 0, lo = -1;
            for (auto [p, type] : line[row]) {
                if (type == IN) {
                    if (crt == 0) lo = p;
                    crt++;
                } else {
                    crt--;
                    if (crt == 0) update(lo, p, mx, row);
                }
            }
            dbg(row, mx);
        }

        auto [mx, lastRow] = query(1, pos);
        vl keep(n+2, 0);
        while (lastRow) {
            keep[lastRow] = 1, lastRow = from[lastRow];
        }

        cout << n - mx << endl;
        FOR(i, 1, n) if (!keep[i]) cout << i << " ";
        cout << endl;
        
    }
    return 0;
}