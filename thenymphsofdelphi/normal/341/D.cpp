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

const int N = 1e5 + 5e4 + 7, S = sqrt(2 * N) + 2, mod = 998244353;

struct fenwick_tree_2d{
    vector <vector <ll>> bit;
    int n, m;

    fenwick_tree_2d(int n = 0, int m = 0){
        this->n = n + 1;
        this->m = m + 1;
        bit.assign(this->n + 1, vector <ll>(this->m + 1, 0));
    }

    fenwick_tree_2d(const vvi& a){
        n = a.size() + 1;
        m = a[0].size() + 1;
        bit.assign(n + 1, vector <ll>(m + 1, 0));
        For(i, 0, a.size()){
            For(j, 0, a[0].size()){
                update(i, j, a[i][j]);
            }
        }
    }

    ll get(int x, int y){
        ll ans = 0;
        for (int i = x; i > 0; i -= i & -i){
            for (int j = y; j > 0; j -= j & -j){
                ans ^= bit[i][j];
            }
        }
        return ans;
    }

    ll get(int x1, int y1, int x2, int y2){
        return get(x2, y2) ^ get(x2, y1 - 1) ^ get(x1 - 1, y2) ^ get(x1 - 1, y1 - 1);
    }

    void update(int x, int y, ll delta){
        for (int i = x; i <= n; i += i & -i){
            for (int j = y; j <= m; j += j & -j){
                bit[i][j] ^= delta;
            }
        }
    }
} bit[2][2];

int n, q;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> q;
    bit[0][0] = fenwick_tree_2d(n, n);
    bit[0][1] = fenwick_tree_2d(n, n);
    bit[1][0] = fenwick_tree_2d(n, n);
    bit[1][1] = fenwick_tree_2d(n, n);
    while (q--){
        int que, x1, y1, x2, y2; cin >> que >> x1 >> y1 >> x2 >> y2;
        if (que == 1){
            ll ans = 0;
            ans ^= bit[x2 & 1][y2 & 1].get(x2, y2);
            ans ^= bit[x2 & 1][(y1 - 1) & 1].get(x2, y1 - 1);
            ans ^= bit[(x1 - 1) & 1][y2 & 1].get(x1 - 1, y2);
            ans ^= bit[(x1 - 1) & 1][(y1 - 1) & 1].get(x1 - 1, y1 - 1);
            cout << ans << endl;
        }
        else{
            ll val; cin >> val;
            bit[x1 & 1][y1 & 1].update(x1, y1, val);
            bit[x1 & 1][(y2 + 1) & 1].update(x1, y2 + 1, val);
            bit[(x2 + 1) & 1][y1 & 1].update(x2 + 1, y1, val);
            bit[(x2 + 1) & 1][(y2 + 1) & 1].update(x2 + 1, y2 + 1, val);
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