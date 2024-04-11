#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 2e5 + 5;
vector <int> g[MAX_N];

int dfs(int v, int prev) {
    int deg = g[v].size() - 1;
    if (deg == 0) return v;
    if (deg > 1) return -1;
    for (int i = 0; i < g[v].size(); i++) {
        if (g[v][i] != prev) return dfs(g[v][i], v);
    }
    return -1;
}

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, v, u;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> v >> u;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    int s = -1;
    for (int i = 1; i <= n; i++) {
        if (g[i].size() >= 3) {
            s = i;
            break;
        }
    }
    if (s == -1) s = 1;
    vector <pair <int, int> > ans;
    int last;
    for (int i = 0; i < g[s].size(); i++) {
        last = dfs(g[s][i], s);
        if (last == -1) {
            cout << "No" << endl;
            return 0;
        }
        ans.push_back(make_pair(s, last));
    }
    cout << "Yes" << endl;
    cout << ans.size() << endl;
    for (pair <int, int> elem : ans) {
        cout << elem.first << ' ' << elem.second << "\n";
    }
    return 0;
}