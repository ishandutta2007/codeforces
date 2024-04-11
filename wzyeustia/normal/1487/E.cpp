#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;
typedef vector<ll> vl;
typedef vector<vl> vvl;

#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
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

const ll MOD = 1e9+7;
ll myMod(ll n) {return (n % MOD + MOD) % MOD;}

vector<pll> getSort(vl& dp, ll size) {
    vector<pll> ret;
    FOR(i, 1, size) {
        ret.eb(dp[i], i);
    }
    sort(all(ret));
    return ret;
} 

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);


    int T = 1;
    // cin >> T;
    REP(I, T) {
        vl n(5); FOR(i, 1, 4) {cin >> n[i];}
        dbg(n);

        vvl dishes(5);
        FOR(i, 1, 4) {
            vl vec(n[i]+3);
            FOR(j, 1, n[i]) cin >> vec[j];
            dishes[i] = vec;
        }

        vector<vector<unordered_set<ll>>> allPairs(4);
        FOR(i, 1, 3) {
            vector<unordered_set<ll>> aLayer(n[i]+5);
            ll m; cin >> m;
            REP(j, m) {
                ll x, y; cin >> x >> y;
                aLayer[x].emplace(y);
            }
            allPairs[i] = aLayer;
        } 

        vvl dp(5, vl(3e5, 9e9));
        FOR(i, 1, n[1]) dp[1][i] = dishes[1][i];
        vector<pll> last = getSort(dp[1], n[1]);


        FOR(i, 1, 3) {
            stack<ll> toCheck;
            FOR(j, 1, n[i+1]) {
                toCheck.emplace(j);
            }
            vector<unordered_set<ll>> &pairs = allPairs[i];

            for (auto pa : last) {
                stack<ll> forNext;
                ll cost, idx; tie(cost, idx) = pa;

                while (!toCheck.empty()) {
                    ll next = toCheck.top(); toCheck.pop();

                    if (pairs[idx].count(next)) forNext.emplace(next);
                    else dp[i+1][next] = cost + dishes[i+1][next];
                }

                toCheck.swap(forNext);
            }
            // dbg(dp[i+1]);

            last = getSort(dp[i+1], n[i+1]);
        }

        ll ans = last[0].first;
        if (ans >= 9e9) {
            cout << -1 << endl;
        }
        else {
            cout << ans << endl;
        }
        // dbg(last[0].first);


    }
    return 0;
}