#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <set>
#include <map>
#include <array>
#include <queue>
 
using namespace std;
 
int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    if (m == 0) {
        cout << 3 << " " << n * 1LL * (n - 1) * 1LL * (n - 2) / 6 << "\n";
        return 0;
    }
    vector<int> col(n);
    bool bipartite = true;
    long long ans = 0LL;
    for (int i = 0; i < n; i++) {
        if (col[i]) continue;
        queue<int> q;
        q.push(i);
        array<int, 2> sto = {0, 0};
        col[i] = 1;
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            ++sto[col[curr] % 2];
            for (int next : adj[curr]) {
                if (col[next] == col[curr]) {
                    bipartite = false;
                } else if (col[next] == 0) {
                    col[next] = 3 - col[curr];
                    q.push(next);
                }
            }
        }
        ans += sto[0] * 1LL * (sto[0] - 1) / 2
            + sto[1] * 1LL * (sto[1] - 1) / 2;
    }
    if (!bipartite) {
        cout << 0 << " " << 1 << "\n";
        return 0;
    }
    int mxDeg = 0;
    int numComp = 0;
    for (int i = 0; i < n; i++) {
        mxDeg = max(mxDeg, (int) adj[i].size());
        numComp += adj[i].size();
    }
    if (mxDeg == 1) {
        cout << 2 << " " << (n - 2) * 1LL * numComp / 2 << "\n";
    } else {
        cout << 1 << " " << ans << "\n";
    }
}