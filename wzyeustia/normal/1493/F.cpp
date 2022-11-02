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

const ll MAXN = 1001;

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

ll ans = 1, qCnt = 0;
bool rev = false;

bool query(int h, int w, int x1, int y1, int x2, int y2) {
    qCnt++;
    if (rev) printf("? %d %d %d %d %d %d\n", w, h, y1, x1, y2, x2);
    else printf("? %d %d %d %d %d %d\n", h, w, x1, y1, x2, y2);
    fflush(stdout);
    bool ret; cin >> ret;
    return ret;
}

void decode(ll n, ll m) {
    ll haveSame = 0; 

    ll cnt = 1;
    while (n%2 == 0) {
        dbg(n, 2);
        bool result = query(n/2, m, 1, 1, 1+n/2, 1);
        if (result) {cnt++; n /= 2;}
        else break;
    } ans *= cnt;

    for (auto pr : prime) {
        if (pr == 2) continue; if (pr > n) break;

        ll cnt = 1;
        while (n%pr == 0) {
            dbg(n, pr);
            ll single = n/pr;
            ll len = single * (pr-1)/2;

            if (!haveSame) {
                bool result1 = query(len, m, 1, 1, 1+len, 1);
                bool result2 = query(len, m, 1, 1, 1+len+single, 1);

                if (result1 && result2) {
                    haveSame = single+1; cnt++; n/=pr;
                } else break;

            } else {
                ll longer = len + single;
                bool result = query(longer, m, 1, 1, haveSame + len, 1);
                if (result) {
                    cnt++; n/=pr;
                } else break;
            }
        }
        ans *= cnt;
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
        ll n, m; cin >> n >> m;
        rev = false; decode(n, m); 
        rev = true; decode(m, n);
        dbg(ans);
        cout << "! " << ans << endl;
        ll limit = 3*floor(log2(n+m));
        dbg(qCnt, limit);
    }
    return 0;
}