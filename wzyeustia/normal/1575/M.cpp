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

#define FOR(i, a, b) for (ll (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (ll (i) = (a); (i) >= (b); (i)--)
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
ll MOD = 1e9+7;
ll M(ll n) {return (n % MOD + MOD) % MOD;}
ll pow2(ll n) {return 1ll << n;}

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)


int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);      
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll n, m; cin >> n >> m;
        string G[n+1];
        REP(i, n+1) cin >> G[i];

        ll xDist[n+1][m+1]; FILL(xDist, 0x7f);
        REP(i, n+1) REP(j, m+1) if (G[i][j] == '1') xDist[i][j] = 0;
        REP(i, n+1) FOR(j, 1, m) chkmin(xDist[i][j], xDist[i][j-1]+1);
        REP(i, n+1) ROF(j, m-1, 0) chkmin(xDist[i][j], xDist[i][j+1]+1);

        // dbg("xDist");
        // REP(i, n+1) {
        //     REP(j, m+1) cout << xDist[i][j] << " ";
        //     cout << endl;
        // }

        ll ans[n+1][m+1]; FILL(ans, 0x7f);
        deque<pll> cand[m+1];
        deque<ll> lim[m+1];
        REP(i, n+1) REP(j, m+1) {
            // dbg(i, j);
            ll offset;
            if (xDist[i][j] > 1e9) offset = 1e9;
            else offset = xDist[i][j] * xDist[i][j];
            
            // dbg(offset);
            if (offset < 1e8) {
                ll thisRow;
                while (!lim[j].empty()) {
                    auto [add, x] = cand[j].back();
                    auto row = lim[j].back();
                    ll delta = offset - add - (i-x)*(i-x);
                    ll slope = 2 * (i-x);

                    // dbg(delta, slope);
                    thisRow = (delta + slope-1) / slope + i;
                    if (thisRow > row) break;
                    lim[j].pop_back(), cand[j].pop_back();
                }

                
                if (cand[j].empty()) cand[j].eb(offset, i);
                else {
                    auto [add, x] = cand[j].back();
                    ll delta = offset - add - (i-x)*(i-x);
                    ll slope = 2 * (i-x);
                    thisRow = (delta + slope-1) / slope + i;
                    cand[j].eb(offset, i);
                    lim[j].eb(thisRow);
                } 
            }
            // add new cand

            while (!lim[j].empty() && lim[j].front() <= i) {
                lim[j].pop_front(), cand[j].pop_front();
            }
            // update done
            if (!cand[j].empty()) {
                auto [add, x] = cand[j].front();
                chkmin(ans[i][j], add + (i-x) * (i-x));
            }
            
        }

        // dbg("upper");
        // REP(i, n+1) {
        //     REP(j, m+1) cout << ans[i][j] << " ";
        //     cout << endl;
        // }

        REP(j, m+1) cand[j].clear(), lim[j].clear();

        ROF(i, n, 0) REP(j, m+1) {
            // dbg(i, j);
            ll offset;
            if (xDist[i][j] > 1e9) offset = 1e9;
            else offset = xDist[i][j] * xDist[i][j];
            
            // dbg(offset);
            if (offset < 1e8) {
                ll thisRow;
                while (!lim[j].empty()) {
                    auto [add, x] = cand[j].back();
                    auto row = lim[j].back();
                    ll delta = offset - add - (x-i)*(x-i);
                    ll slope = 2 * (x-i);
                    thisRow = i - (delta + slope-1) / slope;
                    if (thisRow < row) break;
                    lim[j].pop_back(), cand[j].pop_back();
                }

                
                if (cand[j].empty()) cand[j].eb(offset, i);
                else {
                    auto [add, x] = cand[j].back();
                    ll delta = offset - add - (x-i)*(x-i);
                    ll slope = 2 * (x-i);
                    thisRow = i - (delta + slope-1) / slope;
                    cand[j].eb(offset, i);
                    lim[j].eb(thisRow);
                } 
            }
            // add new cand

            while (!lim[j].empty() && lim[j].front() >= i) {
                lim[j].pop_front(), cand[j].pop_front();
            }
            // update done

            if (!cand[j].empty()) {
                auto [add, x] = cand[j].front();
                chkmin(ans[i][j], add + (i-x) * (i-x));
            }
        }

        // dbg("final");
        // REP(i, n+1) {
        //     REP(j, m+1) cout << ans[i][j] << " ";
        //     cout << endl;
        // }

        ll tot = 0;
        REP(i, n+1) REP(j, m+1) tot += ans[i][j];
        dbg(tot);
        cout << tot << endl;
    }
    return 0;
}