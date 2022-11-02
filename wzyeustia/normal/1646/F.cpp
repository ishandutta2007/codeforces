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
ll MOD = 998'244'353;
// ll M(ll n) {return (n % MOD + MOD) % MOD;}
ll pow2(ll n) {return 1ll << n;}

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)


int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);      
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
		ll n; cin >> n;
        ll cnt[n+1][n+1]; FILL(cnt, 0);
        FOR(i, 1, n) {
            REP(j, n) {
                ll c; cin >> c;
                cnt[i][c]++;
            }
        }
        
        vvl ans;

        ll cost1 = 0;
        while (1) {
            bool done = true;
            vl idx(n+2, 1);
            FOR(i, 1, n) {
                ll mx = 1;
                FOR(c, 1, n) if (cnt[i][c] > mx) {
                    mx = cnt[i][c], idx[i] = c;
                }    
                if (mx > 1) done = false; 
            }

            if (done) break;
            cost1++;

            ll pos = 1;
            FOR(i, 2, n) if (cnt[i][idx[i]] > cnt[pos][idx[pos]]) pos = i;
            
            vl act(n);
            REP(i, n) {
                ll u = (i+pos)%n, v = (i+pos+1)%n;
                if (!u) u = n; if (!v) v = n;

                act[u-1] = idx[u];
                cnt[u][idx[u]]--, cnt[v][idx[u]]++;
                if (cnt[v][idx[u]] > cnt[v][idx[v]]) idx[v] = idx[u];
            }
            ans.eb(act);
        }

        dbg(cost1);

        FOR(i, 2, n) {
            REP(j, i-1) {
                vl act(n);
                REP(k, n) {
                    act[k] = (i-j+k+n)%n;
                    if (!act[k]) act[k] = n;
                }
                dbg(act);
                ans.eb(act);
            }
        }

        ll totCost = ans.size();
        cout << totCost << endl;
        for (auto& act : ans) {
            for (auto c : act) {
                cout << c << " ";
            } cout << endl;
        }
    }   
    return 0;
}