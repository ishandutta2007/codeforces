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

ll n, m, q; 
bool flag = false;

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll n, m; cin >> n >> m;
        ll x, k, y; cin >> x >> k >> y;

        vl a(n+2); FOR(i, 1, n) cin >> a[i];
        a[0] = 0, a[n+1] = -1;

        vl b(m+2); FOR(i, 1, m) cin >> b[i];
        b[0] = 0, b[m+1] = -1;

        bool flag = false;

        vvl segs;
        vl sideCan;
        ll idx = 1;
        FOR(i, 1, m+1) {
            ll left = b[i-1], right = b[i], maxVal = -5;
            vl vec;
            while (a[idx] != right && idx <= n+1) {
                vec.eb(a[idx]); chkmax(maxVal, a[idx++]);
            }

            if (idx == n+2 && i != m+1) {
                flag = true; break;
            }

            if (max(left, right) > maxVal) sideCan.eb(1);
            else sideCan.eb(0);

            segs.eb(vec); idx++;
        }

        if (flag) {
            cout << -1 << endl;
            continue;
        }

        ll ans = 0;
        REP(i, segs.size()) {
            vl& vec = segs[i];
            ll vSize = vec.size();
            if (vSize == 0) continue;

            dbg(vec);
            if (!sideCan[i] && vSize < k) {
                ans = -1; break;
            }

            if (!sideCan[i]) {
                ans += min(x + y*(vSize-k), (vSize/k) * x + y * (vSize%k));
            } else {
                ans += min(y*vSize, (vSize/k) * x + y * (vSize%k));
            }
        }

        dbg(ans);
        cout << ans << endl;
    }
    return 0;
}