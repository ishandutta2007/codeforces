#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int query(char t, int v) {
    cout << t << " " << v + 1 << endl;
    int res;
    cin >> res;
    return res - 1;
}

void answer(int v) {
    cout << 'C' << " " << (v < 0 ? -1 : v + 1) << endl;
}

void solve() {
    int n;
    cin >> n;
    vector<int> path[n];
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        path[u].push_back(v);
        path[v].push_back(u);
    }

    int k[2];
    set<int> x[2];
    for (int i = 0; i < 2; ++i) {
        cin >> k[i];
        for (int j = 0; j < k[i]; ++j) {
            int v;
            cin >> v;
            --v;
            x[i].insert(v);
        }
    }

    int r = query('B', *x[1].begin());  // 1

    // 
    vector<bool> visited(n, false);
    visited[r] = true;
    queue<int> que;
    que.push(r);

    while (!que.empty()) {
        int v = que.front();
        que.pop();
        if (x[0].count(v)) {
            r = v;
            break;
        }

        for (int sv : path[v]) {
            if (visited[sv]) continue;
            visited[sv] = true;
            que.push(sv);
        }
    }

    // r
    if (x[1].count(query('A', r))) {
        answer(r);
    } else {
        answer(-1);
    }
}

int main() {
    int Q;
    cin >> Q;
    for (int q = 0; q < Q; ++q) solve();
    return 0;
}