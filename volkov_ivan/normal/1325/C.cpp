#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 1e5 + 7;
vector <pair <int, int>> g[N];
pair <int, int> deg[N];
int ans[N];

int main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> v >> u;
        g[v].push_back({u, i});
        g[u].push_back({v, i});
        ans[i] = -1;
    }
    for (int i = 1; i <= n; i++) deg[i] = {g[i].size(), i};
    sort(deg + 1, deg + n + 1, greater <pair <int, int>>());
    int t = 0;
    for (int i = 1; i <= n; i++) {
        int v = deg[i].second;
        for (auto u : g[v]) {
            if (ans[u.second] == -1) ans[u.second] = t++;
        }
    }
    for (int i = 0; i < n - 1; i++) cout << ans[i] << '\n';
    return 0;
}