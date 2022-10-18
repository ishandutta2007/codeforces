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

const int N = 3e5 + 5, inf = 1e9 + 7;

struct lazy_segment_tree{
    pii seg[4 * N]; int lazy[4 * N];
    
    void down(int id, int l, int r){
        lazy[id << 1] += lazy[id];
        lazy[id << 1 | 1] += lazy[id];
        seg[id << 1].fi += lazy[id];
        seg[id << 1 | 1].fi += lazy[id];
        lazy[id] = 0;
    }

    pii merge(const pii& lhs, const pii& rhs){
        if (lhs.fi != rhs.fi){
            return lhs.fi < rhs.fi ? lhs : rhs;
        }
        return {lhs.fi, lhs.se + rhs.se};
    }
    
    void build(int id, int l, int r){
        if (l == r){
            seg[id] = {0, 1};
            return;
        }
        int mid = (l + r) >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
        seg[id] = merge(seg[id << 1], seg[id << 1 | 1]);
    }
    
    void update(int id, int l, int r, int u, int v, int val){
        if (v < l || r < u){
            return;
        }
        if (u <= l && r <= v){
            seg[id].fi += val;
            lazy[id] += val;
            return;
        }
        down(id, l, r);
        int mid = (l + r) >> 1;
        update(id << 1, l, mid, u, v, val);
        update(id << 1 | 1, mid + 1, r, u, v, val);
        seg[id] = merge(seg[id << 1], seg[id << 1 | 1]);
    }
    
    pii get(int id, int l, int r, int u, int v){
        if (v < l || r < u){
            return {inf, 1};
        }
        if (u <= l && r <= v){
            return seg[id];
        }
        down(id, l, r);
        int mid = (l + r) >> 1;
        return merge(get(id << 1, l, mid, u, v), get(id << 1 | 1, mid + 1, r, u, v));
    }
} it;

int n;
int a[N];

deque <int> dqmx, dqmn;
ll ans;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n;
    ForE(i, 1, n){
        int x, y; cin >> x >> y;
        a[x] = y;
    }
    it.build(1, 1, n);
    dqmx.push_back(0); dqmn.push_back(0);
    ForE(i, 1, n){
        while (dqmx.back() != 0 and a[dqmx.back()] < a[i]){
            int l, r = dqmx.back(), val = a[dqmx.back()]; dqmx.pop_back(); l = dqmx.back() + 1;
            it.update(1, 1, n, l, r, a[i] - val);
        } dqmx.push_back(i);
        while (dqmn.back() != 0 and a[dqmn.back()] > a[i]){
            int l, r = dqmn.back(), val = a[dqmn.back()]; dqmn.pop_back(); l = dqmn.back() + 1;
            it.update(1, 1, n, l, r, val - a[i]);
        } dqmn.push_back(i);
        it.update(1, 1, n, 1, i - 1, -1);
        ans += it.get(1, 1, n, 1, i).se;
    }
    cout << ans << endl;
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