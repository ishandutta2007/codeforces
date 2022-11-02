#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> t3l;
typedef tuple<ll, ll, ll, ll> t4l;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
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

// FILL by byte!!!
#define FILL(arr, num) memset(arr, num, sizeof(arr))
#define ln cout << endl;

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
ll MOD = 998'244'353;
ll M(ll n) {return (n % MOD + MOD) % MOD;}
ll pow2(ll n) {return 1ll << n;}

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)


int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    const char RED = 'R', WHITE = 'W', EMPTY = '.';

    int T = 1;
    cin >> T;
    REP(I, T) {
        ll n, m; cin >> n >> m;
        char c1 = EMPTY, c2 = EMPTY;

        bool can = true;
        REP(i, n) {
            string s; cin >> s;
            REP(j, m) {
                ll crt = (i+j)&1;
                char val = s[j];
                if (crt) {
                    if (c1 + val == RED+WHITE) can = false;
                    else if (val != EMPTY) c1 = val; 
                } else {
                    if (c2 + val == RED+WHITE) can = false;
                    else if (val != EMPTY) c2 = val;
                }

                dbg(crt, val);
            }
            dbg(c1, c2);
        } 

        dbg(c1, c2);

        if (c1 == c2) {
            if (c1 != EMPTY) can = false;
            else c1 = RED, c2 = WHITE;
        }

        if (!can) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            if (c1 == EMPTY) c1 = RED+WHITE-c2;
            if (c2 == EMPTY) c2 = RED+WHITE-c1;

            REP(i, n) {
                REP(j, m) if ((i+j)&1) {
                    cout << c1;
                } else {
                    cout << c2;
                }
                cout << endl;
            }
        }
    }
    return 0;
}