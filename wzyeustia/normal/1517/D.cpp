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

ll n, m, k;
vector<t3l> G[501][501];

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    ll d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    int T = 1;
    // cin >> T;
    REP(I, T) {
        cin >> n >> m >> k;
        bool can = true;
        if (k%2) can = false;
        k /= 2;

        vvl mx(n+2, vl(m+2, 1e8));
        // vvl col(n+2, vl(m+1)); // (i, j) -> (i, j+1)
        ll cost;
        FOR(i, 1, n) FOR(j, 1, m-1) {
            cin >> cost;
            chkmin(mx[i][j], cost), chkmin(mx[i][j+1], cost);
            G[i][j].eb(i, j+1, cost), G[i][j+1].eb(i, j, cost);
        }
        // vvl row(n+1, vl(m+2)); // (i, j) -> (i+1, j)
        FOR(i, 1, n-1) FOR(j, 1, m) {
            cin >> cost;
            chkmin(mx[i][j], cost), chkmin(mx[i+1][j], cost);
            G[i][j].eb(i+1, j, cost), G[i+1][j].eb(i, j, cost);
        }

        vvvl dp(n+2, vvl(m+2, vl(k+1, 1e16)));
        FOR(i, 1, n) FOR(j, 1, m) dp[i][j][0] = 0;

        FOR(dis, 1, k) FOR(i, 1, n) FOR(j, 1, m) {
            for (auto [x, y, len] : G[i][j]) {
                chkmin(dp[i][j][dis], dp[x][y][dis-1] + len);
            }
        }

        FOR(i, 1, n) {
            FOR(j, 1, m) {
                if (can) printf("%lld ", dp[i][j][k]*2);
                else printf("%d ", -1);
            } printf("\n");
        }
    }
    return 0;
}