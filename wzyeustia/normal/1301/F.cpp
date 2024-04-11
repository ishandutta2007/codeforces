#include <bits/stdc++.h>

using namespace std;

typedef int ll;
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
#define ef emplace_front
#define em emplace
#define mp make_pair
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

// FILL by byte!!!
#define FILL(arr, num) memset(arr, num, sizeof(arr))

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

const ll SZ = 1001, NUM_COL = 41;
ll color[SZ][SZ];
ll dist[NUM_COL][SZ][SZ];
vector<pll> se[NUM_COL];

ll mx[4] = {0, 1, 0, -1};
ll my[4] = {1, 0, -1, 0};
ll n, m, k; 

bool valid(ll x, ll y) {
    return (x>0 && y>0 && x<=n && y<=m);
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        // taken from Retired_MiFaFaOvO...
        // core thought: if we didn't use teleport between same color,
        // we just calculate manhattan distance.

        // if we used at least 1 teleport, 
        // we can consider it as we start from some color, 
        // and we are trying to go to start point and end point. 

        // at first we are not on map, therefore we need to add 1 to distance.
        // when merge, since we only use 1 edge in this color, 
        // we need to cancel it by adding -1.

        cin >> n >> m >> k;
        FOR(i, 1, n) FOR(j, 1, m) {
            cin >> color[i][j];
            se[color[i][j]].eb(i, j);
        }
        FILL(dist, 0x7f);

        FOR(col, 1, k) {
            vl midPoint(k+2, 0x7f7f7f7f);
            midPoint[col] = 0;
            deque<pll> deq; deq.eb(0, col);

            while (!deq.empty()) {
                auto [x, y] = deq.front(); deq.pop_front();
                if (x == 0) {
                    ll crt = midPoint[y];
                    for (auto [nx, ny] : se[y]) {
                        if (dist[col][nx][ny] > crt+1)
                            dist[col][nx][ny] = crt+1, deq.eb(nx, ny);
                    }
                } else {
                    ll crt = dist[col][x][y];
                    if (midPoint[color[x][y]] > crt)
                        midPoint[color[x][y]] = crt, deq.ef(0, color[x][y]);
                    REP(i, 4) {
                        ll nx = x+mx[i], ny = y+my[i];
                        if (valid(nx, ny) && dist[col][nx][ny] > crt+1)
                            dist[col][nx][ny] = crt+1, deq.eb(nx, ny);
                    }
                }
            }
            // FOR(i, 1, n) {
            //     FOR(j, 1, m) {
            //         cout << dist[col][i][j] << " ";
            //     } cout << endl;
            // }
        }

        ll q; cin >> q;
        REP(i, q) {
            ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
            ll ans = abs(x2-x1) + abs(y2-y1);

            FOR(col, 1, k) chkmin(ans, dist[col][x1][y1] + dist[col][x2][y2] - 1);
            cout << ans << endl;
            dbg(ans);
        }
    }
    return 0;
}