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

const int N = 6e2 + 5;

int n, m;
vpii adj[N];

ll dist[N];
bool ck[N];

void dijkstra(int s){
    memset(dist, 0x3f, sizeof(dist));
    memset(ck, 0, sizeof(ck));
    Fora(&edge, adj[s]){
        dist[edge.fi] = min(dist[edge.fi], (ll)edge.se);
    }
    For(turn, 1, n){
        int u = -1;
        For(i, 0, n){
            if (!ck[i] and (u == -1 or dist[i] < dist[u])){
                u = i;
            }
        }
        ck[u] = 1;
        Fora(&edge, adj[u]){
            dist[(edge.fi + dist[u]) % n] = min(dist[(edge.fi + dist[u]) % n], dist[u] + edge.se);
        }
        dist[(u + 1) % n] = min(dist[(u + 1) % n], dist[u] + 1);
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> m;
    ForE(i, 1, m){
        int u, v, w; cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
    }
    For(i, 0, n){
        dijkstra(i);
        For(j, 0, n){
            cout << (j == i ? 0 : dist[j]) << ' ';
        } cout << endl;
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