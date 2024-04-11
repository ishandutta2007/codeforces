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

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    REP(I, T) {
        ll n, time, a, b; cin >> n >> time >> a >> b;
        vl hard(n); REP(i, n) cin >> hard[i];
        vl ddl(n); REP(i, n) cin >> ddl[i];
        ll hardCnt = 0, easyCnt = 0;
        vector<pll> seq;
        REP(i, n) {
            if (hard[i]) hardCnt++; else easyCnt++;
            seq.eb(ddl[i], i);
            seq.eb(ddl[i]-1, 1e9);
        } seq.eb(time, 1e9);
        sort(all(seq));

        ll ans = 0;
        ll hardMin = 0, timeMin = 0, crt = 0;
        for (auto [t, idx] : seq) {
            crt = t;
            if (idx != 1e9) {
                if (hard[idx]) hardMin++, timeMin += b;
                else timeMin += a;
            } else if (timeMin <= crt) {
                ll earn = hardMin, rest = crt - hardMin*b;
                if (rest / a <= easyCnt) earn += rest/a;
                else {
                    earn += easyCnt, rest -= a*easyCnt;
                    earn += min(hardCnt-hardMin, rest/b);
                }
                chkmax(ans, earn);
            }
        }

        dbg(ans);
        cout << ans << endl;
    }
    return 0;
}