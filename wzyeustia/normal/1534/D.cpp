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
ll MOD = 1e9+7; // 998'244'353;
ll M(ll n) {return (n % MOD + MOD) % MOD;}
ll pow2(ll n) {return 1ll << n;}

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

ll n;
vl query(ll r) {
    cout << "? " << r << endl;
    cout.flush();
    vl ret(n+2); FOR(i, 1, n) cin >> ret[i];
    return ret;
}

set<pll> se;
void add(ll u, ll v) {
    if (u>v) swap(u, v);
    se.em(u, v);
}

void answer() {
    cout << "! " << endl;
    assert(se.size() == n-1);
    for (auto [u, v] : se) {
        cout << u << " " << v << endl;
    }
    cout.flush();
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        cin >> n;

        vl near(n+2, 1);
        vl dist = query(1);
        FOR(i, 1, n) if (dist[i] == 1) {
            add(1, i);
        }

        while (true) {
            dbg(near); dbg(dist);
            ll cand = -1, mx = 1;
            FOR(i, 1, n) if (dist[i] > mx) {
                cand = i, mx = dist[i];
            } 
            if (cand == -1) break;

            ll anc = near[cand], len = dist[cand];
            vl newDist = query(cand);
            vl chain(n+2, -1);

            FOR(i, 1, n) if (near[i] == anc) {
                if (dist[i] + newDist[i] == len) chain[dist[i]] = i;    
            }
            FOR(i, 2, len) {
                add(chain[i], chain[i-1]);
                // se.em(chain[i], chain[i-1]);
            }

            FOR(i, 1, n) if (near[i] == anc) {
                ll more = dist[i]+newDist[i] - len;
                near[i] = chain[dist[i]-more/2];
                
                if (more == 2) add(i, near[i]); //se.em(i, near[i]);
                dist[i] = more/2;
                
            }
        }

        answer();

        // dbg("done");
        // for (auto [u, v] : se) {
        //     dbg(u, v);
        // }
        
    }
    return 0;
}