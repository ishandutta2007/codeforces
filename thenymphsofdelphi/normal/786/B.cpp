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

int n, q, s;
int idx[N];
vpii adj[12 * N];
ll dist[12 * N];

int node(int i, int j){
    return (i - 1) * 4 * N + j;
}

void initidx(int id, int l, int r){
    if (l == r){
        idx[l] = id;
        return;
    }
    int mid = (l + r) >> 1;
    adj[node(2, id)].emplace_back(node(2, id << 1), 0);
    adj[node(3, id << 1)].emplace_back(node(3, id), 0);
    initidx(id << 1, l, mid);
    adj[node(2, id)].emplace_back(node(2, id << 1 | 1), 0);
    adj[node(3, id << 1 | 1)].emplace_back(node(3, id), 0);
    initidx(id << 1 | 1, mid + 1, r);
}

void addedge2(int id, int l, int r, int u, int x, int y, int w){
    if (y < l || r < x){
        return;
    }
    if (x <= l && r <= y){
        adj[node(2, idx[u])].emplace_back(node(2, id), w);
        return;
    }
    int mid = (l + r) >> 1;
    addedge2(id << 1, l, mid, u, x, y, w);
    addedge2(id << 1 | 1, mid + 1, r, u, x, y, w);
}

void addedge3(int id, int l, int r, int u, int x, int y, int w){
    if (y < l || r < x){
        return;
    }
    if (x <= l && r <= y){
        adj[node(3, id)].emplace_back(node(3, idx[u]), w);
        return;
    }
    int mid = (l + r) >> 1;
    addedge3(id << 1, l, mid, u, x, y, w);
    addedge3(id << 1 | 1, mid + 1, r, u, x, y, w);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> q >> s;
    initidx(1, 1, n);
    ForE(i, 1, n){
        adj[node(1, idx[i])].emplace_back(node(2, idx[i]), 0);
        adj[node(2, idx[i])].emplace_back(node(1, idx[i]), 0);
        adj[node(1, idx[i])].emplace_back(node(3, idx[i]), 0);
        adj[node(3, idx[i])].emplace_back(node(1, idx[i]), 0);
    }
    while (q--){
        int que; cin >> que;
        if (que == 1){
            int u, v, w; cin >> u >> v >> w;
            adj[node(1, idx[u])].emplace_back(node(1, idx[v]), w);
        }
        else if (que == 2){
            int u, x, y, w; cin >> u >> x >> y >> w;
            addedge2(1, 1, n, u, x, y, w);
        }
        else if (que == 3){
            int u, x, y, w; cin >> u >> x >> y >> w;
            addedge3(1, 1, n, u, x, y, w);
        }
    }
    memset(dist, 0x3f, sizeof(dist));
    priority_queue <pair <ll, int>, vector <pair <ll, int>>, greater <pair <ll, int>>> pq;
    dist[node(1, idx[s])] = 0;
    pq.push(make_pair(0, node(1, idx[s])));
    while (!pq.empty()){
        ll d = pq.top().fi; int u = pq.top().se; pq.pop();
        if (d != dist[u]){
            continue;
        }
        Fora(&v, adj[u]){
            if (dist[v.fi] > d + v.se){
                dist[v.fi] = d + v.se;
                pq.push(make_pair(dist[v.fi], v.fi));
            }
        }
    }
    ForE(i, 1, n){
        if (dist[node(1, idx[i])] == dist[0]){
            cout << -1 << ' ';
        }
        else{
            cout << dist[node(1, idx[i])] << ' ';
        }
    }
}

/*
==================================+
INPUT:                            |
------------------------------    |

------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |

------------------------------    |
==================================+
*/