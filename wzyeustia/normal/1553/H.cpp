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
ll MOD = 1e9+7;
ll M(ll n) {return (n % MOD + MOD) % MOD;}
ll pow2(ll n) {return 1ll << n;}

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

#define Node seg[node]
#define LC seg[Node.lc]
#define RC seg[Node.rc]

struct Seg {
    // bool left;
    int lc = 0, rc = 0;
    int lo = 1e9, hi = -1e9, dep = -1; // dep[root] = 0
    int ans;
} seg[1<<20];

ll n, k;

void modify(ll node) {
    // swap(LC.left, RC.left);
    swap(Node.lc, Node.rc);
}

void calc(ll node) {
    int off = 1<<(k-1 - Node.dep);
    int mid = RC.lo - LC.hi + off;
    Node.ans = min(LC.ans, RC.ans);
    chkmin(Node.ans, mid);

    Node.lo = min(LC.lo, RC.lo + off);
    Node.hi = max(LC.hi, RC.hi + off);

    // dbg(node, Node.lo, Node.hi, Node.ans);
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        cin >> n >> k;
        ll sz = 1<<k;
        vl occ(sz, 0);
        REP(i, n) {
            ll v; cin >> v;
            occ[v] = 1;
        }

        vl cnt(sz, 0);
        REP(bit, k) for (int mask = 0; mask < sz; mask += (1<<bit)) cnt[mask] = k-1-bit;

        FOR(node, 1, 2*sz-1) {
            Node.ans = 1e9, Node.lc = node<<1, Node.rc = Node.lc+1;
            Node.dep = seg[node/2].dep + 1;
        }

        FOR(node, sz, 2*sz-1) {
            ll mask = node - sz;
            if (occ[mask]) Node.lo = Node.hi = 0;
        }

        vl ans(sz, sz);
        ll mask = 0;
        ROF(u, sz-1, 1) calc(u);
        ans[0] = seg[1].ans;


        ROF(i, sz-1, 1) {
            ll d = cnt[i];
            mask ^= (1<<d);

            d = k-1 - d;
            
            FOR(u, 1<<d, (1<<d+1)-1) modify(u);
            ROF(u, (1<<d+1)-1, 1) calc(u);
            ans[mask] = seg[1].ans;

            dbg(mask, ans[mask]);
        }

        dbg(ans);
        REP(i, sz) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}