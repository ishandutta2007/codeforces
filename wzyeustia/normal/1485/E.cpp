#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

#define ln cout << endl;

typedef unsigned long long ULL;
typedef unsigned int Uint;
typedef unsigned char Byte;
typedef long double ld;

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
#endif
// end

template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;

const ld PI = 3.14159265358979323846;
const ld E = 2.718281828459;
const ll SIZE = 3e2+3; 

const ll MOD = 1e9+7;
ll myMod(ll n) {return (n % MOD + MOD) % MOD;}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    REP(I, T) {
        ll n; cin >> n;
        vector<vector<ll>> edges(n+2);
        FOR(i, 2, n) {
            ll j; cin >> j;
            edges[i].eb(j); edges[j].eb(i);
        }
        vector<ll> a(n+2, 0);
        FOR(i, 2, n) {cin >> a[i];}

        vector<ll> parent(n+2, -1), big, small;
        vector<vector<ll>> group;
        group.eb(vector<ll>(1, 1));
        ll depth = 0;
        while (group[depth].size() > 0) {
            vector<ll> next;
            ll low = LLONG_MAX, high = LLONG_MIN;
            for (auto node : group[depth]) {
                chkmin(low, a[node]); chkmax(high, a[node]);

                for (auto child : edges[node]) {
                    if (child != parent[node]) {
                        parent[child] = node;
                        next.eb(child);
                    }
                }
            }

            big.eb(high); small.eb(low);
            group.eb(next);
            depth++;
        }

        // dbg(a);
        // dbg(big); dbg(small);

        vector<ll> dp(n+5, 0);
        depth = 1;
        ll ans = -1;
        while (group[depth].size() > 0) {
            vector<ll> &current = group[depth];
            ll lower = -2e9, upper = -2e9;
            for (auto node : current) {
                chkmax(lower, dp[parent[node]] - a[node]);
                chkmax(upper, dp[parent[node]] + a[node]);
            }

            for (auto node : current) {
                ll red = dp[parent[node]] + max(big[depth] - a[node], a[node] - small[depth]);
                ll blue = max(lower + a[node], upper - a[node]);

                dbg(node, red, blue);
                chkmax(dp[node], max(red, blue));
                chkmax(ans, dp[node]);
            }

            depth++;
        }

        dbg(ans);
        cout << ans << endl;
    }
    return 0;
}