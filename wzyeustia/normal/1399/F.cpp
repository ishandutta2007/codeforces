#include <bits/stdc++.h>

using namespace std;

typedef int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;
typedef vector<int> vl;
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

vvl rightEnds, dp; 

ll calc(ll l, ll r) {
    if (l > r) return 0;
    if (dp[l][r] != -1) return dp[l][r];
    dp[l][r] = 0;

    vl thisEnds = rightEnds[l];
    bool offset = count(all(thisEnds), r);
    chkmax(dp[l][r], offset + calc(l+1, r));

    for (auto endP : thisEnds) {
        if (endP >= r) continue;
        ll newVal = offset + calc(l, endP) + calc(endP+1, r); 
        chkmax(dp[l][r], newVal);
    }

    return dp[l][r];
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    REP(I, T) {
        ll n; cin >> n;
        vl left(n), right(n);
        vl points;
        REP(i, n) {
            cin >> left[i] >> right[i]; 
            points.eb(left[i]); points.eb(right[i]);
        }

        unique(all(points));
        sort(all(points));

        REP(i, n) {
            left[i] = (lower_bound(all(points), left[i]) - points.begin());
            right[i] = (lower_bound(all(points), right[i]) - points.begin());
        }
        // Compress finished..

        ll totSize = points.size();
        rightEnds = vvl(totSize);
        REP(i, n) {
            rightEnds[left[i]].eb(right[i]);
        }
        dp = vvl(totSize, vl(totSize, -1));

        ll ans = calc(0, totSize-1);
        dbg(ans);
        cout << ans << endl;
    }
    return 0;
}