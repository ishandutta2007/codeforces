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

const ll MAXN = 1e7+1;

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

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    sieve(MAXN);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll n; cin >> n;
        vl a(n); REP(i, n) cin >> a[i];

        vl ans1, ans2;
        REP(i, n) {
            ll d1 = 1, d2 = 1;
            for (auto pr : prime) {
                if (sqr(pr) > a[i]) break;
                if (a[i] % pr == 0) {
                    while (a[i] % pr == 0) {
                        d1 *= pr; a[i] /= pr;
                    }
                    d2 = a[i];
                    break;
                }
            }

            if (d1 != 1 && d2 != 1) {
                ans1.eb(d1); ans2.eb(d2);
            } else {
                ans1.eb(-1); ans2.eb(-1);
            }
        }

        dbg(ans1); dbg(ans2);
        for (auto num : ans1) {
            cout << num << " ";
        }ln;
        for (auto num : ans2) {
            cout << num << " ";
        }ln;
    }
    return 0;
}