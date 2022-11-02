#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;
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
const ll MOD = 1e9+7;
ll M(ll n) {return (n % MOD + MOD) % MOD;}
ll pow2(ll n) {return 1ll << n;}

#define Node seg[node]
#define LC seg[2*node]
#define RC seg[2*node+1]
const ll SIZE = 2e5+3;

vl pre;

// TODO: segment definition
struct Seg {
  int l, r, mid;
  ll val, lazy = 0;
} seg[SIZE*8];

void update(int l, int r, ll amt, int node);

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

void build(int l, int r, int node = 1) {
    Node.l = l, Node.r = r, Node.mid = (l+r)>>1, Node.lazy = 0;
    if (l == r) {
        Node.val = pre[l]; // TODO: init value
    } else {
        build(l, Node.mid, 2*node); build(Node.mid+1, r, 2*node+1);
        pUp(node);
    }
}

void update(int l, int r, ll amt, int node = 1) {
    if (l <= Node.l && Node.r <= r) {
        // TODO: update 
        Node.lazy += amt;
        Node.val += amt;
    } else {
        pDown(node);
        if (l <= Node.mid) update(l, r, amt, 2*node); 
        if (r > Node.mid) update(l, r, amt, 2*node+1);
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
        ll ret1 = 1e10, ret2 = 1e10;
        if (l <= Node.mid) ret1 = query(l, r, 2*node);
        if (r > Node.mid) ret2 = query(l, r, 2*node+1);
        return min(ret1, ret2);
    }
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

        map<ll, ll> pos;
        vl p(n+2); FOR(i, 1, n) {cin >> p[i]; pos[p[i]] = i;}
        vl a(n+2); FOR(i, 1, n) cin >> a[i];
        pre = vl(n+2, 0);
        FOR(i, 1, n) pre[i] = pre[i-1] + a[pos[i]];
        dbg(pre);

        build(1, n); 
        // status(n);

        ll tot = 0, ans = 1e10;
        FOR(i, 1, n-1) {
            tot += a[i];
            if (p[i]-1>0) update(1, p[i]-1, a[i]);
            update(p[i], n, -a[i]);

            chkmin(ans, min(query(1, n), tot) );
            // chkmin(ans, pre[n]-tot);
            // status(n);
            dbg(ans, tot);
        }

        dbg(ans);
        cout << ans << endl;
    }
    return 0;
}