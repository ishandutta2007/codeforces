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
ll MOD = 1e9+7;
ll M(ll n) {return (n % MOD + MOD) % MOD;}
ll pow2(ll n) {return 1ll << n;}

vi vis;
vector<vector<pii>> G;

int tot;
void dfs(int u) {
    vis[u] = 1, tot += G[u].size();
    for (auto [v, _] : G[u]) {
        if (!vis[v]) dfs(v);
    }
}

vi used, ans;
void euler(int u) {
    while (!G[u].empty()) {
        auto [v, idx] = G[u].back(); G[u].pop_back();
        if (used[abs(idx)]) continue;
        used[abs(idx)] = 1; 
        euler(v); ans.eb(-idx);
    }
}

const ld OFFSET = 2e9;

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        int n, k; scanf("%d%d", &n, &k);
        map<ld, vector<ld>> ma;
        REP(i, n) {
            ll x, y; scanf("%lld%lld", &x, &y);
            if (!x && !y) continue;

            ld dist = sqrt((ld) sqr(x)+sqr(y)), slope;
            if (y == 0) slope = 1e18;
            else slope = (ld) x/y;
            
            if (x > 0 || (x==0 && y>0)) {
                ma[slope+OFFSET].eb(dist);
            } else {
                ma[slope-OFFSET].eb(dist);
            }
        }

        vector<ld> earn;
        for (auto& [slope, vec] : ma) {
            // vec.eb(0);
            sort(all(vec));
            vector<ld> pre(vec.size()); partial_sum(all(vec), pre.begin());
            dbg(vec); dbg(pre);
            
            int used = 0, other = k-1, cnt = vec.size();
            int l = 0, r = cnt-1, pos;
            REP(i, cnt) {
                ld offset; 
                if (used <= other) {
                    pos = r;    
                } else pos = l;

                if (l == 0) offset = 2*used * vec[pos];
                else offset = 2*(pre[l-1] + used * vec[pos]);

                ld single = (k-1) * vec[pos] - offset;
                earn.eb(single);
                dbg(pos, single);

                if (used <= other) {
                    r--; used++, other--;
                } else l++;
            }
        }

        earn.eb(0);
        sort(all(earn), greater<ld>()); dbg(earn);
        ld ans = 0;
        REP(i, k) ans += earn[i];
        cout << fixed << setprecision(8) << ans << endl;
    }
    return 0;
}