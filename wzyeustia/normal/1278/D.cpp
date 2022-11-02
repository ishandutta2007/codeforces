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

// BIT
int lowbit(int num) {return num & (-num);}

void init(vector<int> &arr, int n, vector<int> &BIT) {
    FOR(i, 1, n) {
        BIT[i] = arr[i] - arr[i-lowbit(i)];
    }
}

int query(int k, vector<int> &BIT) {
    int sum = 0;
    for (int i = k; i > 0; i-=lowbit(i)) {
        sum += BIT[i];
    }
    return sum;
}

void update(int l, int r, int delta, vector<int> &BIT) {
    for (int i = l; i < BIT.size(); i+=lowbit(i)) {
        BIT[i] += delta;
    }
    for (int i = r+1; i < BIT.size(); i+=lowbit(i)) {
        BIT[i] -= delta;
    }
}

const ll IN = 0, OUT = 1;

vvl G;
vl vis;
ll dfs(ll u) {
    vis[u] = 1;
    ll ret = 1;
    for (auto v : G[u]) {
        if (!vis[v]) ret += dfs(v);
    }
    return ret;
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        int n; cin >> n;
        vector<t3l> seq(2*n+2);
        FOR(i, 1, n) {
            ll l, r; cin >> l >> r;
            seq[l] = {IN, i, l}, seq[r] = {OUT, i, l};
        }

        vi BIT(2*n+2, 0);

        bool can = true;
        ll tot = 0;
        FOR(i, 1, 2*n) {
            auto [type, idx, start] = seq[i];
            if (type == IN) {
                update(1, start-1, 1, BIT);
            } else {
                tot += query(start, BIT);
                update(1, start-1, -1, BIT);
            }
        }

        if (tot != n-1) can = false;
        else {
            G = vvl(n+2);
            set<pll> segs; 

            ll check = 0;
            FOR(i, 1, 2*n) {
                auto [type, idx, start] = seq[i];
                if (type == IN) {
                    segs.em(start, idx);
                } else {
                    segs.erase({start, idx});
                    auto iter = segs.upper_bound({start, idx});
                    while (iter != segs.end()) {
                        ll idx2 = iter->second;
                        G[idx].eb(idx2), G[idx2].eb(idx);

                        check++; iter++;
                    }
                }
            }

            assert(check == n-1);
            vis = vl(n+2, 0);
            if (dfs(1) != n) can = false;
        }

        if (can) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}