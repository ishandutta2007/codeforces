#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
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

// FILL by byte!!!
#define FILL(arr, num) memset(arr, num, sizeof(arr))
#define ln cout << endl;

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
ll MOD = 998'244'353;
ll M(ll n) {return (n % MOD + MOD) % MOD;}
ll pow2(ll n) {return 1ll << n;}

mt19937_64 rng((unsigned ll) chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<ll>(a, b)(rng)


int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    
    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll m, n, k, t; cin >> m >> n >> k >> t;
        vl a(m); REP(i, m) cin >> a[i];
        sort(all(a));

        vl p1(k), p2(k), d(k);
        vector<pll> trap, save;
        REP(i, k) {
            cin >> p1[i] >> p2[i] >> d[i];
            trap.eb(p1[i], i), save.eb(p2[i], i);
        } //trap.eb(n+1, -1);
        sort(all(trap)), sort(all(save));

        ll l = 0, r = m-1, ans = 0;
        while (l<=r) {
            ll mid = (l+r)>>1;
            dbg(l, r, mid);
            ll lim = a[mid]; //dbg(lim);
            vl done(k, 0);

            ll cost = 0;
            ll x1 = 0, x2 = 0, k1 = 0, k2 = 0;
            while (k2 < trap.size()) {
                while (k2 < trap.size() && (d[trap[k2].second] <= lim || done[trap[k2].second])) {
                    k2++;
                } if (k2 == trap.size()) break;
                auto [p2, idx] = trap[k2];
                // dbg(p2, idx, d[idx]);

                cost += max(0ll, (p2-1) - x2);
                chkmax(x2, p2-1);
                chkmax(x1, x2);

                while (!done[idx]) {
                    auto [p1, i1] = save[k1++];
                    done[i1] = 1;
                    cost += max(0ll, p1 - x1) * 2;
                    chkmax(x1, p1);
                }

                // dbg(x1, x2, cost);
            }
            cost += n+1 - x2;
            dbg(lim, cost);

            if (cost <= t) {
                r = mid-1, ans = m-mid;
                dbg(mid, ans);
            } else l = mid+1;
        }

        dbg(ans);
        cout << ans << endl;
    }
    return 0;
}