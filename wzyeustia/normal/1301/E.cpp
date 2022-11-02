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

#define FOR(i, a, b) for (ll (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (ll (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define em emplace
#define mp make_pair
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

#define FILL0(arr) memset(arr, 0, sizeof(arr))

#define ln printf("\n");

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
#define err(...)
#endif
// end

template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using MaxHeap = priority_queue<T>;

const ld PI = 3.14159265358979323846;
const ld E = 2.718281828459;
const ll MOD = 998'244'353;
ll M(ll n) {return (n % MOD + MOD) % MOD;}
ll pow2(ll n) {return 1ll << n;}

ll st[502][502][10][10];
ll bt[1000];

ll cover(ll x1, ll y1, ll x2, ll y2) {
    // dbg(x1, y1, x2, y2);
    ll sp1 = bt[x2-x1+1]-1, sp2 = bt[y2-y1+1]-1;
    // dbg(sp1, sp2);
    return max( max(st[x1][y1][sp1][sp2], st[x2-(1<<sp1)+1][y1][sp1][sp2]),
                max(st[x1][y2-(1<<sp2)+1][sp1][sp2], st[x2-(1<<sp1)+1][y2-(1<<sp2)+1][sp1][sp2]));
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    bt[1] = 1;
    FOR(i, 2, 500) bt[i] = bt[i/2] + 1;

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll n, m, q; cin >> n >> m >> q;
        vector<vector<char>> graph(n+2, vector<char>(m+2));
        FOR(i, 1, n) FOR(j, 1, m) {
            cin >> graph[i][j];
        }

        vvl red(n+2, vl(m+2, 0)), green(n+2, vl(m+2, 0)),
            yellow(n+2, vl(m+2, 0)), blue(n+2, vl(m+2, 0));
        FOR(i, 1, n) FOR(j, 1, m) {
            if (graph[i][j] != 'R') red[i][j] = 0;
            else red[i][j] = 1 + min(red[i-1][j-1], min(red[i-1][j], red[i][j-1]));
        }

        FOR(i, 1, n) ROF(j, m, 1) {
            if (graph[i][j] != 'G') green[i][j] = 0;
            else green[i][j] = 1 + min(green[i-1][j+1], min(green[i-1][j], green[i][j+1]));
        }

        ROF(i, n, 1) FOR(j, 1, m) {
            if (graph[i][j] != 'Y') yellow[i][j] = 0;
            else yellow[i][j] = 1 + min(yellow[i+1][j-1], min(yellow[i+1][j], yellow[i][j-1]));
        }

        ROF(i, n, 1) ROF(j, m, 1) {
            if (graph[i][j] != 'B') blue[i][j] = 0;
            else blue[i][j] = 1 + min(blue[i+1][j+1], min(blue[i+1][j], blue[i][j+1]));
        }

        vvl sz(n+2, vl(m+2, 1000));
        FOR(i, 1, n-1) FOR(j, 1, m-1) {
            chkmin(sz[i][j], min(red[i][j], green[i][j+1]));
            chkmin(sz[i][j], min(yellow[i+1][j], blue[i+1][j+1]));
        } 

        FOR(i, 1, n-1) dbg(sz[i]);

        FOR(i, 1, n-1) FOR(j, 1, m-1) st[i][j][0][0] = sz[i][j];
        REP(p, 10) REP(q, 10) FOR(i, 1, n-(1<<p)+1) FOR(j, 1, m-(1<<q)+1) {
            if (p>0) st[i][j][p][q] = max(st[i][j][p-1][q], st[i+(1<<(p-1))][j][p-1][q]);
            if (q>0) st[i][j][p][q] = max(st[i][j][p][q-1], st[i][j+(1<<(q-1))][p][q-1]);
        }

        REP(i, q) {
            ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
            ll l = 0, r = min(x2-x1+1, y2-y1+1)>>1;
            while (l<r) {
                ll mid = (l+r+1)>>1;
                ll val = cover(x1+mid-1, y1+mid-1, x2-mid, y2-mid);

                // dbg(mid, val);
                
                if (val >= mid) l = mid;
                else r = mid-1;
                // dbg(i, l, r);
            }
            dbg(l);
            cout << sqr(2*l) << endl;
        }
    }
    return 0;
}