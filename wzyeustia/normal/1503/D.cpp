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
#define em emplace
#define mp make_pair
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

#define FILL0(arr) memset(arr, 0, sizeof(arr))

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

const ll LEFT = 0, RIGHT = 1;

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll n; cin >> n;
        vector<pll> card;
        vl allIdx(2*n+5);
        REP(i, n) {
            ll x, y; cin >> x >> y;
            card.eb(x, y);
            allIdx[x] = allIdx[y] = i;
        }

        bool can = true;
        vl used(2*n+5, 0);
        ll ans = 0, cnt = 0, nxtS = 1, nxtB = 2*n;

        ll l1 = 2*n+1, l2 = 1;
        ll r1 = 0, r2 = 2*n+1;
        while (cnt < n) {
            ll rev = 0, tot = 0;

            queue<pll> que; que.em(nxtS++, LEFT);
            while (!que.empty()) {
                auto [num, type] = que.front(); que.pop();
                if (used[num]) continue;
                ll idx = allIdx[num];

                auto [fr, ba] = card[idx]; tot++;
                if (type == LEFT && fr > ba) rev++;
                if (type == RIGHT && fr < ba) rev++;
                used[fr] = used[ba] = true;

                

                ll sm = min(fr, ba), big = max(fr, ba);
                if (type == LEFT) {
                    if (sm < l2 || sm > r2) can = false;
                    if (big > l1 || big < r1) can = false;
                    l1 = big, l2 = sm;
                } else {
                    if (sm < r1 || sm > l1) can = false;
                    if (big > r2 || big < l2) can = false;
                    r1 = sm, r2 = big;
                }

                while (nxtS <= sm) que.em(nxtS++, LEFT);
                while (nxtB >= big) que.em(nxtB--, RIGHT);

                
                // dbg(nxtS, nxtB);
            }

            dbg(rev, tot);
            cnt += tot;
            ans += min(rev, tot-rev);
        }

        dbg(can);
        dbg(ans);
        if (can) {
            cout << ans << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}