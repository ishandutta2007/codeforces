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

const int N = 2e5 + 5, mod = 998244353;

struct lazy_segment_tree{
    int seg[4 * N], lazy1[4 * N], lazy2[4 * N];
    
    void down(int id, int l, int r){
        if (lazy1[id] == 1 and lazy2[id] == 0){
            return;
        }
        int mid = (l + r) >> 1;
        seg[id << 1] = (ll)seg[id << 1] * lazy1[id] % mod + (ll)lazy2[id] * (mid - l + 1) % mod; if (seg[id << 1] >= mod) seg[id << 1] -= mod;
        seg[id << 1 | 1] = (ll)seg[id << 1 | 1] * lazy1[id] % mod + (ll)lazy2[id] * (r - mid) % mod; if (seg[id << 1 | 1] >= mod) seg[id << 1 | 1] -= mod;
        lazy1[id << 1] = (ll)lazy1[id << 1] * lazy1[id] % mod;
        lazy2[id << 1] = ((ll)lazy2[id << 1] * lazy1[id] + lazy2[id]) % mod;
        lazy1[id << 1 | 1] = (ll)lazy1[id << 1 | 1] * lazy1[id] % mod;
        lazy2[id << 1 | 1] = ((ll)lazy2[id << 1 | 1] * lazy1[id] + lazy2[id]) % mod;
        lazy1[id] = 1; lazy2[id] = 0;
    }
    
    void build(int id, int l, int r){
        if (l == r){
            seg[id] = 0;
            lazy1[id] = 1; lazy2[id] = 0;
            return;
        }
        int mid = (l + r) >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
        seg[id] = 0;
        lazy1[id] = 1; lazy2[id] = 0;
    }
    
    void update1(int id, int l, int r, int u, int v){
        if (v < l || r < u){
            return;
        }
        if (u <= l && r <= v){
            seg[id] *= 2; if (seg[id] >= mod) seg[id] -= mod;
            lazy1[id] *= 2; if (lazy1[id] >= mod) lazy1[id] -= mod;
            lazy2[id] *= 2; if (lazy2[id] >= mod) lazy2[id] -= mod;
            return;
        }
        down(id, l, r);
        int mid = (l + r) >> 1;
        update1(id << 1, l, mid, u, v);
        update1(id << 1 | 1, mid + 1, r, u, v);
        seg[id] = seg[id << 1] + seg[id << 1 | 1]; if (seg[id] >= mod) seg[id] -= mod;
    }
    
    void update2(int id, int l, int r, int u, int v){
        if (v < l || r < u){
            return;
        }
        if (u <= l && r <= v){
            seg[id] += r - l + 1; if (seg[id] >= mod) seg[id] -= mod;
            lazy2[id]++;
            return;
        }
        down(id, l, r);
        int mid = (l + r) >> 1;
        update2(id << 1, l, mid, u, v);
        update2(id << 1 | 1, mid + 1, r, u, v);
        seg[id] = seg[id << 1] + seg[id << 1 | 1]; if (seg[id] >= mod) seg[id] -= mod;
    }
    
    int get(int id, int l, int r, int u, int v){
        if (v < l || r < u){
            return 0;
        }
        if (u <= l && r <= v){
            return seg[id];
        }
        down(id, l, r);
        int mid = (l + r) >> 1;
        int ans = get(id << 1, l, mid, u, v) + get(id << 1 | 1, mid + 1, r, u, v); if (ans >= mod) ans -= mod;
        return ans;
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
set <interval> stt[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> q;
    it.build(1, 1, n);
    ForE(i, 1, n){
        stt[i].insert(interval(1, n, 0));
    }
    while (q--){
        int que; cin >> que;
        if (que == 1){
            int l, r, val; cin >> l >> r >> val;
            int ll, lr;
            {
                auto itr = --stt[val].upper_bound(interval(l));
                ll = itr->l;
                itr = --stt[val].upper_bound(interval(r));
                lr = itr->l;
            }
            while (1){
                auto itr = stt[val].upper_bound(interval(l));
                if (itr == stt[val].end() or itr->l >= lr){
                    break;
                }
                if (itr->val == 0){
                    it.update2(1, 1, n, itr->l, itr->r);
                }
                else{
                    it.update1(1, 1, n, itr->l, itr->r);
                }
                stt[val].erase(itr);
            }
            if (ll == lr){
                interval cac = *stt[val].lower_bound(interval(ll));
                if (cac.val == 0){
                    it.update2(1, 1, n, l, r);
                }
                else{
                    it.update1(1, 1, n, l, r);
                }
                stt[val].erase(cac);
                if (cac.l < l){
                    stt[val].insert(interval(cac.l, l - 1, cac.val));
                }
                if (r < cac.r){
                    stt[val].insert(interval(r + 1, cac.r, cac.val));
                }
                stt[val].insert(interval(l, r, 1));
            }
            else{
                interval cac1 = *stt[val].lower_bound(interval(ll));
                if (cac1.val == 0){
                    it.update2(1, 1, n, l, cac1.r);
                }
                else{
                    it.update1(1, 1, n, l, cac1.r);
                }
                stt[val].erase(cac1);
                interval cac2 = *stt[val].lower_bound(interval(lr));
                if (cac2.val == 0){
                    it.update2(1, 1, n, cac2.l, r);
                }
                else{
                    it.update1(1, 1, n, cac2.l, r);
                }
                stt[val].erase(cac2);
                if (cac1.l < l){
                    stt[val].insert(interval(cac1.l, l - 1, cac1.val));
                }
                if (r < cac2.r){
                    stt[val].insert(interval(r + 1, cac2.r, cac2.val));
                }
                stt[val].insert(interval(l, r, 1));
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