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

const int N = 1e5 + 5;

struct segment_tree{
    struct node{
        int sum, mxpref, mxsuff, mxsub;

        node(int x = 0): sum(x), mxpref(x), mxsuff(x), mxsub(x){

        }

        friend node merge(const node &lhs, const node &rhs){
            node ans;
            ans.sum = lhs.sum + rhs.sum;
            ans.mxpref = max(lhs.mxpref, (lhs.sum != 0 and lhs.sum == lhs.mxpref and lhs.sum == lhs.mxsuff) ? lhs.sum + rhs.mxpref : 0);
            ans.mxsuff = max((rhs.sum != 0 and rhs.sum == rhs.mxpref and rhs.sum == rhs.mxsuff) ? rhs.sum + lhs.mxsuff : 0, rhs.mxsuff);
            ans.mxsub = max({lhs.mxsub, rhs.mxsub, lhs.mxsuff + rhs.mxpref});
            return ans;
        }
    };

    node seg[1 << 18];

    void build(int id, int l, int r){
        if (l == r){
            seg[id] = node();
            return;
        }
        int mid = (l + r) >> 1;
        build(id * 2, l, mid);
        build(id * 2 + 1, mid + 1, r);
        seg[id] = node();
    }

    void update(int id, int l, int r, int i){
        if (l == r){
            seg[id] = node(1);
            return;
        }
        int mid = (l + r) >> 1;
        if (i <= mid){
            update(id * 2, l, mid, i);
        }
        else{
            update(id * 2 + 1, mid + 1, r, i);
        }
        seg[id] = merge(seg[id * 2], seg[id * 2 + 1]);
    }

    node get(int id, int l, int r, int u, int v){
        if (v < l or r < u){
            return node();
        }
        if (u <= l and r <= v){
            return seg[id];
        }
        int mid = (l + r) >> 1;
        return merge(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
    }
} it;

int n;
int a[N];

int q;
int l[N], r[N], w[N];

pii b[N];
int lo[N], hi[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n;
    ForE(i, 1, n){
        cin >> a[i];
    }
    cin >> q;
    ForE(i, 1, q){
        cin >> l[i] >> r[i] >> w[i];
    }
    
    ForE(i, 1, n){
        b[i] = make_pair(a[i], i);
    }
    sort(b + 1, b + n + 1);
    ForE(i, 1, q){
        lo[i] = 1; hi[i] = 1000000000;
    }
    vi vidx;

    ForE(i, 1, q){
        vidx.emplace_back(i);
    }
    while (!vidx.empty()){
        vi tvidx;
        sort(bend(vidx), [&](int lhs, int rhs){
            return lo[lhs] + hi[lhs] > lo[rhs] + hi[rhs];
        });

        it.build(1, 1, n);
        int ctrvidx = 0;
        FordE(i, n, 1){
            while (ctrvidx < isz(vidx) and ((lo[vidx[ctrvidx]] + hi[vidx[ctrvidx]] + 1) >> 1) > b[i].fi){
                int mid = ((lo[vidx[ctrvidx]] + hi[vidx[ctrvidx]] + 1) >> 1);
                int idx = vidx[ctrvidx];
                if (it.get(1, 1, n, l[idx], r[idx]).mxsub >= w[idx]){
                    lo[idx] = mid;
                }
                else{
                    hi[idx] = mid - 1;
                }
                if (lo[idx] != hi[idx]){
                    tvidx.emplace_back(idx);
                }
                ctrvidx++;
            }
            it.update(1, 1, n, b[i].se);
        }
        while (ctrvidx < isz(vidx)){
            int mid = ((lo[vidx[ctrvidx]] + hi[vidx[ctrvidx]] + 1) >> 1);
            int idx = vidx[ctrvidx];
            if (it.get(1, 1, n, l[idx], r[idx]).mxsub >= w[idx]){
                lo[idx] = mid;
            }
            else{
                hi[idx] = mid - 1;
            }
            if (lo[idx] != hi[idx]){
                tvidx.emplace_back(idx);
            }
            ctrvidx++;
        }

        vidx.swap(tvidx);
    }

    ForE(i, 1, q){
        cout << lo[i] << endl;
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