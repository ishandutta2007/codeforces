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
const ll SIZE = 2e6+5; 

const ll MOD = 998'244'353;
ll M(ll n) {return (n % MOD + MOD) % MOD;}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll n, k; cin >> n >> k;
        vl a(n); REP(i, n) cin >> a[i];
        sort(all(a), greater<ll>());
        dbg(a);

        vl limit(k, 0); ROF(i, k-1, 0) cin >> limit[i];

        vvl ans;
        set<pll> se;
        REP(i, n) {
            auto iter = se.lower_bound(mp(a[i], -99ll));
            if (iter == se.end()) {
                // dbg(i, "new");
                ll idx = ans.size();
                vl vec; vec.eb(a[i]);
                ans.eb(vec);
                
                
                auto iter2 = lower_bound(all(limit), (ll) vec.size()+1);
                if (iter2 != limit.end()) {
                    ll mx = k - (iter2 - limit.begin());
                    se.em(mx, idx);
                }

            } else {
                // dbg(i, "old");
                auto [last, idx] = (*iter);
                se.erase(iter);

                // dbg(last, a[i]);
                vl& vec = ans[idx];
                vec.eb(a[i]);
                
                auto iter2 = lower_bound(all(limit), (ll) vec.size()+1);
                if (iter2 != limit.end()) {
                    ll mx = k - (iter2 - limit.begin());
                    se.em(mx, idx);
                    // dbg(mx, idx);
                }
            }
        }

        ll sz = ans.size();
        dbg(sz);
        cout << sz << endl;
        REP(i, sz) {
            ll cnt = ans[i].size();
            cout << cnt << " ";
            for (auto num : ans[i]) {
                cout << num << " ";
            }ln;
        }
    }
    return 0;
}