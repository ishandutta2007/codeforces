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

ll n, s;
ll current;
vector<vector<pair<ll, ll>>> edges;
vector<ll> weights, sizes;

ll dfs(ll node, ll parent, ll weight) {
    weights[node] = weight;
    
    ll size = 0;
    if (edges[node].size() == 1) size++;
    
    for (auto pa : edges[node]) {
        ll child = pa.first;
        if (child != parent) {
            size += dfs(child, node, pa.second);
        }
    }


    sizes[node] = size;
    current += size * weight;
    return size;
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    REP(I, T) {
        current = 0;
        cin >> n >> s;
        edges = vector<vector<pair<ll, ll>>>(n+5);
        weights = vector<ll>(n+5, 0);
        sizes = vector<ll>(n+5, 0);

        REP(i, n-1) {
            ll u, v, w; cin >> u >> v >> w;
            edges[u].eb(v, w);
            edges[v].eb(u, w);
        }


        dfs(1, -1, 0);
        dbg(weights);
        dbg(sizes);
        dbg(current);

        priority_queue<pair<ll, ll>> pq;
        FOR(i, 2, n) {
            ll earning = (weights[i]+1)/2 * sizes[i];
            pq.emplace(earning, i); 
        }

        ll ans = 0;
        while (current > s) {
            auto pa = pq.top(); pq.pop();
            ll earning, node; tie(earning, node) = pa;

            ans++;
            current -= earning;
            weights[node] /= 2; 
            ll newEarning = (weights[node]+1)/2 * sizes[node];

            pq.emplace(newEarning, node); 
            dbg(current);
        }

        dbg(ans);
        cout << ans << endl;
    }
    return 0;
}