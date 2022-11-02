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

vl cnt;
void merge(ll x, ll y) {
	x = find(x), y = find(y);
	if (x == y) return;
	cnt[x] += cnt[y];
	F[y] = x;
}


// learnt from Origenes...
// Implementation trick: create 2 nodes for each subset (not 1)
// one for taking current point, one for not taking
// then adding edge and unioning will be much easier.
int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
		ll n, k; cin >> n >> k;
		string s; cin >> s;
		vl stat(n+2); FOR(i, 1, n) stat[i] = s[i-1] == '1';
		vl l(n+2), r(n+2), tot(n+2);
		REP(subset, k) {
			ll c; cin >> c;
			REP(j, c) {
				ll val; cin >> val;
				if (tot[val]) r[val] = subset*2;
				else l[val] = subset*2;
				++tot[val];
			}
		}
		dbg(tot);

		F = vl(2*k+2); REP(i, 2*k) F[i] = i;
		cnt = vl(2*k+2, 0); REP(i, k) cnt[i*2] = 1;
		ll ans = 0;
		FOR(i, 1, n) {
			if (tot[i] == 2) {
				ll u = find(l[i]), v = find(r[i]);
				ll u1 = find(u^1), v1 = find(v^1);

				if (u != v && u != v1) {
					ans -= min(cnt[u], cnt[u1]) + min(cnt[v], cnt[v1]);
					if (stat[i]) merge(u, v), merge(u1, v1);
					else merge(u, v1), merge(u1, v);
					u = find(u), u1 = find(u1);
					ans += min(cnt[u], cnt[u1]);
				}
				
			}
			if (tot[i] == 1) {
				ll u = find(l[i]), u1 = find(u^1);
				
				ans -= min(cnt[u], cnt[u1]);
				if (stat[i]) cnt[u] += 1e8;
				else cnt[u1] += 1e8;
				ans += min(cnt[u], cnt[u1]);
			}

			cout << ans << endl;
			// dbg(cnt); dbg(F);
		}
	}
    return 0;
}