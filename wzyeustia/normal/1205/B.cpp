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
ll MOD = 998'244'353;
ll M(ll n) {return (n % MOD + MOD) % MOD;}
ll pow2(ll n) {return 1ll << n;}

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

vvl G;
vl from, dis;
ll mx = 1e5+3;
// void dfs(ll u, ll par) {
//     dbg(u, par);
//     vis[u] = 1;
//     for (auto v : G[u]) if (v != par) {
//         if (vis[v] && dis[u] - dis[v] > 1) {
//             dbg(u, v, dis[u], dis[v]);
//             chkmin(mx, dis[u]+1 - dis[v]);
//         } else if (!vis[v]) {
//             dis[v] = dis[u]+1;
//             dfs(v, u);
//         }
//     }
// }

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);      
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll n; cin >> n;
        
        vvl pos(63);
        vl a(n); 
        REP(i, n) {
            cin >> a[i];
            REP(p, 63) if (a[i] & (1ll << p)) {
                pos[p].eb(i+1);
            }
        }

        G = vvl(n+2);
        from = vl(n+2, 0), dis = vl(n+2, 0);
        set<pll> se;
        bool found = false;
        REP(p, 63) {
            if (pos[p].size() >= 3) {
                found = true;
            } 
            if (found) break;
            if (pos[p].size() == 2) {
                ll u = pos[p][0], v = pos[p][1];
                if (u > v) swap(u, v);
                se.em(u, v);
            }
        }

        dbg(found);
        if (found) {
            cout << 3 << endl;
        } else {
            for (auto [u, v] : se) {
                G[u].eb(v), G[v].eb(u);
                dbg(u, v);
            }

            FOR(i, 1, n) {
                vl used;
                queue<ll> que;
                que.em(i); from[i] = -1;
                while (!que.empty()) {
                    auto u = que.front(); que.pop(); used.eb(u);
                    dbg(u);
                    for (auto v : G[u]) if (v != from[u]) {
                        if (from[v]) {
                            dbg(u, v, dis[u], dis[v]);
                            chkmin(mx, dis[u] + dis[v] + 1);
                        }
                        if (!from[v]) {
                            // dbg(v, from[v]);
                            que.em(v);
                            from[v] = u;
                            dis[v] = dis[u] + 1;
                        }
                    }
                }

                for (auto u : used) {
                    from[u] = 0, dis[u] = 0;
                }
            }
            // FOR(i, 1, n) if (!vis[i]) {
            //     dfs(i, 0);
            // }

            // dbg(dis);
            dbg(mx);
            if (mx > n) cout << -1 << endl;
            else cout << mx << endl;
        }

    }   
    return 0;
}