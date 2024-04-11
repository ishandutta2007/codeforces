#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 200005 * 101;
struct edge {
    int v,w;
};

vector<edge> g[maxn];
int dis[maxn];
bool vis[maxn];
typedef pair<int,int> pii;
priority_queue<pii,vector<pii>,greater<pii>> q;
void dijkstra(int u) {
    memset(dis,0x3f,sizeof(dis));
    dis[u] = 0;
    q.push({0, u});
    while(!q.empty()) {
        pii cur = q.top(); q.pop();
        if(vis[cur.second]) continue;
        vis[cur.second] = 1;
        for(edge e : g[cur.second]) {
            if(dis[e.v] > dis[cur.second] + e.w) {
                dis[e.v] = dis[cur.second] + e.w;
                q.push({dis[e.v], e.v});
            }
        }
    }
}

const int inf = 0x3f3f3f3f;
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<vector<int>>> a(n, vector<vector<int>>(51));
    vector<vector<int>> in(n, vector<int>(51));
    vector<vector<int>> out(n, vector<int>(51));
    for(int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        a[u][w].push_back(v);
        a[v][w].push_back(u);
    }
    int tot = n;
    for(int i = 0; i < n; ++i) {
        vector<int> tmp;
        for(int j = 1; j <= 50; ++j) {
            if(a[i][j].empty()) continue;
            tmp.push_back(j);
            in[i][j] = ++tot;
            out[i][j] = ++tot;
            for(int u : a[i][j]) {
                g[u].push_back({in[i][j], 0});
                g[out[i][j]].push_back({u, 0});
            }
        }
        for(int j : tmp) {
            for(int k : tmp) {
                g[in[i][j]].push_back({out[i][k], (j+k)*(j+k)});
            }
        }
    }
    dijkstra(0);
    for(int i = 0; i < n; ++i) {
        if(dis[i] == inf) cout << -1 << " ";
        else cout << dis[i] << " ";
    }
    cout << endl;
}