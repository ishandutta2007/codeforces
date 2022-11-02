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
const ll MOD = 1e9+7;
ll M(ll n) {return (n % MOD + MOD) % MOD;}

ll fastPow(ll num, ll exp) {
    if (exp == 0) return 1;
    if (exp == 1) return num;
    else {
        ll half = fastPow(num, exp/2);
        if (exp % 2 == 1) 
            return sqr(half)%MOD * num % MOD;
        else 
            return sqr(half)%MOD;
    }
}
 
// number theory
ll getInv(ll y) {
    return fastPow(y, MOD-2)%MOD;
}

vl p2(4e5, 1), p2_inv(4e5, 1);

#define Node seg[node]
#define LC seg[2*node]
#define RC seg[2*node+1]
const ll SIZE = 6e5+3, SET = 1, CLEAR = 0, SET_AND_ASK = 2;
vl earn(1e6);

struct Data {
    ll pre = 0, suf = 0, val = 0, cnt = 0;
};

// TODO: segment definition
struct Seg {
  int l, r, mid;
  Data data;
} seg[SIZE*4];


Data combine(Data &d1, Data &d2) {
    // dbg(d1.cnt, d1.pre, d1.suf, d1.val);
    // dbg(d2.cnt, d2.pre, d2.suf, d2.val);

    Data ret;
    ll tot = d1.val * p2[d2.cnt] % MOD + d2.val * p2[d1.cnt] % MOD; tot %= MOD;
    tot += d1.pre * d2.suf % MOD; tot %= MOD; 
    
    ret.val = tot;
    ret.pre = d1.pre + d2.pre * p2[d1.cnt] % MOD; ret.pre %= MOD;
    ret.suf = d2.suf + d1.suf * p2[d2.cnt] % MOD; ret.suf %= MOD;
    ret.cnt = d1.cnt + d2.cnt;
    // dbg(tot);

    return ret;
}

void update(int idx, int type, int node);

// TODO: pushdown & pushup process
void pDown(int node) {

}

void pUp(int node) {
    Node.data = combine(LC.data, RC.data);
}

void build(int l, int r, int node = 1) {
    Node.l = l, Node.r = r, Node.mid = (l+r)>>1;
    if (l == r) {
        // TODO: init value
    } else {
        build(l, Node.mid, 2*node); build(Node.mid+1, r, 2*node+1);
        pUp(node);
    }
}

void update(int idx, int type, int node = 1) {
    if (Node.l == Node.r && Node.l == idx) {
        // TODO: update 
        if (type == SET) {
            Node.data.cnt = 1;
            Node.data.pre = Node.data.suf = earn[idx];
            Node.data.val = 0;}
        else {
            Node.data.cnt = 0;
            Node.data.pre = Node.data.suf = Node.data.val = 0;}
    } else {
        pDown(node);
        if (idx <= Node.mid) update(idx, type, 2*node); 
        if (idx >  Node.mid) update(idx, type, 2*node+1);
        pUp(node);
    }
}

Data query(int l, int r, int node = 1) {
    // dbg(Node.l, Node.r, node);
    if (l <= Node.l && Node.r <= r) {
        return Node.data;
    } else {
        pDown(node);
        // TODO: combine 
        Data d[2];
        if (l <= Node.mid) d[0] = query(l, r, 2*node);
        if (r > Node.mid) d[1] = query(l, r, 2*node+1);
        return combine(d[0], d[1]);
    }
}

// void status() {
//     cout << "Status: ";
//     FOR(i, 1, n) {
//         cout << query(i, i) << " ";
//     }ln;
// }


int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    FOR(i, 1, 3e5+2) p2[i] = p2[i-1] * 2 % MOD;
    p2_inv[3e5] = getInv(p2[3e5]);
    ROF(i, 3e5-1, 1) p2_inv[i] = p2_inv[i+1] * 2 % MOD;

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll n; cin >> n;
        vl arr(n+2);
        vector<pll> p; FOR(i, 1, n) {
            ll val; cin >> val;
            arr[i] = val;
            p.eb(val, i);
        }

        ll q; cin >> q;
        vector<pll> querys;
        FOR(i, 1, q) {
            ll idx, x; cin >> idx >> x;
            querys.eb(idx, x);
            p.eb(x, n+i);
        }

        sort(all(p));
        FOR(i, 1, n+q) {
            earn[i] = p[i-1].first;
        }

        // cout << "p: " << endl;
        // REP(i, n+q) {
        //     cout << p[i].first <<" "<< p[i].second << " | "; 
        // }ln;

        // arr: [val, idx in segtree]
        vector<pll> seq;
        FOR(i, 1, n) {
            ll idx = lower_bound(all(p), mp(arr[i], i)) - p.begin() + 1;
            arr[i] = idx; // now arr saves real index in segtree
            if (i != n) seq.eb(idx, SET);
            else seq.eb(idx, SET_AND_ASK);
        }

        ll cnt = 0;
        for (auto [idx, x] : querys) {
            ll idx_of_x = lower_bound(all(p), mp(x, n+ (++cnt))) - p.begin() + 1;

            seq.eb(arr[idx], CLEAR);
            arr[idx] = idx_of_x;
            seq.eb(idx_of_x, SET_AND_ASK);
        }

        build(1, n+q);
        for (auto [idx, type] : seq) {
            dbg(idx, type);
            if (type == SET_AND_ASK) {
                update(idx, SET);
                cout << query(1, n+q).val * p2_inv[n] % MOD << endl; //  * p2_inv[n] % MOD 
            } else {
                update(idx, type);
            }
        } 


    }
    return 0;
}