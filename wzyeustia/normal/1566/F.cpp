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

#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
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
#define lb_pos(arr, key) lower_bound(all(arr), key) - (arr).begin()
#define ub_pos(arr, key) upper_bound(all(arr), key) - (arr).begin()

// FILL by byte!!!
#define FILL(arr, num) memset(arr, num, sizeof(arr))

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

template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using MaxHeap = priority_queue<T>;

const ld PI = 3.14159265358979323846;
const ld E = 2.718281828459;
ll MOD = 998'244'353;
ll M(ll n) {return (n % MOD + MOD) % MOD;}
ll pow2(ll n) {return 1ll << n;}

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

const ll UPDATE = 0, CHECK = 1;
const ll LEFT = 0, RIGHT = 1;

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    REP(I, T) {
        ll n, m; cin >> n >> m;
        vector<t3l> seq[n+2];
        vl a(n); REP(i, n) {
            cin >> a[i];
        } a.eb(-1e15), a.eb(1e15);
        sort(all(a));

        vl exist(m, 1);
        vector<pll> seg(m); REP(i, m) {
            ll l, r; cin >> l >> r;
            seg[i] = {l, r};
            ll prev = lb_pos(a, l), nxt = ub_pos(a, r);
            if (prev == nxt) {
                dbg(l, r);
                seq[prev].eb(l, i, LEFT);
                seq[prev].eb(r, i, RIGHT);
            }
        }

        REP(i, n+2) sort(all(seq[i]));

        map<ll, ll> dp, offset; dp[-1e15] = 0;
        FOR(i, 1, n+1) {
            dbg(i);
            ll totLen = a[i] - a[i-1];
            vector<pll> pairs;
            set<pll> lo, hi; lo.em(a[i-1], -1), hi.em(a[i], -1);
            for (auto [pos, idx, type] : seq[i]) {
                if (type == RIGHT) {
                    hi.em(pos, idx);
                }
            }

            pairs.eb((*lo.rbegin()).first, (*hi.begin()).first);
            for (auto [pos, idx, type] : seq[i]) {
                if (type == LEFT) {
                    lo.em(pos, idx);
                    hi.erase(mp(seg[idx].second, idx));

                    pairs.eb((*lo.rbegin()).first, (*hi.begin()).first);
                }
            }

            // until now, everything is OK...

            ll mx0 = 1e15, mx1 = 1e15;
            for (auto [p0, i0, t0] : seq[i-1]) {
                
                if (t0 == RIGHT && dp.count(p0)) {
                    dbg(p0, dp[p0]);
                    ll k = a[i-1] - p0;
                    chkmin(mx0, dp[p0] + k);
                    chkmin(mx1, dp[p0]);
                }
            }
            chkmin(mx0, dp[a[i-1]]); chkmin(mx1, dp[a[i-1]]);
            dbg(mx0, mx1);

            for (auto [l, r] : pairs) {
                dp[r] = 1e15;
            }
            for (auto [l, r] : pairs) {
                ll off = totLen - (r-l);
                dbg(l, r, off);
                chkmin(dp[r], mx0 + off);
                chkmin(dp[r], mx1 + off + l-a[i-1]);
            }


            
            // vector<t3l> sq0, sq1;
            // for (auto [p0, i0, t0] : seq[i-1]) {
            //     if (t0 == RIGHT) {
            //         ll k = a[i-1] - p0;
            //         sq0.eb(-k, UPDATE, dp[p0] + k);
            //         sq1.eb(k, UPDATE, dp[p0]);
            //     }
            // } sq0.eb(0, UPDATE, dp[a[i-1]]), sq1.eb(0, UPDATE, dp[a[i-1]]);
            
            // int paIdx = 0;
            // for (auto [l, r] : pairs) {
            //     dbg(l, r);
            //     sq0.eb(-(l - a[i-1]), CHECK, paIdx);
            //     sq1.eb(l-a[i-1], CHECK, paIdx);
            //     offset[paIdx++] = totLen - (r-l); // ???
            //     dbg(paIdx, offset[paIdx-1]);
                
            //     dp[r] = 1e15;
            // }
            // sort(all(sq0)), sort(all(sq1));

            // ll mx = 1e15;
            // for (auto [_, type, val] : sq0) {
            //     if (type == UPDATE) {
            //         chkmin(mx, val);
            //     } else {
            //         int id = pairs[val].second;
            //         dbg(id, mx+offset[val]);
            //         chkmin(dp[pairs[val].second], mx + offset[val]);
            //     }
            // }
            // if (true) {
            //     ll ans = 1e15;
            //     for (auto [_, type, val] : sq1) {
            //         if (type != UPDATE) {
            //             val = pairs[val].second;
            //             dbg(val, dp[val]);
            //         }
            //     } 
            // }
            // dbg(" ");

            // paIdx = 0;
            // for (auto [l, r] : pairs) {
            //     offset[paIdx++] += l - a[i-1]; // ???
            // }
            // mx = 1e15;
            // for (auto [_, type, val] : sq1) {
            //     if (type == UPDATE) chkmin(mx, val);
            //     else chkmin(dp[pairs[val].second], mx + offset[val]);
            // }

            // if (i == n+1) {
            //     ll ans = 1e15;
            //     for (auto [l, r] : pairs) {
            //         dbg(r, dp[r]);
            //     } 
            // }
        }

        ll ans = dp[1e15];
        cout << ans << endl;
        dbg(ans);
    }
    return 0;
}