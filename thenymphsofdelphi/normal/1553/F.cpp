#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#pragma GCC optimize("O3,unroll-loops,no-stack-protector")

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (int i = l; i < r; i++)
#define ForE(i, l, r) for (int i = l; i <= r; i++)
#define FordE(i, l, r) for (int i = l; i >= r; i--)
#define Fora(v, a) for (auto v: a)
#define bend(a) a.begin(), a.end()
#define isz(a) ((signed)a.size())

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pii>;
using vvi = vector <vi>;

const int N = (1 << 20) + 5, M = 3e5;

struct lazy_segment_tree{
    ll seg[N], lazy[N];
    
    void down(int id, int l, int r){
        int mid = (l + r) >> 1;
        lazy[id << 1] += lazy[id];
        lazy[id << 1 | 1] += lazy[id];
        seg[id << 1] += lazy[id] * (mid - l + 1);
        seg[id << 1 | 1] += lazy[id] * (r - mid);
        lazy[id] = 0;
    }
    
    void build(int id, int l, int r){
        if (l == r){
            seg[id] = 0;
            return;
        }
        int mid = (l + r) >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
        seg[id] = seg[id << 1] + seg[id << 1 | 1];
    }
    
    void update(int id, int l, int r, int u, int v, int val){
        if (v < l || r < u){
            return;
        }
        if (u <= l && r <= v){
            seg[id] += (ll)(r - l + 1) * val;
            lazy[id] += val;
            return;
        }
        down(id, l, r);
        int mid = (l + r) >> 1;
        update(id << 1, l, mid, u, v, val);
        update(id << 1 | 1, mid + 1, r, u, v, val);
        seg[id] = seg[id << 1] + seg[id << 1 | 1];
    }
    
    ll get(int id, int l, int r, int u, int v){
        if (v < l || r < u){
            return 0;
        }
        if (u <= l && r <= v){
            return seg[id];
        }
        down(id, l, r);
        int mid = (l + r) >> 1;
        return get(id << 1, l, mid, u, v) + get(id << 1 | 1, mid + 1, r, u, v);
    }
} it1;

struct segment_tree{
    ll seg[N];
    
    void build(int id, int l, int r){
        if (l == r){
            seg[id] = 0;
            return;
        }
        int mid = (l + r) >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
        seg[id] = seg[id << 1] + seg[id << 1 | 1];
    }
    
    void update(int id, int l, int r, int i, int val){
        if (l == r){
            seg[id] += val;
            return;
        }
        int mid = (l + r) >> 1;
        if (i <= mid){
            update(id << 1, l, mid, i, val);
        }
        else{
            update(id << 1 | 1, mid + 1, r, i, val);
        }
        seg[id] = seg[id << 1] + seg[id << 1 | 1];
    }
    
    ll get(int id, int l, int r, int u, int v){
        if (v < l || r < u){
            return 0;
        }
        if (u <= l && r <= v){
            return seg[id];
        }
        int mid = (l + r) >> 1;
        return get(id << 1, l, mid, u, v) + get(id << 1 | 1, mid + 1, r, u, v);
    }
} it2, it3;

int n;
ll ans;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n;
    ForE(nn, 1, n){
        int x; cin >> x;
        ll tans = 0;
        tans += (ll)(nn - 1) * x + it1.get(1, 1, M, x, x);
        for (int i = 0; i <= M; i += x){
            tans += it2.get(1, 1, M, max(i, 1), min(i + x - 1, M)) - i * it3.get(1, 1, M, max(i, 1), min(i + x - 1, M));
        }
        ans += tans;
        cout << ans << ' ';
        for (int i = x; i <= M; i += x){
            it1.update(1, 1, M, i, min(i + x - 1, M), -i);
        }
        it2.update(1, 1, M, x, x);
        it3.update(1, 1, M, x, 1);
    }
}

/*
==================================================+
INPUT:                                            |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
OUTPUT:                                           |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
*/