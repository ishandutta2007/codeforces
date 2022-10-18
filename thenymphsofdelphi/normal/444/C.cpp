#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

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

const int N = 1e5 + 5;

struct lazy_segment_tree{
    ll seg[4 * N], lazy[4 * N];
    
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
} it;

struct interval{
    int l, r, val;

    interval(int l = 0, int r = 0, int val = 0): l(l), r(r), val(val){

    }

    friend bool operator< (const interval& lhs, const interval& rhs){
        return lhs.l < rhs.l;
    }
};

int n, q;

set <interval> stt;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> q;
    ForE(i, 1, n){
        stt.insert(interval(i, i, i));
    }
    while (q--){
        int que; cin >> que;
        if (que == 1){
            int l, r, val; cin >> l >> r >> val;
            int ll, lr;
            {
                auto itr = --stt.upper_bound(interval(l));
                ll = itr->l;
                itr = --stt.upper_bound(interval(r));
                lr = itr->l;
            }
            while (1){
                auto itr = stt.upper_bound(interval(l));
                if (itr == stt.end() or itr->l >= lr){
                    break;
                }
                it.update(1, 1, n, itr->l, itr->r, abs(itr->val - val));
                stt.erase(itr);
            }
            if (ll == lr){
                interval cac = *stt.lower_bound(interval(ll));
                it.update(1, 1, n, l, r, abs(cac.val - val));
                stt.erase(cac);
                if (cac.l < l){
                    stt.insert(interval(cac.l, l - 1, cac.val));
                }
                if (r < cac.r){
                    stt.insert(interval(r + 1, cac.r, cac.val));
                }
                stt.insert(interval(l, r, val));
            }
            else{
                interval cac1 = *stt.lower_bound(interval(ll));
                it.update(1, 1, n, l, cac1.r, abs(cac1.val - val));
                stt.erase(cac1);
                interval cac2 = *stt.lower_bound(interval(lr));
                it.update(1, 1, n, cac2.l, r, abs(cac2.val - val));
                stt.erase(cac2);
                if (cac1.l < l){
                    stt.insert(interval(cac1.l, l - 1, cac1.val));
                }
                if (r < cac2.r){
                    stt.insert(interval(r + 1, cac2.r, cac2.val));
                }
                stt.insert(interval(l, r, val));
            }
        }
        else{
            int l, r; cin >> l >> r;
            cout << it.get(1, 1, n, l, r) << endl;
        }
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