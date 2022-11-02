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

#define ln printf("\n");

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
ll pow2(ll n) {return 1ll << n;}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll n, m, k; cin >> n >> m >> k;
        ll tot = 4*n*m - 2*n -2*m;
        if (k > tot) {
            cout << "NO" << endl;
            continue; 
        }

        // n, m = 1???

        cout << "YES" << endl;
        vector<tuple<string, ll>> seq;
        REP(i, m) {
            if (i != 0) seq.eb("R", 1);
            seq.eb("D", n-1);
            if (i != 0) seq.eb("LRU", n-1);
            else seq.eb("U", n-1);
        }
        seq.eb("L", m-1);

        vector<tuple<string, ll>> ans;
        for (auto [str, times] : seq) {
            if (times == 0 || k <= 0) continue;
            ll len = str.size();
            if (len * times < k) {
                // cout << times << " " << str << endl;
                ans.eb(str, times);
                k -= len*times;
            } else {
                ll used = k/len, rem = k%len;
                if (used) {
                    // cout << used << " " << str << endl;
                    ans.eb(str, used);
                }
                if (rem) {
                    // cout << "1 ";
                    // REP(i, rem) cout << str[i];
                    ans.eb(str.substr(0, rem), 1);
                } 
                break;
            }
        }

        cout << ans.size() << endl;
        for (auto [str, times] : ans) {
            cout << times << " " << str << endl;
        }


    }
    return 0;
}