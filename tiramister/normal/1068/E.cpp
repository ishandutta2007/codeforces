#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> path[100010];

int kdfs(int r, int v) {
    vector<int> lev;
    for (int sv : path[v]) {
        if (sv == r) continue;
        lev.push_back(kdfs(v, sv));
    }

    if (lev.empty()) return 0;
    if (lev.size() < 3) return -1;

    sort(lev.begin(), lev.end());
    lev.erase(unique(lev.begin(), lev.end()), lev.end());

    if (lev.size() > 1 || lev[0] < 0) {
        return -1;
    } else {
        return lev[0] + 1;
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    if (n == 1) {
        cout << "No" << endl;
        return 0;
    }

    int in[n];
    fill(in, in + n, 0);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        ++in[u], ++in[v];
        path[u].push_back(v);
        path[v].push_back(u);
    }

    queue<int> que;
    for (int v = 0; v < n; ++v) {
        if (in[v] == 1) que.push(v);
    }

    int center = -1;
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        center = v;
        --in[v];

        for (int sv : path[v]) {
            if (in[sv] == 0) continue;
            --in[sv];
            if (in[sv] == 1) que.push(sv);
        }
    }

    cout << (kdfs(-1, center) == k ? "Yes" : "No") << endl;
    return 0;
}