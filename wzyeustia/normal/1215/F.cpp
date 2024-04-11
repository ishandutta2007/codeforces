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

vvl G;
inline ll white(ll u) {return (u<<1);} // not selected
inline ll black(ll u) {return (u<<1)^1;} // selected

void addEdge(ll u, bool b1, ll v, bool b2) {
    ll k1 = (u<<1)^b1, k2 = (v<<1)^b2;
    G[k1].eb(k2);
}
void ban(ll u, bool b1, ll v, bool b2) {
    addEdge(u, b1, v, !b2);
    addEdge(v, b2, u, !b1);
}

const ll MAXN = 2e6+5;
ll dfn[MAXN], low[MAXN], belong[MAXN], dIndex, scc;
bool instack[MAXN];
stack<ll> stk;

void tarjan(ll node){
    int to;
    dfn[node]=low[node]= ++dIndex;
    stk.em(node);

    for(auto adj : G[node]){
        to = adj;
        if(!dfn[to]){
            tarjan(to);
            chkmin(low[node],low[to]);
        }
        else if(!belong[to]) {
            chkmin(low[node],dfn[to]);
        }
    }

    if(dfn[node]==low[node]){
        scc++;
        do{
            to=stk.top(), stk.pop();
            belong[to]=scc;
        }while(to!=node);
    }
}
void solve_tarjan(ll n){
    scc=dIndex=0;
    memset(dfn,0,sizeof(dfn));
    FOR(i, 1, n) if(!dfn[i]) tarjan(i);
}
inline bool selected(ll u) {
    return belong[u<<1] > belong[(u<<1)|1];
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);      
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
		ll c1, n, hi, c2; cin >> c1 >> n >> hi >> c2;
        G = vvl(2*n+2*hi+7);
        FOR(i, 1, hi-1) {
            ll crt = i+n;
            ban(crt, 0, crt+1, 1);
        }
        REP(i, c1) {
            ll u, v; cin >> u >> v;
            ban(u, 0, v, 0);
        }
        FOR(u, 1, n) {
            ll l, r; cin >> l >> r;
            ban(u, 1, n+l, 0);
            if (r+1 <= hi) ban(u, 1, n+r+1, 1);
        }
        REP(i, c2) {
            ll u, v; cin >> u >> v;
            ban(u, 1, v, 1);
        }

        solve_tarjan(2*n+2*hi+3);

        bool can = true;
        FOR(i, 1, n+hi) if (belong[i<<1] == belong[(i<<1)|1]) can = false;
        if (!can) cout << -1 << endl;
        else {
            ll f = -1;
            vl sel;
            FOR(i, 1, n) if (selected(i)) sel.eb(i);
            FOR(i, n+1, n+hi) if (selected(i)) {
                f = i-n;
            }
            ll k = sel.size();

            cout << k << " " << f << endl;
            for (auto u : sel) {
                cout << u << " ";
            } cout << endl;
        }
    }   
    return 0;
}