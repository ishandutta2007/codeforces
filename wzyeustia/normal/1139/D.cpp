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
ll MOD = 1e9+7;
ll M(ll n) {return (n % MOD + MOD) % MOD;}
ll pow2(ll n) {return 1ll << n;}

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

ll getInv(ll a, ll p) {
    return (a == 1 ? 1 : (1 - p * getInv(p % a, a)) / a + p);
}

const ll MAXN = 2e5+1;
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

    sieve(MAXN);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll m; cin >> m;
        vl dp(m+2, 0);
        vvl fac(m+2);
        for (auto pr : prime) FOR(i, 1, m/pr) {
            fac[pr*i].eb(pr);
        }

        FOR(i, 2, m) {
            ll sz = fac[i].size(), msk = 1 << sz;
            vl cnt(msk, 0), val(msk, 0);
            REP(mask, msk) {
                ll crt = 1, odd = 0;
                REP(p, sz) if (mask & (1<<p)) crt*=fac[i][p], odd++;
                cnt[mask] = m / crt;
                val[mask] = crt;
            } 

            REP(p, sz) {
                ll bit = 1<<p;
                REP(mask, msk) if (mask & bit) {
                    cnt[mask^bit] -= cnt[mask];
                }
            }
            dbg(cnt);

            ll sum = 0;
            REP(mask, msk-1) sum = (sum + cnt[mask] * dp[val[mask]])%MOD;
            sum = (sum + m)%MOD;

            dp[i] = sum * getInv(m - cnt[msk-1], MOD)%MOD;
        }

        dbg(dp);

        ll ans = 0;
        FOR(i, 1, m) ans = (ans + dp[i])%MOD;
        ans = ans * getInv(m, MOD);
        ans = (ans + 1)%MOD;
        cout << ans << endl;
    }   
    return 0;
}