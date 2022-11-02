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

vl p, c;
ll ans;
void check(vl& cycle) {
    ll len = cycle.size();
    ll local = len;

    FOR(i, 1, len-1) {
        if (len % i == 0) {

            REP(j, i) {
                dbg(len, i, j);
                int color = cycle[j], can = true;

                for (int idx = j+i; idx < len; idx+=i) 
                    if (cycle[idx] != color) {can = false; break;}

                if (can) {local = i; break;}
            }
        }
        if (local < len) break;
    }

    chkmin(ans, local);
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    REP(I, T) {
        ll n; cin >> n;
        p = vl(n+1); FOR(i, 1, n) cin >> p[i];
        c = vl(n+1); FOR(i, 1, n) cin >> c[i];
        ans = n;

        vl visited(n+1, 0);
        FOR(i, 1, n) {
            if (!visited[i]) {
                vl cycle;

                ll idx = i; cycle.eb(c[i]); visited[idx] = 1;
                while (p[idx] != i) {
                    idx = p[idx]; cycle.eb(c[idx]); visited[idx] = 1;
                }

                dbg(cycle);
                check(cycle);
                dbg(ans);
            }
        }

        dbg(ans);
        cout << ans << endl;
    }
    return 0;
}