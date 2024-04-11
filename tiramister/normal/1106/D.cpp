#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> path[n];
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        path[u].push_back(v);
        path[v].push_back(u);
    }

    priority_queue<int, vector<int>, greater<int>> que;
    que.push(0);

    bool visited[n];
    fill(visited, visited + n, false);
    visited[0] = true;

    while (!que.empty()) {
        int v = que.top();
        que.pop();
        cout << v + 1 << " ";

        for (int sv : path[v]) {
            if (!visited[sv]) {
                que.push(sv);
                visited[sv] = true;
            }
        }
    }

    cout << endl;
    return 0;
}