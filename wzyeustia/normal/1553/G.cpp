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
ll MOD = 998'244'353;
ll M(ll n) {return (n % MOD + MOD) % MOD;}
ll pow2(ll n) {return 1ll << n;}

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

const ll MAXN = 1e6+3;
vl prime;
bool is_composite[MAXN];
void sieve (ll n) {
	std::fill (is_composite, is_composite + n, false);
	for (ll i = 2; i < n; ++i) {
		if (!is_composite[i]) prime.push_back (i);
		for (ll j = 0; j < prime.size () && i * prime[j] < n; ++j) {
			is_composite[i * prime[j]] = true;
			if (i % prime[j] == 0) break;
		}
	}
}

vl decompose(ll num) {
    vl ret;
    for (auto pr : prime) {
        if (sqr(pr) > num) break;
        if (num%pr == 0) {
            ret.eb(pr);
            while (num%pr==0) num/=pr;
        }
    }
    if (num>1) ret.eb(num);

    return ret;
}

vl F;
ll find(ll k) {
    return F[k] == k? k : F[k] = find(F[k]);
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    sieve(MAXN);

    int T = 1;
    // cin >> T;
    REP(I, T) {
		ll n, q; cin >> n >> q;
        vl a(n); REP(i, n) cin >> a[i];
        vl idx(n); REP(i, n) idx[i] = MAXN+i;

        F = vl(MAXN + n + 2); REP(i, MAXN + n + 2) F[i] = i;

        REP(i, n) {
            vl fac = decompose(a[i]);
            for (auto pr : fac) {
                F[find(pr)] = find(idx[i]);
            }
        }


        set<pll> se;
        REP(i, n) {
            vl fac = decompose(a[i]+1);
            ll f0 = find(idx[i]);

            ll k = fac.size();
            REP(p1, k-1) FOR(p2, p1+1, k-1) {
                ll f1 = find(fac[p1]), f2 = find(fac[p2]);
                
                if (f1 > f2) swap(f1, f2);
                if (f1 != f2) se.em(f1, f2); 
            }

            for (auto pr : fac) {
                ll f1 = find(pr);
                if (f0 != f1) {
                    if (f0<f1) se.em(f0, f1);
                    else se.em(f1, f0);
                }
            }
        }

        for (auto [c1, c2] : se) {
            dbg(c1, c2);
        }

        vl ans(q, 2);
        REP(i, q) {
            ll s, t; cin >> s >> t;
            s--; t--;

            ll cc1 = find(idx[s]), cc2 = find(idx[t]);
            if (cc1 > cc2) swap(cc1, cc2);
            dbg(cc1, cc2);

            if (cc1 == cc2) ans[i] = 0;
            else if (se.count(mp(cc1, cc2)) ) ans[i] = 1;
        
            cout << ans[i] << endl;
        }

        dbg(ans);
    }
    return 0;
}