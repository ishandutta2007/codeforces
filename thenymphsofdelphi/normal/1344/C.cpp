#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,fma")

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
int col[N];

void dfs(int u){
    col[u] = 1;
    Fora(&v, adj[u]){
        if (!col[v]){
            dfs(v);
        }
        else if (col[v] == 1){
            cout << -1 << endl;
            exit(0);
        }
    }
    col[u] = 2;
}

int ans;
string sans;

bool ck[N], rck[N];

void dfs1(int u){
    ck[u] = 1;
    Fora(&v, adj[u]){
        if (!ck[v]){
            dfs1(v);
        }
    }
}

void dfs2(int u){
    rck[u] = 1;
    Fora(&v, radj[u]){
        if (!rck[v]){
            dfs2(v);
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> m;
    ForE(i, 1, m){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        radj[v].push_back(u);
    }
    ForE(i, 1, n){
        if (!col[i]){
            dfs(i);
        }
    }
    sans.resize(n);
    ForE(i, 1, n){
        if (!ck[i] and !rck[i]){
            ans++;
            sans[i - 1] = 'A';
        }
        else{
            sans[i - 1] = 'E';
        }
        if (!ck[i]){
            dfs1(i);
        }
        if (!rck[i]){
            dfs2(i);
        }
    }
    cout << ans << endl;
    cout << sans << endl;
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