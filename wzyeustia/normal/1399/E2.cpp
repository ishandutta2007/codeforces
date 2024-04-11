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
ll sum;
vector<vector<tuple<ll, ll, ll>>> edges;
vector<ll> weights, sizes, costs;

ll dfs(ll node, ll parent, ll weight, ll cost) {
    ll size = 0;
    if (edges[node].size() == 1) size++;

    for (auto tu : edges[node]) {
        ll fir, sec, thi; tie(fir, sec, thi) = tu;
        ll child = fir;
        if (child != parent) {
            size += dfs(child, node, sec, thi);
        }
    }

    sizes[node] = size;
    weights[node] = weight;
    costs[node] = cost;
    sum += size * weight;
    return size;
}

vector<ll> deal(priority_queue<pair<ll, ll>> &pq) {
    vector<ll> ret;
    ll tot = 0;
    ret.eb(tot);

    while (sum - tot > s && !pq.empty()) {
        auto pa = pq.top(); pq.pop();
        ll earning, node; tie(earning, node) = pa;

        tot += earning;
        ret.eb(tot);

        weights[node] /= 2; 
        ll newEarning = (weights[node]+1)/2 * sizes[node];
        if (newEarning > 0)
            pq.emplace(newEarning, node);
    }

    return ret;
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    REP(I, T) {
        sum = 0;
        cin >> n >> s;
        edges = vector<vector<tuple<ll, ll, ll>>>(n+5);
        weights = vector<ll>(n+5, 0);
        sizes = vector<ll>(n+5, 0);
        costs = vector<ll>(n+5, 0);
        

        REP(i, n-1) {
            ll u, v, w, c; cin >> u >> v >> w >> c;
            edges[u].eb(v, w, c);
            edges[v].eb(u, w, c);
        }

        dfs(1, -1, 0, 0);

        priority_queue<pair<ll, ll>> pq1, pq2;
        FOR(i, 2, n) {
            ll earning = (weights[i]+1)/2 * sizes[i];
            if (costs[i] == 2) 
                pq2.emplace(earning, i); 
            else 
                pq1.emplace(earning, i);
        }

        ll ans = 2e9;
        vector<ll> earn1 = deal(pq1), earn2 = deal(pq2);
        dbg(earn1); dbg(earn2);
        
        REP(i, earn1.size()) {
            auto iter = lower_bound(all(earn2), sum-s - earn1[i]);
            if (iter == earn2.end()) continue;

            ll pos = iter - earn2.begin();
            ll totCost = i + 2*pos;

            chkmin(ans, totCost);
        }

        dbg(ans);
        cout << ans << endl;
    }
    return 0;
}