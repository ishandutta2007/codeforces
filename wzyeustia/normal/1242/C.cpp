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
ll MOD = 998'244'353;
ll M(ll n) {return (n % MOD + MOD) % MOD;}
ll pow2(ll n) {return 1ll << n;}

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

vector<t3l> ans;
vl dp, split;
vector<vector<t3l>> plan;
void dfs(ll mask) {
    if (!split[mask]) {
        ans.insert(ans.end(), all(plan[mask]));
    } else {
        dfs(split[mask]); dfs(mask ^ split[mask]);
    }
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll k; cin >> k;
        map<ll, ll> ma;

        vvl list(k+1);
        vl sum(k+1);
        ll tot = 0;
        FOR(i, 1, k) {
            ll n; cin >> n;
            list[i].resize(n);
            REP(j, n) {
                cin >> list[i][j];
                tot += list[i][j], sum[i] += list[i][j];
                ma[list[i][j]] = i;
            }
        }

        bool can = true;
        if (abs(tot) % k != 0) can = false;
        ll avg = tot / k;

        dbg(tot, avg);

        ll sz = 1<<k;
        plan = vector<vector<t3l>>(sz);
        dp = vl(sz, 0), split = vl(sz, 0);
        FOR(i, 1, k) {
            ll delta = avg - sum[i];
            for (auto val : list[i]) {
                vector<t3l> seq;
                ll mask = 1 << (i-1);
                
                ll need = val + delta, last = i;
                bool can = true;
                while (val != need) {
                    ll nxt = ma[need];
                    dbg(val, need, nxt);
                    if (!nxt || mask & (1<<nxt-1)) {can = false; break;}

                    seq.eb(need, nxt, last); // {val, from, to}
                    mask |= 1 << nxt-1, need += avg - sum[nxt]; 
                    last = nxt;
                }

                if (can && !dp[mask]) {
                    seq.eb(val, i, last);
                    dp[mask] = 1, plan[mask] = seq;
                }
            }
        }

        REP(mask, sz) for (ll sub = mask; sub > 0; sub = mask&(sub-1)) {
            dbg(mask, sub);
            if (dp[mask]) break;
            if (dp[sub] && dp[mask^sub]) {
                dp[mask] = 1, split[mask] = sub;
            }
        }

        REP(mask, sz) dbg(mask, dp[mask]);
        if (!dp[sz-1]) can = false;
        
        if (!can) cout << "No" << endl;
        else {
            dfs(sz-1);
            cout << "Yes" << endl;
            pll outp[k+1];
            for (auto [val, from, to] : ans) {
                outp[from] = {val, to};
            }
            FOR(i, 1, k) {
                auto [val, to] = outp[i];
                cout << val << " " << to << endl;
            }
        }
    }
    return 0;
}