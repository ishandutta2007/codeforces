#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (auto i = l; i < r; i++)
#define ForE(i, l, r) for (auto i = l; i <= r; i++)
#define FordE(i, l, r) for (auto i = l; i >= r; i--)
#define Fora(v, a) for (auto v: a)
#define bend(a) a.begin(), a.end()
#define isz(a) ((signed)a.size())

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pair <int, int>>;
using vvi = vector <vector <int>>;

const int N = 1e5 + 5, M = 3e5 + 5;

struct lazy_segment_tree{
    pii seg[4 * M]; int lazy[4 * M];

    void build(int id, int l, int r){
        if (l == r){
            seg[id] = make_pair(0, l);
            lazy[id] = 0;
            return;
        }
        int mid = (l + r) >> 1;
        build(id * 2, l, mid);
        build(id * 2 + 1, mid + 1, r);
        seg[id] = max(seg[id * 2], seg[id * 2 + 1]);
        lazy[id] = 0;
    }

    void down(int id){
        if (lazy[id] == 0){
            return;
        }
        seg[id * 2].fi += lazy[id];
        seg[id * 2 + 1].fi += lazy[id];
        lazy[id * 2] += lazy[id];
        lazy[id * 2 + 1] += lazy[id];
        lazy[id] = 0;
    }

    void update(int id, int l, int r, int u, int v, int val){
        if (u <= l and r <= v){
            seg[id].fi += val;
            lazy[id] += val;
            return;
        }
        down(id);
        int mid = (l + r) >> 1;
        if (mid >= u){
            update(id * 2, l, mid, u, v, val);
        }
        if (mid + 1 <= v){
            update(id * 2 + 1, mid + 1, r, u, v, val);
        }
        seg[id] = max(seg[id * 2], seg[id * 2 + 1]);
    }

    pii get(int id, int l, int r, int u, int v){
        if (u <= l and r <= v){
            return seg[id];
        }
        down(id);
        int mid = (l + r) >> 1;
        pii ans = make_pair(INT_MIN, 0);
        if (mid >= u){
            ans = max(ans, get(id * 2, l, mid, u, v));
        }
        if (mid + 1 <= v){
            ans = max(ans, get(id * 2 + 1, mid + 1, r, u, v));
        }
        return ans;
    }
} it;

struct range{
    int l, x, r;

    range(){

    }

    range(int l, int x, int r): l(l), x(x), r(r){

    }
};

struct query{
    int type, idx;

    query(){

    }

    query(int type, int idx): type(type), idx(idx){

    }
};

int n;
range a[N];

tuple <int, int, int> ans;
vector <query> b[M];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n;
    ForE(i, 1, n){
        cin >> a[i].l >> a[i].x >> a[i].r;
    }

    ForE(i, 1, n){
        b[a[i].x].emplace_back(1, i);
        b[a[i].r + 1].emplace_back(2, i);
    }
    it.build(1, 1, M - 1);
    For(x, 1, M){
        Fora(que, b[x]){
            int i = que.idx;
            if (que.type == 1){
                it.update(1, 1, M - 1, a[i].l, a[i].x, 1);
            }
            else{
                it.update(1, 1, M - 1, a[i].l, a[i].x, -1);
            }
        }
        pii cac = it.get(1, 1, M - 1, 1, x);
        tuple <int, int, int> tans = make_tuple(cac.fi, cac.se, x);
        ans = max(ans, tans);
    }
    cout << get<0>(ans) << endl;
    int l, r; tie(ignore, l, r) = ans;
    ForE(i, 1, n){
        if (l <= a[i].x and a[i].x <= r and a[i].l <= l and r <= a[i].r){
            cout << i << ' ';
        }
    } cout << endl;
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