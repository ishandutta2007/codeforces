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

const ll IN = 0, OUT = 1;

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    REP(I, T) {
        ll n; cin >> n;
        vector<tll> seq;
        FOR(i, 1, n) {
            ll x, y; cin >> x >> y;
            seq.eb(x, IN, i);
            seq.eb(y, OUT, i);
        }
        sort(all(seq));

        set<ll> segs;
        vl earn(n+2, 0);
        ll dec = 0, tot = 0, single = 0;
        for (auto [pos, type, idx] : seq) {
            dbg(pos, type, idx);
            if (segs.size()==1 && dec == OUT && type == IN) earn[*segs.begin()]++;
            if (segs.empty() && type == IN) tot++;
            if (segs.size()==1 && type == OUT) single++;
            
            dec = type; 
            if (type == IN) segs.em(idx); 
            else segs.erase(idx);

            dbg(earn);

            // last = pos;
        }

        ll mx = 0;
        FOR(i, 1, n) chkmax(mx, earn[i]);

        dbg(tot, mx, single);
        if (mx > 0) cout << tot+mx << endl;
        else if (single < n) cout << tot << endl;
        else cout << tot-1 << endl;
    }
    return 0;
}