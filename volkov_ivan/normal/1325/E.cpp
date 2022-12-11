#include <iostream>
#include <vector>
#include <cassert>
#include <cstring>
#include <queue>

using namespace std;

const int K = 1007, N = 1e6 + 7;
vector <int> g[N];
bool has[N];
bool vis[N];
int dist[N];
int best = N;
int par[N];

vector <int> fact(int n) {
    int i = 2;
    vector <int> res;
    while (i * i <= n) {
        if (n % i == 0) {
            int k = 0;
            while (n % i == 0) {
                n /= i;
                k++;
            }
            if (k % 2 == 1) res.push_back(i);
        }
        i++;
    }
    if (n != 1) res.push_back(n);
    return res;
}

int bfs(int start) {
    memset(vis, 0, sizeof(vis));
    queue <int> q;
    q.push(start);
    vis[start] = 1;
    dist[start] = 0;
    vector <int> vv;
    par[start] = -1;
    while (!q.empty()) {
        int v = q.front();
        vv.push_back(v);
        q.pop();
        for (int u : g[v]) {
            if (!vis[u]) {
                dist[u] = dist[v] + 1;
                vis[u] = 1;
                par[u] = v;
                q.push(u); 
            }
        }
    }
    for (int v : vv) {
        for (int u : g[v]) {
            if (u != par[v] && dist[v] >= dist[u]) best = min(best, dist[v] + dist[u] + 1);
        }
    }
    return N;
}

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(has, 0, sizeof(has));
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        auto kek = fact(x);
        assert((int) kek.size() <= 2);
        if (kek.empty()) {
            cout << 1 << endl;
            return 0;
        }
        int res = 1;
        for (int elem : kek) res *= elem;
        if (has[res]) best = 2;
        has[res] = 1;
        if ((int) kek.size() == 1) {
            g[1].push_back(kek[0]);
            g[kek[0]].push_back(1);
        } else {
            g[kek[0]].push_back(kek[1]);
            g[kek[1]].push_back(kek[0]);
        }
    }
    for (int i = 1; i < K; i++) bfs(i);
    cout << (best == N ? -1 : best) << endl;
}