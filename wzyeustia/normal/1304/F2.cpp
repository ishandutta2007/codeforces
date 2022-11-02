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
#define reset(x, y) memset(x, y, sizeof(x))
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


#define Node seg[node]
#define LC seg[2*node]
#define RC seg[2*node+1]
const ll SIZE = 2e5+3;

// TODO: segment definition
struct Seg {
  int l, r, mid;
  ll val, lazy = 0;
} seg[SIZE*8];

void update(int l, int r, ll type, int node);

// TODO: pushdown & pushup process
void pDown(int node) {
    if (Node.lazy && Node.l != Node.r) {
        update(Node.l, Node.mid, Node.lazy, node*2);
        update(Node.mid+1, Node.r, Node.lazy, node*2+1);
        Node.lazy = 0;
    }
}

void pUp(int node) {
    Node.val = max(LC.val, RC.val);
}

void build(int l, int r, vl& init, int node = 1) {
    Node.l = l, Node.r = r, Node.mid = (l+r)>>1;
    Node.lazy = 0, Node.val = 0;
    if (l == r) {
        Node.val = init[l]; // TODO: init value
        // dbg(Node.val, init[l]);
    } else {
        build(l, Node.mid, init, 2*node); build(Node.mid+1, r, init, 2*node+1);
        pUp(node);
    }
}

void update(int l, int r, ll val, int node = 1) {
    // dbg(l, r, val);
    if (l <= Node.l && Node.r <= r) {
        // TODO: update 
        Node.lazy += val;
        Node.val += val;
    } else {
        pDown(node);
        if (l <= Node.mid) update(l, r, val, 2*node); 
        if (r > Node.mid) update(l, r, val, 2*node+1);
        pUp(node);
    }
}

ll query(int l, int r, int node = 1) {
    // dbg(Node.l, Node.r, node, Node.val);
    if (l <= Node.l && Node.r <= r) {
        return Node.val;
    } else {
        pDown(node);
        // TODO: combine 
        ll ret1 = 0, ret2 = 0;
        if (l <= Node.mid) ret1 = query(l, r, 2*node);
        if (r > Node.mid) ret2 = query(l, r, 2*node+1);
        return max(ret1, ret2);
    }
}

void status(ll n) {
    cout << "Status: ";
    FOR(i, 1, n) {
        cout << query(i, i) << " ";
    }ln;
}

vvl pre;
ll n, m, k; 

ll offset(ll i, ll j) {
    ll ret = pre[i][j]-pre[i][j-k] + pre[i-1][j]-pre[i-1][j-k];
    return ret;
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        cin >> n >> m >> k;
        vvl earn(n+2, vl(m+2));
        pre = vvl(n+2, vl(m+2));
        FOR(i, 1, n) FOR(j, 1, m) {
            cin >> earn[i][j];
            pre[i][j] = pre[i][j-1] + earn[i][j];
        }
        FOR(i, 1, n) dbg(pre[i]);

        vvl dp(n+2, vl(m+2));
        FOR(i, 1, n) {
            vl &init = dp[i-1];
            build(1, m, init);

            if (i > 1)  FOR(j, 1, k) update(1, j, -earn[i][j]);
            dp[i][1] = query(1, m) + offset(i+1, k);

            FOR(j, k+1, m) {
                ll le = max(1ll, j-2*k+1), ri = j-k;
                // dbg(j, earn[i-1][j-k], le, ri);

                ll last = earn[i][j-k], crt = earn[i][j];
                if (i > 1) {
                    update(le, ri, last);
                    update(j-k+1, j, -crt);
                }
                // status(m);
                dp[i][j-k+1] = query(1, m) + offset(i+1, j);
            }
            dbg(dp[i]);
        }

        ll ans = 0;
        FOR(j, 1, m) {
            chkmax(ans, dp[n][j]);
        }

        dbg(ans);
        cout << ans << endl;
    }
    return 0;
}