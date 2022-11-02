#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
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

typedef unsigned long long ULL;
typedef unsigned int Uint;
typedef unsigned char Byte;
typedef long double ld;

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

const ld PI = 3.14159265358979323846;
const ld E = 2.718281828459;
const ll SIZE = 3e2+3; 

const ll MOD = 1e9+7;
ll myMod(ll n) {return (n % MOD + MOD) % MOD;}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    REP(I, T) {
        ll n; cin >> n;
        string str; cin >> str;
        
        vector<ll> ans(n+1);
        ll idx = 0;
        while (idx <= n) {
            ll len = 1, end = idx;

            if (idx > 0 && str[idx-1] == 'L') len++;
            while (end+2 <= n && str[end] == 'R' && str[end+1] == 'L') {
                len += 2; end += 2;
            }  
            if (end < n && str[end] == 'R') len++;

            for (int i = idx; i <= end; i+=2) {
                ans[i] = len;
            }

            idx = end + 2;
        }

        idx = 1;
        while (idx <= n) {
            ll len = 1, end = idx;

            if (idx > 0 && str[idx-1] == 'L') len++;
            while (end+2 <= n && str[end] == 'R' && str[end+1] == 'L') {
                len += 2; end += 2;
            }  
            if (end < n && str[end] == 'R') len++;

            for (int i = idx; i <= end; i+=2) {
                ans[i] = len;
            }

            idx = end + 2;
        }

        dbg(ans);
        for (auto num : ans) {
            cout << num << " ";
        }ln;
    }
    return 0;
}