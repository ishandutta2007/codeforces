#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef vector<vl> vvl;

#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
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
const ll SIZE = 3e2+3; 

const ll MOD = 1e9+7;
ll myMod(ll n) {return (n % MOD + MOD) % MOD;}


ll fastPow(ll num, ll exp, ll modNum) {
    if (exp == 0) return 1;
    if (exp == 1) return num;
    else {
        ll half = fastPow(num, exp/2, modNum) % modNum;
        if (exp % 2 == 1) {
            return (((half * half) % modNum) * num) % modNum;
        }
        else {
            return (half * half) % modNum;
        }
    }
}
 
// number theory
ll getReverse(ll y, ll modNum) {
    return fastPow(y, modNum - 2, modNum) % modNum;
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    const ll MOD = 998'244'353;

    int T = 1;
    // cin >> T;    
    REP(I, T) {
        ll n; cin >> n;
        vl cost(n); REP(i, n) cin >> cost[i];
        sort(all(cost), greater<ll>());
        vl pre(n); partial_sum(all(cost), pre.begin());

        ll current = 0;
        vl bound(n);
        REP(i, n) {
            current += i*cost[i];
            bound[i] = i;
        }
        vl ans; ans.eb(current);
        
        FOR(k, 2, n) {
            REP(i, n) {
                if (bound[i] == n-1) break;
                ll next = min(n-1, bound[i] + (i+1));
                current -= pre[next] - pre[bound[i]];
                bound[i] = next;
            }
            ans.eb(current);
        }

        ll inverse = getReverse(n, MOD);
        REP(i, n) {
            cout << ((ans[i]%MOD) * inverse)%MOD << " ";
        }ln;
    }
    return 0;
}