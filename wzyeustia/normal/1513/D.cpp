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
#define reset(x, y) memset(x, y, sizeof(x))
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
const ll MOD = 1e9+7;
ll M(ll n) {return (n % MOD + MOD) % MOD;}

ll gcd(ll a, ll b) {
    if (a == 0 || b == 0) return 0;
    if (a < b) swap(a, b);
    return (a % b == 0)? b: gcd(b, a%b);
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    REP(I, T) {
        ll n, p; cin >> n >> p;
        vl a(n); vector<pll> seq; 
        REP(i, n) {
            cin >> a[i];
            seq.eb(a[i], i);
        }
        
        sort(all(seq));
        vl used(n); ll ans = 0;
        for (auto [num, pos] : seq) {
            dbg(num, pos);
            if (num >= p) break;

            ll idx = pos;
            while (idx > 0) {
                if (used[idx] || a[idx-1]%num != 0) break;
                ans += num, used[idx--] = 1;
            }
            idx = pos+1;
            while (idx < n) {
                if (used[idx] || a[idx]%num != 0) break;
                ans += num, used[idx++] = 1;
            }
        }

        FOR(i, 1, n-1) if (!used[i]) ans += p;

        dbg(ans);
        cout << ans << endl;
    }
    return 0;
}