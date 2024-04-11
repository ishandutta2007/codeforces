#include <iostream>
#include <set>
#include <vector>
#include <cstring>

using namespace std;

const int N = 1007;
set <int> g[N];
int deg[N];
int dist[N];
bool bad[N];

void dfs(int v, int p = -1, int d = 0) {
    dist[v] = d;
    for (int u : g[v]) {
        if (u != p) dfs(u, v, d + 1);
    }
}

int main() {
    memset(bad, 0, sizeof(bad));
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;
        g[v].insert(u);
        g[u].insert(v);
    }
    while (1) {
        vector <int> lst;
        for (int i = 1; i <= n; i++) {
            if ((int) g[i].size() == 1) lst.push_back(i);
        }
        if (lst.empty()) {
            for (int i = 1; i <= n; i++) {
                if (!bad[i]) {
                    cout << "! " << i << endl;
                    return 0;
                }
            }
        }
        if ((int) lst.size() == 1) {
            cout << "! " << lst[0] << endl;
            return 0;
        }
        cout << "? " << lst[0] << ' ' << lst[1] << endl;
        int w;
        cin >> w;
        if (w == lst[0]) {
            cout << "! " << lst[0] << endl;
            return 0;
        }
        if (w == lst[1]) {
            cout << "! " << lst[1] << endl;
            return 0;
        }
        int v1 = *g[lst[0]].begin();
        g[lst[0]].erase(v1);
        g[v1].erase(lst[0]);
        int v2 = *g[lst[1]].begin();
        g[lst[1]].erase(v2);
        g[v2].erase(lst[1]);
        bad[lst[0]] = 1;
        bad[lst[1]] = 1;
    }
    return 0;
}