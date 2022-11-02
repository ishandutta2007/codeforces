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

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

vl ori;

// inpersistent segtree
// just do what you want.
#define Node seg[node]
#define LC seg[2*node]
#define RC seg[2*node+1]
const ll SIZE = 1e6+3;

// TODO: segment definition
struct Seg {
  int l, r, mid;
  ll val, lazy = 0;
} seg[SIZE << 2];

void update(int l, int r, ll type, int node);

// TODO: pushdown & pushup process
void pDown(int node) {
    if (Node.lazy && Node.l != Node.r) {
        update(Node.l, Node.mid, Node.lazy, node*2);
        update(Node.mid+1, Node.r, Node.lazy, node*2+1);
        Node.lazy = 0;
    }
}

void pUp(int node) {
    Node.val = max(LC.val, RC.val);
}

void build(int l, int r, int node = 1) {
    Node.l = l, Node.r = r, Node.mid = (l+r)>>1, Node.lazy = 0;
    if (l == r) {
        Node.val = ori[l]; // TODO: init value
    } else {
        build(l, Node.mid, 2*node); build(Node.mid+1, r, 2*node+1);
        pUp(node);
    }
}

void update(int l, int r, ll delta, int node = 1) {
	// if (l > r) return;
    if (l <= Node.l && Node.r <= r) {
        // TODO: update 
        Node.lazy += delta, Node.val += delta;
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
        ll ret = -1e18;
        if (l <= Node.mid) chkmax(ret, query(l, r, 2*node));
        if (r > Node.mid) chkmax(ret, query(l, r, 2*node+1));
        return ret;
    }
}

const ll QUERY = 0, ADD = 1;

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
		ll n, m, p; cin >> n >> m >> p;
		vector<t4l> seq;
		REP(i, n) {
			ll a, ca; cin >> a >> ca;
			seq.eb(a, QUERY, -ca, -1);
		}
		ori = vl(1e6+2, -1e18);
		REP(i, m) {
			ll b, cb; cin >> b >> cb;
			chkmax(ori[b], -cb);
		}
		REP(i, p) {
			ll x, y, z; cin >> x >> y >> z;
			seq.eb(x, ADD, z, y);
		}

		sort(all(seq));
		build(1, 1e6+1);

		ll ans = -1e18;
		for (auto [pos, type, val, from] : seq) {
			dbg(pos, type, val, from);
			if (type == QUERY) {
				chkmax(ans, query(1, 1e6+1) + val);
			} else {
				update(from+1, 1e6+1, val);
			}
		}

		dbg(ans);
		cout << ans << endl;
	}
    return 0;
}