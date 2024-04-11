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

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    const ll MOD = 998'244'353;

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll r, n; cin >> r >> n;
        vector<tuple<int, int, int>> celes;
        REP(i, n) {
            ll t, x, y;
            cin >> t >> x >> y;
            celes.eb(t, x, y);
        }
        celes.eb(0, 1, 1);

        sort(all(celes));

        ll ans = 0;
        vector<ll> dp(n+5, LLONG_MIN);
        dp[0] = 0;
        ll canReach = 0, maxPre = LLONG_MIN;
        FOR(i, 1, n) {
            ll t, x, y; tie(t, x, y) = celes[i];
            while (t - get<0>(celes[canReach]) >= 1000) {
                chkmax(maxPre, dp[canReach++]);
                // dbg(t, get<0>(celes[canReach]));
            }

            chkmax(dp[i], maxPre+1);
            ll last = i-1;
            while (last >= canReach) {
                ll t1, x1, y1; tie(t1, x1, y1) = celes[last];
                if (abs(x-x1) + abs(y-y1) <= abs(t-t1)) {
                    chkmax(dp[i], dp[last]+1);
                }
                last--;
            }

            chkmax(ans, dp[i]);
        }

        // dbg(dp);
        dbg(ans);
        cout << ans << endl;
    }
    return 0;
}