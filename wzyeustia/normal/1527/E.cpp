#include <bits/stdc++.h>

using namespace std;

typedef int ll;
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
ll MOD = 1e9+7;
ll M(ll n) {return (n % MOD + MOD) % MOD;}
ll pow2(ll n) {return 1ll << n;}

vvl dp;

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
    Node.val = min(LC.val, RC.val);
}

ll crt;
void build(int l, int r, int node = 1) {
    Node.l = l, Node.r = r, Node.mid = (l+r)>>1, Node.lazy = 0;
    if (l == r) {
        // dbg(crt, l);
        Node.val = dp[crt][l]; // TODO: init value
    } else {
        build(l, Node.mid, 2*node); build(Node.mid+1, r, 2*node+1);
        pUp(node);
    }
}

void update(int l, int r, int delta, int node = 1) {
    if (l <= Node.l && Node.r <= r) {
        // TODO: update 
        Node.lazy += delta;
        Node.val += delta;
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
        ll ret = 1e9;
        if (l <= Node.mid) chkmin(ret, query(l, r, 2*node));
        if (r > Node.mid) chkmin(ret, query(l, r, 2*node+1));
        return ret;
    }
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll n, k; cin >> n >> k;
        vl a(n+2); FOR(i, 1, n) cin >> a[i];
        vl last(n+2), pos(n+2);
        FOR(i, 1, n) {
            last[i] = pos[a[i]];
            pos[a[i]] = i;
        }
        dbg(last);

        dp = vvl(k+2, vl(n+2, 1e9)); dp[1][0] = 0;
        FOR(j, 1, n) {
            dp[1][j] = dp[1][j-1];
            if (last[j]) dp[1][j] += j-last[j];
        } // dbg(dp[1]);

        FOR(i, 2, k) {
            crt = i-1;
            build(1, n);

            // cout << "stat: " << endl;
            // FOR(pp, 1, n) cout << query(pp, pp) << " ";
            // cout << endl;

            FOR(j, 1, n) {
                if (last[j]>1) {
                    update(1, last[j]-1, j-last[j]);
                }
                dp[i][j] = query(1, j);
            }
            dbg(dp[i]);
        }

        cout << dp[k][n] << endl;
    }
    return 0;
}