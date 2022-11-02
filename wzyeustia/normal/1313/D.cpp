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
const ll MOD = 1e9+7;
ll M(ll n) {return (n % MOD + MOD) % MOD;}

const ll OUT = 0, IN = 1;

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll n, m, k; cin >> n >> m >> k;
        vector<tuple<ll, ll, ll>> seq;
        FOR(i, 1, n) {
            ll l, r; cin >> l >> r;
            seq.eb(l, IN, i);
            seq.eb(r+1, OUT, i);
        }

        sort(all(seq));

        ll sz = (1ll << k);
        // vl cnt(sz);
        // REP(mask, sz) {
        //     ll c = 0;
        //     REP(i, k) {
        //         ll bit = (1 << i);
        //         if (mask & bit) c++; 
        //     }
        //     cnt[mask] = c%2;
        // }   

        vvl dp(2*n+5, vl(sz, -1e18));
        REP(i, sz) dp[0][i] = 0;
        dp[0][0] = 0;

        ll crt = 1, disIdx = 0;
        vl used(k, -1);

        for (auto [pos, type, segIdx] : seq) {
            dbg(pos, type, segIdx);
            disIdx++;
            ll len = pos - crt;

            REP(mask, sz) {
                ll cnt = 0;
                REP(i, k) {
                    ll b = (1<<i);
                    if (used[i] != -1 && (mask&b)) cnt++;
                }

                dp[disIdx][mask] = dp[disIdx-1][mask];
                dp[disIdx][mask] += (cnt%2) * len;
            }

            dbg(dp[disIdx]);
            if (type == OUT) {
                ll BIT;
                REP(i, k) if (used[i] == segIdx) {
                    BIT = i, used[i] = -1;
                    break;
                } 

                ll bit = (1ll << BIT);
                REP(mask, sz) {
                    chkmax(dp[disIdx][mask], dp[disIdx][mask^bit]);
                }
            
            } else {
                ll BIT;
                REP(i, k) if (used[i] == -1) {
                    BIT = i, used[i] = segIdx;
                    break;
                } 
            }

            crt = pos;
            dbg(dp[disIdx]);
        }

        ll ans = dp[disIdx][0];
        // dbg(dp[disIdx]);
        cout << ans << endl;
    }
    return 0;
}