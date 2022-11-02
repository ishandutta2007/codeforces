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

std::vector <int> prime;
bool is_composite[MAXN];

void sieve (int n) {
	std::fill (is_composite, is_composite + n, false);
	for (int i = 2; i < n; ++i) {
		if (!is_composite[i]) prime.push_back (i);
		for (int j = 0; j < prime.size () && i * prime[j] < n; ++j) {
			is_composite[i * prime[j]] = true;
			if (i % prime[j] == 0) break;
		}
	}
}


int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    // sieve(MAXN);
    // vector<set<ll>> factors(prime.size());

    int T = 1;
    // cin >> T;
    REP(I, T) {
        // ll n, q; cin >> n >> q;
        // REP(i, n) {
        //     ll num; cin >> num;
        //     for (auto pr : prime) {
        //         ll cnt = 0;
        //         while (num%pr == 0) {
        //             cnt++; num/=pr;
        //         }

        //         set<>
        //     }
        // }

        ll n; cin >> n;
        string l, r; cin >> l >> r;
        ll tot = 0;

        if (l[0] != r[0]) {
            REP(i, n) cout << '1';
            ln;
        } else {
            ll same = 0;
            REP(i, n) if (l[i] == r[i]) same++; else break;
            if (same >= n-1) {
                cout << r << endl;
            } else {
                same++;
                while (l[same] == '1' && r[same] == '0') same++;
                
                if (same <= n-2) r[n-1] = '1';
                cout << r << endl;
            }
        }

    }
    return 0;
}