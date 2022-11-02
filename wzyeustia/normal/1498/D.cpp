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

const ll MOD = 1e9+7;
ll M(ll n) {return (n % MOD + MOD) % MOD;}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll n, m; cin >> n >> m;
        vl can(m+1, 0); can[0] = 1;
        vl ans(m+1, -1); ans[0] = 0;

        FOR(cnt, 1, n) {
            ll t, x0, y; cin >> t >> x0 >> y;
            ld x = x0 / 1e5;
            dbg(x);

            vl step(m+1, 1e9);
            FOR(i, 0, m) {
                if (can[i]) step[i] = 0;
                ll nxt;
                if (t == 1) nxt = i+ (x0+99999)/100000;
                else nxt = (i*x0 + 99999ll)/100000;

                if (nxt <= m) {
                    chkmin(step[nxt], step[i]+1);
                }

                if (step[i] <= y) can[i] = true;
                if (can[i] && ans[i] == -1) ans[i] = cnt;
            }

        }

        dbg(can); dbg(ans);
        FOR(i, 1, m) cout << ans[i] << " ";
        ln;
    }
    return 0;
}