#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> t3l;
typedef tuple<ll, ll, ll, ll> t4l;
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
#define _1 first
#define _2 second
#define lb_pos(arr, key) lower_bound(all(arr), key) - (arr).begin()
#define ub_pos(arr, key) upper_bound(all(arr), key) - (arr).begin()

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
const ld EPS = 1e-8;
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
        ll n; cin >> n;
        ll dist[n+2][n+2]; FILL(dist, 0x3f);
        string s[n]; REP(i, n) cin >> s[i];

        REP(i, n) REP(j, n) if (s[i][j] == '1') {
            dist[i+1][j+1] = 1;
        }
        FOR(i, 1, n) dist[i][i] = 0;

        FOR(k, 1, n) FOR(i, 1, n) FOR(j, 1, n) {
            chkmin(dist[i][j], dist[i][k] + dist[k][j]);
        }

        ll m; cin >> m;
        vl p(m); REP(i, m) cin >> p[i];
        
        vl len(m, m+2), from(m, -1); len[0] = 1;
        vl last(n+2, -1); last[p[0]] = 0;
        FOR(i, 1, m-1) {
            dbg(last);
            FOR(tt, 1, n) {
                ll j = last[tt]; if (j == -1) continue;

                ll delta = dist[p[j]][p[i]];
                if (len[j] + 1 < len[i] && p[j] != p[i] && delta == i-j) {
                    len[i] = len[j] + 1;
                    from[i] = j;
                }
            }
            last[p[i]] = i;
        }

        dbg(len); dbg(from);

        stack<ll> st;
        ll crt = m-1;
        while (crt != -1) st.em(p[crt]), crt = from[crt];
        ll ans = st.size(); cout << ans << endl;
        while (!st.empty()) {
            cout << st.top() << " "; st.pop();
        } cout << endl;
    }
    return 0;
}