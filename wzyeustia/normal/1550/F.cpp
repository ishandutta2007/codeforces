#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
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

vl F;
ll find(ll k) {
    return F[k] == k? k : F[k] = find(F[k]);
}

vl rock, idx;

set<ll> se;
t3l search(ll u, ll p) {
	ll x, y, w = 1e9;
	auto it = se.lower_bound(p);
	if (it != se.end() && (*it)-p < w) {
		x = idx[u], y = idx[*it], w = (*it)-p;
	} 
	if (it != se.begin()) {
		it--;
		if (p-(*it) < w) x = idx[u], y = idx[*it], w = p-(*it);
	}
	return {x, y, w};
}

vector<pll> G[200'002];

vl dist;
void dfs(ll u, ll par) {
	for (auto [v, w] : G[u]) {
		if (v == par) continue;
		dist[v] = max(dist[u], w);
		dfs(v, u);
	}
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
		ll n, q, s, d; cin >> n >> q >> s >> d;
		rock = vl(n+2), idx = vl(1e6+2); FOR(i, 1, n) {
			cin >> rock[i];
			idx[rock[i]] = i, se.em(rock[i]);
		}

		F = vl(n+2); FOR(i, 1, n) F[i] = i;
		ll cnt = n;
		while (cnt > 1) {
			vl mem[n+1]; FOR(i, 1, n) mem[find(i)].eb(rock[i]);
			FOR(cc, 1, n) {
				ll x, y, w = 1e9;
				for (auto u : mem[cc]) se.erase(u);
				for (auto u : mem[cc]) {
					auto [x1, y1, w1] = search(u, u+d);
					auto [x2, y2, w2] = search(u, u-d);
					
					if (w1 < w) x = x1, y = y1, w = w1;
					if (w2 < w) x = x2, y = y2, w = w2;
				}
				for (auto u : mem[cc]) se.em(u);

				if (find(x) != find(y)) {
					dbg(x, y, w);
					cnt--;
					G[x].eb(y, w), G[y].eb(x, w);
					F[find(x)] = find(y);
				}
			}
		}

		dist = vl(n+2, -1); dist[s] = 0;
		dfs(s, 0);
		
		REP(tt, q) {
			ll t, k; cin >> t >> k;
			if (dist[t] <= k) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
	}
    return 0;
}