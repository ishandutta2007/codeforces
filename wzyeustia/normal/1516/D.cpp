#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;
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

// FILL by byte!!!
#define FILL(arr, num) memset(arr, num, sizeof(arr))

#define ln printf("\n");

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
const ll MOD = 1e9+7;
ll M(ll n) {return (n % MOD + MOD) % MOD;}
ll pow2(ll n) {return 1ll << n;}

const ll MAXN = 1e5+2;
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

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    sieve(MAXN);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll n, q; cin >> n >> q;
        vl a(n+2); FOR(i, 1, n) cin >> a[i];

        vl last(1e5+1, 0);
        vvl par(1e5+2, vl(21, -1)); 

        ll l = 1;
        FOR(i, 1, n) {
            vl factors = decompose(a[i]);
            // dbg(a[i], factors);
            for (auto fac : factors) {
                while (last[fac] >= l) {
                    par[l++][0] = i;
                }
                last[fac] = i;
            }
        }
        while (l<=n+1) par[l++][0] = n+1;

        // cout << "par[0]:" << endl;
        // FOR(i, 1, n) cout << par[i][0] << " ";
        // cout << endl;

        FOR(pow, 1, 19) FOR(i, 1, n+1) {
            ll nxt = par[i][pow-1];
            par[i][pow] = par[nxt][pow-1];
        }

        // FOR(i, 1, n+1) {
        //     dbg(par[i]);
        // }
        
        REP(kk, q) {
            ll l, r; cin >> l >> r;
            ll ans = 1e9, offset = 0;
            ROF(pow, 19, 0) {
                if (par[l][pow] > r) chkmin(ans, offset + (1ll<<pow));
                else offset+=(1ll<<pow), l = par[l][pow]; 
            }

            dbg(ans);
            cout << ans << endl;
        }
    }
    dbg("finish?");
    return 0;
}