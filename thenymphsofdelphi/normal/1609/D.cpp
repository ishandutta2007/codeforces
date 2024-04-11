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

const int N = 1e3 + 5;

struct disjoint_set_union{
    int par[N];

    disjoint_set_union(){
        memset(par, -1, sizeof(par));
    }

    int root(int x){
        return par[x] < 0 ? x : (par[x] = root(par[x]));
    }

    bool merge(int x, int y){
        if ((x = root(x)) == (y = root(y))){
            return 0;
        }
        if (par[x] > par[y]){
            swap(x, y);
        }
        par[x] += par[y];
        par[y] = x;
        return 1;
    }
} dsu;

int n, m;
pii a[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> m;
    ForE(i, 1, m){
        cin >> a[i].fi >> a[i].se;
    }

    int cnt = 0;
    ForE(i, 1, m){
        if (dsu.merge(a[i].fi, a[i].se) == 0){
            cnt++;
        }
        vi b;
        ForE(j, 1, n){
            if (dsu.par[j] < 0){
                b.emplace_back(-dsu.par[j]);
            }
        }
        sort(bend(b)); reverse(bend(b));
        int ans = 0;
        ForE(j, 0, min(isz(b) - 1, cnt)){
            ans += b[j];
        }
        cout << ans - 1 << endl;
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