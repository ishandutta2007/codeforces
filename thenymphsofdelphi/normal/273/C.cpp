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

mt19937 rando(chrono::steady_clock::now().time_since_epoch().count());
int randt(int l, int r, int k = 0){
    if (k > 0){
        return max(randt(l, r, k - 1), (int)(rando() % (r - l + 1)) + l);
    }
    if (k < 0){
        return min(randt(l, r, k + 1), (int)(rando() % (r - l + 1)) + l);
    }
    return rando() % (r - l + 1) + l;
}

const int N = 3e5 + 5;

int n, m;
vi adj[N];

int col[N];

queue <int> qu;

bool issoke(int u){
    int cnt = 0;
    Fora(v, adj[u]){
        if (col[v] == col[u]){
            cnt++;
        }
    }
    return cnt <= 1;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> m;
    ForE(i, 1, m){
        int u, v; cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    ForE(u, 1, n){
        col[u] = 0;
    }
    ForE(u, 1, n){
        if (!issoke(u)){
            qu.emplace(u);
        }
    }
    while (!qu.empty()){
        int u = qu.front(); qu.pop();
        if (issoke(u)){
            continue;
        }
        col[u] = 1 - col[u];
        Fora(v, adj[u]){
            if (!issoke(v)){
                qu.emplace(v);
            }
        }
    }
    ForE(u, 1, n){
        cout << col[u];
    } cout << endl;
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