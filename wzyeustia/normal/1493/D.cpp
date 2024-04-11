#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;
typedef vector<ll> vl;
typedef vector<vl> vvl;

#define FOR(i, a, b) for (ll (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (ll (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define em emplace
#define mp make_pair
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

#define ln cout << endl;

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
#endif
// end

template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using MaxHeap = priority_queue<T>;

const ld PI = 3.14159265358979323846;
const ld E = 2.718281828459;
const ll SIZE = 2e6+3; 

const ll MOD = 1e9+7;
ll myMod(ll n) {return (n % MOD + MOD) % MOD;}

const ll MAXN = 2e5+1;

std::vector <ll> prime;
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

ll n, ans = 1;
vector<set<pll>> factors;
vector<map<ll, ll>> maps;

ll fastPow(ll num, ll exp, ll modNum) {
    if (exp == 0) return 1;
    if (exp == 1) return num;
    else {
        ll half = fastPow(num, exp/2, modNum) % modNum;
        if (exp % 2 == 1) {
            return (((half * half) % modNum) * num) % modNum;
        }
        else {
            return (half * half) % modNum;
        }
    }
}

ll getF(set<pll> &se) {
    if (se.size() != n) return 0;
    return (*se.begin()).first;
}

void add1(ll idx, ll j, ll cnt) {
    auto& se = factors[j];
    auto& val = maps[idx][j];
    dbg(cnt, val);

    ll last = getF(se);
    se.erase(mp(val, idx));
    val += cnt;
    se.em(val, idx);

    ans *= fastPow(prime[j], getF(se)-last, MOD); ans %= MOD;
}

void addX(ll idx, ll num) {
    REP(j, prime.size()) {
        ll pr = prime[j]; if (sqr(pr) > num) break;
        ll cnt = 0; while (num%pr == 0) {cnt++; num/=pr;}

        if (cnt) add1(idx, j, cnt);
    }
    
    ll pos = lower_bound(all(prime), num) - prime.begin();
    if (num > 1) add1(idx, pos, 1);

    dbg(ans);
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    sieve(MAXN);
    factors = vector<set<pll>>(prime.size());
    maps = vector<map<ll, ll>>(2e5+3);
 
    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll q; cin >> n >> q;
        FOR(i, 1, n) {
            ll num; cin >> num;
            addX(i, num);
        }

        REP(i, q) {
            ll idx, num; cin >> idx >> num;
            addX(idx, num);
            cout << ans%MOD << endl;
        }
    }
    return 0;
}