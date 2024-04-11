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
// ll M(ll n) {return (n % MOD + MOD) % MOD;}
ll pow2(ll n) {return 1ll << n;}

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)


int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);      
    cin.tie(nullptr);

    const ll LG = 32;

    int T = 1;
    // cin >> T;
    REP(I, T) {
		ll n; cin >> n;
        vl p(n+1); FOR(i, 1, n) cin >> p[i];
        vl a(n+1); FOR(i, 1, n) cin >> a[i];
        
        vl at(n+1, 0), inDeg(n+1, 0);
        ll inCount = 0, mx = -1, idx = -1;
        FOR(i, 1, n) inDeg[p[i]]++;
        FOR(i, 1, n) if (a[i] > n) {
            if (inDeg[i] == 0) {
                inCount++;
                if (a[i] > mx) {
                    idx = i, mx = a[i];
                }
            }
        } else at[a[i]] = i;
        set<ll> free;
        FOR(i, 1, n) if (at[i] == 0) {
            free.em(i);
        }
        dbg(free);

        vl ans(n+1, -1);
        if (mx == -1) {
           FOR(i, 1, n) ans[i] = a[i]; 
        } else {
            ll round = (mx - n) / inCount;
            ll f[n+2][LG]; 
            FOR(i, 1, n) f[i][0] = p[i];
            FOR(p, 1, LG-1) FOR(i, 1, n) {
                f[i][p] = f [f[i][p-1]] [p-1];
            }

            bool can = true;
            vl to(n+1, 0), used(n+1, 0);
            FOR(i, 1, n) {
                to[i] = i;
                ROF(p, LG-1, 0) if ( (1ll << p) & round ) {
                    to[i] = f[to[i]][p];
                }
                ll crt = a[to[i]];
                if (!used[crt]) {
                    ans[i] = crt;
                    used[crt] = 1;
                } else {
                    auto iter = free.lower_bound(crt);
                    if (iter == free.end()) {
                        dbg(i, "fail");
                        can = false;
                    } else {
                        ll nxt = *iter;
                        ans[i] = nxt, free.erase(nxt);
                    }
                }
            }

            dbg(mx, inCount, round);
            dbg(to);
            dbg(can);
            dbg(ans);
        }

        FOR(i, 1, n) cout << ans[i] << " ";
        cout << endl;
    }   
    return 0;
}