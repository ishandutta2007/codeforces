#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;
typedef vector<ll> vl;
typedef vector<vl> vvl;

#define FOR(i, a, b) for (ll (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (ll (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

#define ln cout << endl;

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
template <typename T>
using MaxHeap = priority_queue<T>;

const ld PI = 3.14159265358979323846;
const ld E = 2.718281828459;
const ll SIZE = 2e6+3; 

const ll MOD = 1e9+7;
ll myMod(ll n) {return (n % MOD + MOD) % MOD;}

vl F;
ll find(ll k) {
    return F[k] == k? k : F[k] = find(F[k]);
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll n; cin >> n;
        F = vl(2*n+5);
        FOR(i, 1, 2*n) F[i] = i;

        vl ans(2*n+5);
        MinHeap<tuple<ll, ll, ll>> heap;

        vvl lca(n+1, vl(n+1));
        FOR(i, 1, n) FOR(j, 1, n) {
            cin >> lca[i][j];
            if (i == j) ans[i] = lca[i][j];
            else if (i<j) heap.emplace(lca[i][j], i, j);
        }
        ll ansSize = n;

        vector<pll> edges;
        while (!heap.empty()) {
            auto [sa, x, y] = heap.top(); heap.pop();
            if (find(x) == find(y)) continue;
            if (ans[find(x)] == sa) {
                edges.eb(find(y), find(x));
                F[find(y)] = find(x);
            } else if (ans[find(y)] == sa) {
                edges.eb(find(x), find(y));
                F[find(x)] = find(y);
            } else {
                ans[++ansSize] = sa;
                edges.eb(find(x), ansSize);
                edges.eb(find(y), ansSize);
                F[find(x)] = F[find(y)] = find(ansSize);
            }
        }

        dbg(ansSize);
        cout << ansSize << endl;
        dbg(ans);
        FOR(i, 1, ansSize) {
            cout << ans[i] << " ";
        }ln;
        dbg(edges.size());
        // cout << edges.size() << endl;
        cout << ansSize << endl;
        for (auto [x, y] : edges) {
            cout << x << " " << y << endl;
        }
    }
    return 0;
}