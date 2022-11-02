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

const ll MOD = 998'244'353;
ll M(ll n) {return (n % MOD + MOD) % MOD;}

const ll MAXN = 1e6+1;

vl prime;
bool is_composite[MAXN];

void sieve (ll n) {
	std::fill (is_composite, is_composite + n, false);
	for (ll i = 2; i < n; ++i) {
		if (!is_composite[i]) prime.push_back (i);
		for (ll j = 0; j < prime.size () && i * prime[j] < n; ++j) {
			is_composite[i * prime[j]] = true;
			if (i % prime[j] == 0) break;
		}
	}
}

ll n, ans = 1e9;
vector<vector<pll>> edges;

void bfs(ll k) {
    // dbg(k);
    vl used(n), depth(MAXN, -1);
    queue<ll> que; que.em(k), depth[k] = 0;

    while (!que.empty()) {
        ll node = que.front(); que.pop();
        // dbg(node);
        for (auto [nxt, idx] : edges[node]) {
            // dbg(node, nxt);
            if (used[idx]) continue;

            used[idx] = true;
            if (depth[nxt] == -1) {
                depth[nxt] = depth[node] + 1;
                que.em(nxt);
            } else {
                chkmin(ans, depth[node] + depth[nxt] + 1);
            }
        }
    }
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    sieve(MAXN);
    ll sz = prime.size();
    edges = vector<vector<pll>>(MAXN);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        cin >> n;
        vl a(n); REP(i, n) cin >> a[i];
        
        bool single = false;
        REP(i, n) {
            if (a[i] == 1) single = true;

            vl fac;
            REP(j, sz) {
                ll pr = prime[j], cnt = 0;
                if (sqr(pr) > a[i]) break;

                while (a[i] % pr == 0) cnt++, a[i]/=pr;
                if (cnt%2) fac.eb(pr); 
            }
            if (a[i] > 1) fac.eb(a[i]);

            if (fac.size() == 0) single = true;
            if (single) break;

            if (fac.size() == 1) 
                fac.eb(1);
            
            edges[fac[1]].eb(fac[0], i), edges[fac[0]].eb(fac[1], i);
        }   
        dbg("factor done.");

        bfs(1);
        for (auto pr : prime) {
            if (pr > 1000) break;
            bfs(pr);
        }
        if (single) {
            cout << 1 << endl;
        } else {
            if (ans > n) cout << -1 << endl;
            else cout << ans << endl;
        }
    }
    return 0;
}