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

const int N = 2e5 + 5, inf = 1e9 + 7;

struct segment_tree{
    tuple <int, int, ll> seg[1 << 19]; int lazy[1 << 19];

    tuple <int, int, ll> merge(const tuple <int, int, ll>& lhs, const tuple <int, int, ll>& rhs){
        if (std::get<0>(lhs) != std::get<0>(rhs)){
            return std::get<0>(lhs) < std::get<0>(rhs) ? lhs : rhs;
        }
        return make_tuple(std::get<0>(lhs), std::get<1>(lhs) + std::get<1>(rhs), std::get<2>(lhs) + std::get<2>(rhs));
    }

    void build(int id, int l, int r, bool parity){
        if (l == r){
            if ((l & 1) == parity){
                seg[id] = make_tuple(0, 1, l);
            }
            else{
                seg[id] = make_tuple(inf, 0, 0);
            }
            return;
        }
        int mid = (l + r) >> 1;
        build(id * 2, l, mid, parity);
        build(id * 2 + 1, mid + 1, r, parity);
        seg[id] = merge(seg[id * 2], seg[id * 2 + 1]);
    }

    void down(int id){
        if (!lazy[id]){
            return;
        }
        std::get<0>(seg[id * 2]) += lazy[id];
        std::get<0>(seg[id * 2 + 1]) += lazy[id];
        lazy[id * 2] += lazy[id];
        lazy[id * 2 + 1] += lazy[id];
        lazy[id] = 0;
    }

    void update(int id, int l, int r, int u, int v){
        if (v < l or r < u){
            return;
        }
        if (u <= l and r <= v){
            std::get<0>(seg[id])++;
            lazy[id]++;
            return;
        }
        down(id);
        int mid = (l + r) >> 1;
        update(id * 2, l, mid, u, v);
        update(id * 2 + 1, mid + 1, r, u, v);
        seg[id] = merge(seg[id * 2], seg[id * 2 + 1]);
    }

    tuple <int, int, ll> get(int id, int l, int r, int u, int v){
        if (v < l or r < u){
            return make_tuple(inf, 0, 0);
        }
        if (u <= l and r <= v){
            return seg[id];
        }
        down(id);
        int mid = (l + r) >> 1;
        tuple <int, int, ll> ansl = get(id * 2, l, mid, u, v), ansr = get(id * 2 + 1, mid + 1, r, u, v);
        return merge(ansl, ansr);
    }
} seg[2];

struct query{
    int idx, type;

    query(int idx = 0, int type = 0): idx(idx), type(type){

    }
};

int n, m;
pii a[N];

vector <query> queries[N];

multiset <int> segintersect[2];

ll ans;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> m;
    ForE(i, 1, n){
        cin >> a[i].fi >> a[i].se;
    }

    ForE(i, 1, n){
        queries[a[i].fi].emplace_back(i, 0);
        queries[a[i].se + 1].emplace_back(i, 1);
    }
    seg[0].build(1, 1, m, 0);
    seg[1].build(1, 1, m, 1);
    int lastr = 0;
    ForE(r, 1, m){
        Fora(&que, queries[r]){
            if (!que.type){
                segintersect[a[que.idx].fi & 1].insert(a[que.idx].fi);
            }
            else{
                segintersect[a[que.idx].fi & 1].erase(segintersect[a[que.idx].fi & 1].find(a[que.idx].fi));
                int tl, tr;
                tl = a[que.idx].fi; tr = a[que.idx].se - 1;
                if ((tl & 1) != (tr & 1)){
                    tl++;
                }
                if (tl <= tr){
                    seg[tr & 1].update(1, 1, m, tl, tr);
                }
                if (!((a[que.idx].se - a[que.idx].fi + 1) & 1)){
                    tl = 1; tr = a[que.idx].fi - 1;
                    if (tl <= tr){
                        seg[0].update(1, 1, m, tl, tr);
                        seg[1].update(1, 1, m, tl, tr);
                    }
                }
                lastr = r - 1;
            }
        }
        int ql[2] = {1, 1}, qr[2] = {r, r};
        if (!segintersect[r & 1].empty()){
            int l = *segintersect[r & 1].begin();
            qr[(r & 1) ^ 1] = l - 1;
        }
        if (!segintersect[(r & 1) ^ 1].empty()){
            int l = *segintersect[(r & 1) ^ 1].rbegin();
            ql[r & 1] = l + 1;
            qr[(r & 1) ^ 1] = 0;
        }
        if (ql[0] <= qr[0]){
            tuple <int, int, ll> tans = seg[0].get(1, 1, m, ql[0], qr[0]);
            if (get<0>(tans) == 0){
                ans += (ll)(r + 1) * get<1>(tans);
                ans -= get<2>(tans);
            }
        }
        if (ql[1] <= qr[1]){
            tuple <int, int, ll> tans = seg[1].get(1, 1, m, ql[1], qr[1]);
            if (get<0>(tans) == 0){
                ans += (ll)(r + 1) * get<1>(tans);
                ans -= get<2>(tans);
            }
        }
        if (segintersect[0].empty() and segintersect[1].empty()){
            ans -= (ll)(r + 1) * (r - lastr);
            ans += (ll)(r + lastr + 1) * (r - lastr) / 2;
        }
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