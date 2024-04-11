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
const ld EPS = 1e-8;
ll MOD = 1e9+7;
ll M(ll n) {return (n % MOD + MOD) % MOD;}
ll pow2(ll n) {return 1ll << n;}

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

string s;

// inpersistent segtree
// just do what you want.
#define Node seg[node]
#define LC seg[2*node]
#define RC seg[2*node+1]
const ll SIZE = 1e6+3;

struct Data {
    ll head, len;
};

Data Merge(Data d1, Data d2) {
    ll t1 = d1.head; if (d1.len%2 == 0) t1 = 1-t1;
    if (d1.len == 0) return d2;
    if (d2.len == 0) return d1;

    if (d2.head == t1) {
        if (d1.len >= d2.len) return {d1.head, d1.len-d2.len};
        else return {1-d1.head, d2.len - d1.len}; 
    } else {
        return {d1.head, d1.len + d2.len};
    }
}

// TODO: segment definition
struct Seg {
  int l, r, mid;
  Data data;
} seg[SIZE << 2];


void update(int l, int r, int type, int node);

// TODO: pushdown & pushup process
void pDown(int node) {
    // if (Node.lazy && Node.l != Node.r) {
    //     update(Node.l, Node.mid, Node.lazy, node*2);
    //     update(Node.mid+1, Node.r, Node.lazy, node*2+1);
    //     Node.lazy = 0;
    // }
}

void pUp(int node) {
    Node.data = Merge(LC.data, RC.data);
}

void build(int l, int r, int node = 1) {
    Node.l = l, Node.r = r, Node.mid = (l+r)>>1;
    if (l == r) {
        Node.data.len = 1;
        Node.data.head = (s[l-1] == '[' || s[l-1] == ']'); // TODO: init value
    } else {
        build(l, Node.mid, 2*node); build(Node.mid+1, r, 2*node+1);
        pUp(node);
    }
}

void update(int l, int r, int type, int node = 1) {
    // if (l <= Node.l && Node.r <= r) {
    //     // TODO: update 
    //     if (type == ZERO) {
    //         Node.lazy = ZERO;
    //         Node.val = 0;}
    //     else {
    //         Node.lazy = ONE;
    //         Node.val = Node.r-Node.l+1;}
    // } else {
    //     pDown(node);
    //     if (l <= Node.mid) update(l, r, type, 2*node); 
    //     if (r > Node.mid) update(l, r, type, 2*node+1);
    //     pUp(node);
    // }
}

Data query(int l, int r, int node = 1) {
    // dbg(Node.l, Node.r, node);
    if (l <= Node.l && Node.r <= r) {
        return Node.data;
    } else {
        pDown(node);
        // TODO: combine 
        Data ret = {0, 0};
        if (l <= Node.mid) ret = Merge(ret, query(l, r, 2*node));
        if (r > Node.mid) ret = Merge(ret, query(l, r, 2*node+1));
        return ret;
    }
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);      
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    REP(I, T) {
        cin >> s;
        ll len = s.size();
        build(1, len);

        ll q; cin >> q;
        REP(i, q) {
            ll l, r; cin >> l >> r;
            Data data = query(l, r);
            dbg(data.head, data.len);

            cout << data.len / 2 << endl;
        }
    }
    return 0;
}