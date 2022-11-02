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

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        int n; scanf("%d", &n);
        pii part[n+2];
        FOR(i, 1, n) {
            int a, b; scanf("%d%d", &a, &b);
            part[i] = {a, b};
        }

        int l = 0, r = 20;
        while (l<=r) {
            int mid = (l+r)>>1;
            int mask = (1<<mid)-1;

            dbg(l, r, mid, mask);
            
            G = vector<vector<pii>>(mask+1);
            FOR(i, 1, n) {
                auto [a, b] = part[i];
                a &= mask, b &= mask;
                G[a].eb(b, i), G[b].eb(a, -i);
                dbg(a, b);
            }

            bool can = true, search = false; int pos = -1;
            REP(i, mask+1) {
                if (G[i].size() % 2) can = false;
                if (G[i].size() && !search) {
                    search = 1, pos = i;
                    vis = vi(mask+1, 0), tot = 0;
                    dfs(i);
                    if (tot < 2*n) can = false;
                }
            }

            dbg(tot, can);

            if (can) {
                ans.clear(), used = vi(n+2);
                euler(pos); dbg(ans);
                l = mid+1;
            } else r = mid-1;
        }

        dbg(l-1); dbg(ans);

        printf("%d\n", l-1);
        REP(i, n) {
            if (ans[i] > 0) {
                printf("%d %d ", ans[i]*2-1, ans[i]*2);
            } else
                printf("%d %d ", -ans[i]*2, -ans[i]*2-1);
        }
    }
    return 0;
}