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
#define reset(x, y) memset(x, y, sizeof(x))
#define pb push_back
#define eb emplace_back
#define em emplace
#define mp make_pair
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

#define FILL0(arr) memset(arr, 0, sizeof(arr))

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
const ll MOD = 998'244'353;
ll M(ll n) {return (n % MOD + MOD) % MOD;}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    REP(I, T) {
        ll n; cin >> n;
        string str; cin >> str;

        vl isBig(n), pos; ll cnt = 0, set = 0;
        REP(i, n-1) {
            if (str[i] == '<') {
                isBig[i+1] = 1, set = 1, cnt++;
            } else if (set) {
                pos.eb(i), set = 0;
            }
        }
        dbg(isBig);
        if (set) pos.eb(n-1);

        vl maxi(n), mini(n);
        ll num = n;
        ROF(i, n-1, 0) if (isBig[i]) maxi[i] = num--;
        REP(i, n) if (!maxi[i]) maxi[i] = num--;

        num = n;
        for (auto p : pos) {
            while (isBig[p]) mini[p--] = num--;
        }
        REP(i, n) if (!mini[i]) mini[i] = num--;

        dbg(maxi); dbg(mini);
        REP(i, n) {cout << mini[i] << " ";} cout << endl;
        REP(i, n) {cout << maxi[i] << " ";} cout << endl;
        
    }
    return 0;
}