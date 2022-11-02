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
#define err(...)
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

ll gcd(ll a, ll b) {
    if (a < b) swap(a, b);
    return (a % b == 0)? b: gcd(b, a%b);
}

pll exStep(ll a, ll b, pll pa) { return {pa.second, pa.first - pa.second*(a/b) };}
pll exgcd(ll a, ll b) { return b ? exStep(a, b, exgcd(b, a%b)) : make_pair(1ll, 0ll); }

vector<tuple<ll, char, ll>> ans;

void doAdd(ll x, ll y) {
    ans.eb(x, '+', y);
}

void doXor(ll x, ll y) {
    ans.eb(x, '^', y);
}

void create(ll base, ll times) {
    ll crt = base;
    while (2*crt <= base * times) {
        doAdd(crt, crt); crt <<= 1;
    }

    ll nxt = (crt >> 1);
    while (nxt >= base) {
        if (crt + nxt <= base * times) {
            doAdd(crt, nxt);
            crt += nxt;
        }
        nxt >>= 1;
    }
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        // After reading tutorial...

        ll x; cin >> x;
        ll step = 0, temp = 1;
        while (2*temp <= x) {
            temp <<= 1, step++;
        }
        ll y = x ^ (x << step);
        
        auto [a, b] = exgcd(x, y);
        
        a = (a%y + y)%y;
        if (a%2 == 0) a += y;
        b = (a*x - 1) / y;
        
        // dbg(a, b, a*x - b*y, a*x ^ b*y);

        create(x, 1ll << step); doXor(x, x << step);
        create(x, a); create(y, b);
        doXor(x*a, y*b);

        ll sz = ans.size();
        cout << sz << endl;
        for (auto [x, ch, y] : ans) {
            cout << x << ' ' << ch << ' ' << y << endl;
        }
    }
    return 0;
}