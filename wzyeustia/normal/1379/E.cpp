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

void build(ll root, ll size, vl& vec) {
    FOR(i, 2, size) {
        vec.eb(root-1 + i/2);
    }
}

bool isPow(ll n) {
    while (!(n&1)) n >>= 1;
    return n == 1; 
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    const ll MOD = 998'244'353;

    int T = 1;
    // cin >> T;    
    REP(I, T) {
        ll n, k; cin >> n >> k;
        bool flag = true;
        vl ans; ans.eb(0);

        if (k > (n-3)/2 || n%2==0) {
            flag = false;
        } else if (k == 0) {
            if (isPow(n+1)) build(1, n, ans);
            else flag = false;
        } else if (k == 1) {
            if (isPow(n+1)) flag = false;
            else build(1, n, ans);
        } else {
            if ((n == 9) && k == 2) flag = false;

            ll root = 1;
            if (isPow(n+1 - 2*(k-1))) {
                ans.eb(1); build(2, 3, ans); ans.eb(1);
                root = 5; k--;
            }

            REP(i, k-1) {
                ans.eb(root); ans.eb(root); root += 2;
            }

            build(root, n+1-root, ans);
        }

        if (n == 1 && k == 0) flag = true;

        if (flag) {
            cout << "YES" << endl;
            for (auto num : ans) {
                cout << num << " ";
            }ln;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}