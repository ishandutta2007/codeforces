#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class TopologicalSort {
public:
    int V_NUM;
    vector<vector<int>> path;
    vector<int> order, id;
    vector<bool> visited;

    explicit TopologicalSort(int V_NUM) : V_NUM(V_NUM) {
        path.resize(V_NUM);
        id.resize(V_NUM);
        visited.assign(V_NUM, false);
    }

    void connect(int u, int v) {
        path[u].push_back(v);
    }

    void dfs(int v) {
        if (visited[v]) return;
        visited[v] = true;

        for (int sv : path[v]) {
            dfs(sv);
        }
        order.push_back(v);
    }

    void build() {
        for (int v = 0; v < V_NUM; ++v) {
            dfs(v);
        }
        reverse(order.begin(), order.end());
        for (int i = 0; i < V_NUM; ++i) {
            id[order[i]] = i;
        }
    }

    bool check() {
        for (int v = 0; v < V_NUM; ++v) {
            for (int sv : path[v]) {
                if (id[v] > id[sv]) return false;
            }
        }
        return true;
    }
};

int main() {
    int N, M;
    cin >> N >> M;

    int u[M], v[M], c[M];
    for (int i = 0; i < M; ++i) {
        cin >> u[i] >> v[i] >> c[i];
        --u[i], --v[i];
    }

    int ok = 1e9 + 1, ng = -1;
    // ok
    while (ok - ng > 1) {
        int mid = (ok + ng) / 2;

        TopologicalSort ts(N);
        for (int i = 0; i < M; ++i) {
            if (c[i] > mid) ts.connect(u[i], v[i]);
        }

        ts.build();
        if (ts.check()) {
            ok = mid;
        } else {
            ng = mid;
        }
    }

    TopologicalSort ts(N);
    for (int i = 0; i < M; ++i) {
        if (c[i] > ok) ts.connect(u[i], v[i]);
    }
    ts.build();

    vector<int> ans;
    for (int i = 0; i < M; ++i) {
        if (ts.id[u[i]] > ts.id[v[i]]) ans.push_back(i);
    }

    cout << ok << " " << ans.size() << endl;
    for (int i : ans) {
        cout << i + 1 << " ";
    }
    cout << endl;

    return 0;
}