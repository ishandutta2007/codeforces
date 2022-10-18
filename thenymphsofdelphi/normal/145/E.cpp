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

const int N = 1e6 + 5;

struct node{
    int sum4, sum7, lis, lds, lazy;

    node(int sum4 = 0, int sum7 = 0, int lis = 0, int lds = 0, int lazy = 0): sum4(sum4), sum7(sum7), lis(lis), lds(lds), lazy(lazy){

    }

    node& operator+= (const node& rhs){
        lis = max(lis + rhs.sum7, sum4 + rhs.lis);
        lds = max(lds + rhs.sum4, sum7 + rhs.lds);
        sum4 += rhs.sum4;
        sum7 += rhs.sum7;
        lazy = 0;
        return *this;
    }

    friend node operator+ (node lhs, const node& rhs){
        lhs += rhs;
        return lhs;
    }
};

struct segment_tree{
    node seg[4 * N];

    segment_tree(){

    }

    void build(const string& s, int id, int l, int r){
        if (l == r){
            if (s[l - 1] == '4'){
                seg[id] = node(1, 0, 1, 1, 0);
            }
            else{
                seg[id] = node(0, 1, 1, 1, 0);
            }
            return;
        }
        int mid = (l + r) >> 1;
        build(s, id * 2, l, mid);
        build(s, id * 2 + 1, mid + 1, r);
        seg[id] = seg[id * 2] + seg[id * 2 + 1];
    }

    void down(int id, int l, int r){
        if (!seg[id].lazy){
            return;
        }
        swap(seg[id * 2].sum4, seg[id * 2].sum7);
        swap(seg[id * 2].lis, seg[id * 2].lds);
        seg[id * 2].lazy ^= 1;
        swap(seg[id * 2 + 1].sum4, seg[id * 2 + 1].sum7);
        swap(seg[id * 2 + 1].lis, seg[id * 2 + 1].lds);
        seg[id * 2 + 1].lazy ^= 1;
        seg[id].lazy = 0;
    }

    void update(int u, int v, int id, int l, int r){
        if (v < l or r < u){
            return;
        }
        if (u <= l and r <= v){
            swap(seg[id].sum4, seg[id].sum7);
            swap(seg[id].lis, seg[id].lds);
            seg[id].lazy ^= 1;
            return;
        }
        down(id, l, r);
        int mid = (l + r) >> 1;
        update(u, v, id * 2, l, mid);
        update(u, v, id * 2 + 1, mid + 1, r);
        seg[id] = seg[id * 2] + seg[id * 2 + 1];
    }
};

int n, q;
string s;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> q;
    cin >> s;
    segment_tree cac;
    cac.build(s, 1, 1, n);
    while (q--){
        string que; cin >> que;
        if (que[0] == 's'){
            int l, r; cin >> l >> r;
            cac.update(l, r, 1, 1, n);
        }
        else{
            cout << cac.seg[1].lis << endl;
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