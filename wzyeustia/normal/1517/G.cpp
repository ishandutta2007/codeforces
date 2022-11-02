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
ll MOD = 998'244'353;
ll M(ll n) {return (n % MOD + MOD) % MOD;}
ll pow2(ll n) {return 1ll << n;}

// maxflow & mincut
struct Dinic {
    struct Edge {
        int u, v; ll cap;
        Edge() : u(), v(), cap() {}
        Edge (int _u, int _v, ll _cap) : u(_u), v(_v), cap(_cap) {}
    };

    vector<Edge> edges;
    vvi Graph;
    int n, S, T;
    vi dist, cur;

    Dinic() : edges(), Graph(), S(), T() {}
	Dinic(int _n, int _S, int _T) {
		n = _n, S = _S, T = _T;
		Graph.resize(n);
		REP(i, n) Graph[i].clear();
		edges = vector<Edge>();
	}

    bool bfs() { // check if there is rest flow 
        dist.resize(n); REP(i, n) dist[i] = n;
        vector<int> que; que.eb(S), dist[S] = 0;
        for (int i = 0; i < que.size(); i++) {
            int u = que[i];
            // dbg(u);
            for (auto idx : Graph[u]) {
                Edge e = edges[idx];
                if (e.cap <= 0) continue; // cannot use
                if (dist[e.v] <= dist[u]+1) continue; // visited
            
                dist[e.v] = dist[u]+1;
                que.eb(e.v);
            }
        }
        // dbg(dist);
        return dist[T] < n;
    }

    ll dfs(int u, ll flow) {
        if (u == T || flow == 0) return flow;
        ll tot = 0;
        for (int& ptr = cur[u]; ptr<Graph[u].size(); ptr++) {
            ll idx = Graph[u][ptr]; Edge &e = edges[idx];
            if (dist[e.v] != dist[u]+1) continue; // not connected in bfs tree
        
            ll usedFlow = dfs(e.v, min(flow, e.cap));
            flow -= usedFlow, tot += usedFlow;
            edges[idx].cap -= usedFlow, edges[idx^1].cap += usedFlow;
            if (!flow) break;
        }
        return tot;
    }

    void add(int u, int v, ll w) { // add pair of flow
        // dbg(u, v, w);
        Graph[u].eb(edges.size());
        edges.eb(Edge(u, v, w));
        Graph[v].eb(edges.size());
        edges.eb(Edge(v, u, 0));
    }

    ll Flow() {
        const ll maxFlow = 1e16;
        ll ans = 0;
        while (bfs()) {
            cur.resize(n); REP(i, n) cur[i] = 0;
            ans += dfs(S, maxFlow);
            // dbg(ans);
        } return ans;
    }
} G;

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll n; cin >> n;
        ll source = 2*n+1, sink = 2*n+2;
        G = Dinic(2*n+4, source, sink);
        
        vector<pll> node(n+2); map<pll, ll> ma;
        ll sum = 0;
        FOR(i, 1, n) {
            ll x, y, w; cin >> x >> y >> w;
            x += 2e9, y += 2e9;
            node[i] = {x, y}, ma[node[i]] = i, sum += w;
            G.add(2*i-1, 2*i, w);
        }

        ll inf = 1e16;
        FOR(i, 1, n) {
            auto [x, y] = node[i];
            if (x%2 != y%2) {
                FOR(nx, x-1, x+1) {
                    ll nxt = ma[{nx, y}];
                    if (nxt && nxt != i) G.add(2*i, 2*nxt-1, inf);
                }
                if (x%2) {
                    G.add(source, 2*i-1, inf);
                    dbg(x, y, x%2, y%2);
                }
            } else if (x%2 == 0) {
                FOR(ny, y-1, y+1) {
                    ll nxt = ma[{x, ny}];
                    if (nxt && nxt != i) G.add(2*i, 2*nxt-1, inf);
                }
            } else {
                G.add(2*i, sink, inf);
            }
        }

        ll ans = sum - G.Flow();
        dbg(ans);
        cout << ans << endl;
    }
    return 0;
}