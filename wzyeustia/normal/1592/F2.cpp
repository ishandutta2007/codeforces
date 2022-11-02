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
const ld EPS = 1e-8;
ll MOD = 1e9+7;
ll M(ll n) {return (n % MOD + MOD) % MOD;}
ll pow2(ll n) {return 1ll << n;}

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

// 1->red, 0->black

const ll MAX_NODE = 2*500 + 5;
vvl G(MAX_NODE);
ll match[MAX_NODE];
bool inPath[MAX_NODE];

ll n, m;

ll lim;
ll dist[MAX_NODE]; // dist in bfs
bool bfs() {
    queue<ll> q;
    lim = 1e9;
    FILL(dist, 0);
    FOR(i, 1, n) if (!match[i]) dist[i] = 1, q.em(i);

    while (!q.empty()) {
        auto u = q.front(); q.pop();
        if (dist[u] > lim) break;
        for (auto v : G[u]) {
            if (!dist[v]) {
                dist[v] = dist[u] + 1;
                if (!match[v]) lim = dist[v];
                else dist[match[v]] = dist[v] + 1, q.em(match[v]);
            }
        }
    }

    return lim != 1e9;
}

bool augmentPath(ll u) {
    for (auto v : G[u]) if (!inPath[v] && dist[v] == dist[u]+1) {
        inPath[v] = 1;
        if (match[v] && dist[v] == lim) continue;
        if (!match[v] || augmentPath(match[v])) {
            match[u] = v, match[v] = u;
            return true;
        }
    }
    return false;
}

int HKmaxMatching() {
    ll ans = 0;
    FILL(match, 0);
    while (bfs()) {
        FILL(inPath, 0);
        FOR(i, 1, n) if (!match[i]) {
            if (augmentPath(i)) ans++;
        }
    }
    return ans;
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);      
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        cin >> n >> m;
        bool suf[n+1][m+1], H[n+1][m+1];
        FILL(H, 0), FILL(suf, 0);

        string str[n];
        REP(i, n) {
            cin >> str[i];
            REP(j, m) suf[i][j] = str[i][j] == 'B';
        }
         
        ll ans = 0;
        ROF(i, n-1, 0) ROF(j, m-1, 0) {
            H[i][j] = suf[i][j] ^ suf[i+1][j] ^ suf[i][j+1] ^ suf[i+1][j+1];
            if (H[i][j]) ans++;
            if (i<n-1 && j<m-1) {
                if (H[i][j] && H[n-1][j] && H[i][m-1]) {
                    ll u = i+1, v = n+j+1;
                    G[u].eb(v), G[v].eb(u);
                }
            }
        }

        ll offset = HKmaxMatching();
        if (H[n-1][m-1]) offset++;
        offset = offset / 2 * 2;

        dbg(ans, offset);
        ans -= offset;
        cout << ans << endl;
    }
    return 0;
}