#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;
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
const ll MOD = 1e9+7;
ll M(ll n) {return (n % MOD + MOD) % MOD;}
ll pow2(ll n) {return 1ll << n;}

ll gcd(ll a, ll b) {
    if (a < b) swap(a, b);
    return (a % b == 0)? b: gcd(b, a%b);
}

const ll MAXN = 2e5+5;
ll dfn[MAXN], low[MAXN], dIndex, scc;
vl belong;
bool instack[MAXN];
stack<ll> stk;

ll n, m; 
vector<vector<pll>> G;
vl dist, nodeGCD, allGCD;

void tarjan(ll node){
    int to;
    dfn[node]=low[node]= ++dIndex;
    stk.em(node);

    for(auto [adj, len] : G[node]){
        to = adj;
        if(!dfn[to]){
            dist[to] = dist[node] + len;
            tarjan(to);
            chkmin(low[node],low[to]);
        }
        else if(!belong[to]) {
            chkmin(low[node],dfn[to]);
            nodeGCD[to] = __gcd(nodeGCD[to], dist[node]+len-dist[to]);
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
void solve_tarjan(){
    scc=dIndex=0;
    memset(dfn,0,sizeof(dfn));
    FOR(i, 1, n) if(!dfn[i]) tarjan(i);
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        cin >> n >> m;
        G = vector<vector<pll>>(n+2);
        REP(i, m) {
            ll a, b, len; cin >> a >> b >> len;
            G[a].eb(b, len);
        }

        dist = vl(n+2, 0), nodeGCD = vl(n+2), allGCD = vl(n+2);
        belong = vl(n+2, 0);
        solve_tarjan();
        dbg(belong); dbg(nodeGCD);
        FOR(i, 1, n) allGCD[belong[i]] = __gcd(allGCD[belong[i]], nodeGCD[i]);
        dbg(allGCD);

        ll q; cin >> q;
        REP(i, q) {
            ll v, s, t; cin >> v >> s >> t;
            bool can = false;
            ll least = __gcd(allGCD[belong[v]], t);
            dbg(least);
            if (s%least == 0)
                can = true;

            if (can) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}