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
const ll SIZE = 2e5+5; 

const ll MOD = 998'244'353;
ll M(ll n) {return (n % MOD + MOD) % MOD;}

vvl star, edges;
vl used;

bool dfs(ll node, ll par) {
    used[node] = true;
    for (auto child : edges[node]) {
        if (child == par) continue;
        if (dfs(child, node))
            star[node].eb(child);
    }

    return star[node].empty();
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    REP(I, T) {
        ll n, m; cin >> n >> m;
        vector<set<ll>> exclude(n+2);
        REP(i, m) {
            ll l, r; cin >> l >> r;
            exclude[l].em(r); exclude[r].em(l);
        }

        vl ans1(n+2, 0), ans2(n+2, 0);

        set<ll> waitlist;
        ll rest = n;
        FOR(i, 1, n) {
            ll sz = n-1 - exclude[i].size();
            if (sz == 0) {
                ans1[i] = ans2[i] = rest--;
            } else {
                waitlist.em(i);
            }
        }

        edges = vvl(n+2), star = vvl(n+2);
        while (!waitlist.empty()) {
            queue<ll> que; que.em(*(waitlist.begin())); waitlist.erase(waitlist.begin());

            while (!que.empty() && !waitlist.empty()) {
                ll node = que.front(); que.pop();
                auto iter = waitlist.begin();

                while (iter != waitlist.end()) {
                    ll adj = (*iter++);
                    if (!exclude[node].count(adj)) {
                        que.em(adj); waitlist.erase(adj);
                        edges[node].eb(adj); edges[adj].eb(node);
                        dbg(node, adj);
                    }
                }
            }
        }

        used = vl(n+2, 0);
        FOR(i, 1, n) {
            if (!used[i] && !ans1[i]) {
                if (dfs(i, -1)) {
                    ll child = edges[i][0];
                    star[child].eb(i);
                }
            }
        }

        ll start = 1;
        FOR(i, 1, n) {
            dbg(star[i]);
            if (!star[i].empty()) {
                ans2[i] = start;
                for (auto num : star[i]) {
                    ans1[num] = start;
                    ans2[num] = ++start;
                }

                ans1[i] = start++;
            }
        }

        dbg(ans1); dbg(ans2);
        FOR(i, 1, n) cout << ans1[i] << ' '; ln;
        FOR(i, 1, n) cout << ans2[i] << ' '; ln;
    }
    return 0;
}