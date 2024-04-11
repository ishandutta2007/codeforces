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

vl F, mxGain, mxIdx, loCost;
ll find(ll k) {
    return F[k] == k? k : F[k] = find(F[k]);
}

// this template contains edges...
// to initialize, call lca_dfs(1, 0)
const ll POW = 20, LCA_SIZE = 2e5+3;
vector<pll> G[LCA_SIZE];
int depth[LCA_SIZE], p[LCA_SIZE][POW], toll[LCA_SIZE][POW];

void lca_dfs(ll u, ll par) {
    if (par <= 0) depth[par] = 0, toll[par][0] = 0;
	depth[u] = depth[par] + 1;
	p[u][0] = par;

	FOR(i, 1, POW-1) {
        ll head = p[u][i-1];
        p[u][i] = p[head][i-1];
        toll[u][i] = max(toll[u][i-1], toll[head][i-1]);
    }
		
    
	for (auto [child, cost] : G[u]) {
		if (child == par) continue;
        toll[child][0] = cost;
		lca_dfs(child, u);
	}
}

ll getToll(ll a, ll b) {
    int ret = 0;

	if (depth[a] > depth[b]) swap(a, b);
	if (depth[a] < depth[b]) {   //a,b
		ll del = depth[b] - depth[a];
		REP(i, POW) if (del & (1 << i)) chkmax(ret, toll[b][i]), b = p[b][i];
	}

    dbg(a, b, ret);

	if (a != b) {    //lca
		ROF(i, POW-1, 0) if (p[a][i] != p[b][i]) {
            chkmax(ret, max(toll[a][i], toll[b][i]));
            a = p[a][i], b = p[b][i];
        }
        
        chkmax(ret, max(toll[a][0], toll[b][0]));
		a = p[a][0], b = p[b][0];
	}

	return ret;
}

void doMerge(ll u, ll v) {
    ll f = find(u), g = find(v);
    if (mxGain[f] == mxGain[g]) {
        ll newToll = getToll(mxIdx[f], mxIdx[g]);
        chkmax(loCost[f], max(newToll, loCost[g]));
    } else if (mxGain[f] < mxGain[g]) {
        loCost[f] = loCost[g];
        mxIdx[f] = mxIdx[g];
    }

    F[g] = f;
    mxGain[f] = max(mxGain[f], mxGain[g]);
}

pll calc(ll u) {
    ll f = find(u);
    ll retGain = mxGain[f], retToll = loCost[f];
    dbg(u, f, mxIdx[f]);
    ll pathToll = getToll(u, mxIdx[f]);
    dbg(pathToll);

    chkmax(retToll, getToll(u, mxIdx[f]));

    return {retGain, retToll};
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);      
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll n, q; cin >> n >> q;
        vl a(n+1); FOR(i, 1, n) cin >> a[i];
        vector<t4l> seq; 
        REP(i, n-1) {
            ll u, v, cap, cost;
            cin >> u >> v >> cap >> cost;
            seq.eb(cap, u, v, cost);
            G[u].eb(v, cost), G[v].eb(u, cost);
        } sort(all(seq), greater<t4l>());
        
        vector<t3l> query;
        REP(i, q) {
            ll lim, u; cin >> lim >> u;
            query.eb(lim, u, i);
        } sort(all(query), greater<t3l>());

        
        F = vl(n+2), mxGain = vl(n+2), mxIdx = vl(n+2), loCost = vl(n+2, 0); 
        FOR(i, 1, n) F[i] = mxIdx[i] = i, mxGain[i] = a[i];
        lca_dfs(1, 0);


        vl gain(q), spend(q);
        ll idx = 0;
        for (auto [cap, u, v, cost] : seq) {
            while (idx < query.size()) {
                auto [lim, start, qIdx] = query[idx];
                if (lim <= cap) break;
                dbg(lim, qIdx);

                tie(gain[qIdx], spend[qIdx]) = calc(start);
                idx++;
            }
            dbg(cap, u, v, cost);
            doMerge(u, v);
        }

        while (idx < query.size()) {
            auto [lim, start, qIdx] = query[idx];
            tie(gain[qIdx], spend[qIdx]) = calc(start);
            idx++;
        }

        // dbg(gain); dbg(spend);
        REP(i, q) cout << gain[i] << " " << spend[i] << endl;
    }
    return 0;
}