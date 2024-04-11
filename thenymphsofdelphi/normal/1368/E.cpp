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

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <pii> vpii;
typedef vector <vi> vvi;

const int N = 2e5 + 5;

int n, m;
vi adj[N], radj[N];
int col[N], dp[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
int q; cin >> q; while (q--){
    cin >> n >> m;
    ForE(i, 1, n){
        adj[i].clear();
        radj[i].clear();
        dp[i] = 0;
        col[i] = 0;
    }
    ForE(i, 1, m){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        radj[v].push_back(u);
    }
    vi vans;
    ForE(u, 1, n){
        bool ck = 0;
        Fora(&v, radj[u]){
            if (dp[v] != -1){
                ck = 1;
            }
            dp[u] = max(dp[u], dp[v]);
        }
        if (!ck){
            continue;
        }
        dp[u]++;
        if (dp[u] <= 1){
            continue;
        }
        dp[u] = -1;
        vans.push_back(u);
    }
    cout << isz(vans) << endl;
    Fora(&v, vans){
        cout << v << ' ';
    } cout << endl;
}
}

/*
==================================================+
INPUT                                             |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
OUTPUT                                            |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
*/