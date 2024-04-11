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

vector<ll> BIT;
const ll MOD = 1e9+7;
ll myMod(ll n) {return (n % MOD + MOD) % MOD;}

ll lowbit(ll num) {return num & (-num);}

ll query(ll k) {
    ll sum = 0;
    for (int i = k; i > 0; i-=lowbit(i)) {
        sum = myMod(BIT[i] + sum);
    }
    return sum;
}

void update(ll l, ll r, ll delta) {
    for (int i = l; i < BIT.size(); i+=lowbit(i)) {
        BIT[i] = myMod(BIT[i]+delta);
    }
    for (int i = r+1; i < BIT.size(); i+=lowbit(i)) {
        BIT[i] = myMod(BIT[i]-delta);
    }
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    REP(I, T) {
        ll n; cin >> n;
        vector<ll> b(n+5, 0), next(n+5, n+1);
        FOR(i, 1, n) {cin >> b[i];}

        map<ll, ll> map;
        ll pre = 0;
        FOR(i, 1, n+1) {
            pre += b[i-1];
            if (map[pre]) {
                ll last = map[pre];
                next[last] = i;
            }
            map[pre] = i;
        }

        dbg(next);

        vector<ll> dpDelta(n+5, 0);
        dpDelta[1] = 1; dpDelta[2] = -1;
        ll val = 0;
        FOR(i, 1, n) {
            val = myMod(val + dpDelta[i]);
            dpDelta[i+1] = myMod(dpDelta[i+1] + val);
            dpDelta[next[i]+1] = myMod(dpDelta[next[i]+1] - val);
        }

        ll ans = myMod(val + dpDelta[n+1]);


        // BIT = vector<ll>(2*n+6, 0);
        // update(1, 1, 1);
        // FOR(i, 1, n) {
        //     ll val = query(i);
        //     // dbg(val);
        //     update(i+1, next[i], val);
        // }

        // ll ans = query(n+1);


        dbg(ans);
        cout << ans << endl;
    }
    return 0;
}