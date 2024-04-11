#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;
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
const ll MOD = 1e9+7;
ll M(ll n) {return (n % MOD + MOD) % MOD;}
ll pow2(ll n) {return 1ll << n;}

ll n;
vvl edges;
vl dp, extra, pt1, pt2;

vector<tuple<ll, ll, ll, ll>> ans;
void cut2link(ll a, ll b, ll c, ll d) {
    ans.eb(a, b, c, d);
}

void dfs(ll node, ll par) {
    pt1[node] = pt2[node] = node;
    ll childCnt = 0, extraCnt = 0, sum = 0;
    for (auto adj : edges[node]) {
        if (adj == par) continue;
        dfs(adj, node);
        if (extra[adj] == 0 && pt1[node] == node) pt1[node] = pt1[adj];
        else if (extra[adj] == 0 && pt2[node] == node) pt2[node] = pt1[adj];

        childCnt++, extraCnt += extra[adj], sum += dp[adj];
    }

    if (childCnt == 0) {
        dp[node] = 0, extra[node] = 0;
        return;
    }

    ll delta = childCnt-extraCnt;
    if (delta <= 1) extra[node] = 0;

    ll save = min(delta, 2ll);
    dp[node] = sum + childCnt - save;

    for (auto adj : edges[node]) {
        if (adj == par) continue;
        if (extra[adj] == 0 && save) {
            save--;
        } else {
            cut2link(adj, node, pt1[adj], pt1[node]);
            pt1[node] = pt2[adj];
        }
    }
    // if (delta == 0) dp[node]++;

    dbg(node, dp[node], extra[node]);
    dbg(pt1[node], pt2[node]);
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    REP(I, T) {
        cin >> n; edges = vvl(n+2);
        dp = vl(n+2, 1e9), extra = vl(n+2, 1), pt1 = vl(n+2), pt2 = vl(n+2);
        ans = vector<tuple<ll, ll, ll, ll>>();
        REP(i, n-1) {
            ll u, v; cin >> u >> v;
            edges[u].eb(v), edges[v].eb(u);
        }

        dfs(1, 0);

        cout << dp[1] << endl;
        for (auto [a, b, c, d] : ans) {
            cout << a << " " << b << " " << c << " " << d << endl;
        }
    }
    return 0;
}