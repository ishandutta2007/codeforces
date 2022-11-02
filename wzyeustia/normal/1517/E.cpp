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

const ll SZ = 2e5+3;
vl pre, pre0, pre1, a;
ll sum;

ll calc(ll init, ll start, ll len) {
    ll cnt = 0, tot = init;
    if (init*2 >= sum) return 0;
    
    ll p2 = start+2, l2 = start+2;
    while (p2 <= start+len && (tot+a[p2])*2 < sum) {
        tot += a[p2], p2+=2;
    } 
    // cnt += (p2-l2)/2;
    // dbg(p2);

    ll p1 = start+1, l1 = start+1;
    while (p2 >= l2) {
        while (p1 <= start+len && (tot+a[p1])*2 < sum) {
            tot += a[p1], p1+=2;
        }
        cnt += (p1-l1+2)/2;
        dbg(p1, p2);
        p2 -= 2, tot -= a[p2];
    } 

    dbg(init, start, len, cnt);
    return cnt%MOD;
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    REP(I, T) {
        ll n; cin >> n; 
        a = vl(n+2); FOR(i, 1, n) cin >> a[i];
        pre = vl(n+2), pre0 = vl(n+2), pre1 = vl(n+2);
        FOR(i, 1, n) {
            pre[i] = pre[i-1]+a[i];
            if (i%2) pre1[i] = pre1[max(0ll, i-2)] + a[i];
            else pre0[i] = pre0[i-2] + a[i];
        } sum = pre[n];

        // dbg(pre); dbg(pre0); dbg(pre1);

        ll ans = 0;
        if (n <= 3) {
            REP(msk, pow(2, n)) {
                ll tot = 0;
                FOR(i, 1, n) {
                    if ((1<<(i-1)) & msk) tot += a[i];
                } if (tot*2 < sum) ans++;
            }
        } else {
            ans = calc(a[1], 1, n-2) + calc(a[1]+a[n], 1, n-3);
            ans += calc(a[2], 2, n-3) + calc(a[2]+a[n], 2, n-4);

            FOR(i, 0, n) {
                if (pre[i]*2 > sum) ans++;
            } 
        }

        dbg(ans);
        cout << ans%MOD << endl;
    }
    return 0;
}