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

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    REP(I, T) {
        ll n, m; cin >> n >> m;
        vector<string> graph(n);
        REP(i, n) cin >> graph[i];

        ll GONE = 1;
        if (n%3==1) GONE = 0;

        bool connected = true;
        REP(i, n) {
            if (i%3==GONE) {
                if (!connected) graph[i-1][0] = graph[i-2][0] = 'X';
                REP(j, m) graph[i][j] = 'X';
                connected = false;
                if (i+3 >= n) connected = true;
            } else {
                int pos;
                if (i%3==1+GONE) pos = i+1;
                else pos = i-1;

                dbg(i, pos);
                REP(j, m) {
                    if (connected) break;
                    auto& crt = graph[i][j];
                    auto& adj = graph[pos][j];
                    
                    if (crt != adj) {
                        connected = true;
                        crt = adj = 'X';
                    }
                }
            } 
        }

        REP(i, n) {
            cout << graph[i] << endl;
        }
    }
    return 0;
}