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

ll hsh(ll a, ll b) {if(a>b) swap(a, b); return a*1e6+b;}
pll decode(ll hsh) {return {hsh/1e6, hsh% 1'000'000};}

vector<set<ll>> edges;
vl ans1, vis;

void dfs(ll node, ll par) {
    vis[node] = 1; ans1.eb(node);
    for (auto adj : edges[node]) {
        if (!vis[adj]) dfs(adj, node);
    }
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    REP(I, T) {
        ll n; cin >> n;
        edges = vector<set<ll>>(n+2);

        vl cnt(n+2, 0);
        vvl tri2edge(n+2, vl(3));
        map<ll, vl> mp;
        FOR(i, 1, n-2) {
            ll a, b, c; cin >> a >> b >> c;
            mp[hsh(a, b)].eb(i), mp[hsh(b, c)].eb(i), mp[hsh(c, a)].eb(i); 
            tri2edge[i][0] = hsh(a, b), tri2edge[i][1] = hsh(b, c), tri2edge[i][2] = hsh(c, a); 
        }

        for (auto& [ha, vec] : mp) {
            if (vec.size() == 1) {
                auto [x, y] = decode(ha);
                edges[x].em(y), edges[y].em(x);
                // dbg(x, y);
            }
            for (auto& tri : vec) {
                cnt[tri] += vec.size();
            }
        }

        ans1.clear(); vis = vl(n+2, 0);
        dfs(1, -1);
        dbg(ans1);
        for (auto num : ans1) {
            cout << num << " ";
        }cout << endl;

        queue<ll> que;
        FOR(tri, 1, n-2) if (cnt[tri] <= 4) que.em(tri);

        vl ans2;
        while (!que.empty()) {
            ll tri = que.front(); que.pop();
            ans2.eb(tri);

            for (auto ha : tri2edge[tri]) {
                vl& adj = mp[ha];
                for (auto t : adj) {
                    cnt[t]--;
                    if (cnt[t] == 4) que.em(t);
                }
            } 
        } 

        dbg(ans2);
        for (auto num : ans2) {
            cout << num << " ";
        }cout << endl;
    }
    return 0;
}