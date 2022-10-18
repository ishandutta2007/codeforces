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

const int N = 22, M = 1 << N;

int n, m;
int a[M];

int adj[2 * M];
bool ck[2 * M];

void dfs(int u){
    ck[u] = 1;
    if (adj[u] and !ck[adj[u]]){
        dfs(adj[u]);
    }
    if (u >= m){
        int msk = u - m;
        For(i, 0, n){
            if ((msk & (1 << i)) and !ck[m + (msk ^ (1 << i))]){
                dfs(m + (msk ^ (1 << i)));
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> m;
    For(i, 0, m){
        cin >> a[i]; 
    }
    memset(adj, -1, sizeof(adj));
    For(i, 0, m){
        adj[i] = m + (((1 << n) - 1) ^ a[i]);
        adj[m + a[i]] = i;
    }
    int ans = 0;
    For(i, 0, m){
        if (!ck[i]){
            ans++;
            dfs(i);
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