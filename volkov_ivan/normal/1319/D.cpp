#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <set>

using namespace std;

const int N = 2e5 + 7;
vector <int> g[N];
int dist[N];
set <int> prv[N];
bool vis[N];

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> v >> u;
        g[u].push_back(v);
    }
    int k;
    cin >> k;
    vector <int> path(k);
    for (int i = 0; i < k; i++) cin >> path[i];
    int t = path[k - 1];
    vis[t] = 1;
    dist[t] = 0;
    queue <int> q;
    q.push(t);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : g[v]) {
            if (!vis[u]) {
                vis[u] = 1;
                dist[u] = dist[v] + 1;
                q.push(u);
            }
            if (vis[u] && dist[u] == dist[v] + 1) {
                prv[u].insert(v);
            }
        }
    }
    int mini = 0, maxi = 0;
    for (int i = 1; i < k; i++) {
        if (prv[path[i - 1]].find(path[i]) == prv[path[i - 1]].end()) mini++, maxi++;
        else {
            if ((int) prv[path[i - 1]].size() >= 2) maxi++;
        }
    }
    cout << mini << ' ' << maxi << endl;
}