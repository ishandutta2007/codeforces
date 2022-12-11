#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 2e5 + 7;
vector <int> g[MAX_N];
int lleft[MAX_N], rright[MAX_N], arr[MAX_N];
int T = 0;

void dfs(int v) {
    lleft[v] = T;
    arr[T++] = v;
    for (int u : g[v]) dfs(u);
    rright[v] = T - 1;
}

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    int n, v, u, k, q;
    cin >> n >> q;
    for (int i = 2; i <= n; i++) {
        cin >> v;
        g[v].push_back(i);
    }
    dfs(1);
    for (int i = 0; i < q; i++) {
        cin >> u >> k;
        if (rright[u] - lleft[u] + 1 < k) cout << -1 << "\n";
        else cout << arr[lleft[u] + k - 1] << "\n";
    }
    return 0;
}