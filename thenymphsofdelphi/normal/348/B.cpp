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
const ll infll = (ll)1e13 + 7;

ll lcm(ll x, ll y){
    return (__int128)(x / __gcd(x, y)) * y >= infll ? infll : x / __gcd(x, y) * y;
}

int n;
int a[N];
vi adj[N];

ll sum[N];
ll dp1[N];

void dfs1(int u, int p){
    int cntchild = 0;
    dp1[u] = 1;
    Fora(v, adj[u]){
        if (v == p){
            continue;
        }
        cntchild++;
        dfs1(v, u);
        dp1[u] = lcm(dp1[u], dp1[v]);
    }
    dp1[u] = min(dp1[u] * cntchild, infll);
    if (cntchild == 0){
        dp1[u] = 1;
    }
}

ll dp2[N];
ll ans;

void dfs2(int u, int p){
    int cntchild = 0;
    ll mn = infll;
    sum[u] = a[u];
    Fora(v, adj[u]){
        if (v == p){
            continue;
        }
        cntchild++;
        dfs2(v, u);
        sum[u] += sum[v];
        mn = min(mn, sum[v]);
    }
    if (cntchild){
        ll val = mn / (dp1[u] / cntchild) * (dp1[u] / cntchild);
        ans += sum[u] - cntchild * val;
        sum[u] = cntchild * val;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n;
    ForE(i, 1, n){
        cin >> a[i];
    }
    For(i, 1, n){
        int u, v; cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    dfs1(1, 1);
    if (dp1[1] == infll){
        cout << accumulate(a + 1, a + n + 1, 0ll) << endl;
        return 0;
    }
    dfs2(1, 1);
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