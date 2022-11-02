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

vl F;
ll find(ll k) {
    return F[k] == k? k : F[k] = find(F[k]);
}

void merge(ll p1, ll p2) {
    ll p11 = p1<<1, p12 = p11+1;
    ll p21 = p2<<1, p22 = p21+1;

    if (find(p11) != find(p22)) F[find(p11)] = find(p22);
    if (find(p12) != find(p21)) F[find(p12)] = find(p21);
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    REP(I, T) {
        ll n; cin >> n;
        set<ll> pos[n+1][n+1]; // [col][val]
        vvl a(2*n, vl(n));
        REP(i, 2*n) {
            REP(j, n) {
                cin >> a[i][j];
                pos[j][a[i][j]].em(i);
            }
        }

        vl ans;

        const ll FREE = 0, NEED = 1, THROW = 2;
        vl stat(2*n, FREE);
        queue<ll> que;
        REP(col, n) FOR(val, 1, n) if (pos[col][val].size() == 1) {
            ll p = *pos[col][val].begin();
            if (stat[p] == FREE) que.em(p), stat[p] = NEED;
        }

        while (!que.empty()) {
            ll p = que.front(); que.pop();
            // dbg(p);
            if (stat[p] == NEED) {
                ans.eb(p);
                REP(col, n) {
                    ll val = a[p][col];
                    for (auto p0 : pos[col][val]) if (stat[p0] == FREE) {
                        que.em(p0), stat[p0] = THROW;
                    } pos[col][val].clear();
                }

            } else {
                REP(col, n) {
                    ll val = a[p][col];
                    pos[col][val].erase(p);
                    
                    if (pos[col][val].size() == 1) {
                        ll p0 = *pos[col][val].begin();
                        if (stat[p0] == FREE) que.em(p0), stat[p0] = NEED;
                    }
                }
            }
        }
        dbg(stat);

        ll tot = 1;
        F = vl(4*n); REP(i, 4*n) F[i] = i;
        REP(col, n) FOR(val, 1, n) if (pos[col][val].size() > 0) {
            assert((pos[col][val].size() == 2));
            auto iter = pos[col][val].begin();
            ll p1 = *iter, p2 = *(++iter);
            // dbg(p1, p2);
            merge(p1, p2);
        }

        vl cc_stat(4*n, FREE);
        REP(p, 2*n) if (stat[p] == FREE) {
            ll cc = find(2*p);
            if (cc_stat[cc] != THROW) {
                ans.eb(p);
                if (cc_stat[cc] == FREE) tot = (tot*2)%MOD;
                cc_stat[cc] = NEED, cc_stat[cc^1] = THROW;
            }
        } 

        dbg(tot); dbg(ans); 
        cout << tot << endl;
        REP(i, n) cout << ans[i]+1 << " ";
        cout << endl;
    }
    return 0;
}