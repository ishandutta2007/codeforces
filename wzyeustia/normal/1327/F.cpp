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
const ll SIZE = 2e5+5; 

const ll MOD = 998'244'353;
ll M(ll n) {return (n % MOD + MOD) % MOD;}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        // learnt from Origenes...
        // no need to sort, can calculate nxt in O(N+M)
        ll n, k, m; cin >> n >> k >> m;
        vector<tuple<ll, ll, ll>> seg;
        REP(i, m) {
            ll l, r, x; cin >> l >> r >> x;
            seg.eb(l, r, x);
        }
        // sort(all(seg));

        ll ans = 1;
        REP(level, k) {
            ll bit = (1ll << level);
            vl fixed(n+3, 0), nxt(n+3, -1), suf(n+3, n+1);

            ll near = n+1, idx = n;
            ROF(i, m-1, 0) {
                auto [l, r, x] = seg[i];
                if (x&bit) fixed[l]++, fixed[r+1]--;
                else chkmin(suf[l-1], r);
            }

            nxt[n+1] = n+1;
            ROF(i, n, 0) nxt[i] = min(nxt[i+1], suf[i]);
            partial_sum(all(fixed), fixed.begin());

            dbg(fixed); dbg(nxt);

            vl delta(n+3, 0); delta[0] = 1, delta[1] = -1;
            ll crt = 0;
            FOR(i, 0, n) {
                crt += delta[i]; crt %= MOD;
                dbg(i, crt);
                if (fixed[i]) continue;

                delta[i+1] += crt; delta[i+1] %= MOD;
                delta[nxt[i]+1] -= crt; delta[nxt[i]+1] = M(delta[nxt[i]+1]);
            }

            crt += delta[n+1]; crt %= MOD;
            dbg(crt);

            ans = M(ans * crt);
        }

        cout << ans << endl;
    }
    return 0;
}