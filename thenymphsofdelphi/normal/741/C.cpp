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

int n;
pii a[N];
vi adj[N];
int col[N];

void dfs(int u, int t){
    col[u] = t;
    Fora(&v, adj[u]){
        if (col[v]){
            continue;
        }
        dfs(v, 3 - t);
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n;
    ForE(i, 1, n){
        int x, y; cin >> x >> y;
        a[i] = make_pair(x, y);
        adj[x].push_back(y); adj[y].push_back(x);
        adj[2 * i - 1].push_back(2 * i); adj[2 * i].push_back(2 * i - 1);
    }
    ForE(i, 1, 2 * n){
        if (!col[i]){
            dfs(i, 1);
        }
    }
    ForE(i, 1, n){
        cout << col[a[i].fi] << ' ' << col[a[i].se] << endl;
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