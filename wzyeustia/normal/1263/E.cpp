#include <bits/stdc++.h>

using namespace std;

typedef int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
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
ll MOD = 1e9+7;
ll M(ll n) {return (n % MOD + MOD) % MOD;}
ll pow2(ll n) {return 1ll << n;}

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

// inpersistent segtree
// just do what you want.
#define Node seg[node]
#define LC seg[2*node]
#define RC seg[2*node+1]
const ll SIZE = 1e6+8;

// TODO: segment definition
struct Seg {
  int l, r, mid;
  ll hi, lo, lazy = 0;
} seg[SIZE << 3];

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
    Node.hi = max(LC.hi, RC.hi);
	Node.lo = min(LC.lo, RC.lo);
}

void build(int l, int r, int node = 1) {
    Node.l = l, Node.r = r, Node.mid = (l+r)>>1, Node.lazy = 0;
    if (l == r) {
        Node.hi = Node.lo = 0; // TODO: init value
    } else {
        build(l, Node.mid, 2*node); build(Node.mid+1, r, 2*node+1);
        pUp(node);
    }
}

void update(int l, int r, int delta, int node = 1) {
    if (l <= Node.l && Node.r <= r) {
        // TODO: update 
		Node.hi += delta, Node.lo += delta, Node.lazy += delta;
    } else {
        pDown(node);
        if (l <= Node.mid) update(l, r, delta, 2*node); 
        if (r > Node.mid) update(l, r, delta, 2*node+1);
        pUp(node);
    }
}

ll query(int l, int r, bool hi, int node = 1) {
    // dbg(Node.l, Node.r, node);
    if (l <= Node.l && Node.r <= r) {
		if (hi) return Node.hi;
        else return Node.lo;
    } else {
        pDown(node);
        // TODO: combine 
        ll ret = -1e8; if (!hi) ret = 1e8;
        if (l <= Node.mid) {
			if (hi) chkmax(ret, query(l, r, hi, 2*node));
			else chkmin(ret, query(l, r, hi, 2*node));
		}
		if (r > Node.mid) {
			if (hi) chkmax(ret, query(l, r, hi, 2*node+1));
			else chkmin(ret, query(l, r, hi, 2*node+1));
		}
		return ret;
    }
}

ll rgt;
void go(char ch, ll l) {
	dbg(ch, l, rgt);
	if (ch == '(') update(l, rgt, 1);
	else update(l, rgt, -1);
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
		ll n; cin >> n;
		string s; cin >> s;
		// dbg(s);

		rgt = n+2;
		vector<char> seq(n+5, 'a');
		build(1, rgt);

		vl ans(n+2, -1);
		ll cur = 1;
		REP(i, n) {
			if (s[i] == 'L' && cur > 1) cur--;
			if (s[i] == 'R') cur++;

			if (s[i] != 'L' && s[i] != 'R') {
				if (seq[cur] == '(') go(')', cur);
				if (seq[cur] == ')') go('(', cur);
				seq[cur] = s[i];
			}
			if (s[i] == '(' || s[i] == ')') {
				go(s[i], cur);
			}

			// dbg(query(rgt, rgt, 1));

			if (query(rgt, rgt, 1) == 0 && query(1, rgt, 0) == 0) ans[i] = query(1, rgt, 1);
		}

		dbg(ans);
		REP(i, n) cout << ans[i] << " "; cout << endl;
	}
    return 0;
}