#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (auto i = (l); i < (r); i++)
#define ForE(i, l, r) for (auto i = (l); i <= (r); i++)
#define FordE(i, l, r) for (auto i = (l); i >= (r); i--)
#define Fora(v, a) for (auto v: (a))
#define bend(a) (a).begin(), (a).end()
#define isz(a) ((signed)(a).size())

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pii>;
using vvi = vector <vi>;

const int N = 1e5 + 5;

int n;
vi adj[N];

int lim;
vpii vans;

void dfs(int u, int p, int x){
    int sz = 0;
    Fora(v, adj[u]){
        if (v == p){
            continue;
        }
        sz++;
    }

    int y = x;
    vans.emplace_back(u, y);
    Fora(v, adj[u]){
        if (v == p){
            continue;
        }
        if (sz <= x - 1 and y >= x){
            y = x - 1 - sz;
            vans.emplace_back(u, y);
        }
        dfs(v, u, y + 1);
        y++;
        vans.emplace_back(u, y);
        sz--;
    }
    if (sz <= x - 1 and y >= x){
        y = x - 1 - sz;
        vans.emplace_back(u, y);
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n;
    For(i, 1, n){
        int u, v; cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    ForE(i, 1, n){
        lim = max(lim, isz(adj[i]));
    }
    dfs(1, 1, 0);

    cout << isz(vans) << endl;
    Fora(elem, vans){
        cout << elem.fi << ' ' << elem.se << endl;
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