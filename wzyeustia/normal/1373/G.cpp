#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;
typedef vector<ll> vl;
typedef vector<vl> vvl;

#define FOR(i, a, b) for (ll (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (ll (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

#define Node seg[node]
#define LC seg[2*node]
#define RC seg[2*node+1]

#define ln cout << endl;

// Can I use this?
#ifndef ONLINE_JUDGE
#define dbg(x...) do { cout << "\033[32;1m " << #x << " -> "; err(x); } while (0)
void err() { cout << "\033[39;0m" << endl; }
template<template<typename...> class T, typename t, typename... A>
void err(T<t> a, A... x) { for (auto v: a) cout << v << ' '; err(x...); }
template<typename T, typename... A>
void err(T a, A... x) { cout << a << ' '; err(x...); }
#else
#define dbg(...)
#endif
// end

template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using MaxHeap = priority_queue<T>;

const ld PI = 3.14159265358979323846;
const ld E = 2.718281828459;
const ll MOD = 998'244'353;
ll myMod(ll n) {return (n % MOD + MOD) % MOD;} 

ll n, m; 
const ll SIZE = 2e5+3;

struct Seg {
  int l, r, mid;
  int val, lazy = 0;
} seg[SIZE*8];

void pDown(ll node) {
    if (Node.lazy && Node.l != Node.r) {
        LC.lazy += Node.lazy; RC.lazy += Node.lazy;
        LC.val += Node.lazy; RC.val += Node.lazy;
        Node.lazy = 0;
    }
}

void pUp(ll node) {
    Node.val = max(LC.val, RC.val);
}

void build(ll l, ll r, ll node) {
    Node.l = l, Node.r = r, Node.mid = (l+r)/2;
    if (l == r) {
        Node.val = l-n-1;
    } else {
        ll mid = (l+r)>>1;
        build(l, mid, 2*node); build(mid+1, r, 2*node+1);
        pUp(node);
    }
}

void update(ll l, ll r, ll k, ll node = 1) {
    if (l <= Node.l && Node.r <= r) {
        Node.lazy += k; Node.val += k;
    } else {
        pDown(node);
        if (l <= Node.mid) update(l, r, k, 2*node); 
        if (r > Node.mid) update(l, r, k, 2*node+1);
        pUp(node);
    }
}

ll query(ll l, ll r, ll node = 1) {
    if (l <= Node.l && Node.r <= r) {
        return Node.val;
    } else {
        pDown(node);
        ll ret = LLONG_MIN;
        if (l <= Node.mid) chkmax(ret, query(l, r, 2*node));
        if (r > Node.mid) chkmax(ret, query(l, r, 2*node+1));
        // pUp(node);
        return ret;
    }
}

ll myH(ll x, ll y) {
    return x * 1e8 + y;
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll k; cin >> n >> k >> m;
        build(1, 2*n, 1);

        set<ll> s;
        multiset<ll> ms;
        ms.emplace(n+1);

        REP(i, m) {
            ll x, y; cin >> x >> y;
            ll pos = abs(x-k) + y;
            if (!s.count(myH(x, y))) {
                s.emplace(myH(x, y)); ms.emplace(pos);
                update(1, pos, 1);
            } else {
                s.erase(myH(x, y)); ms.erase(ms.find(pos));
                update(1, pos, -1);
            }

            ll maxpos = *(ms.rbegin());
            ll ans = query(1, maxpos);
            dbg(ans);
            cout << max(ans, 0ll) << endl;
        }
    }
    return 0;
}