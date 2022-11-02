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

ll getInv(ll a, ll p) {
 return (a == 1 ? 1 : (1 - p * getInv(p % a, a)) / a + p);
}

const ll FAC_SIZE = 55;
ll fac[FAC_SIZE], inv[FAC_SIZE];
void initFac(ll sz) {
    fac[0] = 1, inv[0] = 1;
    FOR(i, 1, sz-1) {
        fac[i] = fac[i-1]*i;
        dbg(i, fac[i]);
    }
}

ll find(ll k, vl& F) {
    return F[k] == k? k : F[k] = find(F[k], F);
}

void allocate(ll start, ll pos, ll len, vl& ans) {
    dbg(start, pos, len);
    vl can(len+2, 1); can[len] = 0;
    vl F(len+2); FOR(i, 1, len) F[i] = i;
    F[len] = 1;
    ll ban = 1;

    ROF(f, len-1, 2) {
        ban++;
        ll div = fac[max(0ll, f-2)], th = (pos+div-1)/div;
        pos %= div; if (!pos) pos = div;
        dbg(f, div, th);
    
        ll num = 1;
        while (true) { 
            if (can[num] && find(num, F) != find(ban, F))  {
                th--;
                if (th == 0) break;
            } num++;
        }

        can[num] = 0;
        ans[start+ban-1] = num+start-1;
        F[find(num, F)] = find(ban, F);
    }
    FOR(i, 1, len) if (can[i]) {ans[start+len-1] = start+i-1; break;}
    ans[start] = start+len-1;
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    initFac(21);

    vvl dp(52, vl(52, 0));
    dp[0][0] = 1;
    ll lim = 0;
    FOR(i, 1, 50) {
        FOR(j, 1, i) {
            dp[i][j] = dp[i-j][0] * fac[max(0ll, j-2)], dp[i][0] += dp[i][j]; 
            if (dp[i][0] > 1e18 || dp[i][0] < 0) {lim = i; break;} 
        }
        if (lim) break;
    }

    // cout << "dp: " << endl;
    // FOR(i, 1, 50) cout << dp[i][0] << " ";
    // cout << endl;
    // dbg(lim);

    int T = 1;
    cin >> T;
    REP(I, T) {
        ll n, k; cin >> n >> k;
        if (n <= lim && k > dp[n][0]) {
            cout << -1 << endl;
            continue;
        }

        vl ans(n+2, 0);
        FOR(i, 1, n-lim) ans[i] = i;

        ll i = max(1ll, n-lim+1);
        while (i <= n) {
            ll rest = n-i+1, crt = 0, len = 0;
            do {
                crt += dp[rest][++len];
            } while (crt < k);

            dbg(len, crt, k);
            
            FOR(pp, 1, len-1) k -= dp[rest][pp];
            ll div = dp[rest-len][0];
            ll pos = (k+div-1) / div;
            k %= div; if (!k) k = div;

            dbg(k);
            allocate(i, pos, len, ans);

            i += len;
        }

        dbg(ans);
        FOR(i, 1, n) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}