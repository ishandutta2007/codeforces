#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

#define MKPR make_pair
#define ALL(c) begin(c), end(c)
#define ALLn(arr, n) arr, arr+n
#define FILL0(arr) memset(arr, 0, sizeof(arr))
#define FILL1(arr) memset(arr, -1, sizeof(arr))

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

constexpr ll MOD = 1e9+7;
constexpr double EPS = 1e-8;
//Common variables

template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;

const ll SIZE = 3+5e5;
vector<ll> F(SIZE);
vector<vector<pair<ll, ll>>> edges(SIZE, vector<pair<ll, ll>>());

vector<vector<ll>> dist(SIZE, vector<ll>(2, LLONG_MAX));
set<pair<ll, ll>> candidates;

ll realDis(ll node) {
    return max(dist[node][0], dist[node][1]);
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(asdias, T) {
        ll n, m; cin >> n >> m;
        REP(i, m) {
            ll u, v, t; cin >> u >> v >> t;
            // edges[u].eb(v, t);
            edges[v].eb(u, t);
        } 

        candidates.emplace(0, n);
        dist[n][0] = dist[n][1] = 0;

        while (!candidates.empty()) {
            auto first = candidates.begin();
            ll distance, node; tie(distance, node) = *first;
            candidates.erase(*first);
            if (distance == LLONG_MAX) break;

            for (auto adj : edges[node]) {
                ll next, type; tie(next, type) = adj;
                if (dist[next][type] > distance + 1) {
                    candidates.erase(MKPR(realDis(next), next));
                    dist[next][type] = distance + 1;
                    candidates.emplace(realDis(next), next);
                }
                // dbg('!');
            }
            // dbg("?");
        }

        if (realDis(1) != LLONG_MAX) 
            cout << realDis(1) << endl;
        else cout << -1 << endl;

        FOR(i, 1, n) {
            if (realDis(i) == dist[i][0]) 
                cout << 0;
            else cout << 1;
        }cout << endl;
        // dbg("finished.");
        

        // keep track of distance by black/white
        // every time get node with minimum min(disB, disW);
    }
    return 0;
}