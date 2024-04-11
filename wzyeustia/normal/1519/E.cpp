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

ll getInv(ll a, ll p) {
 return (a == 1 ? 1 : (1 - p * getInv(p % a, a)) / a + p);
}

ll gcd(ll a, ll b) {
    if (a < b) swap(a, b);
    return (a % b == 0)? b: gcd(b, a%b);
}

pll cancel(pll p) {
    ll div = gcd(p._1, p._2);
    return {p._1/div, p._2/div};
}

vl used;
map<pll, ll> visited;
map<pll, vector<pair<pll, ll>>> ma;
vector<pll> ans;

void dfs(pll node, ll lastIdx) {
    if (visited[node]) return;
    visited[node] = 1;

    ll last = -1;
    for (auto [adj, idx] : ma[node]) {
        if (idx == lastIdx) continue;
        if (!visited[adj]) dfs(adj, idx);
        if (!used[idx]) {
            if (last == -1) last = idx;
            else {
                // dbg(last, idx);
                used[last] = used[idx] = 1;
                ans.eb(last, idx);
                last = -1;
            }
        }
    }

    if (lastIdx != -1 && last != -1) {
        used[last] = used[lastIdx] = 1;
        ans.eb(last, lastIdx);
        last = -1;
    } 
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll n; cin >> n;
        used = vl(n);
        REP(i, n) {
            ll a, b, c, d; cin >> a >> b >> c >> d;
            pll s1 = cancel({(a+b)*d, b*c}),
                s2 = cancel({a*d, b*(c+d)});
            ma[s1].eb(s2, i), ma[s2].eb(s1, i);
        }

        for (auto& [slope, vec] : ma) {
            // dbg(slope); dbg(vec);
            if (!visited[slope]) dfs(slope, -1);
        }

        cout << ans.size() << endl;
        for (auto [n1, n2] : ans) {
            dbg(n1, n2);
            cout << n1+1 << " " << n2+1 << endl;
        }
    }
    return 0;
}