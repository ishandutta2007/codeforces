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

const int N = 5e5 + 5;

int n, m;
unordered_set <int> adj[N];

void readTest(){
    cin >> n >> m;
    ForE(i, 1, n){
        adj[i].clear();
    }
    ForE(i, 1, m){
        int u, v; cin >> u >> v;
        adj[u].insert(v); adj[v].insert(u);
    }
}

set <int> rem;
vi adj2[N];
int center[N], sz[N];
int p[N], q[N];

void resetTest(){
    rem.clear();
    ForE(i, 1, n){
        rem.insert(i);
        adj2[i].clear();
        center[i] = 0;
        sz[i] = 0;
    }
}

void dfs(int u){
    rem.erase(u);
    int v;
    for (auto itr = rem.begin(); itr != rem.end(); itr = rem.upper_bound(v)){
        v = *itr;
        if (adj[u].find(v) == adj[u].end()){
            adj2[u].push_back(v);
            adj2[v].push_back(u);
            dfs(v);
        }
    }
}

void solveTest(){
    ForE(i, 1, n){
        if (rem.find(i) != rem.end()){
            dfs(i);
        }
    }
    ForE(i, 1, n){
        if (!center[i]){
            if (isz(adj2[i]) == 0){
                center[i] = i;
                sz[i] = 1;
                continue;
            }
            int j = adj2[i][0];
            if (!center[j]){
                center[i] = i; center[j] = i; sz[i] = 2;
            }
            else if (center[j] == j){
                center[i] = j; sz[j]++;
            }
            else if (sz[center[j]] == 2){
                sz[center[j]] = 0; center[center[j]] = j; center[j] = j; center[i] = j; sz[j] = 3;
            }
            else{
                sz[center[j]]--;
                center[j] = j; center[i] = j; sz[j] = 2;
            }
        }
    }
    unordered_map <int, vi> mpp;
    ForE(i, 1, n){
        mpp[center[i]].push_back(i);
    }
    int ctr = 0, delta;
    Fora(&v, mpp){
        delta = 0;
        p[v.fi] = ctr + 1;
        For(i, 0, isz(v.se)){
            if (v.se[i] == v.fi){
                delta--;
                continue;
            }
            p[v.se[i]] = ctr + 2 + i + delta;
        }
        delta = 0;
        q[v.fi] = ctr + isz(v.se);
        For(i, 0, isz(v.se)){
            if (v.se[i] == v.fi){
                delta--;
                continue;
            }
            q[v.se[i]] = ctr + 1 + i + delta;
        }
        ctr += isz(v.se);
    }
    ForE(i, 1, n){
        cout << p[i] << ' ';
    } cout << endl;
    ForE(i, 1, n){
        cout << q[i] << ' ';
    } cout << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen(".inp", "r", stdin);
    // freopen(".out", "w", stdout);
int q; cin >> q; while (q--){
    readTest();
    resetTest();
    solveTest();
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