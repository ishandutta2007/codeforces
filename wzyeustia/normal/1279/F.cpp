#include <bits/stdc++.h>

using namespace std;

typedef int ll;
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
ll MOD = 1e9+7;
ll M(ll n) {return (n % MOD + MOD) % MOD;}
ll pow2(ll n) {return 1ll << n;}

int n, k, len;
int solve(vi& a) {
    int l = 0, r = n, sum = 0;
    FOR(i, 1, n) sum += a[i];
    dbg(a); dbg(sum);

    int cost = 0, rest = sum, used = 0;
    while (l<=r) {
        int mid = (l+r)>>1;
        vi dp(n+len+2, 1e9), op(n+len+2, 1e9); dp[0] = op[0] = 0;
        FOR(i, 1, n+len) {
            dp[i] = dp[i-1] + a[i], op[i] = op[i-1];
            if (i >= len && dp[i] >= dp[i-len] + mid) {
                if (dp[i] > dp[i-len] + mid) op[i] = op[i-len]+1;
                else chkmin(op[i], op[i-len]+1); 
                dp[i] = dp[i-len] + mid;
            } 
        }

        dbg(l, r);
        dbg(mid, dp[n+len], op[n+len]);

        if (op[n] > k) {
            l = mid+1;
        } else {
            cost = mid, rest = dp[n+len], used = op[n+len];
            r = mid-1;
        }
    }
    dbg(cost, rest, used);

    int ans = rest - k*cost;
    return ans;
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        cin >> n >> k >> len;
        string s; cin >> s;
        vi a(n+len+2); REP(i, n) a[i+1] = (s[i] >= 'a' && s[i] <= 'z');

        int ans = 1e9;
        chkmin(ans, solve(a));
        FOR(i, 1, n) a[i] ^= 1;
        chkmin(ans, solve(a));
        dbg(ans); cout << ans << endl;
    }
    return 0;
}