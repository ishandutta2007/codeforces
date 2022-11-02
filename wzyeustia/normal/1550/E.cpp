#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll, ll, ll> t3l;
typedef tuple<ll, ll, ll, ll> t4l;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
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

mt19937_64 rng((unsigned ll) chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<ll>(a, b)(rng)


int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll n, k; cin >> n >> k;
        string s; cin >> s;

        ll l = 1, r = n, ans = 0;
        while (l<=r) {
            ll len = (l+r)>>1;
            bool can = false;

            vector<queue<ll>> head(k);
            vl cnt(k, 0);
            ll tot = 0;
            REP(i, len) if (s[i] != '?') {
                if (!cnt[s[i]-'a']) tot++;
                cnt[s[i]-'a']++;
            }

            if (tot == 1) REP(col, k) if (cnt[col]) {
                head[col].em(0);
                break;
            }
            if (tot == 0) REP(col, k) head[col].em(0);

            REP(ta, n-len) {
                ll he = ta+len;
                if (s[he] != '?') {
                    if (!cnt[s[he]-'a']) tot++;
                    cnt[s[he]-'a']++;
                }
                if (s[ta] != '?') {
                    cnt[s[ta]-'a']--;
                    if (!cnt[s[ta]-'a']) tot--;
                }
                

                if (tot == 1) REP(col, k) if (cnt[col]) {
                    head[col].em(ta+1);
                    break;
                }
                if (tot == 0) REP(col, k) head[col].em(ta+1);
            }
            
            vl dp((1 << k), 1e9); dp[0] = 0;
            MinHeap<pll> heap; heap.em(0, 0);
            while (!heap.empty()) {
                auto [pos, mask] = heap.top(); heap.pop();
                if (dp[mask] != pos) continue;

                REP(col, k) {
                    while (!head[col].empty() && head[col].front() < pos) head[col].pop();
                    ll nxt = -1; 
                    if (!head[col].empty()) nxt = head[col].front() + len;
                    // dbg(mask, col, nxt);
                    if (nxt != -1) {
                        ll nMask = mask | (1 << col);
                        if (dp[nMask] > nxt) {
                            dp[nMask] = nxt; heap.em(nxt, nMask);
                        }
                    }
                }
            }
            // dbg(dp);
            can = (dp[(1<<k)-1] < 1e9);

            dbg(len, can);
            if (can) {
                ans = len, l = len+1;
            } else r = len-1;
        }

        dbg(ans);
        cout << ans << endl;
    }
    return 0;
}