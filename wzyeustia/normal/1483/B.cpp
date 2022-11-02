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

vl F;

ll find(ll k) {
    return F[k] == k? k : F[k] = find(F[k]);
}

ll gcd(ll a, ll b) {
    if (a < b) swap(a, b);
    return (a % b == 0)? b: gcd(b, a%b);
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    REP(I, T) {
        ll n; cin >> n;
        vl a(n); REP(i, n) cin >> a[i];
        vl nxt(n); REP(i, n) nxt[i] = (i+1)%n;
        vl chk(n, 1);
        F = vl(n+2); REP(i, n+2) F[i] = i;

        dbg(F);
        vl ans;
        ll idx = 0;
        while (true) {
            // dbg(idx); dbg(chk); dbg(nxt);
            idx = find(idx);

            if (!chk[idx]) break;
            // if (idx == nxt[idx]) break;

            if (gcd(a[idx], a[nxt[idx]]) == 1) {
                chk[nxt[idx]] = 0;
                ans.eb(nxt[idx] + 1);
                nxt[idx] = nxt[nxt[idx]];
            } else {
                chk[idx] = 0;
                F[find(idx)] = find(nxt[idx]);
            }
            idx = nxt[idx];
        }

        ll sz = ans.size();
        // cout << "ans : ";
        cout << sz << " ";
        for (auto num : ans) {
            cout << num << " "; 
        }ln;

    }
    return 0;
}