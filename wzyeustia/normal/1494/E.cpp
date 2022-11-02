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

ll myH(ll x, ll y) {
    return x * 1e8+y;
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll n, m; cin >> n >> m;

        map<ll, char> edges;
        set<pll> same, diff;
        REP(i, m) {
            char type; cin >> type;
            if (type == '+') {
                ll u, v; char c; cin >> u >> v >> c;
                if (edges[myH(v, u)] == c) {
                    same.emplace(u, v);
                } else if (edges[myH(v, u)] != '\0') {
                    diff.emplace(u, v);
                }
                edges[myH(u, v)] = c;
            }
            if (type == '-') {
                ll u, v; cin >> u >> v;
                if (edges[myH(v, u)] == edges[myH(u, v)]) {
                    same.erase(make_pair(u, v));
                    same.erase(make_pair(v, u));
                } else if (edges[myH(v, u)] != '\0') {
                    diff.erase(make_pair(u, v));
                    diff.erase(make_pair(v, u));
                }
                edges[myH(u, v)] = '\0';
            }

            if (type == '?') {
                ll k; cin >> k;
                if (same.size() > 0 || (diff.size() > 0 && k%2!=0)) {
                    cout << "YES" << endl;
                } else {
                    cout << "NO" << endl;
                }
            }
        }
    }
    return 0;
}