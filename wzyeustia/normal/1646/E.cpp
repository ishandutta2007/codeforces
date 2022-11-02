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
ll MOD = 998'244'353;
// ll M(ll n) {return (n % MOD + MOD) % MOD;}
ll pow2(ll n) {return 1ll << n;}

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

const ll MAXN = 1e6+3;
vl prime;
bool comp[MAXN];
void sieve (ll n) {
	// std::fill (comp, comp + n, false);
	for (ll i = 2; i < n; ++i) {
		if (!comp[i]) prime.push_back (i);
		for  (auto pr : prime) {
            if (i * pr >= n) break;
			comp[i * pr] = true;
			if (i % pr == 0) break;
		}
	}
}


int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);      
    cin.tie(nullptr);

    const ll LG = 23;
    sieve(MAXN);

    int T = 1;
    // cin >> T;
    REP(I, T) {
		ll n, m; cin >> n >> m;
        vl used(m * LG + 2, 0), earn(LG+2, 0);
        FOR(i, 1, LG) {
            FOR(j, 1, m) if (!used[i*j]) earn[i]++;
            FOR(j, 1, m) used[i*j] = 1;
        }
        dbg(earn);

        vl type(n+2, 0);
        for (auto pr : prime) {
            FOR(i, 1, n/pr) {
                ll crt = i, cnt = 1;
                while (crt % pr == 0) cnt++, crt/=pr;
                // if (type[i*pr] == 0) type[i*pr] = cnt;
                dbg(i*pr, cnt);
                type[i*pr] = __gcd(type[i*pr], cnt);
            }
        }
        dbg(type);

        ll ans = 1;
        FOR(i, 2, n) ans += earn[type[i]];
        cout << ans << endl;
    }   
    return 0;
}