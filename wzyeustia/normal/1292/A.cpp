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
ll MOD = 998'244'353;
ll M(ll n) {return (n % MOD + MOD) % MOD;}
ll pow2(ll n) {return 1ll << n;}

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)


int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
		ll n, q; cin >> n >> q;
        vl flip[3][n+2];
        FOR(i, 1, q) {
            ll x, y; cin >> x >> y;
            flip[x][y].eb(i);
        } FOR(i, 1, 2) FOR(j, 1, n) flip[i][j].eb(q+2);

        vl access(q+2, 0);
        FOR(i, 2, n) FOR(j, i-1, min(n-1, i+1ll)) {
            bool c1 = true, c2 = true;
            ll k1 = 0, k2 = 0;
            while (flip[1][i][k1] != flip[2][j][k2]) {
                ll crt = min(flip[1][i][k1], flip[2][j][k2]);
                if (!c1 && !c2) access[crt]++; 

                if (flip[1][i][k1] < flip[2][j][k2]) {
                    c1 = !c1, k1++;
                } else c2 = !c2, k2++;

                if (!c1 && !c2) access[crt]--;
            }
        }

        dbg(access);
        FOR(i, 1, q) {
            access[i] += access[i-1];
            if (access[i] >= 0) {
                cout << "Yes" << endl; 
            } else cout << "No" << endl;
        }
    }
    return 0;
}