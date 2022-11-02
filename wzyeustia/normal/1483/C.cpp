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
#define em emplace
#define mp make_pair
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

#define FILL0(arr) memset(arr, 0, sizeof(arr))

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
#define err(...)
#endif
// end

template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using MaxHeap = priority_queue<T>;

const ld PI = 3.14159265358979323846;
const ld E = 2.718281828459;

const ll MOD = 998'244'353;
ll M(ll n) {return (n % MOD + MOD) % MOD;}

#define Node seg[node]
#define LC seg[2*node]
#define RC seg[2*node+1]
const ll SIZE = 3e5+3;

// TODO: segment definition
struct Seg {
  int l, r, mid;
  ll val, lazy;
} seg[SIZE*8];

void update(int l, int r, ll type, int node);

// TODO: pushdown & pushup process
void pDown(int node) {
    if (Node.lazy != -1e18 && Node.l != Node.r) {
        update(Node.l, Node.mid, Node.lazy, node*2);
        update(Node.mid+1, Node.r, Node.lazy, node*2+1);
        Node.lazy = -1e18;
    }
}

void pUp(int node) {
    Node.val = max(LC.val, RC.val);
}

void build(int l, int r, int node = 1) {
    Node.l = l, Node.r = r, Node.mid = (l+r)>>1, Node.lazy = -1e18;
    if (l == r) {
        if (l == 1) Node.val = 0;
        else Node.val = -1e18; // TODO: init value
    } else {
        build(l, Node.mid, 2*node); build(Node.mid+1, r, 2*node+1);
        pUp(node);
    }
}

void update(int l, int r, ll val, int node = 1) {
    if (l <= Node.l && Node.r <= r) {
        // TODO: update 
        chkmax(Node.lazy, val);
        chkmax(Node.val, val);
    } else {
        pDown(node);
        if (l <= Node.mid) update(l, r, val, 2*node); 
        if (r > Node.mid) update(l, r, val, 2*node+1);
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
        ll ret = -1e18;
        if (l <= Node.mid) chkmax(ret, query(l, r, 2*node));
        if (r > Node.mid) chkmax(ret, query(l, r, 2*node+1));
        return ret;
    }
}

void status(ll n) {
    cout << "Status: ";
    FOR(i, 2, n+1) {
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
        vl h(n+3), b(n+3);
        FOR(i, 2, n+1) cin >> h[i];
        FOR(i, 2, n+1) cin >> b[i];

        vl pre(n+3), nxt(n+3);
        h[1] = -1e18, h[n+2] = -1e18;
        stack<pll> st;
        FOR(i, 1, n+2) {
            while (!st.empty() && st.top().second > h[i]) st.pop();
            if (!st.empty()) pre[i] = st.top().first;
            st.em(i, h[i]);
        }

        while (!st.empty()) st.pop();
        ROF(i, n+2, 1) {
            while (!st.empty() && st.top().second > h[i]) st.pop();
            if (!st.empty()) nxt[i] = st.top().first;
            st.em(i, h[i]);
        }

        dbg(pre); dbg(nxt);

        // dp[i]: already used ith number 
        build(1, n+2);
        
        FOR(i, 2, n+1) {
            ll mx = query(pre[i], i-1);
            ll newVal = mx + b[i];
            dbg(pre[i], i-1, newVal);
            update(i, nxt[i]-1, mx + b[i]);

            dbg(i, nxt[i]-1);

            // status(n);
        }

        // status(n);
        ll ans = query(n+1, n+1);
        dbg(ans);

        cout << ans << endl;
    }
    return 0;
}