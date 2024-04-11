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
const ll SIZE = 3e2+3; 

const ll MOD = 998'244'353;
ll myMod(ll n) {return (n % MOD + MOD) % MOD;}

vector<vector<pll>> edges; 
vector<bool> visited;
vl lastVal;

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll n, m; cin >> n >> m;
        edges = vector<vector<pll>>(n+2);
        REP(i, m) {
            ll u, v, w; cin >> u >> v >> w;
            edges[u].eb(v, w);
            edges[v].eb(u, w);
        }

        vl dist(n+2, INT32_MAX);
        dist[1] = 0;
        MinHeap<pll> minHeap; minHeap.emplace(dist[1], 1);

        visited = vector<bool>(n+2, 0);
        lastVal = vl(n+2, 100);
        while (!minHeap.empty()) {
            auto [dis, node] = minHeap.top(); minHeap.pop(); 
            // ll dis, node; tie(dis, node) = pa;
            if (visited[node]) continue;
            visited[node] = true;

            for (auto [child, weight] : edges[node]) {
                // ll child, weight; tie(child, weight) = pa;
                if (lastVal[child] <= weight) continue;
                lastVal[child] = weight;

                for (auto [next, nextW] : edges[child]) {
                    // ll next, nextW; tie(next, nextW) = pa;
                    ll newDis = dis + sqr(weight+nextW);
                    if (dist[next] > newDis) {
                        dist[next] = newDis;
                        minHeap.emplace(dist[next], next);
                    }
                }
            }
        }

        dbg(dist);
        FOR(i, 1, n) {
            if (dist[i] >= 2e9) cout << -1 << " ";
            else cout << dist[i] << " ";
        }ln;
    }
    return 0;
}