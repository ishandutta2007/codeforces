#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> t3l;
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
ll MOD = 998'244'353;
ll M(ll n) {return (n % MOD + MOD) % MOD;}
ll pow2(ll n) {return 1ll << n;}

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

string s; 

#define Node seg[node]
#define LC seg[2*node]
#define RC seg[2*node+1]
const ll SIZE = 2e5+3;

// TODO: segment definition
struct Data {
    int a = 0, b = 0, c = 0, ab = 0, bc = 0, abc = 0;
};

struct Seg {
  int l, r, mid;
  Data data;
} seg[SIZE << 2];

Data Merge(Data &d1, Data &d2) {
    Data d0;
    d0.a = d1.a+d2.a, d0.b = d1.b+d2.b, d0.c = d1.c+d2.c;
    d0.ab = min(d1.a+d2.b, min(d1.ab+d2.b, d1.a+d2.ab));
    d0.bc = min(d1.b+d2.c, min(d1.bc+d2.c, d1.b+d2.bc));
    d0.abc = min(d1.a+d2.abc, d1.a+d2.bc);
    chkmin(d0.abc, min(d1.ab+d2.bc, d1.ab+d2.c));
    chkmin(d0.abc, d1.abc+d2.c);
    return d0;
}

void pUp(int node) {
    Node.data = Merge(LC.data, RC.data);
}

void build(int l, int r, int node = 1) {
    Node.l = l, Node.r = r, Node.mid = (l+r)>>1;
    if (l == r) {
        char ch = s[l-1];
        if (ch == 'a') Node.data.a = 1;
        if (ch == 'b') Node.data.b = 1;
        if (ch == 'c') Node.data.c = 1;
    } else {
        build(l, Node.mid, 2*node); build(Node.mid+1, r, 2*node+1);
        pUp(node);
    }
}

void update(int l, int r, char ch, int node = 1) {
    if (l <= Node.l && Node.r <= r) {
        char past = s[l-1];
        if (past == 'a') Node.data.a = 0;
        if (past == 'b') Node.data.b = 0;
        if (past == 'c') Node.data.c = 0;
        s[l-1] = ch;
        if (ch == 'a') Node.data.a = 1;
        if (ch == 'b') Node.data.b = 1;
        if (ch == 'c') Node.data.c = 1;
    } else {
        if (l <= Node.mid) update(l, r, ch, 2*node); 
        if (r > Node.mid) update(l, r, ch, 2*node+1);
        pUp(node);
    }
}


int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);      
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll n, q; cin >> n >> q;
        cin >> s;
        build(1, n);

        REP(i, q) {
            ll pos; char ch; cin >> pos >> ch;
            update(pos, pos, ch);
            ll ans = seg[1].data.abc;
            dbg(ans);
            cout << ans << endl;
        }
    }
    return 0;
}