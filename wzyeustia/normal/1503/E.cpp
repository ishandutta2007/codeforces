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
const ll MOD = 998'244'353;
ll M(ll n) {return (n % MOD + MOD) % MOD;}

ll fastPow(ll num, ll exp) {
    if (exp == 0) return 1;
    if (exp == 1) return num;
    else {
        ll half = fastPow(num, exp/2);
        if (exp % 2 == 1) 
            return sqr(half)%MOD * num % MOD;
        else 
            return sqr(half)%MOD;
    }
}
 
// number theory
ll getInv(ll y) {
    return fastPow(y, MOD-2)%MOD;
}

const ll SIZE = 1e5+3;
ll fac[SIZE], inv[SIZE];

ll comb(ll x, ll y) { // select y from x
    if (x < y) return 0;
    return fac[x] * inv[y]%MOD * inv[x-y]%MOD;
}

ll calc(ll n, ll m) {
    vvl val(m+2, vl(n+2)), pre(m+2, vl(n+2));

    FOR(i, 1, m-1) {
        FOR(x, 1, n) {
            ll upper = comb(i+x-1, i), lower = comb(i-1 + n-x, i-1);
            // dbg(i, x, upper, lower);
            val[i][x] = upper * lower % MOD;
            pre[i][x] = (pre[i][x-1] + val[i][x]) % MOD;
        }
        // dbg(pre[i]);
    }

    ll ans = 0, offset = 0;
    FOR(i, 1, m-1) FOR(x, 1, n) {
        ans = (ans + pre[i][x] * val[m-i][n-x]%MOD) % MOD;
        offset = (offset + val[i][x] * val[m-i][n-x]%MOD) % MOD;
    }
    ans = (2 * ans + MOD - offset) % MOD;

    return ans;
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    fac[0] = 1, inv[0] = 1;
    FOR(i, 1, SIZE-1) fac[i] = fac[i-1]*i%MOD;
    inv[SIZE-1] = getInv(fac[SIZE-1]);
    ROF(i, SIZE-2, 1) inv[i] = inv[i+1]*(i+1)%MOD;

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll n, m; cin >> n >> m;
        ll ans = (calc(n, m) + calc(m, n)) % MOD;
        cout << ans << endl;
    }
    return 0;
}