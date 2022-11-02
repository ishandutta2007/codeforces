#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> t3l;
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
#define lb_pos(arr, key) lower_bound(all(arr), key) - (arr).begin()
#define ub_pos(arr, key) upper_bound(all(arr), key) - (arr).begin()

// FILL by byte!!!
#define FILL(arr, num) memset(arr, num, sizeof(arr))

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

template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using MaxHeap = priority_queue<T>;

const ld PI = 3.14159265358979323846;
const ld E = 2.718281828459;
const ld EPS = 1e-8;
ll MOD = 1e9+7;
ll M(ll n) {return (n % MOD + MOD) % MOD;}
ll pow2(ll n) {return 1ll << n;}

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

const ll IN = 0, CHECK = 1, OUT = 2;
const ll MX = 1e6+2;
multiset<int> se[MX];
vector<t3l> seq[MX];

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);      
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll n, w; cin >> n >> w;
        REP(i, n) {
            ll len; cin >> len;
            REP(j, len) {
                ll val; cin >> val;
                ll l = j, r = w - len + j;
                seq[l].eb(IN, val, i);
                seq[r+1].eb(OUT, val, i);
            }
            if (len < w) {
                seq[0].eb(IN, 0, i);
                seq[w-len].eb(OUT, 0, i);
                seq[len].eb(IN, 0, i);
            }
        } 
        // REP(i, w) {
        //     seq[i].eb(CHECK, -1, -1);
        //     sort(all(seq[i]));
        // }

        vl ans(w), crt(n);
        ll tot = 0;
        REP(i, w) {
            for (auto [type, val, row] : seq[i]) {
                dbg(type, val, row);
                // if (type == CHECK) ans[i] = tot;
                if (type == IN) {
                    tot -= crt[row];
                    se[row].em(val);
                    if (!se[row].empty())crt[row] = *se[row].rbegin();
                    tot += crt[row];
                }
                if (type == OUT) {
                    tot -= crt[row];
                    se[row].erase(se[row].find(val));
                    if (!se[row].empty())crt[row] = *se[row].rbegin();
                    tot += crt[row];
                }
            }
            ans[i] = tot;
        }
        

        dbg(ans);
        REP(i, w) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}