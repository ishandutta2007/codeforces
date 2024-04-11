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

const int N = 1e5 + 5;

int n, m;
pii a[N];

vi adj[N];
int col[N];

bool dfs(int u){
    col[u] = 1;
    Fora(&v, adj[u]){
        if (!col[v]){
            if (dfs(v)){
                return 1;
            }
        }
        if (col[v] == 1){
            return 1;
        }
    }
    col[u] = 2;
    return 0;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    ForE(i, 1, m){
        cin >> a[i].fi >> a[i].se;
        adj[a[i].fi].push_back(a[i].se);
    }
    ForE(i, 1, n){
        if (!col[i]){
            if (dfs(i)){
                cout << 2 << endl;
                ForE(i, 1, m){
                    if (a[i].fi > a[i].se){
                        cout << 2 << ' ';
                    }
                    else{
                        cout << 1 << ' ';
                    }
                } cout << endl;
                return 0;
            }
        }
    }
    cout << 1 << endl;
    ForE(i, 1, m){
        cout << 1 << ' ';
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