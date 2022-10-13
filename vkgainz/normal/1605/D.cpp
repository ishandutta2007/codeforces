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
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; i++) {
            int u, v; cin >> u >> v;
            --u, --v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> x, y;
        queue<int> q;
        q.push(0);
        vector<int> d(n, -1);
        d[0] = 0;
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            for (int next : adj[curr]) {
                if (d[next] == -1) {
                    d[next] = d[curr] + 1;
                    q.push(next);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (d[i] % 2) {
                y.push_back(i);
            } else {
                x.push_back(i);
            }
        }
        if (x.size() > y.size()) {
            swap(x, y);
        }
        vector<int> p(n);
        int r = 0, s = 0;
        for (int i = 0; i < 20; i++) {
            if (x.size() & (1 << i)) {
                for (int j = (1 << i); j < min((1 << (i + 1)), n); j++) {
                    p[x[r++]] = j;
                }
            } else {
                for (int j = (1 << i); j < min((1 << (i + 1)), n + 1); j++) {
                    p[y[s++]] = j;                   
                }
            }
        }
        for (int i = 0; i < n; i++) {
            cout << p[i] << " ";
        }
        cout << "\n";
    }
}