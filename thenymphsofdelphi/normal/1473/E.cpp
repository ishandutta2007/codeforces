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

const int N = 2e5 + 5;

struct node{
    int u; bool mx, mn;

    node(){

    }

    node(int u, bool mx, bool mn): u(u), mx(mx), mn(mn){

    }
};

bool operator< (const node& lhs, const node& rhs){
    return 0;
}

int n, m;
vpii adj[N];

ll dist[N][2][2];

priority_queue <pair <ll, node>, vector <pair <ll, node>>, greater <pair <ll, node>>> pq;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> m;
    ForE(i, 1, m){
        int u, v, w; cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    memset(dist, 0x3f, sizeof(dist));
    dist[1][0][0] = 0;
    pq.push(make_pair(dist[1][0][0], node(1, 0, 0)));
    while (!pq.empty()){
        ll d = pq.top().fi; node nd = pq.top().se; pq.pop();
        if (dist[nd.u][nd.mx][nd.mn] != d){
            continue;
        }
        Fora(&edge, adj[nd.u]){
            ll td = d + edge.se;
            if (dist[edge.fi][nd.mx][nd.mn] > td){
                dist[edge.fi][nd.mx][nd.mn] = td;
                pq.push(make_pair(td, node(edge.fi, nd.mx, nd.mn)));
            }
            if (!nd.mn and dist[edge.fi][nd.mx][1] > td + edge.se){
                dist[edge.fi][nd.mx][1] = td + edge.se;
                pq.push(make_pair(td + edge.se, node(edge.fi, nd.mx, 1)));
            }
            if (!nd.mx and dist[edge.fi][1][nd.mn] > td - edge.se){
                dist[edge.fi][1][nd.mn] = td - edge.se;
                pq.push(make_pair(td - edge.se, node(edge.fi, 1, nd.mn)));
            }
            if (!nd.mx and !nd.mn and dist[edge.fi][1][1] > td){
                dist[edge.fi][1][1] = td;
                pq.push(make_pair(td, node(edge.fi, 1, 1)));
            }
        }
    }
    ForE(u, 2, n){
        cout << dist[u][1][1] << ' ';
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