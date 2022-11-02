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
ll MOD = 998'244'353;
ll M(ll n) {return (n % MOD + MOD) % MOD;}
ll pow2(ll n) {return 1ll << n;}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    char ch[3] = {'0', '1', '?'};
    vl val(1e6); val['0'] = 0, val['1'] = 1, val['?'] = 2;
    const ll INSERT = 1, QUERY = 2;

    int T = 1;
    // cin >> T;
    REP(I, T) {
        const ll SIZE = 3e5+5;
        vl amt(SIZE), cost(SIZE); 
        ll q, crt = 0; cin >> q >> amt[0] >> cost[0];

        vvl fa(SIZE, vl(20, -1)); 
        FOR(i, 1, q) {
            ll type; cin >> type;
            if (type == INSERT) {
                crt = i;
                ll par; cin >> par >> amt[crt] >> cost[crt];
                fa[crt][0] = par;
                FOR(pow, 1, 19) {
                    ll last = fa[crt][pow-1];
                    if (fa[crt][pow-1] == -1) break;
                    fa[crt][pow] = fa[last][pow-1];
                }
                // dbg(fa[crt]);

            } else {
                ll v, w; cin >> v >> w;
                ll ans = 0, price = 0;
                while (w > 0 && amt[v]) {
                    ll head = v;
                    ROF(pow, 19, 0) {
                        ll anc = fa[head][pow];
                        if (anc != -1 && amt[anc]) head = anc;
                    }

                    ll got = min(w, amt[head]);
                    ans += got, price += got*cost[head];
                    amt[head] -= got, w -= got;

                    dbg(head, got);
                }

                dbg(ans, price);
                cout << ans << " " << price << endl;
                cout.flush();
            }
        }
    }
    return 0;
}