#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <set>
#include <map>
#include <array>
#include <queue>
#include <unordered_map>
#include <cstring>
#include <iomanip>
#include <chrono>
 
using namespace std;
 
int main() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<pair<int, int>>> par(n);
        vector<vector<int>> tree(n);
        vector<tuple<int, int, int>> edges;
        for (int i = 0; i < n - 1; i++) {
            int x, y, v; cin >> x >> y >> v;
            --x, --y;
            tree[x].push_back(y);
            tree[y].push_back(x);
            if (v != -1) {
                int p = __builtin_popcount(v) % 2;
                par[x].push_back({y, p});
                par[y].push_back({x, p});
                edges.push_back({x, y, v});
            }
            //draw edges by parity of v
        }
        for (int i = 0; i < m; i++) {
            int a, b, p; cin >> a >> b >> p;
            --a, --b;
            par[a].push_back({b, p});
            par[b].push_back({a, p});
        }
        vector<int> id(n);
        vector<int> d(n);
        bool work = true;
        for (int i = 0; i < n && work; i++) {
            if (id[i]) continue;
            id[i] = 2;
            queue<int> q;
            q.push(i);
            while (!q.empty() && work) {
                int curr = q.front();
                q.pop();
                for (auto next : par[curr]) {
                    if (id[next.first] == 0) {
                        id[next.first] = 2 - (id[curr] + next.second) % 2;
                        q.push(next.first);
                    } else {
                        if (id[next.first] 
                                != (2 - (id[curr] + next.second) % 2)) {
                            work = false;
                            break;
                        }
                    }
                }
            }
            q.push(i);
        }
        if (!work) { 
            cout << "NO" << "\n";
            continue;
        } else {
            cout << "YES" << "\n";
        }
        queue<int> q;
        q.push(0);
        d[0] = 1;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int next : tree[curr]) {
                if (d[next] == 0) {
                    d[next] = d[curr] + 1;
                    q.push(next);
                }
            }
        }
        vector<int> f(n, -1);
        vector<int> val(n);
        f[0] = 0;
        for (auto &[a, b, c] : edges) {
            if (d[a] > d[b]) {
                f[a] = c;
            } else {
                f[b] = c;
            }
        }
        q.push(0);
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int next : tree[curr]) {
                if (d[next] > d[curr]) {
                    q.push(next);
                    if (f[next] != -1) {
                        val[next] = val[curr] ^ f[next];
                        continue;
                    }
                    if (id[next] == id[curr]) {
                        f[next] = 0;
                    } else {
                        f[next] = val[curr] ^ (id[next] % 2);   
                    }
                    val[next] = val[curr] ^ f[next];
                }
            }
        }
        q.push(0);
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int next : tree[curr]) {
                if (d[next] > d[curr]) {
                    cout << curr + 1 << " " << next + 1 << " " << f[next] << "\n";
                    q.push(next);
                }
            }
        }
    }
}