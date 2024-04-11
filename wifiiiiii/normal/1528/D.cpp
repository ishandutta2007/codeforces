#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int maxn = 605;
struct edge {
    int v, w;
    bool operator < (const edge & e) const {
        return w < e.w;
    }
};
vector<edge> g[maxn];
int dis[maxn], vis[maxn], from[maxn];
typedef pair<int,int> pii;
priority_queue<pii,vector<pii>,greater<pii>> q;
int n, m;
void dijkstra(int u) {
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[u] = 0;
    q.push({0, u});
    int start = -1;
    while(!q.empty()) {
        pii cur = q.top(); q.pop();
        if(vis[cur.second]) continue;
        vis[cur.second] = 1;
//        D(cur.second);
        for(edge e : g[cur.second]) {
            for(int i = 0; i < n; ++i) {
                int v = (e.v + dis[cur.second] + i) % n, w = dis[cur.second] + e.w + i;
                if(v == cur.second) continue;
//                D(cur.second, dis[cur.second], i, v, w);
                if(dis[v] > w) {
                    dis[v] = w;
                    from[v] = cur.second;
                    q.push({dis[v], v});
                    start = cur.second;
                } else if(v != u) {
                    break;
                }
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    for(int i = 0; i < n; ++i) {
        sort(g[i].begin(), g[i].end());
    }
    for(int i = 0; i < n; ++i) {
        dijkstra(i);
        for(int j = 0; j < n; ++j) cout << dis[j] << " ";
        cout << '\n';
    }
}